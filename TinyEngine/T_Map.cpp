//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ����: 2019-11-28
// ��Ȩ���� 2007-2019 ������
// (C) 2007-2019 WanLizhong All Rights Reserved
//*******************************************************************

#include "T_Map.h"

//ʹ�õ�ͼ���ݹ���
T_Map::T_Map(LAYERINFO layerInfo)
{
	graph = NULL;
	graph = new T_Graph(layerInfo.tile_path);
	if (graph != NULL)	//���·������ͼƬ���ɹ�����
	{
		layer_data = layerInfo.data;

		SetWidth(layerInfo.map_cols*layerInfo.tile_width);
		SetHeight(layerInfo.map_rows*layerInfo.tile_height);

		first_gid = layerInfo.first_gid;
		tile_width = layerInfo.tile_width;
		tile_height = layerInfo.tile_height;
		map_cols = layerInfo.map_cols;
		map_rows = layerInfo.map_rows;

		hbmp_layer = T_Graph::CreateBlankBitmap((int)GetWidth(), (int)GetHeight(), Color::White);
		dc_buf = CreateCompatibleDC(GetDC(0));
		hbmp_old = (HBITMAP)SelectObject(dc_buf, hbmp_layer);

		Visible = true;
		updated = true;
	}
}

//ʹ�ñ���ͼƬ����
T_Map::T_Map(wchar_t* imgFilepath)
{
	bool loadOK = false;
	graph = NULL;

	int len = (int)wcslen(imgFilepath);
	if (len <= 0)
	{
		throw L"�ļ�·������Ϊ�գ�";
	}
	if (len > 0)
	{
		graph = new T_Graph(imgFilepath);
		if (graph != NULL)	//���·������ͼƬ���ɹ�����
		{
			SetWidth(graph->GetImageWidth());
			SetHeight(graph->GetImageHeight());

			tile_width = 0;
			tile_height = 0;
			map_cols = 0;
			map_rows = 0;
			X = 0;
			Y = 0;
			Visible = true;
		}
	}
}

// ��������
T_Map::~T_Map(void)
{
	vector<vector<int>>::iterator p = layer_data.begin();
	for (; p != layer_data.end();)
	{
		p->clear();
		p = layer_data.erase(p);
	}
	layer_data.clear();
	//ʹ��swap,���Ԫ�ز������ڴ�
	//�����������С����������
	vector<vector<int>> emptyVec;
	layer_data.swap(emptyVec);

	delete graph;
	graph = NULL;

	SelectObject(dc_buf, hbmp_old);
	DeleteObject(hbmp_layer);
	DeleteObject(hbmp_old);
	DeleteDC(dc_buf);//ɾ���ڴ��豸
	hbmp_layer = NULL;
	hbmp_old = NULL;
}

// �޸ĵ�ǰͼ��ָ���С��е�Ԫ��ֵ
void T_Map::setTile(int col, int row, int tileIndex)
{
	if ((col < 0) || (col >= map_cols) || (row < 0) || (row >= map_rows))
	{
		throw L"��������ֵ��Ч��";
	}

	if (tileIndex > 0)
	{
		if (tileIndex >= (map_cols*map_rows))
			throw L"ͼ������ֵ��Ч��";
	}

	layer_data[row][col] = tileIndex;

	updated = true;
}

// ��ȡ��ǰͼ��ָ���С��е�Ԫ��ֵ
int T_Map::getTile(int col, int row)
{
	if ((col < 0) || (col >= map_cols) || (row < 0) || (row >= map_rows))
	{
		throw L"��������ֵ��Ч��";
	}

	return layer_data[row][col];
}

// ���»��Ƶ�ǰͼ��ȫ��ͼ��
void T_Map::Redraw(HDC hdc)
{
	if (graph->GetImageHeight() > 0 && graph->GetImageWidth() > 0)
	{
		int width = (int)GetWidth();
		int height = (int)GetHeight();

		SelectObject(dc_buf, hbmp_old);
		DeleteObject(hbmp_layer);
		hbmp_layer = NULL;
		hbmp_layer = T_Graph::CreateBlankBitmap(width, height, Color::White);
		hbmp_old = (HBITMAP)SelectObject(dc_buf, hbmp_layer);

		if (Visible == true)
		{
			int tileIndex = 0;

			int tX = 0, tY = 0;
			int r = 0, c = 0;
			int img_col = 0, img_row = 0;

			int tileImageWidth = graph->GetImageWidth();
			HDC memDC = CreateCompatibleDC(hdc);
			HBITMAP OldMemBmp = (HBITMAP)SelectObject(memDC, graph->GetBmpHandle());

			for (r = 0, tY = 0; r < map_rows; r++, tY += tile_height)
			{
				for (c = 0, tX = 0; c < map_cols; c++, tX += tile_width)
				{
					int imgTotalCols = tileImageWidth / tile_width;
					tileIndex = layer_data[r][c];
					//�õ�ͼƬ�ϵ����к�
					if (first_gid == 1)
					{
						//�õ�ͼƬ�ϵ����к�
						img_col = (tileIndex - 1) % imgTotalCols;
						img_row = (tileIndex - 1) / imgTotalCols;
					}
					else
					{
						img_col = tileIndex % imgTotalCols;
						img_row = tileIndex / imgTotalCols;
					}

					BLENDFUNCTION frame_bf;
					frame_bf.BlendOp = AC_SRC_OVER;
					frame_bf.BlendFlags = 0;
					frame_bf.SourceConstantAlpha = 255;
					frame_bf.AlphaFormat = AC_SRC_ALPHA;
					AlphaBlend(
						dc_buf, tX, tY, tile_width, tile_height,
						memDC, img_col*tile_width, img_row*tile_height,
						tile_width, tile_height, frame_bf
					);
				}
			}
			//��ԭ��ʹ��ԭ�������滻�ڴ��豸�е�λͼ����
			SelectObject(memDC, OldMemBmp);
			DeleteDC(memDC);//ɾ���ڴ��豸
			DeleteObject(OldMemBmp);//ɾ��λͼ����
			updated = false;
		}
	}
}

// ͼ�����
void T_Map::Draw(HDC hdc)
{
	//���Ʊ���ͼ��
	if (tile_width == 0 && tile_height == 0)
	{
		if (graph->GetImageHeight() > 0 && graph->GetImageWidth() > 0)
		{
			graph->PaintImage(hdc, (int)X, (int)Y);
		}
	}
	//������Tiles��ɵĵ�ͼͼ��
	if (tile_width > 0 && tile_height > 0)
	{
		if (updated == true)
		{
			Redraw(hdc);
		}

		if (updated == false)
		{
			BLENDFUNCTION frame_bf;
			frame_bf.BlendOp = AC_SRC_OVER;
			frame_bf.BlendFlags = 0;
			frame_bf.SourceConstantAlpha = 255;
			frame_bf.AlphaFormat = AC_SRC_ALPHA;

			AlphaBlend(
				hdc, (int)X, (int)Y, (int)GetWidth(), (int)GetHeight(),
				dc_buf, 0, 0, (int)GetWidth(), (int)GetHeight(), frame_bf
			);
		}
	}
}