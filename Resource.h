#pragma once
#include ".\\TinyEngine\\T_Layer.h"
#include ".\\TinyEngine\\T_Graph.h"
#include "GameInit.h"

#define ROUND(x) (int)(x+0.5)

class Resource :
	public T_Layer
{
private:
	//资源的一些属性
	ResourceType type;
	int reward;
	bool dead;
	int ratioWidth;
	int ratioHeight;
	int frameHeight;
	int frameWidth;
	float ratio;
	bool hasFrames;
	T_Graph* img;
	int rows;
	int cols;
	int frames;
	int index;

public:
	Resource(wstring, int, int, float r = 1.0);
	Resource(wstring, float r = 1.0);
	~Resource();
	virtual string ClassName() { return "Resource"; }
	void Draw(HDC hdc);

	void setImg(wstring, int, int);

	void setImg(T_Graph*, int, int);

	float getRatio() {
		return ratio;
	}

	void setRatio(float r) {
		ratio = r;
		if (frameWidth == 0 && frameHeight == 0) {
			ratioWidth = ROUND(ratio * Width);
			ratioHeight = ROUND(ratio * Height);
		}
		else {
			ratioWidth = ROUND(ratio * frameWidth);
			ratioHeight = ROUND(ratio * frameHeight);
		}
	}

	int getRatioWidth() {
		return ratioWidth;
	}

	int getRatioHeight() {
		return ratioHeight;
	}

	ResourceType getType() {
		return type;
	}
	void setType(ResourceType t) {
		type = t;
	}
	int getReward() {
		return reward;
	}
	void setReward(int r) {
		reward = r;
	}
	bool isDead() {
		return dead;
	}
	void setDead(bool d) {
		dead = d;
	}
};

