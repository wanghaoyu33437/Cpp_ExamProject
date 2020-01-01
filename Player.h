#pragma once
#include ".\\TinyEngine\\T_Sprite.h"
#include "GameInit.h"
#include "Npc.h"
#include "Boss.h"

class Player :
	public T_Sprite
{
private:
	WhichPlayer who;
	int blood;
	PlayerState state;
	PlayerState lastState;
	DWORD InvincibleTime;
	bool invincible = false;

	int hint_frame[3] = {0,0,0};
	int zy_death_frame[9] = { 0,1,2,3,4,5,5,5,5 };
	int zy_Box1_frame[3] = { 0,6,7 };
	int zy_Box2_frame[6] = { 0,1,1,0,2,2};


	int SpeedX;
	int SpeedY;
	int SpeedZ;

	vFrameSet frames;
	void LoadFrames(WhichPlayer);//加载所有可能的动作帧
public:
	Player(WhichPlayer, PlayerState);
	~Player();

	PlayerState getState() { return state; }
	void setState(PlayerState newState);

	void addScore(int val) { score += val + rand() % 1000; }

	//检测攻击
	boolean playerAttack(Npc* npc_sp);
	boolean playerAttack(Boss* boss_sp);

	void setInvincible(bool i) { invincible = i; InvincibleTime = GetTickCount(); }
	bool IsInvincible() { return invincible; }

	DWORD getInvincibleTime() { return InvincibleTime; }

	PlayerState getLastState() {
		return lastState;
	}
	void setLastState(PlayerState newState) {
		state = newState;
	}
	
	WhichPlayer getWho() { return who; }
	void setWho(WhichPlayer newWho) { who = newWho; }

	void setBlood(int b) { blood = b; }
	int getBlood() { return blood; }
	void subBlood(int sub_num) { blood -= sub_num; }
	void addBlood(int add_num) { blood += add_num; }

	void SetXSpeed(const int speedX) { SpeedX = speedX; }
	void SetYSpeed(const int speedY) { SpeedY = speedY; }
	void SetZSpeed(const int speedZ) { SpeedZ = speedZ; }
	int GetXSpeed() const { return SpeedX; }
	int GetYSpeed() const { return SpeedY; }
	int GetZSpeed() const { return SpeedZ; }
};

