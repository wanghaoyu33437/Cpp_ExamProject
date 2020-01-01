//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ����: 2019-11-28
// ��Ȩ���� 2007-2019 ������
// (C) 2007-2019 WanLizhong All Rights Reserved
//*******************************************************************

#include "T_Graph.h"
#include "T_Config.h"

// T_Graph��Ĭ�Ϲ��캯��
//
T_Graph::T_Graph()
{
	hBmp = NULL;
}

// T_Graph�๹�캯����ʹ��ָ�����ļ�������һ��HBITMAP����
T_Graph::T_Graph(wstring fileName)
{
	LoadImageFile(fileName);
}

// T_Graph����������
T_Graph::~T_Graph()
{
	Destroy();
}

// T_Graph���ͷ���Դ�ķ���
void T_Graph::Destroy()
{
	GdiFlush();
	if(hBmp)
	{
		DeleteObject(hBmp);
		hBmp = NULL;
	}
}

bool T_Graph::LoadImageFile(wstring path)
{
	Bitmap* pBmp = Bitmap::FromFile(path.c_str());
	if(!pBmp) return false;

	ImageWidth = pBmp->GetWidth();
	ImageHeight = pBmp->GetHeight();

	if(ImageHeight==0 || ImageWidth==0) return false;

	Status status = pBmp->GetHBITMAP(NULL, &hBmp);
	if(pBmp) 
	{
		delete pBmp;
		pBmp = NULL;
	}
	if(status == S_OK) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

HBITMAP T_Graph::CreateBlankBitmap(int width, int height, COLORREF color)
{
	BYTE* pBits = NULL;
	BITMAPINFO bmi;
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = height;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = width * height * 4;
	HBITMAP blankBmp = CreateDIBSection(NULL, &bmi, DIB_RGB_COLORS, (void **)&pBits, NULL, NULL);
	PaintBlank(blankBmp, width, height, color);
	return blankBmp;
}

////////////////////////////////////////////////////////////////////////////////////
// �ӵ�һ����ָ����HBITMAP�������ݴ���һ��Bitmap���ָ�����
////////////////////////////////////////////////////////////////////////////////////
Bitmap* T_Graph::HBITMAP_To_Bitmap(HBITMAP hbmp, HDC hdc)
{
	BITMAP bmp;
	int width, height;

	// ����λͼ�����ȡBITMAP�ṹ����������
	memset((void*)&bmp, 0, sizeof(BITMAP));
	GetObject(hbmp, sizeof(BITMAP), (void*)&bmp);
	width = bmp.bmWidth;
	height = bmp.bmHeight;
	byte* bmpBytes = (byte*)bmp.bmBits;

	if(width<=0 && height<=0) return NULL;

	// ����λͼ����½�һ��PixelFormat32bppPARGB��ʽ��Bitmap����
	Bitmap* BmpCpy = new Bitmap(width, height, PixelFormat32bppPARGB);

	// ����LockBits����Ϊλͼ�������ݿ���׼���ڴ滺����
	BitmapData bmpData;
	Rect rect(0, 0, width, height);
	BmpCpy->LockBits(&rect, ImageLockModeWrite, PixelFormat32bppPARGB, &bmpData);

	// �����λͼÿ��������������ָ��ָ������
	int lineSize = width * 4;
	byte* cpyBytes = (byte*)(bmpData.Scan0);
	// ����λͼ�ĸ����п�������������������
	for (int y = 0; y < height; y++)
	{
		memcpy((y * lineSize)+cpyBytes, 
			((height - y -1) * lineSize)+bmpBytes, 
			lineSize);
	}
	// �����ڴ滺����
	BmpCpy->UnlockBits(&bmpData);

	return BmpCpy;
}


void T_Graph::PaintImage(HDC hdc, int x, int y)
{
	//����֡ͼ���ڴ��豸
	HDC memDC = CreateCompatibleDC(hdc);
	//���հ׵�֡ͼѡ���ڴ��豸
	HBITMAP OldFrameBmp = (HBITMAP)SelectObject(memDC, hBmp);
	//����ʹ��GDI��BitBlt����,����ֱ���ڴ渴��,�ٶȽϿ�
	BitBlt(hdc, x, y, ImageWidth, ImageHeight, memDC, 0, 0, SRCCOPY);
	//��ԭ��ʹ��ԭ�������滻�ڴ��豸�е�λͼ����
	SelectObject(memDC, OldFrameBmp);
	DeleteDC(memDC);//ɾ���ڴ��豸
	DeleteObject(OldFrameBmp);//ɾ��λͼ����
}

void T_Graph::PaintImage(HDC hdc, int x, int y, int width, int height)
{
	//����ȫͼ���ڴ��豸
	HDC memDC = CreateCompatibleDC(hdc);
	//��Դͼѡ���ڴ��豸��
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(memDC, hBmp);
	SetStretchBltMode(hdc, COLORONCOLOR);
	StretchBlt(hdc, x, y, width, height, 
		       memDC, 0, 0, ImageWidth, ImageHeight, 
		       SRCCOPY);

	//ʹ��ԭ�������滻ȫͼ�ڴ��豸�е�λͼ����
	SelectObject(memDC, hOldBitmap);
	DeleteDC(memDC);//ɾ��ȫͼ�ڴ��豸
	DeleteObject(hOldBitmap);//ɾ��λͼ����
}

void T_Graph::PaintImage(HDC hdc, int x, int y, int width, int height, BYTE alpha)
{
	//����ȫͼ���ڴ��豸
	HDC memDC = CreateCompatibleDC(hdc);
	//��Դͼѡ���ڴ��豸��
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(memDC, hBmp);

	BLENDFUNCTION dc_bf;
	dc_bf.BlendOp = AC_SRC_OVER;
	dc_bf.BlendFlags = 0;
	dc_bf.SourceConstantAlpha = alpha;
	dc_bf.AlphaFormat = AC_SRC_ALPHA;

	SetStretchBltMode(hdc, COLORONCOLOR);

	AlphaBlend(hdc, x, y, width, height, 
		       memDC, 0, 0, ImageWidth, ImageHeight, 
		       dc_bf);
	//StretchBlt(hdc, x, y, width, height, 
	//			 memDC, 0, 0, ImageWidth, ImageHeight, 
	//			 SRCCOPY);

	//ʹ��ԭ�������滻ȫͼ�ڴ��豸�е�λͼ����
	SelectObject(memDC, hOldBitmap);
	DeleteDC(memDC);//ɾ��ȫͼ�ڴ��豸
	DeleteObject(hOldBitmap);//ɾ��λͼ����
}

//rotType:��ת����
void T_Graph::PaintRegion(HBITMAP in_hbitmap, HDC destDC, int destX, int destY, 
						  int srcX, int srcY, int regionWidth, int regionHeight,
						  float ratio, int rotType, BYTE alpha)  
{
	int width = (int)(regionWidth*ratio);
	int height = (int)(regionHeight*ratio);

	BYTE* pBits = NULL;
	BITMAPINFO bmi;
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = height;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32; 
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = width * height * 4;

	HDC frameDC = ::CreateCompatibleDC(NULL);
	HBITMAP hbitmap = CreateDIBSection(NULL, &bmi, DIB_RGB_COLORS, (void **)&pBits, NULL, NULL);
	HBITMAP OldFrameBmp = (HBITMAP)SelectObject(frameDC, hbitmap);

	HDC memDC = CreateCompatibleDC(destDC);
	HBITMAP OldMemBmp = (HBITMAP)SelectObject(memDC, in_hbitmap);

	BLENDFUNCTION frame_bf;
	frame_bf.BlendOp = AC_SRC_OVER;
	frame_bf.BlendFlags = 0;
	frame_bf.SourceConstantAlpha = 255;
	frame_bf.AlphaFormat = AC_SRC_ALPHA;
	AlphaBlend(frameDC, 0, 0, (int)(regionWidth*ratio), (int)(regionHeight*ratio), 
		       memDC, srcX, srcY, regionWidth, regionHeight, frame_bf);

	Bitmap* nowFrameBmp =HBITMAP_To_Bitmap(hbitmap, destDC);

	//��ԭ��ʹ��ԭ�������滻�ڴ��豸�е�λͼ����
	SelectObject(frameDC, OldFrameBmp);
	DeleteDC(frameDC);//ɾ���ڴ��豸
	DeleteObject(OldFrameBmp);//ɾ��λͼ����
	OldFrameBmp = NULL;
	DeleteObject(hbitmap);//ɾ��λͼ����
	hbitmap = NULL;

	//��ԭ��ʹ��ԭ�������滻�ڴ��豸�е�λͼ����
	SelectObject(memDC, OldMemBmp);
	DeleteDC(memDC);//ɾ���ڴ��豸
	DeleteObject(OldMemBmp);//ɾ��λͼ����
	OldMemBmp = NULL;

	//��ת֡ͼ
	switch(rotType)
	{
	case TRANS_NONE:
		break;
	case TRANS_NOFLIP_ROT90:
		nowFrameBmp->RotateFlip(Rotate90FlipNone);
		width = (int)(regionHeight*ratio);
		height = (int)(regionWidth*ratio);
		break;
	case TRANS_NOFLIP_ROT180:
		nowFrameBmp->RotateFlip(Rotate180FlipNone);
		width = (int)(regionWidth*ratio);
		height = (int)(regionHeight*ratio);
		break;
	case TRANS_NOFLIP_ROT270:
		nowFrameBmp->RotateFlip(Rotate270FlipNone);
		width = (int)(regionHeight*ratio);
		height = (int)(regionWidth*ratio);
		break;
	case TRANS_VFLIP_NOROT:
		nowFrameBmp->RotateFlip(RotateNoneFlipY);
		width = (int)(regionWidth*ratio);
		height = (int)(regionHeight*ratio);
		break;
	case TRANS_VFLIP_ROT90:
		nowFrameBmp->RotateFlip(Rotate90FlipY);
		width = (int)(regionHeight*ratio);
		height = (int)(regionWidth*ratio);
		break;
	case TRANS_VFLIP_ROT180:
		nowFrameBmp->RotateFlip(Rotate180FlipY);
		width = (int)(regionWidth*ratio);
		height = (int)(regionHeight*ratio);
		break;
	case TRANS_VFLIP_ROT270:
		nowFrameBmp->RotateFlip(Rotate270FlipY);
		width = (int)(regionHeight*ratio);
		height = (int)(regionWidth*ratio);
		break;
	case TRANS_HFLIP_NOROT:
		nowFrameBmp->RotateFlip(RotateNoneFlipX);
		width = (int)(regionWidth*ratio);
		height = (int)(regionHeight*ratio);
		break;
	case TRANS_HFLIP_ROT90:
		nowFrameBmp->RotateFlip(Rotate90FlipX);
		width = (int)(regionHeight*ratio);
		height = (int)(regionWidth*ratio);
		break;
	case TRANS_HFLIP_ROT180:
		nowFrameBmp->RotateFlip(Rotate180FlipX);
		width = (int)(regionWidth*ratio);
		height = (int)(regionHeight*ratio);
		break;
	case TRANS_HFLIP_ROT270:
		nowFrameBmp->RotateFlip(Rotate270FlipX);
		width = (int)(regionHeight*ratio);
		height = (int)(regionWidth*ratio);
		break;
	}
	
	HBITMAP hbmp = NULL;
	nowFrameBmp->GetHBITMAP(NULL, &hbmp );
	HDC bufDC = CreateCompatibleDC(destDC);
	HBITMAP OldbufBmp = (HBITMAP)SelectObject( bufDC, hbmp);

	BLENDFUNCTION buf_bf;
	buf_bf.BlendOp = AC_SRC_OVER;
	buf_bf.BlendFlags = 0;
	buf_bf.SourceConstantAlpha = alpha;
	buf_bf.AlphaFormat = AC_SRC_ALPHA;
	AlphaBlend(destDC, destX, destY, width, height, 
		       bufDC, 0, 0, width, height, buf_bf);

	//��ԭ��ʹ��ԭ�������滻�ڴ��豸�е�λͼ����
	SelectObject(bufDC, OldbufBmp);
	DeleteDC(bufDC);//ɾ���ڴ��豸
	DeleteObject(OldbufBmp);//ɾ��λͼ����
	OldbufBmp = NULL;
	DeleteObject(hbmp);//ɾ��λͼ����
	hbmp = NULL;
	DeleteObject(nowFrameBmp);//ɾ��λͼ����
	delete nowFrameBmp;//ɾ��λͼ����
	nowFrameBmp = NULL;
}

void T_Graph::PaintFrame( HBITMAP in_hbitmap, HDC destDC, int destX, int destY, 
						  int FrameCount, int RowFrames, int wFrame, int hFrame,
						  float ratio, int rotType, BYTE alpha)
{

	int col=FrameCount%RowFrames;
	int row = (FrameCount-col)/RowFrames;
	PaintRegion(in_hbitmap, destDC, destX, destY, 
		        col*wFrame, row*hFrame, wFrame, hFrame, 
				ratio, rotType, alpha);
}

void T_Graph::PaintBlank(HDC hdc, int x, int y, int width, int height, Color crColor)
{
	Gdiplus::Graphics g(hdc);
	Rect rectangle(x, y, width, height);
	SolidBrush solidBrush( crColor );
	g.FillRectangle( &solidBrush, rectangle );
	g.ReleaseHDC(hdc);
}

void T_Graph::PaintBlank(HDC hdc, int x, int y, int width, int height, COLORREF crColor, int alpLevel)
{
	HBITMAP hbitmap = CreateCompatibleBitmap(hdc, width, height);
	HDC memdc = ::CreateCompatibleDC(NULL);
	HBITMAP OldBmp = (HBITMAP)SelectObject(memdc, hbitmap);

	HBRUSH hBrush = CreateSolidBrush(crColor);
	RECT rcBitmap = { x, y, width, height };
	FillRect(memdc, &rcBitmap, hBrush);

	BLENDFUNCTION frame_bf;
	frame_bf.BlendOp = AC_SRC_OVER;
	frame_bf.BlendFlags = 0;
	frame_bf.SourceConstantAlpha = alpLevel;
	frame_bf.AlphaFormat = 0;
	AlphaBlend(hdc, x, y, width, height, memdc, 0, 0, width, height, frame_bf);
	
	// �ָ��ڴ��豸�е�λͼ����
	SelectObject(memdc, OldBmp);
	// ɾ���ڴ��豸
	DeleteDC(memdc);
	// ɾ��λͼ����
	DeleteObject(OldBmp);
	// �ͷž��
	OldBmp = NULL;
	// ɾ��λͼ����
	DeleteObject(hbitmap);
	// �ͷž��
	hbitmap = NULL;
	// ɾ����ˢ
	DeleteObject(hBrush);
}

void T_Graph::PaintBlank(HBITMAP hbmp, int width, int height, COLORREF crColor)
{
	HDC memdc = ::CreateCompatibleDC(NULL);
	HBITMAP OldBmp = (HBITMAP)SelectObject(memdc, hbmp);

	HBRUSH hBrush = CreateSolidBrush(crColor);
	RECT rcBitmap = {0, 0, width, height};
	FillRect(memdc, &rcBitmap, hBrush);
	
	// �ָ��ڴ��豸�е�λͼ����
	SelectObject(memdc, OldBmp);
	// ɾ���ڴ��豸
	DeleteDC(memdc);
	// ɾ��λͼ����
	DeleteObject(OldBmp);
	// �ͷž��
	OldBmp = NULL;
	// ɾ����ˢ
	DeleteObject(hBrush);
}

void T_Graph::PaintText(HDC hdc, RectF fontRect, wstring text, REAL fontSize,
						wstring fontName, Color fontColor, FontStyle style, 
						StringAlignment align)
{
	//ʹ��GDI�������л���
	Graphics graph(hdc);
	FontFamily fontFamily(fontName.c_str());
	Font font(&fontFamily, fontSize, style, UnitPoint);

	StringFormat format;
	format.SetLineAlignment(StringAlignmentCenter);
	format.SetAlignment(align);
	SolidBrush  solidBrush1(fontColor);

	graph.SetTextRenderingHint(TextRenderingHintAntiAlias);
	graph.DrawString(text.c_str(), (INT)wcslen(text.c_str()), &font, fontRect, &format, &solidBrush1);
	graph.ReleaseHDC(hdc);
}