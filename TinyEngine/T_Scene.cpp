//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ����: 2019-11-28
// ��Ȩ���� 2007-2019 ������
// (C) 2007-2019 WanLizhong All Rights Reserved
//*******************************************************************
#include "T_Scene.h"

// ���캯��
T_Scene::T_Scene()
{
	lastSceneX = 0;
	lastSceneY = 0;
	SceneY = 0;
	SceneX = 0;
	SceneWidth = 0;
	SceneHeight = 0;
	WinWidth = 0;
	WinHeight = 0;
	pBarrier = NULL;		//��ײͼ��ָ��
	pMask= NULL;			//���ֲ�ָ��
	LayerChanged = false;
}

// ��������
T_Scene::~T_Scene(void)
{
	RemoveAll();
}

// ������ʼ��
void T_Scene::InitScene(int scn_x, int scn_y, 
						int scn_width, int scn_height, 
						int win_width, int win_height)
{
	SceneX = scn_x;
	SceneY = scn_y;
	lastSceneX = scn_x;
	lastSceneY = scn_y;
	SceneWidth = scn_width;
	SceneHeight = scn_height;
	WinWidth = win_width;
	WinHeight = win_height;
}

// ������λ����
void T_Scene::SetScenePos(int x, int y)
{
	lastSceneX = SceneX;
	lastSceneY = SceneY;

	SceneX = x;
	SceneY = y;
}

// �����ƶ�������
void T_Scene::MoveScene(int speedX, int speedY)
{	
	lastSceneX = SceneX;
	lastSceneY = SceneY;

	int nextStepX, nextStepY; 
	nextStepX = SceneX + speedX;
	nextStepY = SceneY + speedY;

	if(nextStepX >= 0) 
		speedX = 0 - SceneX;
	if(nextStepX <= (WinWidth-SceneWidth)) 
		speedX = (WinWidth-SceneWidth) - SceneX;

	if(nextStepY >= 0) 
		speedY = 0 - SceneY;
	if(nextStepY <= (WinHeight-SceneHeight)) 
		speedY = (WinHeight-SceneHeight) - SceneY;

	SceneX += speedX;
	SceneY += speedY;
}

void T_Scene::ScrollScene(T_Sprite* player)
{
	bool scn_scrolling = false;
	int speedX=0, speedY=0;
	switch(player->GetDir())
	{
	case DIR_LEFT:
		speedX = player->GetSpeed();
		speedY = 0;
		// �����ɫ���봰�����Ե���֮һ�������򣬳���������
		if (player->GetX() > (WinWidth/5) ) 
		{
			scn_scrolling = false;
		}
		else// ���봰�����Ե���֮һ�������򣬳�����Ҫ����
		{
			scn_scrolling = true;
		}
		break;
	case DIR_RIGHT:
		speedX = -player->GetSpeed();
		speedY = 0;
		// �����ɫ���봰���ұ�Ե���֮һ�������򣬳���������
		if (player->GetX() < (WinWidth*4/5)-player->GetRatioSize().cx) 
		{
			scn_scrolling = false;
		}
		else// ���봰���ұ�Ե���֮һ�������򣬳�����Ҫ����
		{
			scn_scrolling = true;
		}
		break;
	case DIR_UP:
		speedX = 0;
		speedY = player->GetSpeed();

		// �����ɫ���봰���ϱ�Ե���֮һ�������򣬳���������
		if (player->GetY() > (WinHeight/5)) 
		{
			scn_scrolling = false;
		}
		else // ���봰���ϱ�Ե���֮һ�������򣬳�����Ҫ����
		{
			scn_scrolling = true;
		}
		break;
	case DIR_DOWN:
		speedX = 0;
		speedY =  -player->GetSpeed();
		// �����ɫ���봰���±�Ե���֮һ�������򣬳���������
		if (player->GetY() < (WinHeight*4/5)-player->GetRatioSize().cy) 
		{
			scn_scrolling = false;
		}
		else// ���봰���±�Ե���֮һ�������򣬳�����Ҫ����
		{
			scn_scrolling = true;
		}
		break;
	case DIR_LEFT_UP:
		// �����ɫ���봰�����Ե���ϱ�Ե���֮һ�������򣬳���������
		if (player->GetX() > (WinWidth/5)  &&  player->GetY() > (WinHeight/5)) 
		{
			scn_scrolling = false;
		}
		// ���봰�����Ե���ϱ�Ե���֮һ�������򣬳�����Ҫ����
		if (player->GetX() <= (WinWidth/5) &&  player->GetY() <= (WinHeight/5)) 
		{
			// �����ɫ���Ͻǵ�����
			POINT spPT = {player->GetX(), player->GetY()};
			// ���㳡�����Ͻǵ�����
			POINT scenePT = {SceneX, SceneY};
			// ���ݽ�ɫ�ƶ����ٶȣ������spPT��scenePT֮�䣬
			// ��������б���ƶ�ʱ��X��Y����ķ�������
			// speedX��speedYΪ���ռ�����
			T_Util::GetBevelSpeed(spPT, scenePT, player->GetSpeed(), speedX, speedY);
			speedX = -speedX;
			speedY = -speedY;
			scn_scrolling = true;
		}
		break;
	case DIR_LEFT_DOWN:
		// �����ɫ���봰�����Ե���±�Ե���֮һ�������򣬳���������
		if ((player->GetX() > (WinWidth/5)) &&  
			(player->GetY() < ((WinHeight*4/5)-player->GetRatioSize().cy)))
		{
			scn_scrolling = false;
		}
		//���봰�����Ե���±�Ե���֮һ�������򣬳�����Ҫ����
		if ((player->GetX() <= (WinWidth/5)) &&  
			(player->GetY() >= ((WinHeight*4/5)-player->GetRatioSize().cy)))
		{
			// �����ɫ���½ǵ�����
			POINT spPT = {player->GetX(), player->GetY()+player->GetRatioSize().cy};
			// ���㳡�����½ǵ�����
			POINT scenePT = {SceneX, SceneY+SceneHeight};
			// ���ݽ�ɫ�ƶ����ٶȣ������spPT��scenePT֮�䣬
			// ��������б���ƶ�ʱ��X��Y����ķ�������
			// speedX��speedYΪ���ռ�����
			T_Util::GetBevelSpeed(spPT, scenePT, player->GetSpeed(), speedX, speedY);
			speedX = -speedX;
			speedY = -speedY;
			scn_scrolling = true;
		}
		break;
	case DIR_RIGHT_UP:
		// �����ɫ���봰���ұ�Ե���ϱ�Ե���֮һ�������򣬳���������
		if ((player->GetX() < (WinWidth*4/5)-player->GetRatioSize().cx) &&  
			(player->GetY() > (WinHeight/5)))
		{
			scn_scrolling = false;
		}
		//���봰���ұ�Ե���ϱ�Ե���֮һ�������򣬳�����Ҫ����
		if ((player->GetX() >= (WinWidth*4/5)-player->GetRatioSize().cx) &&  
			(player->GetY() <= (WinHeight/5)))
		{
			// �����ɫ���Ͻǵ�����
			POINT spPT = {player->GetX()+player->GetRatioSize().cx, player->GetY()};
			// ���㳡�����Ͻǵ�����
			POINT scenePT = {SceneX+SceneWidth, SceneY};
			// ���ݽ�ɫ�ƶ����ٶȣ������spPT��scenePT֮�䣬
			// ��������б���ƶ�ʱ��X��Y����ķ�������
			// speedX��speedYΪ���ռ�����
			T_Util::GetBevelSpeed(spPT, scenePT, player->GetSpeed(), speedX, speedY);
			speedX = -speedX;
			speedY = -speedY;
			scn_scrolling = true;
		}
		break;
	case DIR_RIGHT_DOWN:
		// �����ɫ���봰���ұ�Ե���±�Ե���֮һ�������򣬳���������
		if ((player->GetX() < (WinWidth*4/5)-player->GetRatioSize().cx) &&  
			(player->GetY() < (WinHeight*4/5)-player->GetRatioSize().cy))
		{
			scn_scrolling = false;
		}
		//���봰���ұ�Ե���±�Ե���֮һ�������򣬳�����Ҫ����
		if ((player->GetX() >= (WinWidth*4/5)-player->GetRatioSize().cx) &&  
			(player->GetY() >= (WinHeight*4/5)-player->GetRatioSize().cy))
		{
			// �����ɫ���½ǵ�����
			POINT spPT = {player->GetX()+player->GetRatioSize().cx, 
				          player->GetY()+player->GetRatioSize().cy};
			// ���㳡�����½ǵ�����
			POINT scenePT = {SceneX+SceneWidth, SceneY+SceneHeight};
			// ���ݽ�ɫ�ƶ����ٶȣ������spPT��scenePT֮�䣬
			// ��������б���ƶ�ʱ��X��Y����ķ�������
			// speedX��speedYΪ���ռ�����
			T_Util::GetBevelSpeed(spPT, scenePT, player->GetSpeed(), speedX, speedY);
			speedX = -speedX;
			speedY = -speedY;
			scn_scrolling = true;
		}
		break;
	}
	//�����ͼ���Թ�����������ͼ
	if (scn_scrolling == true) 
	{
		MoveScene((int)speedX, (int)speedY);
	}
}


// ���ͼ��
void T_Scene::Append(GAMELAYER gm_layer)
{
	sceneLayers.push_back(gm_layer);
	LayerChanged = true;
}

// ��ָ����ͼ��������ǰ����ͼ��
void T_Scene::Insert(GAMELAYER gm_layer, int index)
{
	int p_index = 0;
	SCENE_LAYERS::iterator p;
	for (p = sceneLayers.begin(); p != sceneLayers.end(); p++) 
	{
		if(p_index == index)
		{
			sceneLayers.insert(p, gm_layer);
			break;
		}
		p_index++;
	}
}

// ɾ��ָ��ͼ��
void T_Scene::Remove(GAMELAYER gm_layer)
{
	SCENE_LAYERS::iterator p;
	for (p = sceneLayers.begin(); p != sceneLayers.end(); p++) 
	{
		if((*p).layer == gm_layer.layer)
		{
			sceneLayers.erase(p);
			break;
		}
	}
}

// ɾ��ȫ��ͼ��
void T_Scene::RemoveAll()
{	
	//���ͼ������
	SCENE_LAYERS::iterator vp = sceneLayers.begin();
	for (; vp != sceneLayers.end();) 
	{
		if(vp->layer)
		{
			delete vp->layer;
			vp->layer = NULL;
			vp = sceneLayers.erase(vp);
		}
	}
	sceneLayers.clear();
	//ʹ��swap,���Ԫ�ز������ڴ�
	//�����������С����������
	vector<GAMELAYER> emptyVec;
	sceneLayers.swap(emptyVec);
}

// ͼ������ȽϺ������ú�������Ϊ��̬������
bool T_Scene::SortByZorder(const GAMELAYER &l1, const GAMELAYER &l2)
{
	return l1.z_order < l2.z_order;//��������
}

// ����ͼ�������Ŷ�ͼ���������
void T_Scene::SortLayers()
{
	sort(sceneLayers.begin(),sceneLayers.end(),SortByZorder);  
	LayerChanged = false;
}

// �õ���ͼ�Ϸ��ϰ������λ��
POINT T_Scene::getRandomFreeCell()
{
	POINT cellPos = {0, 0};

	int row = 0, col = 0;

	do 
	{
		row = rand()%(pBarrier->getMapRows()-1);
		col = rand()%(pBarrier->getMapCols()-1);
		if(row==0) row = 1;
		if(col==0) col = 1;

		bool isFree = true;

		for(int r=row-1; r<=row+1; r++)
		{
			for(int c=col-1; c<=col+1; c++)
			{
				if(pBarrier->getTile(c, r)!=0 ||
					pMask->getTile(c, r)!=0)
				{
					isFree = false;
					break;
				}
			}
			if(isFree == false)
			{
				break;
			}
		}

		if(isFree == true)
		{
			break;
		}
	}while(1);

	cellPos.x = (col-1)*pBarrier->getTileWidth();
	cellPos.y = (row-1)*pBarrier->getTileHeight();

	cellPos.x = SceneX + cellPos.x;
	cellPos.y = SceneY + cellPos.y;

	return cellPos;
}

// ������һ������ָ�����ַ������Ƿ���ڵڶ�������ָ���Ĺؼ���
// ������ڣ������ؼ��ֺ��ֵ��ת�������ͣ�ͨ���������������
void T_Scene::GetTxtMapValue(wstring str, wstring keywords, int& value)
{
	int pos;
	pos = (int)(str.find(keywords));
	if(pos !=-1)
	{
		pos= (int)(str.find(L"="));
		value = _wtoi(str.substr(pos+1, wcslen(str.c_str())).c_str());
	}
}

// ������һ������ָ�����ַ������Ƿ���ڵڶ�������ָ���Ĺؼ���
// ������ڣ������ؼ��ֺ��ֵ��ת�����ַ�����ͨ���������������
void T_Scene::GetTxtMapValue(wstring str, wstring keywords, wstring& value)
{
	int pos;
	pos = (int)(str.find(keywords));
	if(pos !=-1)
	{
		pos= (int)(str.find(L"="));
		value = str.substr(pos+1, wcslen(str.c_str())).c_str();
		pos= (int)(value.find(L">"));
		if(pos !=-1)
		{
			value = value.substr(0, pos);
		}
	}
}

// ������һ������ָ����CSV��ʽ�ĵ�ͼ�����ַ���
// ��������ĵ�ͼ���ݱ��浽�ڶ���������dataԪ����
void T_Scene::parseCsvData(wstring csv_data, LAYERINFO& m_LayerInfo)
{
	wstring data = csv_data;

	vector<int> layerDataRow( m_LayerInfo.map_cols );
	int m_LayerRow = 0;
	int m_LayerCol = 0;

	for (int i = 0; i < m_LayerInfo.map_rows; i++)
	{
		m_LayerInfo.data.push_back( layerDataRow );
	}

	int pos =0;
	while(pos !=-1 && m_LayerRow<m_LayerInfo.map_rows)
	{
		pos= (int)(data.find(','));
		int gid = _wtoi(data.substr(0,pos).c_str());
		data = data.substr(pos+1, data.size());

		m_LayerInfo.data[m_LayerRow][m_LayerCol] = gid;

		m_LayerCol++;
		if(m_LayerCol == m_LayerInfo.map_cols)
		{
			m_LayerCol = 0;
			m_LayerRow++;
		}
	}
}

// ���ز���ָ���ĵ�ͼ�ļ����������еĵ�ͼ���ݣ������浽����ͼ����
bool T_Scene::LoadTxtMap(const char* txtmap_path)
{
	//	***************************************************************************
	//	txt���ı���ͼ��ʽ��
	//	map_width=50					//�Ⱥź�Ϊ��ͼͼ������
	//	map_height=50					//�Ⱥź�Ϊ��ͼͼ������
	//	tile_width=32					//�Ⱥź�Ϊ��ͼͼ����
	//	tile_height=32				//�Ⱥź�Ϊ��ͼͼ��߶�
	//	tile_path=map\Forest.png		//�Ⱥź�Ϊ��ͼͼ��ͼ���ļ�·��
	//	tile_grid_id=1				//�Ⱥź�Ϊ��ͼͼ������ʼ��
	//	back_layer_name=background	//�Ⱥź�Ϊ��ͼ����ͼ������
	//	barrier_layer_name=obstacle	//�Ⱥź�Ϊ��ͼ�ϰ����ͼ������
	//	mask_layer_name=mask			//�Ⱥź�Ϊ��ͼ����ͼ������
	//	<layer name=background>		//<layer>���,����Ϊ��ͼ����,nameΪͼ������
	//	����<layer>���֮��ճ��csv��ʽһά��ͼ����
	//	</layer>						//��ͼ���ݽ����ı��
	//	......						//�����������ϸ�ʽʹ��<layer>����������ͼ��
	//	***************************************************************************
	
	string str;
	wifstream infile(txtmap_path,ios::in);

	if(!infile)
	{
		return false;
	}

	wchar_t* l_str = new wchar_t[10240];
	wstring line_str;
	wstring mapdata= L"";
	bool startReadMapData=false;
	int layerCount=0;
	wstring barrierName = L"";
	wstring maskName = L"";
	wstring bkgName = L"";
	wstring currentlayerName = L"";

	LAYERINFO layerInfo;
	GAMELAYER mapLayer;

	while(!infile.eof())
	{
		infile.getline(l_str, 10240);//���ж�ȡ,��ȡ�������l_str
		line_str = wstring(l_str);

		//�����ж϶�ȡ��ÿ���������Ƿ���Ҫ���ҵĹؼ���, Ȼ���������Ӧ������
		GetTxtMapValue(line_str, L"map_cols", layerInfo.map_cols);
		GetTxtMapValue(line_str, L"map_rows", layerInfo.map_rows);
		GetTxtMapValue(line_str, L"tile_width", layerInfo.tile_width);
		GetTxtMapValue(line_str, L"tile_height", layerInfo.tile_height);
		GetTxtMapValue(line_str, L"tile_path", layerInfo.tile_path);
		GetTxtMapValue(line_str, L"tile_grid_id", layerInfo.first_gid);
		GetTxtMapValue(line_str, L"back_layer_name", bkgName);
		GetTxtMapValue(line_str, L"barrier_layer_name", barrierName);
		GetTxtMapValue(line_str, L"mask_layer_name", maskName);
		
		// �����Ƿ���layer���, ����ȡ��Ӧ��ͼ������
		if(line_str.find(L"<layer")!=-1)
		{
			GetTxtMapValue(line_str, L"name", currentlayerName);

			//���">"���Ƿ�������
			int pos = (int)(line_str.find(L">"));
			if(pos>0 && pos < (int)(line_str.length()-1))
			{
				line_str = line_str.substr(pos+1, line_str.length());
				mapdata = mapdata+line_str;
			}
			startReadMapData = true;
			continue;
		}
		// ������ͼͼ������
		if(startReadMapData == true)
		{
			// ���û�е�������</layer>���, ���Ͻ�ͼ������������ַ�����
			if(line_str.find(L"</layer>") == -1)
			{
				mapdata = mapdata+line_str;
			}
			// ������������</layer>���
			if(line_str.find(L"</layer>") != -1)
			{
				startReadMapData = false;
				// �������ַ����е�ͼ������
				parseCsvData(mapdata, layerInfo);
				// ��ͼ�����ݹ���T_Map����
				mapLayer.layer = new T_Map(layerInfo);
				// �жϵ�ǰͼ���Ƿ�Ϊ����ͼ��
				if( currentlayerName == bkgName && 
					currentlayerName != L"" && bkgName!= L"")
				{
					mapLayer.layer->SetLayerTypeID(LAYER_MAP_BACK);
					mapLayer.type_id = LAYER_MAP_BACK;
					layerInfo.type_id = LAYER_MAP_BACK;
				}
				// �жϵ�ǰͼ���Ƿ�Ϊ�ϰ�ͼ��
				if(currentlayerName == barrierName && 
				   currentlayerName != L"" && barrierName!= L"")
				{
					pBarrier = (T_Map*)mapLayer.layer;//ָ����ײͼ��
					mapLayer.layer->SetLayerTypeID(LAYER_MAP_BARR);
					mapLayer.type_id = LAYER_MAP_BARR;
					layerInfo.type_id = LAYER_MAP_BARR;
					
				}
	
				//���Ϊ���ֲ�,��z_orderΪLAYER_MAX
				if(currentlayerName == maskName && 
				   currentlayerName != L"" && maskName!= L"")
				{
					mapLayer.z_order = LAYER_MAX;
					mapLayer.layer->setZorder(LAYER_MAX);
					pMask = (T_Map*)mapLayer.layer;//ָ������ͼ��
					mapLayer.layer->SetLayerTypeID(LAYER_MAP_MASK);
					mapLayer.type_id = LAYER_MAP_MASK;
					layerInfo.type_id = LAYER_MAP_MASK;
				}
				else
				{
					mapLayer.z_order = layerCount;
					mapLayer.layer->setZorder(layerCount);
				}
				// ��ͼ�������ӵ�ͼ��������
				sceneLayers.push_back(mapLayer);
				
				mapdata = L"";
				layerInfo.data.clear();
				layerInfo.type_id = -1;
				layerCount = layerCount + 1;
			}
		}
	}
	delete[] l_str;
	return true;
}

// ������Ϸ�����Ļ���
void T_Scene::Draw(HDC hdc, int x, int y)
{	
	// ���㳡����ǰ�����볡����һ������Ĳ�ֵ
	int offsetX =0;
	int offsetY =0;
	offsetX = (abs(lastSceneX) - abs(SceneX));
	offsetY = (abs(lastSceneY) - abs(SceneY));
	// ���ͼ�㷢�����κα仯
	if(LayerChanged == true)
	{
		SortLayers();//��ͼ����������
	}
		
	int pX, pY;
	// ����ȫ��ͼ��
	SCENE_LAYERS::iterator p;
	for (p = sceneLayers.begin(); p != sceneLayers.end(); p++) 
	{
		// ����ÿ��ͼ��Ҫƽ�ƵĲ���
		pX = (*p).layer->GetX();
		pX += offsetX;
		pY = (*p).layer->GetY();
		pY += offsetY;
		(*p).layer->SetPosition(pX, pY);
		// ���ͼ��ɼ�,������Ƴ���
		if((*p).layer->IsVisible() == true)
		{
			(*p).layer->Draw(hdc);//����ͼ���Լ��Ļ��Ʒ���
		}
	}

	//�����ݸ�λ
	lastSceneX = SceneX;
	lastSceneY = SceneY;
}