#pragma once
#include "TinyEngine\T_Sprite.h"
#include "GameInit.h"

class Boss :
	public T_Sprite
{
private:
	//指明是哪一位Npc
	WhichBoss who;
	//生命值
	int blood;
	//上一次的状态
	BossState lastState;
	//当前的状态
	BossState state;
	//所有可能的动作帧的集合
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
