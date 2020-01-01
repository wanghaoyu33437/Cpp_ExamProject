//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ����: 2018-12-13
// ��Ȩ���� 2007-2018 ������
// (C) 2007-2018 WanLizhong All Rights Reserved
//*******************************************************************

#pragma once
#include "T_Config.h"
#include "T_Graph.h"
#include "T_Audio.h"



//
// ���˵���֧�֣�
// ��ֱ���У������ְ�ť��ͼƬ��ť
// ˮƽ���У������ְ�ť��ͼƬ��ť
//
class T_Menu
{
protected:
	MENU_INFO menu_info;								// �˵���Ϣ
	
	int m_index;										// ��ǰ����˵�������
	bool isItemFocused;									// ��ǰ�˵��Ƿ�񽹵�
	
	int lastIndex;
	int key_index;
	int MaxMenuItemLen;									// ��˵����ֳ���

	int bkImageAlpha;									// ����ͼƬ͸����
	int bkColor;										// ������ɫ

	T_Graph gm_menuBkg;									// �˵�����
	T_Graph BtnDIB;										// �˵�ͼƬ					
	vector<MENUITEM> gm_menuItems;						// �˵���Ŀ

	int GetMenuIndex(int x, int y);						// ���ݵ�ǰ����������˵���������
	StringAlignment GetAlignment();						
	FontStyle GetFontStyle();

	AudioDXBuffer* m_MoveSound;							// �˵�����ƹ�ʱ������
	AudioDXBuffer* m_ClickSound;						// �˵������ʱ������

public:
	T_Menu();
	virtual ~T_Menu(void);

	// ���ò˵�����ͼƬ��͸���ȼ�������ɫ
	void SetMenuBkg(wstring img_path, int alphaLevel=255, COLORREF backColor=RGB(0,0,0));	
	void SetBtnBmp(wstring img_path,						// ���ò˵���ťͼƬ
		           int btnWidth,							// ͼƬ��ť��
		           int btnHeight);							// ͼƬ��ť��

	void SetMenuInfo(MENU_INFO menuInfo);			
	void AddMenuItem(MENUITEM menuItem);					// ��Ӳ˵�������Ŀ

	//�˵�����: btnTrans��ť͸����, 255��͸��; startState�Ƿ���ƿ�ʼ�˵�
	void DrawMenu(HDC hdc, BYTE btnTrans=255, bool startState=true);

	int MenuMouseClick(int x, int y);					// �˵�������¼�����
	void MenuMouseMove(int x, int y);					// �˵�����ƶ��¼�����
	int MenuKeyDown(WPARAM key);						// �˵������¼�����

	int GetMenuIndex(){ return m_index; }				// ���ص�ǰ��m_index
	void SetMenuIndex(int i){ m_index = i; }			// ���õ�ǰ��m_index

	void DestroyAll();

	void SetMoveSound(AudioDXBuffer* ms_buffer);
	void SetClickSound(AudioDXBuffer* mc_buffer);
};
