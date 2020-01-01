//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ��Ȩ���� 2007-2013 ������
// (C) 2007-2013 WanLizhong All Rights Reserved
//*******************************************************************

#pragma once
#include "T_Config.h"

class T_Util
{
public:

	static HWND GetHWnd()
	{
		return FindWindow(WIN_CLASS, NULL);
	}

	static HINSTANCE GetHInst()
	{
		return GetModuleHandle(NULL);
	}

	static wchar_t * int_to_wstring(int i);

	// ��������rangeָ����Χ�ĵȶ������
	// ����iArrayΪ�����������������
	// ����iArray�������ȶ���ΪԪ�ظ�������range������
	static void GetRandomNum(int range, int* iArray);


	// ����startPT��destPT֮��
	// б���ƶ�ʱX����Y��ķ���ֵ
	// xRatio��yRatioΪ�������
	static void GetBevelSpeed(
		IN POINT startPT, IN POINT destPT, 
		OUT int& xRatio, OUT int& yRatio
	);

	// �������������������ָ������㡢�յ�������ƶ��ٶ�
	// ���Ҫ��������ֱ���ƶ��ҳ����ٶ�Ϊָ���ƶ��ٶ�
	// ������������̱߶�Ӧ�ķ����ٶ�
	// xRatio��yRatioΪ�������, �����ռ�����
	// ���������Զ��жϷ���
	//	xRatio��yRatioΪ��ֵ����ʾ���ҡ����ƶ�
	//	xRatio��yRatioΪ��ֵ����ʾ�������ƶ�
	static void GetBevelSpeed(
		IN POINT startPT, IN POINT destPT, IN int Speed, 
		OUT int& xRatio, OUT int& yRatio
	);
};