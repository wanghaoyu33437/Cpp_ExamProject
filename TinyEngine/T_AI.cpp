//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ����: 2019-11-28
// ��Ȩ���� 2007-2019 ������
// (C) 2007-2019 WanLizhong All Rights Reserved
//*******************************************************************


#include "T_AI.h"


//���ά��GAME_DIR��Ԫ�ر��һ��
//�ڶ�ά��ʾ��Ӧ����Ķ�ܷ���
int T_AI::EvadeDir[8][5]={
	//DIR_LEFT��ܷ���
	{DIR_RIGHT, DIR_DOWN, DIR_UP, DIR_RIGHT_UP, DIR_RIGHT_DOWN},
	//DIR_RIGHT��ܷ���
	{DIR_LEFT, DIR_DOWN, DIR_UP, DIR_LEFT_UP, DIR_LEFT_DOWN},	
	//DIR_UP��ܷ���
	{DIR_DOWN, DIR_LEFT, DIR_RIGHT, DIR_LEFT_DOWN, DIR_RIGHT_DOWN},	
	//DIR_DOWN��ܷ���
	{DIR_UP, DIR_LEFT, DIR_RIGHT, DIR_LEFT_UP, DIR_RIGHT_UP},	
	//DIR_LEFT_UP��ܷ���
	{DIR_RIGHT_DOWN, DIR_RIGHT_UP, DIR_RIGHT, DIR_UP, DIR_DOWN},
	//DIR_LEFT_DOWN��ܷ���
	{DIR_RIGHT_UP, DIR_RIGHT_DOWN, DIR_RIGHT, DIR_UP, DIR_DOWN},
	//DIR_RIGHT_UP��ܷ���
	{DIR_LEFT_DOWN, DIR_LEFT_UP, DIR_LEFT, DIR_UP, DIR_DOWN},
	//DIR_RIGHT_DOWN��ܷ���
	{DIR_LEFT_UP, DIR_LEFT_DOWN, DIR_LEFT, DIR_UP, DIR_DOWN}		
};

T_AI::T_AI(int d_style)
{
	dir_style = d_style;
}

T_AI::~T_AI(void)
{
}

// �������spָ���Ľ�ɫǰ�������Ӧ����ײ�������
// ����sp�������Ľ�ɫ����
// ����spSizeTimes����ɫ��ߵı����������������ķ�Χ
// ����testRec������Ͳ������õ����յļ������
void T_AI::GetHitRect(IN T_Sprite* sp, IN int spSizeTimes, OUT RECT& testRec)
{
	int sp_width = sp->GetRatioSize().cx;
	int sp_height = sp->GetRatioSize().cy;

	switch(sp->GetDir())
	{
	case DIR_LEFT:
		testRec.left = sp->GetX()-spSizeTimes*sp_width;
		testRec.top = sp->GetY();
		testRec.right = sp->GetX();
		testRec.bottom = sp->GetY()+sp_height;;
		break;

	case DIR_RIGHT:
		testRec.left = sp->GetX()+sp_width;
		testRec.top = sp->GetY();
		testRec.right = sp->GetX()+(spSizeTimes+1)*sp_width;
		testRec.bottom = sp->GetY()+sp_height;;
		break;

	case DIR_UP:
		testRec.left = sp->GetX();
		testRec.top = sp->GetY()-spSizeTimes*sp_height;
		testRec.right = sp->GetX()+sp_width;
		testRec.bottom = sp->GetY();
		break;

	case DIR_DOWN:
		testRec.left = sp->GetX();
		testRec.top = sp->GetY()+sp_height;;
		testRec.right = sp->GetX()+sp_width;
		testRec.bottom = sp->GetY()+(spSizeTimes+1)*sp_height;
		break;

	case DIR_LEFT_UP:
		testRec.left = sp->GetX()-spSizeTimes*sp_width;
		testRec.top = sp->GetY()-spSizeTimes*sp_height;
		testRec.right = sp->GetX();
		testRec.bottom = sp->GetY();
		break;

	case DIR_LEFT_DOWN:
		testRec.left = sp->GetX()-spSizeTimes*sp_width;
		testRec.top = sp->GetY()+sp_height;;
		testRec.right = sp->GetX();
		testRec.bottom = sp->GetY()+(spSizeTimes+1)*sp_height;
		break;

	case DIR_RIGHT_UP:
		testRec.left = sp->GetX()+sp_width;
		testRec.top = sp->GetY()-spSizeTimes*sp_height;
		testRec.right = sp->GetX()+(spSizeTimes+1)*sp_width;
		testRec.bottom = sp->GetY();
		break;

	case DIR_RIGHT_DOWN:
		testRec.left = sp->GetX()+sp_width;
		testRec.top = sp->GetY()+sp_height;;
		testRec.right = sp->GetX()+(spSizeTimes+1)*sp_width;
		testRec.bottom = sp->GetY()+(spSizeTimes+1)*sp_height;
		break;
	}
}

// �����ƶ������ٶȺ�ָ���Ļ��Χ���㵱ǰ��ɫ���ƶ�λ��
MoveCoord T_AI::GetMoveCoord(T_Sprite* npc_sp, int dir, int speed, RECT boundary)
{
	MoveCoord mRate;
	int nextStepX, nextStepY;
	int SpeedX=0, SpeedY=0;
	mRate.BoundDir = -1;	//û���ڱ߽���

	int sp_width = npc_sp->GetRatioSize().cx;
	int sp_height = npc_sp->GetRatioSize().cy;
 
	switch(dir)
	{
	case DIR_LEFT:
		SpeedX = -speed;
		SpeedY = 0;
		//������һ���ƶ��Ƿ񳬹��߽�
		nextStepX = npc_sp->GetX()-speed;
		if(nextStepX <= boundary.left) 
		{
			SpeedX =  -(npc_sp->GetX()-boundary.left);
			mRate.BoundDir = DIR_LEFT;
		}
		break;

	case DIR_RIGHT:
		SpeedX =speed;
		SpeedY = 0;
		//������һ���ƶ��Ƿ񳬹��߽�
		nextStepX = npc_sp->GetX()+ sp_width + speed;
		if(nextStepX >= boundary.right)
		{
			SpeedX = boundary.right - (npc_sp->GetX()+sp_width);
			mRate.BoundDir = DIR_RIGHT;
		}
		break;

	case DIR_UP:
		SpeedX = 0;
		SpeedY = -speed;
		//������һ���ƶ��Ƿ񳬹��߽�
		nextStepY = npc_sp->GetY()-speed;
		if(nextStepY <= boundary.top) 
		{
			SpeedY =-(npc_sp->GetY()-boundary.top);
			mRate.BoundDir = DIR_UP;
		}
		break;

	case DIR_DOWN:
		SpeedX = 0;
		SpeedY = speed;
		//������һ���ƶ��Ƿ񳬹��߽�
		nextStepY = npc_sp->GetY() + sp_height + speed;
		if(nextStepY >= boundary.bottom) 
		{
			SpeedY = boundary.bottom - (npc_sp->GetY()+sp_height);
			mRate.BoundDir = DIR_DOWN;
		}
		break;
	
	case DIR_LEFT_UP:
		SpeedX = -speed;
		SpeedY = -speed;

		//������һ���ƶ��Ƿ񳬹��߽�
		nextStepX = npc_sp->GetX()-speed;
		if(nextStepX <= boundary.left) 
		{
			SpeedX =  -(npc_sp->GetX()-boundary.left);
			SpeedY = -(npc_sp->GetX()-boundary.left);
			mRate.BoundDir = DIR_LEFT;
			break;
		}
		nextStepY = npc_sp->GetY()-speed;
		if(nextStepY <= boundary.top) 
		{
			SpeedY =-(npc_sp->GetY()-boundary.top);
			SpeedX = -(npc_sp->GetY()-boundary.top);
			mRate.BoundDir = DIR_UP;
		}
		break;

	case DIR_LEFT_DOWN:
		SpeedX = -speed;
		SpeedY = speed;

		//������һ���ƶ��Ƿ񳬹��߽�
		nextStepX = npc_sp->GetX()-speed;
		if(nextStepX <=boundary.left) 
		{
			SpeedX =  -(npc_sp->GetX()-boundary.left);
			SpeedY =  (npc_sp->GetX()-boundary.left);
			mRate.BoundDir = DIR_LEFT;
			break;
		}
		nextStepY = npc_sp->GetY() + sp_height + speed;
		if(nextStepY >=boundary.bottom) 
		{
			SpeedY = boundary.bottom - (npc_sp->GetY()+sp_height);
			SpeedX = -(boundary.bottom - (npc_sp->GetY()+sp_height));
			mRate.BoundDir = DIR_DOWN;
		}
		break;

	case DIR_RIGHT_UP:
		SpeedX = speed;
		SpeedY = -speed;

		//������һ���ƶ��Ƿ񳬹��߽�
		nextStepX = npc_sp->GetX()+ sp_width + speed;
		if(nextStepX >= boundary.right) 
		{
			SpeedX = boundary.right - (npc_sp->GetX()+sp_width);
			SpeedY = -(boundary.right - (npc_sp->GetX()+sp_width));
			mRate.BoundDir = DIR_RIGHT;
			break;
		}
		nextStepY = npc_sp->GetY()-speed;
		if(nextStepY <= boundary.top) 
		{
			SpeedY =-( npc_sp->GetY()-boundary.top);
			SpeedX = npc_sp->GetY()-boundary.top;
			mRate.BoundDir = DIR_UP;
		}
		break;

	case DIR_RIGHT_DOWN:
		SpeedX = speed;
		SpeedY = speed;

		//������һ���ƶ��Ƿ񳬹��߽�
		nextStepX = npc_sp->GetX()+ sp_width + speed;
		if(nextStepX >= boundary.right) 
		{
			SpeedX = boundary.right - (npc_sp->GetX()+sp_width);
			SpeedY = boundary.right - (npc_sp->GetX()+sp_width);
			mRate.BoundDir = DIR_RIGHT;
			break;
		}
		nextStepY = npc_sp->GetY() + sp_height + speed;
		if(nextStepY >=boundary.bottom) 
		{
			SpeedY = boundary.bottom - (npc_sp->GetY()+sp_height);
			SpeedX = boundary.bottom - (npc_sp->GetY()+sp_height);
			mRate.BoundDir = DIR_DOWN;
		}
	}

	mRate.moveX = SpeedX;
	mRate.moveY = SpeedY;
	mRate.oldX = npc_sp->GetX();
	mRate.oldY = npc_sp->GetY();
	return mRate;
}

// �����ƶ������ٶȺ�ָ���Ļ��Χ�Խ�ɫ�����δ���
void T_AI::Wander(T_Sprite* npc_sp, int npc_dir, int speed, RECT boundary)
{
	// ��ȡ��ǰ��Ϸ��ɫ���ƶ�������ٶȼ�������һ�����ƶ���Ϣ
	MoveCoord mRate = GetMoveCoord(npc_sp, npc_dir, speed, boundary);
	// �����ɫû�е�����Χ�ı߽�
	if(mRate.BoundDir == -1 )
	{
		// ��ɫ�����ƶ�
		npc_sp->Move(mRate.moveX, mRate.moveY);
	}
	// �����ɫ������Χ�ı߽�
	if(mRate.BoundDir != -1) 
	{
		int r_dir = 0;
		// ���ݽ�ɫ���ƶ�����ģʽ��ȡһ�������ܷ���
		if(dir_style == 8) 
		{
			r_dir = rand()%5;
		}
		else
		{
			r_dir = rand()%3;
		}
		// ����ɫ��λ�ڱ߽�
		npc_sp->SetPosition(mRate.oldX, mRate.oldY);
		// Ϊ��ɫ�����µ��ƶ�����
		npc_sp->SetDir(EvadeDir[mRate.BoundDir][r_dir]);
	}
}

// �����ƶ������ٶȺ�ָ���ĵ�ͼ����Խ�ɫ�����δ���
void T_AI::Wander(T_Sprite* npc_sp, int npc_dir, int speed, T_Map* map)
{
	// ������Ϸ��ͼ�ľ��η�Χ
	RECT mapBound;
	mapBound.left = map->GetX();
	mapBound.top = map->GetY();
	mapBound.right = map->GetX()+map->GetWidth();
	mapBound.bottom = map->GetY()+map->GetHeight();

	// ��ȡ��ǰ��Ϸ��ɫ���ƶ�������ٶȼ�������һ�����ƶ���Ϣ
	MoveCoord mRate = GetMoveCoord(npc_sp, npc_dir, speed, mapBound);
	
	// ���ݽ�ɫ���ƶ��ķ���ģʽ��ȡһ�������ܷ���
	int r_dir = 0;
	if(dir_style == 8) 
	{
		r_dir = rand()%5;
	}
	else
	{
		r_dir = rand()%3;
	}
	
	// �����ɫû�е�����Ϸ��ͼ�ı߽�
	if(mRate.BoundDir == -1 )
	{
		npc_sp->Move(mRate.moveX, mRate.moveY);
	}
	// �����ɫ�Ѿ�������Ϸ��ͼ�ı߽�
	if(mRate.BoundDir != -1) 
	{
		npc_sp->SetPosition(mRate.oldX, mRate.oldY);
		npc_sp->SetDir(EvadeDir[mRate.BoundDir][r_dir]);
	}
	if(npc_sp->CollideWith(map)) 
	{
		// ����ɫ��λ�ڱ߽�
		npc_sp->SetPosition(mRate.oldX, mRate.oldY);
		// Ϊ��ɫ�����µ��ƶ����򣨳�����3�������ܣ�
		npc_sp->SetDir(EvadeDir[npc_sp->GetDir()][rand()%3]);
	}
}



// ��ɫ��ܴ�����һ������Ϊ��ܵĶ��󣬵ڶ�������ΪҪ�رܵļ�����
void T_AI::Evade(T_Sprite* npc_sp, T_Sprite* player)
{
	RECT lprcDst;
	RECT playerRect={player->GetX(), player->GetY(), 
					 player->GetX()+player->GetRatioSize().cx, 
					 player->GetY()+player->GetRatioSize().cy };

	RECT testRect;
	GetHitRect(npc_sp, 1, testRect);

	if ((IntersectRect(&lprcDst, &playerRect, &testRect))==TRUE)
	{

		int r_dir = 0;
		if(dir_style == 8) 
		{
			r_dir = rand()%5;
		}
		else
		{
			r_dir = rand()%3;
		}
		npc_sp->SetDir(EvadeDir[npc_sp->GetDir()][r_dir]);
	}
}

// ��ɫ���ص�������һ������Ϊ�����󣬵ڶ�������Ϊ���������ڵĽ�ɫ����
void T_AI::CheckOverlay(T_Sprite* npc_sp, vector<T_Sprite*> vSpriteSet)
{
	vector<T_Sprite*>::iterator p;

	RECT testRec;
	GetHitRect(npc_sp, 1, testRec);// ��ȡ��ǰSprite��Χ�ľ���

	int r_dir = 0;
	if(dir_style == 8) 
	{
		r_dir = rand()%5;
	}
	else
	{
		r_dir = rand()%3;
	}

	RECT lprcDst;
	for (p = vSpriteSet.begin(); p != vSpriteSet.end(); p++) 
	{
		if(*p == npc_sp) continue;
		
		RECT pRect={(*p)->GetX(), (*p)->GetY(), 
					(*p)->GetX()+(*p)->GetRatioSize().cx, 
					(*p)->GetY()+(*p)->GetRatioSize().cy };

		if ((IntersectRect(&lprcDst, &pRect, &testRec))==TRUE)
		{
			npc_sp->SetDir(EvadeDir[npc_sp->GetDir()][r_dir]);
		}
	}
}

//NPC׷����Ϊ
void T_AI::Chase(Npc* npc_sp, Player* player_sp)
{
	
	//�����ɫ�Ų�λ��
	int npc_x = npc_sp->GetX()+npc_sp->GetWidth()/2;
	int npc_y = npc_sp->GetY() + npc_sp->GetHeight();
	int player_x = player_sp->GetX()+player_sp->GetWidth();
	int player_y = player_sp->GetY() + player_sp->GetHeight();
	if (player_sp->GetRotation() == TRANS_VFLIP_ROT180)
		player_x = player_sp->GetX();

	int distance = npc_sp->GetWidth()*1.5;
	if(npc_sp->getWho() == Npc4)
		distance = npc_sp->GetWidth()*1.8;
	
	float _x = fabs(npc_x - player_x);
	float _y = fabs(npc_y - player_y);
	boolean moveFg = (_x < distance) ? true : false;
	if (npc_sp->getState() != nDEATH)
	{
		if ((_x>distance || (_x<distance && _y>10)) && (npc_sp->getState() != nATTACK1 && npc_sp->getState() != nATTACK2)) {
			npc_sp->setState(nWALK);
			int r;
			if (!moveFg) {
				//y��x����������y����
				if (_y / _x > 3) r = 1;
				//x��y����������x����
				else if (_x / _y > 3 && _x>distance) r = 0;
				//�ȽϽӽ�ʱ���������Ч��������ǰ����
				else {
					r = rand() % 2;
				}
			}
			else {
				r = 1;
			}
			//����Ŀ�귽��ѡ��ǰ������
			if (r == 0) {
				//����
				if (player_x > npc_x) {
					npc_sp->SetRotation(TRANS_NONE);
					npc_sp->SetDir(DIR_RIGHT);
					npc_sp->Move(npc_sp->GetSpeed(), 0);
				}
				//����
				else if (player_x <= npc_x) {
					npc_sp->SetRotation(TRANS_HFLIP_NOROT);
					npc_sp->SetDir(DIR_LEFT);
					npc_sp->Move(-npc_sp->GetSpeed(), 0);
				}
			}
			else {
				//����
				if (player_y > npc_y) {
					npc_sp->SetDir(DIR_UP);
					npc_sp->Move(0, npc_sp->GetSpeed());
				}
				//����
				else if (player_y <= npc_y) {
					npc_sp->SetDir(DIR_DOWN);
					if (npc_y>256)
						npc_sp->Move(0, -npc_sp->GetSpeed());
				}
			}
			npc_sp->SetStartTime(GetTickCount());
		}
		else {
			if (npc_sp->getState() != nATTACK1 && npc_sp->getState() != nATTACK2 &&GetTickCount() - npc_sp->GetStartTime() > 1500)
			{
				npc_sp->SetStartTime(GetTickCount());
				int at = rand() % 2;
				if (at == 0) npc_sp->setState(nATTACK1);
				else npc_sp->setState(nATTACK2);
			}
		}
	}
	//���npc���������2s��ʧ
	else {
		if (GetTickCount() - npc_sp->getDeathTime() > 800)
			npc_sp->SetAlpha(0.8);
		if (GetTickCount() - npc_sp->getDeathTime() > 1500)
			npc_sp->SetAlpha(0.5);
		if (GetTickCount() - npc_sp->getDeathTime() > 2000)
			npc_sp->SetVisible(false);
	}
	return;
}

//NPC�����㷨
void T_AI::Roam(Npc* npc_sp, Player* player_sp,int Lbarrier,int Rbarrier)
{
	//�����ɫ�Ų�����
	int npc_x = npc_sp->GetX() + npc_sp->GetWidth() / 2;
	int npc_y = npc_sp->GetY() + npc_sp->GetHeight();
	int player_x = player_sp->GetX() + player_sp->GetWidth();
	int player_y = player_sp->GetY() + player_sp->GetHeight();
	int X_speed = 0;
	int Y_speed = 0;

	if (npc_sp->getState() != nDEATH)
	{
		if (npc_x > player_x)
			npc_sp->SetRotation(TRANS_HFLIP_NOROT);
		else
			npc_sp->SetRotation(TRANS_NONE);

		if (GetTickCount() - npc_sp->GetStartTime()>2000)
		{
			npc_sp->SetStartTime(GetTickCount());
			int r_dir = rand() % 3;
			npc_sp->SetDir(EvadeDir[npc_sp->GetDir()][r_dir]);
		}
		if (npc_sp->getState() == nWALK)
		{
			if (npc_sp->GetDir() == DIR_LEFT)
			{
				X_speed = -npc_sp->GetSpeed();
			}
			else if (npc_sp->GetDir() == DIR_RIGHT)
			{
				X_speed = npc_sp->GetSpeed();
			}
			else if (npc_sp->GetDir() == DIR_UP)
			{
				Y_speed = -npc_sp->GetSpeed();
			}
			else if (npc_sp->GetDir() == DIR_DOWN)
			{
				Y_speed = npc_sp->GetSpeed();
			}
			if (npc_y + Y_speed > 300 && npc_y + Y_speed<650 && npc_x + X_speed>-(320 + Lbarrier) && npc_x + X_speed<(320 + Rbarrier))
				npc_sp->Move(X_speed, Y_speed);
			else
			{
				int r_dir = rand() % 3;
				npc_sp->SetDir(EvadeDir[npc_sp->GetDir()][r_dir]);
			}
		}

		if (player_sp->GetRotation() == TRANS_VFLIP_ROT180)
			player_x = player_sp->GetX();

		int distance = npc_sp->GetWidth()*1.5;
		if (npc_sp->getWho() == Npc4)
			distance = npc_sp->GetWidth()*1.5;

		float _x = fabs(npc_x - player_x);
		float _y = fabs(npc_y - player_y);
		boolean moveFg = (_x < distance) ? true : false;

		if ((_x>distance || (_x<distance && _y>20)) && (npc_sp->getState() != nATTACK1 && npc_sp->getState() != nATTACK2))
		{
			npc_sp->setState(nWALK);
		}
		else {
			if (npc_sp->getState() != nATTACK1 && npc_sp->getState() != nATTACK2 &&GetTickCount() - npc_sp->GetEndTime() > 1000)
			{
				npc_sp->SetEndTime(GetTickCount());
				int at = rand() % 2;
				if (at == 0) npc_sp->setState(nATTACK1);
				else npc_sp->setState(nATTACK2);
			}
		}
	}
	//���npc���������2s��ʧ
	else {
		if (GetTickCount() - npc_sp->getDeathTime() > 800)
			npc_sp->SetAlpha(0.8);
		if (GetTickCount() - npc_sp->getDeathTime() > 1500)
			npc_sp->SetAlpha(0.5);
		if (GetTickCount() - npc_sp->getDeathTime() > 2000)
			npc_sp->SetVisible(false);
	}
}


//Boss׷�ٶ���㷨
void T_AI::Charge(Boss* boss_sp, Player* player_sp)
{

	//�����ɫ�Ų�λ��
	int boss_x = boss_sp->GetX() + boss_sp->GetWidth() / 2;
	int boss_y = boss_sp->GetY() + boss_sp->GetHeight();
	int player_x = player_sp->GetX() + player_sp->GetWidth();
	int player_y = player_sp->GetY() + player_sp->GetHeight();
	if (player_sp->GetRotation() == TRANS_VFLIP_ROT180)
		player_x = player_sp->GetX();

	int distance = boss_sp->GetWidth()*1.2;
	if (boss_sp->getWho() == Boss2)
		distance = boss_sp->GetWidth()*1;
	if (boss_sp->getWho() == Boss3)
		distance = boss_sp->GetWidth()*1.2;
	if (boss_sp->getWho() == Boss4)
		distance = boss_sp->GetWidth()*0.9;

	float _x = fabs(boss_x - player_x);
	float _y = fabs(boss_y - player_y);
	boolean moveFg = (_x < distance) ? true : false;
	if (boss_sp->getState() != bDEATH && boss_sp->getState()!=bRESTAND)
	{
		
		if ((_x>distance || (_x<distance && _y>20)) && (boss_sp->getState() != bATTACK1 && boss_sp->getState() != bATTACK2 && boss_sp->getState() != bATTACK3)) {
			boss_sp->setState(bWALK);

			int r;
			if (!moveFg) {
				//y��x����������y����
				if (_y / _x > 3) r = 1;
				//x��y����������x����
				else if (_x / _y > 3 && _x>distance) r = 0;
				//�ȽϽӽ�ʱ���������Ч��������ǰ����
				else {
					r = rand() % 2;
				}
			}
			else {
				r = 1;
			}
			//����Ŀ�귽��ѡ��ǰ������
			if (r == 0) {
				if (GetTickCount() - boss_sp->GetEndTime() > 4000)
				{
					boss_sp->SetEndTime(GetTickCount());
					boss_sp->setState(bATTACK3);
				}

				//����
				if (player_x > boss_x) {
					boss_sp->SetRotation(TRANS_NONE);
					boss_sp->SetDir(DIR_RIGHT);
					boss_sp->Move(boss_sp->GetSpeed(), 0);
				}
				//����
				else if (player_x <= boss_x) {
					boss_sp->SetRotation(TRANS_HFLIP_NOROT);
					boss_sp->SetDir(DIR_LEFT);
					boss_sp->Move(-boss_sp->GetSpeed(), 0);
				}
			}
			else {
				//����
				if (player_y > boss_y) {
					boss_sp->SetDir(DIR_UP);
					boss_sp->Move(0, boss_sp->GetSpeed());
				}
				//����
				else if (player_y <= boss_y) {
					boss_sp->SetDir(DIR_DOWN);
					if (boss_y>256)
						boss_sp->Move(0, -boss_sp->GetSpeed());
				}
			}
			boss_sp->SetStartTime(GetTickCount());
		}
		else {
			if (boss_sp->getState() != bATTACK1 && boss_sp->getState() != bATTACK2  && boss_sp->getState() != bATTACK3 
				&&GetTickCount() - boss_sp->GetStartTime() > 800 &&boss_sp->getState()!=nHINT)
			{
				boss_sp->SetStartTime(GetTickCount());
				int at = rand() % 2;
				if (at == 0) boss_sp->setState(bATTACK1);
				else if (at == 1) boss_sp->setState(bATTACK2);
			}
		}
	}
	
	return;
}

//Boss���Ҷ������㷨
void T_AI::BossRoam(Boss* npc_sp, Player* player_sp, int Lbarrier, int Rbarrier)
{
	//�����ɫ�Ų�����
	int npc_x = npc_sp->GetX() + npc_sp->GetWidth() / 2;
	int npc_y = npc_sp->GetY() + npc_sp->GetHeight();
	int player_x = player_sp->GetX() + player_sp->GetWidth();
	int player_y = player_sp->GetY() + player_sp->GetHeight();
	int X_speed = 0;
	int Y_speed = 0;

	if (npc_sp->getState() != bDEATH)
	{
		if (npc_x > player_x)
			npc_sp->SetRotation(TRANS_HFLIP_NOROT);
		else
			npc_sp->SetRotation(TRANS_NONE);

		if (GetTickCount() - npc_sp->GetStartTime()>2000)
		{
			npc_sp->SetStartTime(GetTickCount());
			int r_dir = rand() % 3;
			npc_sp->SetDir(EvadeDir[npc_sp->GetDir()][r_dir]);
		}
		if (npc_sp->getState() == bWALK)
		{
			if (npc_sp->GetDir() == DIR_LEFT)
			{
				X_speed = -npc_sp->GetSpeed();
			}
			else if (npc_sp->GetDir() == DIR_RIGHT)
			{
				X_speed = npc_sp->GetSpeed();
			}
			else if (npc_sp->GetDir() == DIR_UP)
			{
				Y_speed = -npc_sp->GetSpeed();
			}
			else if (npc_sp->GetDir() == DIR_DOWN)
			{
				Y_speed = npc_sp->GetSpeed();
			}
			if (npc_y + Y_speed > 300 && npc_y + Y_speed<650 && npc_x + X_speed>-(320 + Lbarrier) && npc_x + X_speed<(320 + Rbarrier))
				npc_sp->Move(X_speed, Y_speed);
			else
			{
				int r_dir = rand() % 3;
				npc_sp->SetDir(EvadeDir[npc_sp->GetDir()][r_dir]);
			}
		}

		if (player_sp->GetRotation() == TRANS_VFLIP_ROT180)
			player_x = player_sp->GetX();

		int distance = npc_sp->GetWidth()*1.5;
		if (npc_sp->getWho() == Npc4)
			distance = npc_sp->GetWidth()*1.5;

		float _x = fabs(npc_x - player_x);
		float _y = fabs(npc_y - player_y);
		boolean moveFg = (_x < distance) ? true : false;
		if ((_x>distance || (_x<distance && _y>20)) && (npc_sp->getState() != bATTACK1 && npc_sp->getState() != bATTACK2))
		{
			npc_sp->setState(bWALK);
		}
		else {
			if (npc_sp->getState() != bATTACK1 && npc_sp->getState() != bATTACK2 && npc_sp->getState() != bATTACK3 &&GetTickCount() - npc_sp->GetEndTime() > 1000)
			{
				npc_sp->SetEndTime(GetTickCount());
				int at = rand() % 2;
				if (at == 0) npc_sp->setState(bATTACK1);
				else npc_sp->setState(bATTACK2);
			}
		}
	}
}



