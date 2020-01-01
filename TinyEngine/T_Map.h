//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ����: 2019-11-28
// ��Ȩ���� 2007-2019 ������
// (C) 2007-2019 WanLizhong All Rights Reserved
//*******************************************************************
#pragma once
#include "T_Graph.h"
#include "T_Layer.h"

class T_Map:public T_Layer
{
protected:
	int tile_width;					// ͼ���
	int tile_height;				// ͼ���
	int map_cols;					// ��ͼͼ��������
	int map_rows;					// ��ͼͼ��������
	int	first_gid;					// ͼ���Ŵ�0����1��ʼ	
	bool updated;					// ��ͼͼ���Ƿ����
	
	T_Graph* graph;					// ����ͼ��ͼ��򱳾�ͼ��
	HDC dc_buf;						// ��ǰͼ���ڴ��豸
	HBITMAP hbmp_old;				// �滻ǰ��ԭʼλͼ���
	HBITMAP hbmp_layer;				// ��ǰͼ��λͼ���
	vector<vector<int>> layer_data;	// ��ͼͼ������
	
public:
	T_Map(LAYERINFO layerInfo);		//ʹ�õ�ͼ���ݹ���
	T_Map(wchar_t* imgFilepath);		//ʹ�ñ���ͼƬ����
	virtual ~T_Map(void);

	int getTileWidth(){ return tile_width; }		// ���ͼ���
	int getTileHeight(){ return tile_height; }		// ���ͼ���
	int getMapCols(){ return map_cols; }			// ��ȡ��ͼͼ��������
	int getMapRows(){ return map_rows; }			// ��ȡ��ͼͼ��������
	void setUpdate(bool updt){ updated = updt; }	// ����ͼ��λͼ�Ƿ����
	bool getUpdate(){ return updated; }				// ��ȡͼ��λͼ�Ƿ����״̬
	virtual string ClassName(){ return "T_Map"; }	// ��ȡ��ǰ�������

	void setTile(int col, int row, int tileIndex);	// �޸ĵ�ǰͼ��ָ���С��е�Ԫ��ֵ
	int getTile(int col, int row);					// ��ȡ��ǰͼ��ָ���С��е�Ԫ��ֵ
	void Redraw(HDC hdc);							// ���»��Ƶ�ǰͼ��ȫ��ͼ��
	void Draw(HDC hdc);								// ���ظ����е�ͬ������,����ͼ�����
};