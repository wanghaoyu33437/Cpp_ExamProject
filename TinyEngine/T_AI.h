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
#include "T_Sprite.h"
#include "T_Map.h"
#include "..\\EngineConfig.h"
#include"..\\Npc.h"
#include"..\\Player.h"
#include"..\\Boss.h"
#include<iostream>

// ��¼�ƶ���Ϣ�Ľṹ��
struct MoveCoord
{
	int oldX;			// �ƶ�ǰ��X����
	int oldY;			// �ƶ�ǰ��Y����
	int moveX;			// �ƶ����X����
	int moveY;			// �ƶ����Y����
	int BoundDir;		// �ڱ߽��ϵķ���
};

class T_AI
{
private:
	int dir_style;		// ����ģʽ����ֵ������4��8

	// ��ܷ���
	// ���ά��GAME_DIR��Ԫ�ر��һ��
	// �ڶ�ά��ʾ��Ӧ�Ķ�ܷ���
	static int EvadeDir[8][5];

	// �������spָ���Ľ�ɫǰ�������Ӧ����ײ�������
	// ����sp�������Ľ�ɫ����
	// ����spSizeTimes����ɫ��ߵı����������������ķ�Χ
	// ����testRec������Ͳ������õ����յļ������
	void GetHitRect(IN T_Sprite* sp, IN int spSizeTimes, OUT RECT& testRec);

	// �����ƶ������ٶȺ�ָ���Ļ��Χ���㵱ǰ��ɫ���ƶ�λ��
	MoveCoord GetMoveCoord(T_Sprite* npc_sp, int dir, int speed, RECT boundary);

public:
	T_AI(int d_style);	// d_style��ֵ������4��8
	virtual ~T_AI(void);

	// �����ƶ������ٶȺ�ָ���Ļ��Χ�Խ�ɫ�����δ���
	void Wander(T_Sprite* npc_sp, int npc_dir, int speed, RECT boundary);
	// �����ƶ������ٶȺ�ָ���ĵ�ͼ����Խ�ɫ�����δ���
	void Wander(T_Sprite* npc_sp, int npc_dir, int speed, T_Map* map);
	// ��ɫ��ܴ�����һ������Ϊ��ܵĶ��󣬵ڶ�������ΪҪ�رܵļ�����
	void Evade(T_Sprite* npc_sp, T_Sprite* player);
	// ��ɫ���ص�������һ������Ϊ�����󣬵ڶ�������Ϊ���������ڵĽ�ɫ����
	void CheckOverlay(T_Sprite* npc_sp, vector<T_Sprite*> vSpriteSet);

	//NPC׷���㷨
	void Chase(Npc* npc_sp, Player* player_sp);

	//NPC�����㷨
	void Roam(Npc* npc_sp, Player* player_sp, int Lbarrier, int Rbarrier);

	//Boss���Ҷ������㷨
	void BossRoam(Boss* npc_sp, Player* player_sp, int Lbarrier, int Rbarrier);

	//Boss׷�ٶ���㷨
	void Charge(Boss* boss_sp, Player* player_sp);
};
