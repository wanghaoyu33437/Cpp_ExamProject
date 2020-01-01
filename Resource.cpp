#include "Resource.h"

Resource::Resource(wstring path, int fWidth, int fHeight, float r)
{
	ratio = r;
	setImg(path, fWidth, fHeight);
	index = 0;
	X = 0;
	Y = 0;
	type = NORES;
	reward = 0;
	dead = false;
}

Resource::Resource(wstring path, float ratio)
{
	new (this)Resource(path, 0, 0, ratio);
}



Resource::~Resource()
{
}

void Resource::Draw(HDC hdc)
{
	if (hasFrames) {
		img->PaintFrame(
			img->GetBmpHandle(), hdc, GetX(), GetY(), (index % rows) * frameWidth,
			(index / rows) * frameHeight, Width, Height, ratio, TRANS_NONE, 255);
		index = (++index) % frames;
	}
	else {
		img->PaintRegion(
			img->GetBmpHandle(), hdc, GetX(), GetY(),
			0, 0, Width, Height, ratio, TRANS_NONE, 255);
	}
}

void Resource::setImg(wstring path, int fWidth, int fHeight)
{
	img = new T_Graph(path);
	setImg(img, fWidth, fHeight);
}

void Resource::setImg(T_Graph* i, int fWidth, int fHeight)
{
	img = i;
	frameWidth = fWidth;
	frameHeight = fHeight;
	Width = img->GetImageWidth();
	Height = img->GetImageHeight();

	if (frameWidth == 0 && frameHeight == 0) {
		hasFrames = false;
		ratioWidth = ROUND(ratio * Width);
		ratioHeight = ROUND(ratio * Height);
		cols = 0;
		rows = 0;
		frames = 0;
	}
	else {
		hasFrames = true;
		ratioWidth = ROUND(ratio * frameWidth);
		ratioHeight = ROUND(ratio * frameHeight);
		cols = Width / frameWidth;
		rows = Height / frameHeight;
		frames = cols * rows;
	}
}
