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
		throw L"ͼ��·��Ϊ��!";
	}

	// �޶����Ľ�ɫͼƬ
	if (frameWidth == 0 && frameHeight == 0)
	{
		SetWidth(spImg.GetImageWidth());
		SetHeight(spImg.GetImageHeight());

		totalFrames = rawFrames = 0; // ������֡��
	}
	else// ���ж����Ľ�ɫͼƬ
	{
		SetWidth(frameWidth);
		SetHeight(frameHeight);

		frameCols = spImg.GetImageWidth() / frameWidth;		// ����֡ͼƬ������
		frameRows = spImg.GetImageHeight() / frameHeight;	// ����֡ͼƬ������
		totalFrames = frameCols*frameRows;					// ������֡��
		rawFrames = frameCols*frameRows;					// ��¼ԭʼ������֡��
		forward = 0;									// ��ǰ֡������ʼ��
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
			throw L"ͼ��·��Ϊ��!";
		}
		// �޶����Ľ�ɫͼƬ
		if (frameWidth == 0 && frameHeight == 0)
		{
			SetWidth(spImg.GetImageWidth());
			SetHeight(spImg.GetImageHeight());
			totalFrames = rawFrames = 0; // ������֡��
		}
		else// ���ж����Ľ�ɫͼƬ
		{
			SetWidth(frameWidth);
			SetHeight(frameHeight);
			frameCols = spImg.GetImageWidth() / frameWidth;		// ����֡ͼƬ������
			frameRows = spImg.GetImageHeight() / frameHeight;	// ����֡ͼƬ������
			totalFrames = frameCols*frameRows;					// ������֡��
			rawFrames = frameCols*frameRows;					// ��¼ԭʼ������֡��
			forward = 0;									// ��ǰ֡������ʼ��
			backward = totalFrames - 1;
		}
	}

	//���ڹ���Ķ���������֡��
	if ((newState == bATTACK1 || newState == bATTACK2) && who == Boss1)
		this->SetSequence(ATTACK_FRAMES2, 6);
	else if (newState == bATTACK2 && who == Boss2)
		this->SetSequence(ATTACK_FRAMES2, 6);
	else if ((newState == bATTACK1 || newState == bATTACK2) && who == Boss3)
		this->SetSequence(ATTACK_FRAMES2, 6);
	else if (newState == bATTACK1 && who == Boss4)
		this->SetSequence(ATTACK_FRAMES3, 6);
	else if (newState == bRESTAND && who == Boss3)
		this->SetSequence(BossChange, 30);    //�޸�boss����֡��
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
			//���������ײ���Ľ�ɫ��������
			RECT hitRec;
			hitRec.left = ply_x;
			hitRec.top = ply_y;
			hitRec.right = ply_x + ply_width;
			hitRec.bottom = ply_y + ply_height;

			RECT thisRect;
			//�泯�ұߵĹ�������
			if (this->GetRotation() == TRANS_NONE)
			{
				thisRect.left = npc_x + npc_width / 2;
				thisRect.top = npc_y;
				thisRect.right = npc_x + npc_width;
				thisRect.bottom = npc_y + npc_height;
			}
			//�泯����Ĺ�������
			else
			{
				thisRect.left = npc_x;
				thisRect.top = npc_y;
				thisRect.right = npc_x + npc_width / 2;
				thisRect.bottom = npc_y + npc_height;
			}
			//��ʽһ��ͬʱ����4������
			return thisRect.left <= hitRec.right &&
				hitRec.left <= thisRect.right &&
				thisRect.top <= hitRec.bottom &&
				hitRec.top <= thisRect.bottom;
		}
	}
	return false;
}





