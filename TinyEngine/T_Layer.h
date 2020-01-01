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
#include "T_Config.h"

class T_Layer
{
public:
	T_Layer() {};
	virtual ~T_Layer(void) {};

protected:
	int Width, Height;	// ͼ��Ŀ���
	int X, Y;			// ͼ���X��Y����
	bool Visible;		// ͼ���Ƿ�ɼ�
	int LayerTypeID;	// ͼ��ı�ʶ��ȡֵΪLAYER_TYPE������
	int zorder;			// ͼ��Ļ���˳��

public:
	// ���úͻ�ȡͼ��Ŀ���
	void SetWidth(int width) { Width = width; }
	int GetWidth() { return Width; }
	void SetHeight(int height) { Height = height; }
	int GetHeight() { return Height; }

	// ���úͻ�ȡͼ���X��Y����
	void SetPosition(int x, int y) { X = x; Y = y; }
	int GetX() { return X; }
	int GetY() { return Y; }

	// ���úͻ�ȡͼ��ɼ���
	void SetVisible(bool visible) { Visible = visible; }
	bool IsVisible() { return Visible; }

	// ���úͻ�ȡͼ��ı�ʶ��ȡֵΪLAYER_TYPE������
	void SetLayerTypeID(int i) { LayerTypeID = i; }
	int GetLayerTypeID() { return LayerTypeID; }

	// ���úͻ�ȡͼ��Ļ���˳��
	int getZorder() { return zorder; }
	void setZorder(int z) { zorder = z; }

	// ͼ���ƶ�
	//dx_speed: ��ֵ�����ƶ��� ��ֵ�����ƶ�
	//dy_speed: ��ֵ�����ƶ��� ��ֵ�����ƶ�
	void Move(int dx_speed, int dy_speed) { X += dx_speed; Y += dy_speed; }

	// ��ȡ���༰�����������
	virtual string ClassName() { return "T_Layer"; }

	// ���麯���������������ʵ��
	virtual void Draw(HDC hdc) = 0;
};