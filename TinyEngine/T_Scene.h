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
#include "T_Map.h"
#include "T_Layer.h"
#include "T_Sprite.h"

typedef struct
{
	int z_order;	// ͼ�����(���ԽСͼ�������Խ��)
	int type_id;	// LAYER_TYPE����ֵ��ͼ�����ͱ�ʶ��
	T_Layer* layer;	// ��ͼͼ��ͼ��	
}GAMELAYER;

// ��Ϸ�е�ͼ����������
typedef vector<GAMELAYER> SCENE_LAYERS;

class T_Scene
{
protected:

	SCENE_LAYERS sceneLayers;		// ������Ϸ��ȫ��ͼ���vector����
	T_Map* pBarrier;				// ��ײͼ��ָ��
	T_Map* pMask;					// ���ֲ�ָ��

	int SceneWidth, SceneHeight;	// ���������Ŀ���
	int WinWidth, WinHeight;		// ���ڵĿ���
	int lastSceneX, lastSceneY;		// ������һ�ε�����λ��
	int SceneX, SceneY;				// ������ǰ������λ��
	bool LayerChanged;				// ͼ���Ƿ����仯

	//ͼ������ȽϺ������ú�������Ϊ��̬������
	static bool SortByZorder(const GAMELAYER &l1, const GAMELAYER &l2);
	
public:
	T_Scene();
	virtual ~T_Scene(void);
	
	//����������������������������������������������������������������
	// ��ȡ�������ݳ�Աֵ�ĺ���
	//����������������������������������������������������������������
	// ��ȡ������ǰX����
	int getSceneX(){ return SceneX; }
	// ��ȡ������ǰY����
	int getSceneY(){ return SceneY; }
	// ��ȡ������һ��X����
	int getlastSceneX(){ return lastSceneX; }
	// ��ȡ������һ��Y����
	int getlastSceneY(){ return lastSceneY; }
	// ��ȡ�����е�ͼ�ϰ�ͼ��
	T_Map* getBarrier(){ return pBarrier; }
	// ��ȡ�����е�ͼ����ͼ��
	T_Map* getMask(){ return pMask; }
	// ������ͼ������
	int GetTotalLayers(){ return (int)(sceneLayers.size()); }
	// ��ȡ����ͼ����������
	SCENE_LAYERS* getSceneLayers(){ return &sceneLayers; }	
	
	//����������������������������������������������������������������
	// �볡��������صĺ���
	//����������������������������������������������������������������
	// ������ʼ��
	void InitScene(int scn_x, int scn_y, 
		           int scn_width, int scn_height, 
		           int win_width, int win_height);
	// ���ó������Ͻ�����
	void SetScenePos(int x, int y);
	// ��������ǰ���갴�ղ���ָ���Ĳ����ƶ�
	void MoveScene(int speedX, int speedY);
	// ���ݲ���ָ���Ľ�ɫ�����жϳ����Ƿ���Ҫ����
	void ScrollScene(T_Sprite* player);
		
	//����������������������������������������������������������������
	// ��ͼ�������صĺ���
	//����������������������������������������������������������������
	// ���ͼ��
	void Append(GAMELAYER gm_layer);
	// ��ָ����ͼ��������ǰ����ͼ��
	void Insert(GAMELAYER gm_layer, int index);
	// ɾ��ָ��ͼ��
	void Remove(GAMELAYER gm_layer);
	// ɾ��ȫ��ͼ��
	void RemoveAll();
	// ����ͼ�������Ŷ�ͼ���������
	void SortLayers();
	// �õ���ͼ�Ϸ��ϰ������λ��
	POINT getRandomFreeCell();

	//����������������������������������������������������������������
	// ���ͼ�ļ������йصĺ���
	//����������������������������������������������������������������
	// ������һ������ָ�����ַ������Ƿ���ڵڶ�������ָ���Ĺؼ���
	// ������ڣ������ؼ��ֺ��ֵ��ת�������ͣ�ͨ���������������
	void GetTxtMapValue(wstring str, wstring keywords, int& value);
	// ������һ������ָ�����ַ������Ƿ���ڵڶ�������ָ���Ĺؼ���
	// ������ڣ������ؼ��ֺ��ֵ��ת�����ַ�����ͨ���������������
	void GetTxtMapValue(wstring str, wstring keywords, wstring& value);
	// ������һ������ָ����CSV��ʽ�ĵ�ͼ�����ַ���
	// ��������ĵ�ͼ���ݱ��浽�ڶ���������dataԪ����
	void parseCsvData(wstring csv_data, LAYERINFO& m_LayerInfo);
	// ���ز���ָ���ĵ�ͼ�ļ����������еĵ�ͼ���ݣ������浽����ͼ����
	bool LoadTxtMap(const char* txtmap_path);
	
	//����������������������������������������������������������������
	// ���������������Ƶĺ���
	//����������������������������������������������������������������
	void Draw(HDC hdc, int x, int y);

};

