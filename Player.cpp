#include "Player.h"
#include "Npc.h"
#include "Boss.h"

Player::Player(const WhichPlayer w, const PlayerState newState)
{
	who = w;
	state = newState;
	lastState = state;
	blood = 26;
	score = 0;

	LPCTSTR imgPath = nullptr; int frameWidth = 0; int frameHeight = 0;

	//why����
	if (who == zy)
	{
		imgPath = ZyPaths[state];
		frameWidth = ZyParams[state][0];
		frameHeight = ZyParams[state][1];
	}

	if (wcslen(imgPath) > 0)
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
		totalFrames = frameCols * frameRows;					// ������֡��
		rawFrames = frameCols * frameRows;					// ��¼ԭʼ������֡��
		forward = 0;									// ��ǰ֡������ʼ��
		backward = totalFrames - 1;
	}

	frameSequence = NULL;
	loopForward = true;

	mapBlockPT.x = -1;
	mapBlockPT.y = -1;
}

Player::~Player()
{
}

void Player::setState(const PlayerState newState)
{
	lastState = state;
	state = newState;

	LPCTSTR imgPath = nullptr;
	int frameWidth = 0;
	int frameHeight = 0;
	if (who == zy)
	{
		imgPath = ZyPaths[state];
		frameWidth = ZyParams[state][0];
		frameHeight = ZyParams[state][1];
	}

	if (wcslen(imgPath) > 0)
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
		totalFrames = frameCols * frameRows;					// ������֡��
		rawFrames = frameCols * frameRows;					// ��¼ԭʼ������֡��
		forward = 0;									// ��ǰ֡������ʼ��
		backward = totalFrames - 1;
	}

	switch (newState)
	{
	case PICK:
		break;
	case BACKHIT:
	case FRONTHIT:
		this->SetSequence(hint_frame, 3);
		break;
	case DEATH:
		this->SetSequence(zy_death_frame, 9);
		break;
		//why �޸�
	case BOX1:
		this->SetSequence(zy_Box1_frame, 3);
		break;
	case BOX2:
		this->SetSequence(zy_Box2_frame, 6);
		break;
	default:
		this->frameSequence = nullptr;
		break;
	}
}

boolean Player::playerAttack(Npc* npc_sp)
{
	//why�޸�
	int npc_x = npc_sp->GetX();
	int npc_y = npc_sp->GetY();
	int npc_width = npc_sp->GetRatioSize().cx;
	int npc_height = npc_sp->GetRatioSize().cy;
	int ply_x = this->GetX();
	int ply_y = this->GetY();
	int ply_width = this->GetRatioSize().cx;
	int ply_height = this->GetRatioSize().cy;
	//���������ײ���Ľ�ɫ�����������ڿ����ڵ�������ɫ����ͬһˮƽʱ
	RECT hitRec;
	hitRec.left = npc_x;
	hitRec.top = npc_y;
	hitRec.right = npc_x + npc_width;
	hitRec.bottom = npc_y + npc_height;
	RECT thisRect;
	if (this->getState() == BOX1)
	{
		//why �޸�
		if (abs((ply_y + ply_height) - (npc_y + npc_height)) <= npc_height / 5)
		{

			//�泯�ұߵĹ�������
			if (this->GetRotation() == TRANS_NONE)
			{
				thisRect.left = ply_x + ply_width / 2;
				//thisRect.top = ply_y;
				thisRect.right = ply_x + ply_width;
				//thisRect.bottom = ply_y + ply_height;
			}
			//�泯����Ĺ�������
			else
			{
				thisRect.left = ply_x;
				//	thisRect.top = ply_y;
				thisRect.right = ply_x + ply_width / 2;
				//thisRect.bottom = ply_y + ply_height;
			}
			//��ʽһ��ͬʱ����4������
			return thisRect.left <= hitRec.right &&
				hitRec.left <= thisRect.right;
			//thisRect.top <= hitRec.bottom &&
			//hitRec.top <= thisRect.bottom;
		}
		else
			return false;

	}
	if (this->getState() == BOX2)
	{
		//�泯�ұߵĹ�������
		if (abs((ply_y + ply_height) - (npc_y + npc_height)) <= npc_height / 3)
		{
			//�泯�ұߵĹ�������
			if (this->GetRotation() == TRANS_NONE)
			{
				thisRect.left = ply_x + ply_width / 5 * 2;
				//thisRect.top = ply_y;
				thisRect.right = ply_x + ply_width;
				//thisRect.bottom = ply_y + ply_height;
			}
			//�泯����Ĺ�������
			else
			{
				thisRect.left = ply_x;
				//	thisRect.top = ply_y;
				thisRect.right = ply_x + ply_width / 5 * 3;
				//thisRect.bottom = ply_y + ply_height;
			}
			//��ʽһ��ͬʱ����4������
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

boolean Player::playerAttack(Boss* boss_sp)
{
	if (this->getState() == BOX1 || this->getState() == BOX2)
	{
		int npc_x = boss_sp->GetX();
		int npc_y = boss_sp->GetY();
		int npc_width = boss_sp->GetRatioSize().cx;
		int npc_height = boss_sp->GetRatioSize().cy;

		int ply_x = this->GetX();
		int ply_y = this->GetY();
		int ply_width = this->GetRatioSize().cx;
		int ply_height = this->GetRatioSize().cy;

		if (abs((ply_y + ply_height) - (npc_y + npc_height)) <= 20)
		{
			//���������ײ���Ľ�ɫ�����������ڿ����ڵ�������ɫ����ͬһˮƽʱ
			RECT hitRec;
			hitRec.left = npc_x;
			hitRec.top = npc_y;
			hitRec.right = npc_x + npc_width;
			hitRec.bottom = npc_y + npc_height;

			RECT thisRect;
			//�泯�ұߵĹ�������
			if (this->GetRotation() == TRANS_NONE)
			{
				thisRect.left = ply_x + ply_width / 2;
				//thisRect.top = ply_y;
				thisRect.right = ply_x + ply_width;
				//thisRect.bottom = ply_y + ply_height;
			}
			//�泯����Ĺ�������
			else
			{
				thisRect.left = ply_x;
				//	thisRect.top = ply_y;
				thisRect.right = ply_x + ply_width / 2;
				//thisRect.bottom = ply_y + ply_height;
			}
			//��ʽһ��ͬʱ����4������
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