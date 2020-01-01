#include "Boss.h"
#include<iostream>


Boss::Boss(WhichBoss w, BossState newState)
{
	who = w;
	state = newState;
	lastState = bATTACK1;
	blood = 100;

	LPCTSTR imgPath; int frameWidth; int frameHeight;
	imgPath = NULL;
	if (who == Boss1) {
		imgPath = boss1Paths[state];
		frameWidth = boss1Params[state][0];
		frameHeight = boss1Params[state][1];
	}
	else if (who == Boss2) {
		imgPath = boss2Paths[state];
		frameWidth = boss2Params[state][0];
		frameHeight = boss2Params[state][1];
	}
	else if (who == Boss3) {
		imgPath = boss3Paths[state];
		frameWidth = boss3Params[state][0];
		frameHeight = boss3Params[state][1];
	}
	else if (who == Boss4) {
		imgPath = boss4Paths[state];
		frameWidth = boss4Params[state][0];
		frameHeight = boss4Params[state][1];
	}

	if (wcslen(imgPath)>0)
	{
		spImg.LoadImageFile(imgPath);
		spOldImg = spImg;
	}
	else
	{
		throw L"图像路径为空!";
	}

	// 无动画的角色图片
	if (frameWidth == 0 && frameHeight == 0)
	{
		SetWidth(spImg.GetImageWidth());
		SetHeight(spImg.GetImageHeight());

		totalFrames = rawFrames = 0; // 动画总帧数
	}
	else// 具有动画的角色图片
	{
		SetWidth(frameWidth);
		SetHeight(frameHeight);

		frameCols = spImg.GetImageWidth() / frameWidth;		// 动画帧图片总列数
		frameRows = spImg.GetImageHeight() / frameHeight;	// 动画帧图片总行数
		totalFrames = frameCols*frameRows;					// 动画总帧数
		rawFrames = frameCols*frameRows;					// 记录原始动画总帧数
		forward = 0;									// 当前帧计数初始化
		backward = totalFrames - 1;
	}

	frameSequence = NULL;
	loopForward = true;

	mapBlockPT.x = -1;
	mapBlockPT.y = -1;
}

void Boss::setState(BossState newState)
{
	if (state != newState)
	{
		lastState = state;
		state = newState;

		LPCTSTR imgPath; int frameWidth; int frameHeight;
		imgPath = NULL;
		if (who == Boss1) {
			imgPath = boss1Paths[state];
			frameWidth = boss1Params[state][0];
			frameHeight = boss1Params[state][1];
		}
		else if (who == Boss2) {
			imgPath = boss2Paths[state];
			frameWidth = boss2Params[state][0];
			frameHeight = boss2Params[state][1];
		}
		else if (who == Boss3) {
			imgPath = boss3Paths[state];
			frameWidth = boss3Params[state][0];
			frameHeight = boss3Params[state][1];
		}
		else if (who == Boss4) {
			imgPath = boss4Paths[state];
			frameWidth = boss4Params[state][0];
			frameHeight = boss4Params[state][1];
		}
		if (wcslen(imgPath)>0)
		{
			spImg.LoadImageFile(imgPath);
			spOldImg = spImg;
		}
		else
		{
			throw L"图像路径为空!";
		}
		// 无动画的角色图片
		if (frameWidth == 0 && frameHeight == 0)
		{
			SetWidth(spImg.GetImageWidth());
			SetHeight(spImg.GetImageHeight());
			totalFrames = rawFrames = 0; // 动画总帧数
		}
		else// 具有动画的角色图片
		{
			SetWidth(frameWidth);
			SetHeight(frameHeight);
			frameCols = spImg.GetImageWidth() / frameWidth;		// 动画帧图片总列数
			frameRows = spImg.GetImageHeight() / frameHeight;	// 动画帧图片总行数
			totalFrames = frameCols*frameRows;					// 动画总帧数
			rawFrames = frameCols*frameRows;					// 记录原始动画总帧数
			forward = 0;									// 当前帧计数初始化
			backward = totalFrames - 1;
		}
	}

	//对于过快的动作，重置帧数
	if ((newState == bATTACK1 || newState == bATTACK2) && who == Boss1)
		this->SetSequence(ATTACK_FRAMES2, 6);
	else if (newState == bATTACK2 && who == Boss2)
		this->SetSequence(ATTACK_FRAMES2, 6);
	else if ((newState == bATTACK1 || newState == bATTACK2) && who == Boss3)
		this->SetSequence(ATTACK_FRAMES2, 6);
	else if (newState == bATTACK1 && who == Boss4)
		this->SetSequence(ATTACK_FRAMES3, 6);
	else if (newState == bRESTAND && who == Boss3)
		this->SetSequence(BossChange, 30);    //修改boss变身帧数
	else
		this->frameSequence = NULL;

}

Boss::~Boss()
{
}


boolean Boss::bossAttack(T_Sprite* player_sp)
{
	if (this->getState() == bATTACK2 || this->getState() == bATTACK1 
		|| (this->getWho()==Boss2 &&this->getState()==bATTACK3) || (this->getWho() == Boss4 && this->getState() == bATTACK3))
	{
		int npc_x = this->GetX();
		int npc_y = this->GetY();
		int npc_width = this->GetRatioSize().cx;
		int npc_height = this->GetRatioSize().cy;

		int ply_x = player_sp->GetX();
		int ply_y = player_sp->GetY();
		int ply_width = player_sp->GetRatioSize().cx;
		int ply_height = player_sp->GetRatioSize().cy;

		if (abs(ply_y - npc_y) <= (ply_height / 4))
		{
			//计算参与碰撞检测的角色矩形区域
			RECT hitRec;
			hitRec.left = ply_x;
			hitRec.top = ply_y;
			hitRec.right = ply_x + ply_width;
			hitRec.bottom = ply_y + ply_height;

			RECT thisRect;
			//面朝右边的攻击区域
			if (this->GetRotation() == TRANS_NONE)
			{
				thisRect.left = npc_x + npc_width / 2;
				thisRect.top = npc_y;
				thisRect.right = npc_x + npc_width;
				thisRect.bottom = npc_y + npc_height;
			}
			//面朝左面的攻击区域
			else
			{
				thisRect.left = npc_x;
				thisRect.top = npc_y;
				thisRect.right = npc_x + npc_width / 2;
				thisRect.bottom = npc_y + npc_height;
			}
			//方式一：同时满足4个条件
			return thisRect.left <= hitRec.right &&
				hitRec.left <= thisRect.right &&
				thisRect.top <= hitRec.bottom &&
				hitRec.top <= thisRect.bottom;
		}
	}
	return false;
}





