#pragma once
#include "TinyEngine\T_Sprite.h"
#include "GameInit.h"

class Npc :
	public T_Sprite
{
private:
	//ָ������һλNpc
	WhichNpc who;
	//����ֵ
	int blood;
	//��һ�ε�״̬z
	NpcState lastState;
	//��ǰ��״̬
	NpcState state;
	//���п��ܵĶ���֡�ļ���
	DWORD deathTime;

public:
	Npc(WhichNpc, NpcState);
	~Npc();

	int ATTACK_FRAMES2[6] = { 0,0,0,1,1,1 };
	int ATTACK_FRAMES3[6] = { 0,0,1,1,2,2 };

	NpcState getState() { return state; }
	void setState(NpcState newState);
	void setWho(WhichNpc newWho) {
		who = newWho;
	}
	WhichNpc getWho() {
		return who;
	}
	boolean npcAttack(T_Sprite* player_sp);
	void setBlood(int new_blood) { blood = new_blood; }
	int getBlood() { return blood; }
	void subBlood(int sub_num) { blood -= sub_num; }
	void setDeathTime(DWORD dtime) { deathTime = dtime; }
	DWORD getDeathTime() { return deathTime; }
};
