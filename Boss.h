#pragma once
#include "TinyEngine\T_Sprite.h"
#include "GameInit.h"

class Boss :
	public T_Sprite
{
private:
	//ָ������һλNpc
	WhichBoss who;
	//����ֵ
	int blood;
	//��һ�ε�״̬
	BossState lastState;
	//��ǰ��״̬
	BossState state;
	//���п��ܵĶ���֡�ļ���
	DWORD deathTime;

public:
	Boss(WhichBoss, BossState);
	~Boss();

	int ATTACK_FRAMES2[6] = { 0,0,0,1,1,1 };
	int ATTACK_FRAMES3[6] = { 0,0,1,1,2,2 };
	int BossChange[30] = { 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9 };

	BossState getState() { return state; }
	void setState(BossState newState);
	void setWho(WhichBoss newWho) {
		who = newWho;
	}
	WhichBoss getWho() {
		return who;
	}
	boolean bossAttack(T_Sprite* player_sp);
	void setBlood(int new_blood) { blood = new_blood; }
	int getBlood() { return blood; }
	void subBlood(int sub_num) { blood -= sub_num; }
	void setDeathTime(DWORD dtime) { deathTime = dtime; }
	DWORD getDeathTime() { return deathTime; }
};
