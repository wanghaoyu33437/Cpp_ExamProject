//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ��Ȩ���� 2007-2013 ������
// (C) 2007-2013 WanLizhong All Rights Reserved
//*******************************************************************

#pragma once
#include "T_Graph.h"
#include "T_Map.h"
#include "T_Layer.h"
#include "T_Util.h"

#define ROUND(x) (int)(x+0.5)	//������������ĺ�

class T_Sprite :public T_Layer
{
protected:
	//����������������������������������������������������������������
	// ���ɫͼ����ص�����
	//����������������������������������������������������������������

	T_Graph	spImg;					// ԭʼ��ɫͼƬ
	T_Graph	spOldImg;				// �޸�ǰ��ɫͼƬ
	int		frameCols;				// ԭʼ֡ͼƬ������
	int		frameRows;				// ԭʼ֡ͼƬ������
	int		rawFrames;				// ԭʼ֡ͼƬ��֡��
	int		totalFrames;			// ��ǰ֡ͼƬ��֡��
	int		forward;				// ��ǰ���󲥷�֡����
	int		backward;				// �Ӻ���ǰ����֡����
	bool	loopForward;			// �Ƿ��ǰ���󲥷�֡
	int*	frameSequence;			// �Զ��嶯��֡����
	float	frameRatio;				// ֡ͼƬ�Ŵ����С�ȣ�1��ԭʼ������1�Ŵ�С��1��С��
	int		frameRotate;			// ֡ͼƬ��ת��ת��ʽ(ȡֵΪTRANSFER����ֵ)
	BYTE	frameAlpha;				// ֡ͼƬ͸����(255��͸��, 0��ȫ͸��)

	//����������������������������������������������������������������
	// ���ɫ״̬��ص�����
	//����������������������������������������������������������������

	int		dir;					// ��ʼ����
	int		lastDir;				// �ϴη���
	bool	active;					// �Ƿ�ɻ
	bool	dead;					// �Ƿ�����
	int		speed;					// ��ʼ�ƶ��ٶ�
	int		level;					// ��ʼ��Ϸ�ȼ�
	int		score;					// ��Ϸ��ֵ

	DWORD	startTime;				// ��ʱ��ʼʱ��
	DWORD	endTime;				// ��ʱ����ʱ��

	//����������������������������������������������������������������
	// ����ײ�����ص�����
	//����������������������������������������������������������������

	RECT	colideRect;				// ��ײ����������
	int		colideWidth;			// ��ײ������
	int		colideHeight;			// ��ײ����߶�
	POINT	mapBlockPT;				// ��ײ���ϰ�ʱ��λ��

public:
	//����������������������������������������������������������������
	// ���캯��������������������ȡ����
	//����������������������������������������������������������������

	// ���캯������˵��:
	// frameWidth��frameHeightֵ��Ϊ0: ��ɫͼ���޶���
	// frameWidth��frameHeightֵ������0: ��ɫͼ�����֡����
	T_Sprite() {}
	T_Sprite(LPCTSTR imgPath, int frameWidth = 0, int frameHeight = 0);
	// ��������
	virtual ~T_Sprite(void);
	// ��ȡ������
	virtual string ClassName() { return "T_Sprite"; }

	//����������������������������������������������������������������
	// ��ͼ����صĲ���
	//����������������������������������������������������������������

	T_Graph* GetImage() { return &spImg; }				// ��ñ���T_Graph����
	void SetImage(T_Graph* pImg) { spImg = *pImg; }		// ���ñ���T_Graph����
	void ResetImage() { spImg = spOldImg; }				// �ָ�����T_Graph����

	int GetForward() { return forward; };


	float GetRatio() { return frameRatio; }				// ������ű�
	void SetRatio(float rat) { frameRatio = rat; }		// �������ű�
	// �������űȼ���֡ͼƬ����
	SIZE GetRatioSize()
	{
		SIZE ratioFrameSize;
		ratioFrameSize.cx = ROUND(frameRatio*Width);
		ratioFrameSize.cy = ROUND(frameRatio*Height);
		return ratioFrameSize;
	}

	int GetRotation() { return frameRotate; }			// ���ͼ��ת����ʽ
	void SetRotation(int rot) { frameRotate = rot; }		// ����ͼ��ת����ʽ(rotΪTRANSFER����ֵ)

	BYTE GetAlpha() { return frameAlpha; }				// ���͸����ֵ
	void SetAlpha(BYTE a) { frameAlpha = a; }			// ����͸����ֵ

	//����������������������������������������������������������������
	// ��״̬��صĲ���
	//����������������������������������������������������������������

	int GetDir() { return dir; }							// ��÷���ֵ			
	void SetDir(int d) { dir = d; }						// ���÷���ֵ

	bool IsActive() { return active; }					// �Ƿ�ɻ
	void SetActive(bool act) { active = act; }			// �����Ƿ�ɻ

	bool IsDead() { return dead; }						// ����״̬
	void SetDead(bool dd) { dead = dd; }					// ��������״̬

	int GetSpeed() { return speed; }						// ����ٶ�ֵ
	void SetSpeed(int spd) { speed = spd; }				// �����ٶ�ֵ

	int GetLevel() { return level; }						// ��õȼ�ֵ
	void SetLevel(int lvl) { level = lvl; }				// ���õȼ�ֵ

	int GetScore() { return score; }						// ��÷�ֵ
	void SetScore(int scr) { score = scr; }				// ���÷�ֵ

	//����������������������������������������������������������������
	// ���ʱ��صĲ���
	//����������������������������������������������������������������

	void SetEndTime(DWORD time) { endTime = time; }		// ���ü�ʱ����ʱ��
	DWORD GetEndTime() { return endTime; }				// ��ü�ʱ����ʱ��
	void SetStartTime(DWORD time) { startTime = time; }	// ���ü�ʱ��ʼʱ��
	DWORD GetStartTime() { return startTime; }			// ��ü�ʱ��ʼʱ��

	//����������������������������������������������������������������
	// ����ײ��صĲ���
	//����������������������������������������������������������������

	// ������������������ײ��������(px��pyΪ��ֵ�Ŵ󡢸�ֵ��С����λΪ����)
	void AdjustCollideRect(int px = 0, int py = 0);
	// ������ź��ʵ����ײ����������
	RECT* GetCollideRect();
	// ����ɫ��ײ, distance�����ײ�ľ���
	bool CollideWith(T_Sprite* target, int distance = 0);
	// ����ͼ��ײ
	bool CollideWith(IN T_Map* map);
	// ��ȡ��ײ���ϰ�ʱ��λ��
	POINT GetMapBlockPT() { return mapBlockPT; }

	//����������������������������������������������������������������
	// �붯��֡��صĲ���
	//����������������������������������������������������������������

	// ��ǰ������ѭ����������֡
	void LoopFrame(bool ahead = true);
	// ��ǰ������ѭ������һ������֡
	bool LoopFrameOnce(bool ahead = true);
	// ��ȡԭʼ֡�ĳ���
	int GetRawFrames() { return rawFrames; }
	// ����֡�������鳤��
	int GetTotalFrames() { return totalFrames; }

	// ��ȡ��ǰ֡���к�
	int GetFrame(bool ahead = true)
	{
		if (ahead == true)
			return forward;
		else
			return backward;
	}

	// ���õ�ǰ֡���к�
	void SetFrame(int sequenceIndex, bool ahead = true)
	{
		if (ahead == true)
			forward = sequenceIndex;
		else
			backward = sequenceIndex;
	}

	// �����µ�֡����
	void SetSequence(int* sequence, int length)
	{
		frameSequence = sequence;
		totalFrames = length;
	}

	//����������������������������������������������������������������
	// �������صĲ���
	//����������������������������������������������������������������

	// ��������жϷ���
	int GetDir(POINT mousePT);
	// ����ɫ�Ƿ񵽴���괦
	bool MoveTo(IN POINT mousePT, IN POINT desPT, IN RECT Boundary);
	// ����ɫ�Ƿ񵽴��ͼ��괦
	bool MoveTo(IN POINT mousePT, IN POINT desPT, IN T_Map* map);

	//����������������������������������������������������������������
	// �����ʼ�������ƺ���
	//����������������������������������������������������������������

	// ��ʼ���������
	void Initiate(SPRITEINFO spInfo);
	// ����������
	void Draw(HDC hdc);

};

// ������������������ײ��������(px��pyΪ��ֵ�Ŵ󡢸�ֵ��С����λΪ����)
inline void T_Sprite::AdjustCollideRect(int px, int py)
{
	if (px == 0 && py == 0)
	{
		return;
	}
	else
	{
		RECT tempRec = { 0, 0, colideWidth, colideHeight };
		InflateRect(&tempRec, px, py); //�����������������
		colideWidth = tempRec.right - tempRec.left;
		colideHeight = tempRec.bottom - tempRec.top;
	}
}

// ������ź��ʵ����ײ����������
inline RECT* T_Sprite::GetCollideRect()
{
	int c_left, c_top;
	if (frameRatio > 0)
	{
		c_left = (GetRatioSize().cx - colideWidth) / 2;
		c_top = (GetRatioSize().cy - colideHeight) / 2;
	}
	else
	{
		c_left = ((int)GetWidth() - colideWidth) / 2;
		c_top = ((int)GetHeight() - colideHeight) / 2;
	}

	colideRect.left = (LONG)X + c_left;
	colideRect.right = colideRect.left + colideWidth;
	colideRect.top = (LONG)Y + c_top;
	colideRect.bottom = colideRect.top + colideHeight;
	return &colideRect;
}

// ��Ȿ��ɫ�����Ƿ���Ŀ���ɫ��ײ(distance����Ϊ������)
inline bool T_Sprite::CollideWith(T_Sprite* target, int distance)
{
	//���������ײ���Ľ�ɫ��������
	RECT targetRect = *(target->GetCollideRect());
	RECT hitRec;
	hitRec.left = targetRect.left - distance;
	hitRec.top = targetRect.top - distance;
	hitRec.right = targetRect.right + distance;
	hitRec.bottom = targetRect.bottom + distance;
	RECT thisRect = *(this->GetCollideRect());
	int cw = abs(thisRect.right - thisRect.left);
	int tw = abs(hitRec.right - hitRec.left);
	int ch = abs(thisRect.bottom - thisRect.top);
	int th = abs(hitRec.bottom - hitRec.top);

	//��ʽһ��ͬʱ����4������
	return thisRect.left <= hitRec.right &&
		hitRec.left <= thisRect.right &&
		thisRect.top <= hitRec.bottom &&
		hitRec.top <= thisRect.bottom;

	//��ʽ����ͬʱ����2������
	//return (abs((thisRect.left + cw/2)-(hitRec.left + tw/2))<(cw+tw)/2) &&
	//       (abs((thisRect.top + ch/2)-(hitRec.top + th/2))<(ch+th)/2);
}