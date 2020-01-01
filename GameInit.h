#pragma once
#define PlayerStateCount 16
#define NpcStateCount 6

typedef vector<T_Graph*> vFrameSet;

//两个障碍物
const Rect stone1 = { 1948,140,880,10 };
const Rect stone2 = { 3448,128,800,10 };

const int map1[] = { 0,928,1952,2976,4000,4770,5984 };
const int map2[] = { 0,1100,2200,3300,4550 };



//存储zgl所需使用到的所有序列的图片
const LPCTSTR ZyPaths[] = {
	L".\\res\\zy\\zy-stand-185-186.png",
	L".\\res\\zy\\zy-walk-185-186.png",
	L".\\res\\zy\\zy-run-206-186.png",
	L".\\res\\zy\\zy-jump-193-186.png",
	L".\\res\\zy\\zy-stand-185-186.png",//get
	L".\\res\\zy\\zy-box-234-186.png",//box
	L".\\res\\zy\\zy-box3-254-186.png",//boxsuccess
	L".\\res\\zy\\zy-death-185-186.png",//death
	L".\\res\\zy\\zy-behit-185-186.png",
	L".\\res\\zy\\zy-behit-185-186.png",
	L".\\res\\zy\\zy-stand-185-186.png",

};//对应zy各种动作所需帧长宽
const int ZyParams[][2] = {
{185,186},
	{185,186},
	{206,186},
	{193,186},
	{206,186},//get
	{233,186},
	{254,186},//box1
	{185,186},//death
	{185,186},
	{185,186},
	{185,186}

};




const wstring bonus[] = {
	L".\\res\\FoodAndGun\\food1.png",
	L".\\res\\FoodAndGun\\food2.png",
	L".\\res\\FoodAndGun\\zhouzi.png",
	L".\\res\\FoodAndGun\\jitui.png",
	L".\\res\\FoodAndGun\\food1.png",
	L".\\res\\FoodAndGun\\jitui.png",
	L".\\res\\FoodAndGun\\apple.png",
	L".\\res\\FoodAndGun\\apple.png",
	L".\\res\\FoodAndGun\\jitui.png"
};

const int bonusParams[][2] = {
	{ 48, 30 },
	{ 45, 25 },
	{ 45, 25 },
	{ 66, 36 },
	{ 48, 18 },
	{ 66, 36 },
	{ 13, 14 },
	{ 13, 14 },
	{ 66, 36 }
};

const wstring guns[] = {
	L".\\res\\FoodAndGun\\ak.png",
	L".\\res\\FoodAndGun\\98k.png",
	L".\\res\\FoodAndGun\\s686.png",
	L".\\res\\FoodAndGun\\uzi.png"
};

const int gunParams[][2] = {
	{ 72, 18 },
	{ 74, 14 },
	{ 56, 12 },
	{ 41, 15 }
};

enum GunType {
	AK,
	KAR98K,
	S686,
	UZI,
	NOGUN
};

enum ResourceType {
	FOOD1,
	FOOD2,
	LOBSTER,
	COFFEE,
	HAMBURGER,
	CHOCOLATE,
	SANDWICH,
	APPLE,
	BULLETS,
	NORES
};

enum PlayerState {
	STAND,
	WALK,
	RUN,
	JUMP,
	PICK,
	BOX1,
	BOX2,
	DEATH,
	FRONTHIT,
	BACKHIT,
	RESTAND,
	NONE
};

enum WhichPlayer {
	Jack,
	Luan,
	zy
};

//NPC血量图片
const wstring NpcBloodBk[] = {
	L".\\res\\blood\\npc1.png",
	L".\\res\\blood\\npc2.png",
	L".\\res\\blood\\npc4.png",
	L".\\res\\blood\\npc5.png",
	L".\\res\\blood\\boss1.png",
	L".\\res\\blood\\boss2.png",
	L".\\res\\blood\\boss3.png",
	L".\\res\\blood\\boss4.png"
};


//NPC
enum WhichNpc {
	Npc1,
	Npc2,
	Npc3,
	Npc4,
	Npc5
};

enum NpcState {
	nWALK,
	nATTACK1,
	nATTACK2,
	nHINT,
	nDEATH,
	nRESTAND
};

//NPC1-盾牌士兵
const LPCTSTR npc1Paths[] = {
	L".\\res\\NPC\\NPC1-1\\NPC1-1-walk-85-75.png",
	L".\\res\\NPC\\NPC1-1\\NPC1-1-attack1-240-64.png",
	L".\\res\\NPC\\NPC1-1\\NPC1-1-attack2-240-78.png",
	L".\\res\\NPC\\NPC1-1\\NPC1-1-hint-54-84.png",
	L".\\res\\NPC\\NPC1-1\\NPC1-1-death-108-56.png",
	L".\\res\\NPC\\NPC1-1\\NPC1-1-restand-42-83.png"
};
const int npc1Params[][2] = {
	{ 85,75 },
	{ 80,64 },
	{ 56,78 },
	{ 54,84 },
	{ 108,56 },
	{ 42,83 }
};

//NPC2-斧头士兵
const LPCTSTR npc2Paths[] = {
	L".\\res\\NPC\\NPC1-2\\NPC1-2-walk-85-77.png",
	L".\\res\\NPC\\NPC1-2\\NPC1-2-attack1-133-73.png",
	L".\\res\\NPC\\NPC1-2\\NPC1-2-attack1-133-73.png",
	L".\\res\\NPC\\NPC1-2\\NPC1-2-hint-53-79.png",
	L".\\res\\NPC\\NPC1-2\\NPC1-2-death-106-53.png",
	L".\\res\\NPC\\NPC1-2\\NPC1-2-restand-53-90.png"
};
const int npc2Params[][2] = {
	{ 85,77 },
	{ 133,73 },
	{ 133,73 },
	{ 53,79 },
	{ 106,53 },
	{ 53,90 }
};

//NPC3-墩子
const LPCTSTR npc3Paths[] = {
	L".\\res\\NPC\\NPC2-1\\dino-walk-80.5-92.png",
	L".\\res\\NPC\\NPC2-1\\dino-attack-100-87.png",
	L".\\res\\NPC\\NPC2-1\\dino-attack-100-87.png",
	L".\\res\\NPC\\NPC2-1\\dino-hint-59-91.png",
	L".\\res\\NPC\\NPC2-1\\dino-death-101-67.png",
	L".\\res\\NPC\\NPC2-1\\dino-hint-59-91.png",
};
const int npc3Params[][2] = {
	{ 80.5,92 },
	{ 100,87 },
	{ 100,87 },
	{ 59,91 },
	{ 101,67 },
	{ 59,91 }
};

//NPC4-斧头马
const LPCTSTR npc4Paths[] = {
	L".\\res\\NPC\\NPC2-2\\NPC2-2-walk-160-118.png",
	L".\\res\\NPC\\NPC2-2\\NPC2-2-attack1-200-159.png",
	L".\\res\\NPC\\NPC2-2\\NPC2-2-attack1-200-159.png",
	L".\\res\\NPC\\NPC2-2\\NPC2-2-hint-131-160.png",
	L".\\res\\NPC\\NPC2-2\\NPC2-2-death-115-107.png",
	L".\\res\\NPC\\NPC2-2\\NPC2-2-hint-153-164.png",
};
const int npc4Params[][2] = {
	{ 160,118 },
	{ 200,159 },
	{ 200,159 },
	{ 131,160 },
	{ 115,107 },
	{ 131,160 }
};

//NPC5-红腰胖刀
const LPCTSTR npc5Paths[] = {
	L".\\res\\NPC\\NPC3-1\\npc3-walk-120-93.png",
	L".\\res\\NPC\\NPC3-1\\npc3-attack1-132.5-168.png",
	L".\\res\\NPC\\NPC3-1\\npc3-attack1-132.5-168.png",
	L".\\res\\NPC\\NPC3-1\\npc3-hint-102-100.png",
	L".\\res\\NPC\\NPC3-1\\npc3-death-129-88.png",
	L".\\res\\NPC\\NPC3-1\\npc3-hint-102-100.png",
};
const int npc5Params[][2] = {
	{ 120,93 },
	{ 132.5,168 },
	{ 132.5,168 },
	{ 102,100 },
	{ 129,88 },
	{ 102,100 }
};

//Boss
enum WhichBoss {
	Boss1,
	Boss2,
	Boss3,
	Boss4
};
enum BossState {
	bWALK,
	bATTACK1,
	bATTACK2,
	bATTACK3,
	bHINT,
	bDEATH,
	bRESTAND
};
//Boss1
const LPCTSTR boss1Paths[] = {
	L".\\res\\NPC\\boss1\\boss1-walk-118-105.png",
	L".\\res\\NPC\\boss1\\boss1-attack3-160-111.png",
	L".\\res\\NPC\\boss1\\boss1-attack3-160-111.png",
	L".\\res\\NPC\\boss1\\boss1-attack1-160-120.png",
	L".\\res\\NPC\\boss1\\boss1-hint-53-104.png",
	L".\\res\\NPC\\boss1\\boss1-getDown-139-72.png",
	L".\\res\\NPC\\boss1\\boss1-restand-92-92.png"
};
const int boss1Params[][2] = {
	{ 118,105 },
	{ 160,111 },
	{ 160,111 },
	{ 160,120 },
	{ 53,104 },
	{ 139,72 },
	{ 92,92 }
};

//Boss2
const LPCTSTR boss2Paths[] = {
	L".\\res\\NPC\\boss2\\boss2-walk-152.5-84.png",
	L".\\res\\NPC\\boss2\\boss2-attack1-160-69.png",
	L".\\res\\NPC\\boss2\\boss2-attack2-207-120.png",
	L".\\res\\NPC\\boss2\\boss2-attack2-207-120.png",
	L".\\res\\NPC\\boss2\\boss2-hint-98-88.png",
	L".\\res\\NPC\\boss2\\boss2-getDown-160-91.png",
	L".\\res\\NPC\\boss2\\boss2-restand-114-83.png"
};
const int boss2Params[][2] = {
	{ 152.5,84 },
	{ 160,69 },
	{ 207,120 },
	{ 207,120 },
	{ 98,88 },
	{ 160,91 },
	{ 114,83 }
};

//Boss3
const LPCTSTR boss3Paths[] = {
	L".\\res\\NPC\\boss3\\boss3-walk_1-107.6-90.png",
	L".\\res\\NPC\\boss3\\boss3-attack1_2-160-91.png",
	L".\\res\\NPC\\boss3\\boss3-attack1_2-160-91.png",
	L".\\res\\NPC\\boss3\\boss3-attack1_1-86-91.png",
	L".\\res\\NPC\\boss3\\boss3-hint_1-68-89.png",
	L".\\res\\NPC\\boss3\\boss3-getDown_1-120-45.png",
	L".\\res\\NPC\\boss3\\boss3-change-200-91.png"
};
const int boss3Params[][2] = {
	{ 107.6,90 },
	{ 160,91 },
	{ 160,91 },
	{ 86,91 },
	{ 68,89 },
	{ 120,45 },
	{ 200,91 }
};

//Boss4
const LPCTSTR boss4Paths[] = {
	L".\\res\\NPC\\boss4\\boss3-walk_2-177-60.png",
	L".\\res\\NPC\\boss4\\boss3-attack2_1-224-108.png",
	L".\\res\\NPC\\boss4\\boss3-attack2_2-224-108.png",
	L".\\res\\NPC\\boss4\\boss3-attack2_2-224-108.png",
	L".\\res\\NPC\\boss4\\boss3-hint_2-141-74.png",
	L".\\res\\NPC\\boss4\\boss3-death_2-145-65.png",
	L".\\res\\NPC\\boss4\\boss3-restand_2-143-6.png"
};
const int boss4Params[][2] = {
	{ 177,60 },
	{ 224,108 },
	{ 224,108 },
	{ 224,108 },
	{ 141,74 },
	{ 145,65 },
	{ 143,63 }
};


const wstring actor[][4] = {
	{
		L".\\res\\over\\actor-Jack-66-103.png",
		L".\\res\\over\\jack-over-72-72.png",
		L".\\res\\over\\words1Jack.png",
		L".\\res\\over\\words2Jack.png"
	},
	{
		L".\\res\\over\\actor-Luan-68-95.png",
		L".\\res\\over\\Luan-over-72-72.png",
		L".\\res\\over\\words1Luan.png",
		L".\\res\\over\\words2Luan.png"
	},

		{
		L".\\res\\over\\zy-actor-204-200.png",
		L".\\res\\over\\zy-over.jpg",
		L".\\res\\over\\words1Luan.png",
		L".\\res\\over\\words2Luan.png"
	},
};

const int actorParams[][4][2] = {
	{
		{ 66, 103 },
		{ 72, 72 }
	},
	{
		{ 68, 95 },
		{ 72, 72 }
	},
	{
		{ 204, 200 },
		{ 72, 72 }
	},

};

const LPCTSTR members[] = {
	L".\\res\\Members\\yxc.png",
	L".\\res\\Members\\why.jpg"
};

const LPCTSTR intros[] = {
	L"伊显纯（组长)\n1710班\n8002117392\n总体架构\n菜单模块开发\n部分玩家模块开发\nNpcAI及碰撞检测开发",
	L"王浩宇\n1706班\n8002117234\n玩家模块开发\n代码整合\n整体调试\nNpc模块开发\n代码整合"
};