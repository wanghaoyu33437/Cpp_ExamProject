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

//����ˢ��ʱ��
#define RESOURCE_INTERVAL 10000

//��̵ļ����ʱ��
#define INTERVAL 1000
#define X_WALK_SPEED 20
#define X_RUN_SPEED 40
#define Y_WALK_SPEED 8
#define Y_RUN_SPEED 16
//�����Ծ��֡ͼ����Ҫ�̶���8֡��
#define Z_SPEED 140
#define GRAVITY 40
#define FRAME_SPEED 12
//ʳ�ﵯҩ������
#define FOOD_NUM 9
//ǹ֧������
#define WEAPON_NUM 4
#define AMMO 0
//������ȡ��Դ�ĸ���(0~10, 0->�������κν���, 10->ÿ�λ�ɱ���˶����ý���)
#define LUCKY_LEVEL 10

//�ؿ���
#define LEVEL_COUNT 2

typedef vector<T_Sprite*> vSpritSet;
typedef vector<Resource*> vResSet;
typedef vector<Npc*>  vNpcSet;

class EngineConfig : public T_Engine
{
private:

	static int FRAME_DOWN[20];
	//��ͼ����
	

	T_Menu* main;
	T_Menu* about;
	T_Menu* pause;
	T_Menu* choosePlayer;
	T_Menu* help;
	T_Menu* over;

	//����
	Player *player1 = nullptr, *player2 = nullptr;//ָ�����ʵ��
	T_Sprite *scrollSprite = nullptr;
	bool isAttacked1 = false;
	WhichPlayer who;//��ѡ��Ľ�ɫ
	bool keyValid1, keyValid2;//��������
	bool canScroll;
	bool loadPlayer2 = false;
	bool checkClear = false;
	int curPos;
	T_Scene t_scene;
	DWORD resource_interval = 0;

	vResSet resource;			//��Ʒ����
	vSpritSet player_bomb_set;	//�ڵ�����


	//ȫ�ֱ���
	POINT mouse_pt;
	int scn_width, scn_height;

	//��ҵ�Ѫ��������
	T_Graph* bloodBk;
	//Npc��Ѫ��������
	T_Graph* bloodEBk;
	//Ѫ����ɫͼƬ
	T_Graph* life;

	//�ɰ�
	T_Graph mask;

	//����Ƿ��ǹ
	bool holdGun;
	//��ҵ��ӵ�����
	int bullets;

	GunType type;
	T_Graph* gun;

	//��ǰ�Ĺؿ�
	int curLevel = 0;
	static wstring level[LEVEL_COUNT];
	T_Graph* bk[LEVEL_COUNT];
	//��˸��Ч
	DWORD startTime;
	DWORD endTime;
	bool flag;

	int last_dir1, last_dir2;

	//��ǰ�����ı�ţ�ʹ�÷��������㵱ǰ�����ƶ�������λ��
	int curStage = 0;
	static int levelStage[LEVEL_COUNT][5];

	long dTime1, dTime2;

	//�Ĵ�������
	int registerNum1;
	int registerNum2;
	int registerNum3;
	int registerNum4;
	int overStage;

	//	���ֱ���
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

	//���ܺ���
	void LoadMap();				//���ص�ͼ
	void LoadPlayer();			//������ҽ�ɫ
	void LoadMenus();			//���ز˵�
	
	bool checkBarrier(T_Sprite* sp, int nextStepX, int nextStepY, Rect stone);		//����ͼ�е�ʯͷ
	void UpdatePlayerPos();//�������λ��

	void UpdateAnimation();		//������Ϸ����
	void UpdateResources();
	void UpdateBombPos(vSpritSet* bombset);
	void UpdateBombPosBoss(vSpritSet* bombset);
	void BombCollide(T_Sprite* bomb);	//�ڵ�������
	void BombCollide_Boss(T_Sprite* bomb);
	bool check_bomb_attack_boss(Boss* boss, T_Sprite* sp);
	bool check_bomb_attack(vNpcSet* npc_set, T_Sprite* sp);
	bool check_bomb_attack_player(Player* player, T_Sprite* sp);
	void AddRandomResource(int x, int y);
	//��ʼ��Ϸ
	void GameBegin();
	void LoadBomb(T_Sprite* sp, vSpritSet& bombset, int offset, int iTime = 0);			//�ڵ�����
	void LoadMusic();	//��������
	//����Ѫ��
	void PaintBlood(HDC);
	void PaintNpcBlood(HDC hdc, Npc* npc);
	void PaintBossBlood(HDC hdc, Boss* boss);
	//��ȡָ����Χ�������
	int GetRandomNum(int start, int end)
	{
		srand(time(nullptr));
		int k = rand() % (end - start + 1) + start;
		return k;
	}
	
	//NPC���

	DWORD	myTime;				// ��ʱ����ʱ��


	int Checkpoint1 = 0;   //��һ�ط�Ϊ7���ؿ���
	int Checkpoint2 = 0;   //�ڶ��ط�Ϊ5���ؿ���
	int Checkpoint3 = 0;   //�����ط�Ϊ2���ؿ���

	void updateGate(int new_level, int new_point);
	//Npc
	//��һ��NPC
	vNpcSet c1p1_npcSet;
	vNpcSet c1p2_npcSet;
	vNpcSet c1p3_npcSet;
	vNpcSet c1p4_npcSet;
	vNpcSet c1p5_npcSet;
	vNpcSet c1p6_npcSet;
	//�ڶ���NPC
	vNpcSet c2p1_npcSet;
	vNpcSet c2p2_npcSet;
	vNpcSet c2p3_npcSet;
	vNpcSet c2p4_npcSet;

	//Boss
	Boss *boss1;
	Boss *boss2;
	Boss *boss3;
	Boss *boss4;

	//���ز�ͬ�ؿ��Ĺؿ���NPC
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
	//����Boss
	void LoadBoss1();
	void LoadBoss2();
	void LoadBoss3();
	void LoadBoss4();

	void CheckAttack();	//��⹥������

	//����ؿ�����
	void Clearpoint(int Checkpoint1, int Checkpoint2, int Checkpoint3);
	vSpritSet boss_bomb_set;	//boss�ڵ�����

	void LoadBossBomb(T_Sprite* sp, vSpritSet& bombset, int offset);	//�����ڵ�
	
	void UpdateNpcPos();		//����NPCλ��
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
	bool checkNpcClear();		//�ж��Ƿ����NPC
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

