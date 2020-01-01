//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ����: 2019-11-28
// ��Ȩ���� 2007-2019 ������
// (C) 2007-2019 WanLizhong All Rights Reserved
//*******************************************************************
#include "T_Display.h"

//���캯�� 
T_Display::T_Display():mode_changed(false)
{
	SaveMode();
}

//��������
T_Display::~T_Display()
{
	ResetMode();
}

// �洢���ڵ���ʾģʽ
void T_Display::SaveMode()
{
	ZeroMemory(&devmode_saved, sizeof(devmode_saved));
	devmode_saved.dmSize = sizeof(devmode_saved);
	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devmode_saved);
}

// ��ԭ��֮ǰ�洢����ʾģʽ
void T_Display::ResetMode()
{
	if (mode_changed) 
	{
		ChangeDisplaySettings(&devmode_saved, 0);
		mode_changed = false;
	}
}

// ������ʾģʽ
bool T_Display::ChangeMode(int width, int height)
{
	DEVMODE	devmode;
	ZeroMemory(&devmode, sizeof(devmode));
	devmode.dmSize = sizeof(devmode);
	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devmode);
	devmode.dmPelsWidth = width;
	devmode.dmPelsHeight = height;
	devmode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
	if (ChangeDisplaySettings(&devmode, CDS_FULLSCREEN) == DISP_CHANGE_SUCCESSFUL)
	{
		mode_changed = true;
		return true;
	}
	return false;
}