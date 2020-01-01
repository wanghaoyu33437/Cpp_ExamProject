//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ��Ȩ���� 2007-2013 ������
// (C) 2007-2013 WanLizhong All Rights Reserved
//*******************************************************************

#include "T_Sprite.h"

T_Sprite::T_Sprite(LPCTSTR imgPath, int frameWidth, int frameHeight)
{
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

T_Sprite::~T_Sprite(void)
{
}

void T_Sprite::Initiate(SPRITEINFO spInfo)
{
	SetPosition(spInfo.X, spInfo.Y);	// ��ɫ����
	Visible = spInfo.Visible;			// ��ɫ�Ƿ�ɼ�
	dir = spInfo.Dir;					// ��ɫ����
	active = spInfo.Active;				// ��ɫ״̬���Ƿ��ƶ���
	speed = spInfo.Speed;				// ��ɫ�ƶ��ٶ�
	dead = spInfo.Dead;					// ��ɫ����״̬
	level = spInfo.Level;				// ��ɫ�ȼ�
	score = spInfo.Score;				// ��ɫ��ɫ��ֵ 
	frameRatio = spInfo.Ratio;			// ֡ͼƬ���ű�(����1ԭʼ������1�Ŵ�С��1��С)
	frameRotate = spInfo.Rotation;		// ֡ͼƬ�Ƿ���ת�任(TRANSFERֵ֮һ)
	frameAlpha = spInfo.Alpha;			// ֡ͼƬ͸����
	if (frameRatio > 0)
	{
		colideWidth = GetRatioSize().cx;
		colideHeight = GetRatioSize().cy;
	}
	else
	{
		colideWidth = (int)GetWidth();
		colideHeight = (int)GetHeight();
	}
}

//��ǰ������ѭ����������֡
void T_Sprite::LoopFrame(bool ahead)
{
	loopForward = ahead;
	if (totalFrames > 0)
	{
		if (ahead == true)
		{
			forward = forward + 1;
			if (forward > totalFrames - 1)
			{
				forward = 0;
			}
		}
		else
		{
			backward = backward - 1;
			if (backward < 0)
			{
				backward = totalFrames - 1;
			}
		}
	}
}

bool T_Sprite::LoopFrameOnce(bool ahead)
{
	loopForward = ahead;
	if (totalFrames <= 0) return true;
	if (totalFrames > 0)
	{
		if (ahead == true)
		{
			forward = forward + 1;
			if (forward > totalFrames - 1)
			{
				forward = 0;
				return true;//������һ������֡
			}
			else
			{
				return false;
			}
		}
		if (ahead == false)
		{
			backward = backward - 1;
			if (backward < 0)
			{
				backward = totalFrames - 1;
				return true;//������һ������֡
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

void T_Sprite::Draw(HDC hdc)
{
	int frmIndex = 0;
	if (frameSequence != NULL && backward >= 0 && forward >= 0)
	{
		if (loopForward == false)
			frmIndex = frameSequence[backward];
		else
			frmIndex = frameSequence[forward];
	}
	else
	{
		if (loopForward == false)
			frmIndex = backward;
		else
			frmIndex = forward;
	}

	if (&spImg != NULL)
	{
		if (Visible == true)
		{
			if (totalFrames == 0)
			{
				spImg.PaintRegion(
					spImg.GetBmpHandle(), hdc, (int)X, (int)Y,
					0, 0, Width, Height, frameRatio, frameRotate, frameAlpha
				);
			}
			else
			{
				spImg.PaintFrame(
					spImg.GetBmpHandle(), hdc, (int)X, (int)Y, frmIndex,
					frameCols, Width, Height, frameRatio, frameRotate, frameAlpha
				);
			}
		}
	}
}

bool T_Sprite::MoveTo(IN POINT mousePT, IN POINT desPT, IN RECT Boundary)
{
	//ʹ�������½�ɫλ��
	//
	//����Ƿ񵽴�Ŀ�ĵأ�ʹ�õĹؼ�������PtInRect
	//���ݽ�ɫ��ǰλ�ý���һ���������򣬼��û�����Ƿ��������
	//ע�⣬��������̫С���������ɲ���
	//��ָ����(desPT)����5������Ϊ������ȽϺ���
	//����û������������λ�ã����ʾ��ɫ�Ѿ��Ƶ���Ŀ�ĵ�
	//�������Ŀ�ĵأ����ɫͣ�ڼ������
	//
	int  xRatio, yRatio;
	if (active == true)
	{
		SIZE ratioFrameSize = GetRatioSize();	//�������ź��֡ͼ�ߴ�
		RECT HotRect;//����õľ�������(ָ��������5������Ϊ�����)
		HotRect.left = (long)(desPT.x - 5);
		HotRect.top = (long)(desPT.y - 5);
		HotRect.right = (long)(desPT.x + 5);
		HotRect.bottom = (long)(desPT.y + 5);

		// ��mousePT��desPT�����ɫ��speed�ٶ��ƶ�ʱ��X��Y������ƶ��ٶ�
		T_Util::GetBevelSpeed(desPT, mousePT, speed, xRatio, yRatio);

		BOOL ToDesPos = PtInRect(&HotRect, mousePT);

		if (ToDesPos == TRUE)
		{
			return true;
		}
		if (ToDesPos == FALSE)
		{
			// ��һ��X��Y������ƶ��ٶ�
			int nextStepX = (int)xRatio;
			int nextStepY = (int)yRatio;

			// ��ȡ��һ���ƶ�
			POINT nextPT = { (long)(GetX() + nextStepX), (long)(GetY() + nextStepY) };

			// �ж���һ���Ƿ��������߽磬�������ͣ�ڱ߽�λ��
			if (nextPT.x <= Boundary.left)
				nextStepX = Boundary.left - (int)GetX();
			if ((nextPT.x + ratioFrameSize.cx) >= Boundary.right)
				nextStepX = Boundary.right - ratioFrameSize.cx - (int)GetX();
			if (nextPT.y <= Boundary.top)
				nextStepY = Boundary.top - (int)GetY();
			if ((nextPT.y + ratioFrameSize.cy) >= Boundary.bottom)
				nextStepY = Boundary.bottom - ratioFrameSize.cy - (int)GetY();

			// ���ݼ�����ƶ�����ƶ���ɫ��λ��
			Move(nextStepX, nextStepY);

			return false;
		}
	}
	return true;
}

bool T_Sprite::MoveTo(IN POINT mousePT, IN POINT desPT, IN T_Map* map)
{
	//����Ƿ񵽴�Ŀ�ĵأ�ʹ�õĹؼ�������PtInRect
	//���ݽ�ɫ��ǰλ�ý���һ���������򣬼��û�����Ƿ��������
	//ע�⣬��������̫С���������ɲ���
	//��ָ����(desPT)����5������Ϊ������ȽϺ���
	//����û������������λ�ã����ʾ��ɫ�Ѿ��Ƶ���Ŀ�ĵ�
	//�������Ŀ�ĵأ����ɫͣ�ڼ������
	int  xRatio, yRatio;
	if (active == true)
	{
		// �������ź��֡ͼ�ߴ�
		SIZE ratioFrameSize = GetRatioSize();
		// ����õľ�������(ָ��������5������Ϊ�����)
		RECT HotRect;
		HotRect.left = (long)(desPT.x - 5);
		HotRect.top = (long)(desPT.y - 5);
		HotRect.right = (long)(desPT.x + 5);
		HotRect.bottom = (long)(desPT.y + 5);

		// ��mousePT��desPT�����ɫ��speed�ٶ��ƶ�ʱ��X��Y������ƶ��ٶ�
		T_Util::GetBevelSpeed(desPT, mousePT, speed, xRatio, yRatio);
		// �ж������Ƿ��ڼ����
		BOOL ToDesPos = PtInRect(&HotRect, mousePT);
		// ����ڼ������ʾ��ɫ�Ѿ�����Ŀ�ĵ�
		if (ToDesPos == TRUE)
		{
			return true;
		}
		// ��ɫû�е���Ŀ�ĵ�
		if (ToDesPos == FALSE)
		{
			// ��һ��X��Y������ƶ��ٶ�
			int nextStepX = (int)xRatio;
			int nextStepY = (int)yRatio;
			int x = 0;
			int y = 0;
			// ���û�к͵�ͼ�ϰ�����ײ��������ƶ�
			if (!CollideWith(map))
			{
				x = GetX();
				y = GetY();
				Move(nextStepX, nextStepY);
			}
			// ����͵�ͼ�ϰ�����ײ����λ����ײǰ��λ��
			if (CollideWith(map))
			{
				SetPosition(x, y);
			}

			return false;
		}
	}
	return true;
}

//��������жϷ���
int T_Sprite::GetDir(POINT mousePT)
{
	int dir = -1;
	POINT spNowXY = { (long)GetX(),(long)GetY() };

	//�������ź��֡ͼ�ߴ�
	SIZE ratioFrameSize = GetRatioSize();

	//���ս�ɫ�����������ο���������
	//��Ϊ���յľ������򣨸��ݽ�ɫ��ǰ��������ã�
	RECT SpriteRect;
	SpriteRect.left = (long)GetX();
	SpriteRect.top = (long)GetY();
	SpriteRect.right = (long)(GetX() + ratioFrameSize.cx);
	SpriteRect.bottom = (long)(GetY() + ratioFrameSize.cy);

	//�жϳ�������
	if (mousePT.x <= SpriteRect.left &&
		mousePT.y >= SpriteRect.top &&
		mousePT.y <= SpriteRect.bottom)
	{
		dir = DIR_LEFT;
	}
	else if (mousePT.x >= SpriteRect.right &&
		mousePT.y >= SpriteRect.top && mousePT.y <= SpriteRect.bottom)
	{
		dir = DIR_RIGHT;
	}
	else if (mousePT.y <= (SpriteRect.bottom - ratioFrameSize.cy / 2) &&
		mousePT.x > SpriteRect.left && mousePT.x < SpriteRect.right)
	{
		dir = DIR_UP;
	}
	else if (mousePT.y > (SpriteRect.bottom - ratioFrameSize.cy / 2) &&
		mousePT.x > SpriteRect.left && mousePT.x < SpriteRect.right)
	{
		dir = DIR_DOWN;
	}
	else if (mousePT.x < SpriteRect.left && mousePT.y < SpriteRect.top)
	{
		dir = DIR_LEFT_UP;
	}
	else if (mousePT.x < SpriteRect.left && mousePT.y > SpriteRect.bottom)
	{
		dir = DIR_LEFT_DOWN;
	}
	else if (mousePT.x > SpriteRect.right && mousePT.y < SpriteRect.top)
	{
		dir = DIR_RIGHT_UP;
	}
	else if (mousePT.x > SpriteRect.right && mousePT.y > SpriteRect.bottom)
	{
		dir = DIR_RIGHT_DOWN;
	}
	else
	{
		dir = -1;
	}
	return dir;
}

// ����ͼ��ײ
bool T_Sprite::CollideWith(IN T_Map* map)
{
	// �������ΪͼƬ�򲻼���ͼ��ײ
	if (map->getMapRows() == 0 && map->getMapCols() == 0)
	{
		mapBlockPT.x = -1;
		mapBlockPT.y = -1;
		return false;
	}

	// �����ͼ���ɼ����ɫ���ɼ�������ͼ��ײ
	if ((!(map->IsVisible())) || (!(this->IsVisible())))
	{
		mapBlockPT.x = -1;
		mapBlockPT.y = -1;
		return false;
	}

	// ���㵱ǰ��ͼͼ��ľ��η�Χ
	int mapLeft = map->GetX();
	int mapTop = map->GetY();
	int mapRight = mapLeft + map->GetWidth();
	int mapBottom = mapTop + map->GetHeight();

	// ��õ�ͼͼ����ʹ�õ�ͼ��Ŀ��
	int tW = map->getTileWidth();
	int tH = map->getTileHeight();

	// ���㵱ǰ��ɫ�ľ��η�Χ
	int spLeft = this->GetCollideRect()->left;
	int spTop = this->GetCollideRect()->top;
	int spRight = this->GetCollideRect()->right;
	int spBottom = this->GetCollideRect()->bottom;

	// ��õ�ǰ��ͼ��ͼ���������
	int tNumCols = map->getMapCols();
	// ��õ�ǰ��ͼ��ͼ���������
	int tNumRows = map->getMapRows();

	// ���㵱ǰ��ɫ��ʵ�ʵĿ��
	int spW = spRight - spLeft;
	int spH = spBottom - spTop;

	RECT lprcDst;
	// �������ϼ����ͼ��ľ��η�Χ�ͽ�ɫ�ľ��η�Χ�����������ζ���
	RECT mapRect = { mapLeft, mapTop, mapRight, mapBottom };
	RECT spRect = { spLeft, spTop, spRight, spBottom };
	// ����������ζ���û�з����κ���ײ�����˳�����
	if ((IntersectRect(&lprcDst, &mapRect, &spRect)) == FALSE)
	{
		mapBlockPT.x = -1;
		mapBlockPT.y = -1;
		return false;
	}

	// ����������ζ���������ײ�����ȼ����ɫ�����ϡ��¡����ҵľ�������
	int startRow = (spTop <= mapTop) ? 0 : (spTop - mapTop) / tH;
	int endRow = (spBottom < mapBottom) ? (spBottom - 1 - mapTop) / tH : tNumRows - 1;
	int startCol = (spLeft <= mapLeft) ? 0 : (spLeft - mapLeft) / tW;
	int endCol = (spRight < mapRight) ? (spRight - 1 - mapLeft) / tW : tNumCols - 1;

	// ���ݽ�ɫ�����ϡ��¡����ҵľ��������ж��ĸ���������Ϊ�ϰ�
	for (int row = startRow; row <= endRow; ++row)
	{
		for (int col = startCol; col <= endCol; ++col)
		{
			// �����ǰ�������ڵ�ͼ���ڵ�ͼ������Ϊ��0���ͱ�ʾ���ϰ�
			if (map->getTile(col, row) != 0)
			{
				mapBlockPT.x = col;	// ��¼��ǰ�ϰ�ͼ�����
				mapBlockPT.y = row;	// ��¼��ǰ�ϰ�ͼ�����

				// ���ݽ�ɫ��ǰ�ķ��������ײǰ��λ��
				int x = GetX(), y = GetY();
				switch (GetDir())
				{
				case DIR_LEFT:
					x = GetX() + GetSpeed();
					y = GetY();
					break;
				case DIR_RIGHT:
					x = GetX() - GetSpeed();
					y = GetY();
					break;
				case DIR_UP:
					x = GetX();
					y = GetY() + GetSpeed();
					break;
				case DIR_DOWN:
					x = GetX();
					y = GetY() - GetSpeed();
					break;
				}
				// ����ɫ��λ��ײǰ��λ��
				SetPosition(x, y);
				return true;
			}
		}
	}
	return false;
}