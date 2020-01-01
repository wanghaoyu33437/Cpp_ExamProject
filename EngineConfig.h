#pragma once
#include "TinyEngine/T_Engine.h"
#include "TinyEngine/T_Scene.h"
#include "TinyEngine/T_AI.h"
#include "Player.h"
#include "Npc.h"
#include "Boss.h"
#include "Resource.h"
#include "TinyEngine/T_Menu.h"
#include "TinyEngine/T_Audio.h"

//奖励刷新时间
#define RESOURCE_INTERVAL 10000

//冲刺的检测间隔时间
#define INTERVAL 1000
#define X_WALK_SPEED 20
#define X_RUN_SPEED 40
#define Y_WALK_SPEED 8
#define Y_RUN_SPEED 16
//玩家跳跃的帧图数需要固定（8帧）
#define Z_SPEED 140
#define GRAVITY 40
#define FRAME_SPEED 12
//食物弹药种类数
#define FOOD_NUM 9
//枪支种类数
#define WEAPON_NUM 4
#define AMMO 0
//调整获取资源的概率(0~10, 0->不会获得任何奖励, 10->每次击杀敌人都会获得奖励)
#define LUCKY_LEVEL 10

//关卡数
#define LEVEL_COUNT 2

typedef vector<T_Sprite*> vSpritSet;
typedef vector<Resource*> vResSet;
typedef vector<Npc*>  vNpcSet;

class EngineConfig : public T_Engine
{
private:

	static int FRAME_DOWN[20];
	//地图变量
	

	T_Menu* main;
	T_Menu* about;
	T_Menu* pause;
	T_Menu* choosePlayer;
	T_Menu* help;
	T_Menu* over;

	//对象
	Player *player1 = nullptr, *player2 = nullptr;//指向玩家实例
	T_Sprite *scrollSprite = nullptr;
	bool isAttacked1 = false;
	WhichPlayer who;//所选择的角色
	bool keyValid1, keyValid2;//按键屏蔽
	bool canScroll;
	bool loadPlayer2 = false;
	bool checkClear = false;
	int curPos;
	T_Scene t_scene;
	DWORD resource_interval = 0;

	vResSet resource;			//物品集合
	vSpritSet player_bomb_set;	//炮弹集合


	//全局变量
	POINT mouse_pt;
	int scn_width, scn_height;

	//玩家的血条背景；
	T_Graph* bloodBk;
	//Npc的血条背景；
	T_Graph* bloodEBk;
	//血条颜色图片
	T_Graph* life;

	//蒙版
	T_Graph mask;

	//玩家是否持枪
	bool holdGun;
	//玩家的子弹数量
	int bullets;

	GunType type;
	T_Graph* gun;

	//当前的关卡
	int curLevel = 0;
	static wstring level[LEVEL_COUNT];
	T_Graph* bk[LEVEL_COUNT];
	//闪烁字效
	DWORD startTime;
	DWORD endTime;
	bool flag;

	int last_dir1, last_dir2;

	//当前场景的标号，使用分数来计算当前场景移动的限制位置
	int curStage = 0;
	static int levelStage[LEVEL_COUNT][5];

	long dTime1, dTime2;

	//寄存器变量
	int registerNum1;
	int registerNum2;
	int registerNum3;
	int registerNum4;
	int overStage;

	//	音乐变量
	AudioDX ds;
	AudioDXBuffer bk1_buffer;
	AudioDXBuffer bk2_buffer;
	AudioDXBuffer bk3_buffer;
	AudioDXBuffer box1_buffer;
	AudioDXBuffer box2_buffer;
	AudioDXBuffer gun1_buffer;
	AudioDXBuffer gun2_buffer;
	AudioDXBuffer walk_buffer;
	AudioDXBuffer mousedown_buffer;
	AudioDXBuffer mouseover_buffer;

	//功能函数
	void LoadMap();				//加载地图
	void LoadPlayer();			//加载玩家角色
	void LoadMenus();			//加载菜单
	
	bool checkBarrier(T_Sprite* sp, int nextStepX, int nextStepY, Rect stone);		//检测地图中的石头
	void UpdatePlayerPos();//更新玩家位置

	void UpdateAnimation();		//更新游戏动画
	void UpdateResources();
	void UpdateBombPos(vSpritSet* bombset);
	void UpdateBombPosBoss(vSpritSet* bombset);
	void BombCollide(T_Sprite* bomb);	//炮弹处理函数
	void BombCollide_Boss(T_Sprite* bomb);
	bool check_bomb_attack_boss(Boss* boss, T_Sprite* sp);
	bool check_bomb_attack(vNpcSet* npc_set, T_Sprite* sp);
	bool check_bomb_attack_player(Player* player, T_Sprite* sp);
	void AddRandomResource(int x, int y);
	//开始游戏
	void GameBegin();
	void LoadBomb(T_Sprite* sp, vSpritSet& bombset, int offset, int iTime = 0);			//炮弹载入
	void LoadMusic();	//加载声音
	//绘制血条
	void PaintBlood(HDC);
	void PaintNpcBlood(HDC hdc, Npc* npc);
	void PaintBossBlood(HDC hdc, Boss* boss);
	//获取指定范围的随机数
	int GetRandomNum(int start, int end)
	{
		srand(time(nullptr));
		int k = rand() % (end - start + 1) + start;
		return k;
	}
	
	//NPC相关

	DWORD	myTime;				// 计时结束时间


	int Checkpoint1 = 0;   //第一关分为7个关卡点
	int Checkpoint2 = 0;   //第二关分为5个关卡点
	int Checkpoint3 = 0;   //第三关分为2个关卡点

	void updateGate(int new_level, int new_point);
	//Npc
	//第一关NPC
	vNpcSet c1p1_npcSet;
	vNpcSet c1p2_npcSet;
	vNpcSet c1p3_npcSet;
	vNpcSet c1p4_npcSet;
	vNpcSet c1p5_npcSet;
	vNpcSet c1p6_npcSet;
	//第二关NPC
	vNpcSet c2p1_npcSet;
	vNpcSet c2p2_npcSet;
	vNpcSet c2p3_npcSet;
	vNpcSet c2p4_npcSet;

	//Boss
	Boss *boss1;
	Boss *boss2;
	Boss *boss3;
	Boss *boss4;

	//加载不同关卡的关卡点NPC
	void Loadc1p1Npc();
	void Loadc1p2Npc();
	void Loadc1p3Npc();
	void Loadc1p4Npc();
	void Loadc1p5Npc();
	void Loadc1p6Npc();
	void Loadc2p1Npc();
	void Loadc2p2Npc();
	void Loadc2p3Npc();
	void Loadc2p4Npc();
	//加载Boss
	void LoadBoss1();
	void LoadBoss2();
	void LoadBoss3();
	void LoadBoss4();

	void CheckAttack();	//检测攻击函数

	//清除关卡缓存
	void Clearpoint(int Checkpoint1, int Checkpoint2, int Checkpoint3);
	vSpritSet boss_bomb_set;	//boss炮弹集合

	void LoadBossBomb(T_Sprite* sp, vSpritSet& bombset, int offset);	//加载炮弹
	
	void UpdateNpcPos();		//更新NPC位置
	void LevelChange(HDC hdc);
public:
	EngineConfig(const HINSTANCE hInstance, const LPCTSTR szWindowClass, const LPCTSTR szTitle,
	             const WORD Icon = NULL, const WORD SmIcon = NULL,
	             const int iWidth = WIN_WIDTH, const int iHeight = WIN_HEIGHT)
		: T_Engine(hInstance, szWindowClass, szTitle, Icon, SmIcon, iWidth, iHeight){}
	~EngineConfig(){}

	void GameStartInit();
	void GameInit() override;
	void InitParams();
	bool checkScreenScroll();
	bool checkNpcClear();		//判断是否清空NPC
	bool check_npc_clear(vNpcSet* npc_set);
	bool checkPlayerAttack(vNpcSet* npc_set);
	void GameChangeInit();
	void GameLogic() override;
	void Destroy();
	void GameEnd() override;
	void paintBullets(const HDC hdc);
	void GamePaint(HDC hdc) override;
	bool checkPickItems(Player* p);
	void GameKeyAction(int ActionType = KEY_SYS_NONE) override;
	void WalkOrRun1() const;
	void WalkOrRun2() const;
	void GameMouseAction(int x, int y, int Action) override;
};

