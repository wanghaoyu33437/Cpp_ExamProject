//*******************************************************************
// TinyEngine引擎  
// 作者: 万立中(WanLizhong)
// 博客: www.wanlizhong.com 
// 日期: 2013-08-02
// 更新: 2019-11-28
// 版权所有 2007-2019 万立中
// (C) 2007-2019 WanLizhong All Rights Reserved
//*******************************************************************
#include "T_Display.h"

//构造函数 
T_Display::T_Display():mode_changed(false)
{
	SaveMode();
}

//析构函数
T_Display::~T_Display()
{
	ResetMode();
}

// 存储现在的显示模式
void T_Display::SaveMode()
{
	ZeroMemory(&devmode_saved, sizeof(devmode_saved));
	devmode_saved.dmSize = sizeof(devmode_saved);
	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devmode_saved);
}

// 还原成之前存储的显示模式
void T_Display::ResetMode()
{
	if (mode_changed) 
	{
		ChangeDisplaySettings(&devmode_saved, 0);
		mode_changed = false;
	}
}

// 更改显示模式
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