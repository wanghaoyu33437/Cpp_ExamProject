#include "Npc.h"
#include<iostream>


Npc::Npc(WhichNpc w, NpcState newState)
{
	who = w;
	state = newState;
	lastState = nATTACK1;
	blood = 20;

	LPCTSTR imgPath; int frameWidth; int frameHeight;
	imgPath = NULL;
	if (who == Npc1) {
		imgPath = npc1Paths[state];
		frameWidth = npc1Params[state][0];
		frameHeight = npc1Params[state][1];
	}
	else if(who == Npc2) {
		imgPath = npc2Paths[state];
		frameWidth = npc2Params[state][0];
		frameHeight = npc2Params[state][1];
	}
	else if (who == Npc3) {
		imgPath = npc3Paths[state];
		frameWidth = npc3Params[state][0];
		frameHeight = npc3Params[state][1];
	}
	else if (who == Npc4) {
		imgPath = npc4Paths[state];
		frameWidth = npc4Params[state][0];
		frameHeight = npc4Params[state][1];
	}
	else if (who == Npc5) {
		imgPath = npc5Paths[state];
		frameWidth = npc5Params[state][0];
		frameHeight = npc5Params[state][1];
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

void Npc::setState(NpcState newState)
{
	if (state != newState)
	{
		lastState = state;
		state = newState;

		LPCTSTR imgPath; int frameWidth; int frameHeight;
		imgPath = NULL;
		if (who == Npc1) {
			imgPath = npc1Paths[state];
			frameWidth = npc1Params[state][0];
			frameHeight = npc1Params[state][1];
		}
		else if (who == Npc2) {
			imgPath = npc2Paths[state];
			frameWidth = npc2Params[state][0];
			frameHeight = npc2Params[state][1];
		}
		else if (who == Npc3) {
			imgPath = npc3Paths[state];
			frameWidth = npc3Params[state][0];
			frameHeight = npc3Params[state][1];
		}
		else if (who == Npc4) {
			imgPath = npc4Paths[state];
			frameWidth = npc4Params[state][0];
			frameHeight = npc4Params[state][1];
		}
		else if (who == Npc5) {
			imgPath = npc5Paths[state];
			frameWidth = npc5Params[state][0];
			frameHeight = npc5Params[state][1];
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

	if ((newState == nATTACK1 || newState == nATTACK2) && who==Npc1)
		//T_Sprite
		this->SetSequence(ATTACK_FRAMES3, 6);
	else if(newState == nATTACK1 && who==Npc2)
		this->SetSequence(ATTACK_FRAMES3, 6);
	else if(newState == nATTACK2 && who == Npc2)
		this->SetSequence(ATTACK_FRAMES2, 6);
	else if(newState == nATTACK1 && who == Npc4)
		this->SetSequence(ATTACK_FRAMES2, 6);
	else
		this->frameSequence = NULL;
	
}

Npc::~Npc()
{
}


boolean Npc::npcAttack(T_Sprite* player_sp)
{
	if (this->getState() == nATTACK1 || this->getState() == nATTACK2)
	{
		int npc_x = this->GetX();
		int npc_y = this->GetY();
		int npc_width = this->GetRatioSize().cx;
		int npc_height = this->GetRatioSize().cy;

		int ply_x = player_sp->GetX();
		int ply_y = player_sp->GetY();
		int ply_width = player_sp->GetRatioSize().cx;
		int ply_height = player_sp->GetRatioSize().cy;

		if (abs((ply_y + ply_height) - npc_y - npc_height) <= 20)
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
				hitRec.left <= thisRect.right;
				//thisRect.top <= hitRec.bottom &&
				//hitRec.top <= thisRect.bottom;
		}
		else
			return false;
	}
	return false;
}





