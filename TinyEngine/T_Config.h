//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ����: 2019-11-28
// ��Ȩ���� 2007-2019 ������
// (C) 2007-2019 WanLizhong All Rights Reserved
//*******************************************************************

#ifndef TCONFIG_H
#define TCONFIG_H

#include <windows.h>
#include <typeinfo.h>
#include <time.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#include <gdiplus.h>
#pragma comment(lib,"Msimg32.lib")
#pragma comment(lib,"gdiplus.lib")
using namespace Gdiplus;


static const int WIN_WIDTH		 = 1024;			// Ĭ����Ϸ���ڿ�
static const int WIN_HEIGHT		 = 768;				// Ĭ����Ϸ���ڸ�
static const COLORREF WIN_BKCLR = RGB(50, 50, 50);	// Ĭ�ϴ��ڱ���ɫ(����: 2019-09-28)

static const int FRAME_SPEED	 = 100;				// Ĭ����Ϸ֡Ƶ

static const int MENU_WIDTH		 = 200;				// Ĭ�ϲ˵���
static const int MENU_HEIGHT	 = 60;				// Ĭ�ϲ˵���
static const int MENU_SPACE		 = 10;				// Ĭ�ϲ˵��������
static const int MENU_ALPHA		 = 180;				// Ĭ�ϲ˵�������͸����
static const COLORREF MENU_BKCLR = RGB(0, 0, 0);	// Ĭ�ϲ˵�����ɫ

static const int LAYER_MAX		= 1000;				// Ĭ����Ϸͼ�����ֵ

static const LPCTSTR WIN_CLASS	
	= TEXT("TinyEngine");;							// Ĭ��ע��Ĵ�������
static const LPCTSTR WIN_TITLE						// Ĭ�ϴ��ڱ���
	= TEXT("TinyEngine Ver 1.0 ����:������(C) 2007-2013");

// ��Ϸ����������ֵΪ�������Ӧ�ļ�ֵ
enum GAME_DIR
{
	DIR_LEFT,					// ��
	DIR_RIGHT,					// ��
	DIR_UP,						// ��
	DIR_DOWN,					// ��
	DIR_LEFT_UP,				// ����
	DIR_LEFT_DOWN,				// ����
	DIR_RIGHT_UP,				// ����
	DIR_RIGHT_DOWN				// ����
};

// ͼ����ƴ�����
enum TRANSFER
{
	TRANS_NONE,					// ԭʼͼ��
	TRANS_NOFLIP_ROT90,			// ԭʼͼ��˳ʱ����ת90��
	TRANS_NOFLIP_ROT180,		// ԭʼͼ��˳ʱ����ת180��
	TRANS_NOFLIP_ROT270,		// ԭʼͼ��˳ʱ����ת270��
	TRANS_VFLIP_NOROT,			// ԭʼͼ��ֱ��ת
	TRANS_VFLIP_ROT90,			// ԭʼͼ��ֱ��ת��˳ʱ����ת90��
	TRANS_VFLIP_ROT180,			// ԭʼͼ��ֱ��ת��˳ʱ����ת180��
	TRANS_VFLIP_ROT270,			// ԭʼͼ��ֱ��ת��˳ʱ����ת27��
	TRANS_HFLIP_NOROT,			// ԭʼͼ��ˮƽ��ת
	TRANS_HFLIP_ROT90,			// ԭʼͼ��ˮƽ��ת��˳ʱ����ת90��
	TRANS_HFLIP_ROT180,			// ԭʼͼ��ˮƽ��ת��˳ʱ����ת180��
	TRANS_HFLIP_ROT270			// ԭʼͼ��ˮƽ��ת��˳ʱ����ת270��
};

// ��Ϸ״̬ö�ٳ�������
enum GAME_STATE
{
	GAME_START,					// ��ʼ
	GAME_RUN,					// ����
	GAME_PAUSE,					// ��ͣ
	GAME_UPGRADE,				// ����
	GAME_WIN,					// ͨ��
	GAME_OVER,					// ����
	GAME_HELP,					// ����״̬
	GAME_ABOUT,					// ����״̬
	GAME_SETTING,				// ����״̬
	GAME_CHOOSEPLAYER,			// ѡ���ɫ״̬
	GAME_LEVELCHANGE			// �ؿ��л�
};
 
// ������Ϊ����
enum KM_ACTION
{
	KEY_SYS_NONE,				// ��ϵͳ��������
	KEY_UP,						// �ͷŰ���
	KEY_DOWN,					// ���¼�
	MOUSE_MOVE,					// ����ƶ�
	MOUSE_LCLICK,				// ���������
	MOUSE_RCLICK				// ����Ҽ����
};

// ͼ������
enum LAYER_TYPE
{
	LAYER_PLY,					// ���
	LAYER_NPC,					// NPC
	LAYER_PLY_BOMB,				// ����ڵ�
	LAYER_NPC_BOMB,				// NPC�ڵ�
	LAYER_MAP_BACK,				// ��ͼ������
	LAYER_MAP_BARR,				// ��ͼ�ϰ���
	LAYER_MAP_MASK,				// ��ͼ���ֲ�
	LAYER_EXPLOSION,			// ��ըЧ��ͼ��
	LAYER_TARGET,				// �����ͱ�����Ŀ��
	LAYER_BONUS,				// ��Ϸ�еĽ���
	LAYER_NONE					// ��Ϸ�з���Ϸ����
};

// ��Ϸ��ɫ�ؼ���Ϣ(ÿ��������ɫ��������ȫ��ֵ)
typedef struct
{
	int		X;					// ��ɫ��ʼX����
	int		Y;					// ��ɫ��ʼY����
	int		Dir;				// ��ɫ��ʼ����(ȡֵΪGAME_DIR����)
	int		Speed;				// ��ɫ��ʼ���ƶ��ٶ�
	int		Level;				// ��ɫ��ʼ�ĵȼ�
	int		Score;				// ��ɫ��ɫ��ֵ 
	bool	Visible;			// ��ɫ����Ļ���Ƿ�ɼ�
	bool	Active;				// ��ɫ��״̬���Ƿ��ƶ���
	bool	Dead;				// ��ɫ�Ƿ�������״̬
	BYTE	Alpha;				// ��ɫ͸����
	float	Ratio;				// ����֡ͼƬ�Ŵ����С��
								// ����1ԭʼ������1�Ŵ�С��1��С
	int		Rotation;			// ֡ͼƬ�Ƿ���任(ȡֵΪTRANSFER����)
}SPRITEINFO;

//��ͼÿ��ͼ����Ϣ
typedef struct
{
	int		type_id;			// ͼ���ʶ��(ȡֵΪLAYER_TYPE����)
	int		map_cols;			// ��ͼ���(ͼ������)
	int		map_rows;			// ��ͼ�߶�(ͼ������)
	int		tile_width;			// ͼ����
	int		tile_height;		// ͼ��߶�
	wstring	tile_path;			// ͼ��ԭʼͼƬ·��
	int		first_gid;			// ��ͼ���ݴ�0����1��ʼ
								// Tiled��ͼ�༭���Ĭ��Ϊ1
	vector<vector<int>> data;	// ͼ������	
}LAYERINFO;

// �˵�����Ϣ
typedef struct  
{
	POINT pos;
	wstring ItemName;
}MENUITEM;

// �˵���Ϣ
typedef struct  
{
	int		width;				// �˵����
	int		height;				// �˵��߶�
	int		space;				// �˵���֮��������
	int		align;				// ���ֶ��뷽ʽ(0:�����; 1:����; 2:�Ҷ���)
	LPCTSTR fontName;			// ��������
	bool	isBold;				// �Ƿ����
	Color	normalTextColor;	// �����˵�������ɫ
	Color	focusTextColor;		// ����˵�������ɫ
}MENU_INFO;

#endif