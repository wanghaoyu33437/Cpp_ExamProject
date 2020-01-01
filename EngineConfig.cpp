#include "EngineConfig.h"
#include "GameInit.h"
#include "iostream"

bool a = false;
static EngineConfig* pGame;

int WINAPI WinMain(const HINSTANCE h_instance, HINSTANCE hPrevInsatnce,
	PSTR szCmdLine, int iCmdShow) {
	pGame = new EngineConfig(h_instance, L"GameDemo", L"EngineDemo", NULL, NULL, 1024, 768);
	EngineConfig::pEngine = pGame;

	pGame->SetFrame(10);
	pGame->SetFullScreen(false);

	pGame->StartEngine();
	return TRUE;
}


//加载第一关第一关卡
//加载第一关第一关卡
void EngineConfig::Loadc1p1Npc()
{
	GAMELAYER gameLayer;
	SPRITEINFO spInfo;
	Npc* npc = new Npc(Npc2, nWALK);
	int Lbarrier = 0;

	spInfo.Active = false;
	spInfo.Alpha = 220;
	spInfo.Dead = false;
	spInfo.Dir = DIR_UP;
	spInfo.Level = 0;
	spInfo.Ratio = 3.0f;
	spInfo.Rotation = TRANS_NONE;
	spInfo.Score = 0;
	spInfo.Speed = 18 + rand() % 10;
	spInfo.Visible = true;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	npc->Initiate(spInfo);
	c1p1_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	//npc = new Npc(Npc2, nWALK);
	//spInfo.Speed = 18 + rand() % 10;
	//spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	//spInfo.Y = 300 + 150 * (rand() % 2);
	//npc->Initiate(spInfo);
	//c1p1_npcSet.push_back(npc);
	//npc->SetLayerTypeID(LAYER_NPC);
	//gameLayer.layer = npc;
	//gameLayer.type_id = LAYER_NPC;
	//gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	//gameLayer.layer->setZorder(gameLayer.z_order);
	//t_scene.Append(gameLayer);

	//npc = new Npc(Npc1, nWALK);
	//spInfo.Speed = 18 + rand() % 10;
	//spInfo.Ratio = 3.0f;
	//spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	//spInfo.Y = 300 + 150 * (rand() % 2);
	//npc->Initiate(spInfo);
	//c1p1_npcSet.push_back(npc);
	//npc->SetLayerTypeID(LAYER_NPC);
	//gameLayer.layer = npc;
	//gameLayer.type_id = LAYER_NPC;
	//gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	//gameLayer.layer->setZorder(gameLayer.z_order);
	//t_scene.Append(gameLayer);

	npc = new Npc(Npc2, nWALK);
	spInfo.Speed = 18 + rand() % 10;
	spInfo.Ratio = 3.0f;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	npc->Initiate(spInfo);
	c1p1_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	//测试代码
	/*GAMELAYER gameLayer1;
	SPRITEINFO spInfo1;
	boss1 = new Boss(Boss1, bWALK);

	spInfo1.Active = false;
	spInfo1.Alpha = 220;
	spInfo1.Dead = false;
	spInfo1.Dir = DIR_UP;
	spInfo1.Level = 0;
	spInfo1.Ratio = 3.0f;
	spInfo1.Rotation = TRANS_NONE;
	spInfo1.Score = 0;
	spInfo1.Speed = 30;
	spInfo1.Visible = true;
	spInfo1.X = 500;
	spInfo1.Y = 400;
	boss1->Initiate(spInfo1);
	boss1->SetLayerTypeID(LAYER_NPC);
	gameLayer1.layer = boss1;
	gameLayer1.type_id = LAYER_NPC;
	gameLayer1.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer1.layer->setZorder(gameLayer1.z_order);
	t_scene.Append(gameLayer1);*/
}
void EngineConfig::Loadc1p2Npc()
{
	GAMELAYER gameLayer;
	SPRITEINFO spInfo;
	Npc* npc = new Npc(Npc4, nWALK);
	int Lbarrier = 0;

	spInfo.Active = false;
	spInfo.Alpha = 220;
	spInfo.Dead = false;
	spInfo.Dir = DIR_UP;
	spInfo.Level = 0;
	spInfo.Ratio = 3.0f;
	spInfo.Rotation = TRANS_NONE;
	spInfo.Score = 0;
	spInfo.Speed = 18 + rand() % 10;
	spInfo.Visible = true;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	npc->Initiate(spInfo);
	c1p2_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	//npc = new Npc(Npc1, nWALK);
	//spInfo.Speed = 18 + rand() % 10;
	//spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	//spInfo.Y = 300 + 150 * (rand() % 2);
	//npc->Initiate(spInfo);
	//c1p2_npcSet.push_back(npc);
	//npc->SetLayerTypeID(LAYER_NPC);
	//gameLayer.layer = npc;
	//gameLayer.type_id = LAYER_NPC;
	//gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	//gameLayer.layer->setZorder(gameLayer.z_order);
	//t_scene.Append(gameLayer);

	//npc = new Npc(Npc1, nWALK);
	//spInfo.Speed = 18 + rand() % 10;
	//spInfo.Ratio = 3.0f;
	//spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	//spInfo.Y = 300 + 150 * (rand() % 2);
	//npc->Initiate(spInfo);
	//c1p2_npcSet.push_back(npc);
	//npc->SetLayerTypeID(LAYER_NPC);
	//gameLayer.layer = npc;
	//gameLayer.type_id = LAYER_NPC;
	//gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	//gameLayer.layer->setZorder(gameLayer.z_order);
	//t_scene.Append(gameLayer);

	npc = new Npc(Npc2, nWALK);
	spInfo.Speed = 18 + rand() % 10;
	spInfo.Ratio = 3.0f;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	npc->Initiate(spInfo);
	c1p2_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

}
void EngineConfig::Loadc1p3Npc()
{
	GAMELAYER gameLayer;
	SPRITEINFO spInfo;
	Npc* npc = new Npc(Npc3, nWALK);
	int Lbarrier = 0;

	spInfo.Active = false;
	spInfo.Alpha = 220;
	spInfo.Dead = false;
	spInfo.Dir = DIR_UP;
	spInfo.Level = 0;
	spInfo.Ratio = 3.0f;
	spInfo.Rotation = TRANS_NONE;
	spInfo.Score = 0;
	spInfo.Speed = 18 + rand() % 10;
	spInfo.Visible = true;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 350 + 50 * (rand() % 2);
	npc->Initiate(spInfo);
	c1p3_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc4, nWALK);
	spInfo.Speed = 18 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 350 + 50 * (rand() % 2);
	spInfo.Ratio = 2.5f;
	npc->Initiate(spInfo);
	c1p3_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);
}
void EngineConfig::Loadc1p4Npc()
{
	GAMELAYER gameLayer;
	SPRITEINFO spInfo;
	Npc* npc = new Npc(Npc5, nWALK);
	int Lbarrier = 0;

	spInfo.Active = false;
	spInfo.Alpha = 220;
	spInfo.Dead = false;
	spInfo.Dir = DIR_UP;
	spInfo.Level = 0;
	spInfo.Ratio = 2.2f;
	spInfo.Rotation = TRANS_NONE;
	spInfo.Score = 0;
	spInfo.Speed = 18 + rand() % 10;
	spInfo.Visible = true;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 350 + 100 * (rand() % 2);
	npc->Initiate(spInfo);
	c1p4_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc2, nWALK);
	spInfo.Speed = 18 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 3.0f;
	npc->Initiate(spInfo);
	c1p4_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc2, nWALK);
	spInfo.Speed = 18 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 3.0f;
	npc->Initiate(spInfo);
	c1p4_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);
}
void EngineConfig::Loadc1p5Npc()
{
	GAMELAYER gameLayer;
	SPRITEINFO spInfo;
	Npc* npc = new Npc(Npc5, nWALK);
	int Lbarrier = 0;

	spInfo.Active = false;
	spInfo.Alpha = 220;
	spInfo.Dead = false;
	spInfo.Dir = DIR_UP;
	spInfo.Level = 0;
	spInfo.Ratio = 2.5f;
	spInfo.Rotation = TRANS_NONE;
	spInfo.Score = 0;
	spInfo.Speed = 18 + rand() % 10;
	spInfo.Visible = true;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 350 + 100 * (rand() % 2);
	npc->Initiate(spInfo);
	c1p5_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc3, nWALK);
	spInfo.Speed = 18 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 3.0f;
	npc->Initiate(spInfo);
	c1p5_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc4, nWALK);
	spInfo.Speed = 18 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 3.0f;
	npc->Initiate(spInfo);
	c1p5_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);
}
void EngineConfig::Loadc1p6Npc()
{
	GAMELAYER gameLayer;
	SPRITEINFO spInfo;
	Npc* npc = new Npc(Npc5, nWALK);
	int Lbarrier = 0;

	spInfo.Active = false;
	spInfo.Alpha = 220;
	spInfo.Dead = false;
	spInfo.Dir = DIR_UP;
	spInfo.Level = 0;
	spInfo.Ratio = 2.5f;
	spInfo.Rotation = TRANS_NONE;
	spInfo.Score = 0;
	spInfo.Speed = 18 + rand() % 10;
	spInfo.Visible = true;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 350 + 100 * (rand() % 2);
	npc->Initiate(spInfo);
	c1p6_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	//npc = new Npc(Npc5, nWALK);
	//spInfo.Speed = 18 + rand() % 10;
	//spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	//spInfo.Y = 300 + 150 * (rand() % 2);
	//spInfo.Ratio = 2.5f;
	//npc->Initiate(spInfo);
	//c1p6_npcSet.push_back(npc);
	//npc->SetLayerTypeID(LAYER_NPC);
	//gameLayer.layer = npc;
	//gameLayer.type_id = LAYER_NPC;
	//gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	//gameLayer.layer->setZorder(gameLayer.z_order);
	//t_scene.Append(gameLayer);

	//npc = new Npc(Npc2, nWALK);
	//spInfo.Speed = 18 + rand() % 10;
	//spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	//spInfo.Y = 300 + 150 * (rand() % 2);
	//spInfo.Ratio = 3.0f;
	//npc->Initiate(spInfo);
	//c1p6_npcSet.push_back(npc);
	//npc->SetLayerTypeID(LAYER_NPC);
	//gameLayer.layer = npc;
	//gameLayer.type_id = LAYER_NPC;
	//gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	//gameLayer.layer->setZorder(gameLayer.z_order);
	//t_scene.Append(gameLayer);

	//npc = new Npc(Npc2, nWALK);
	//spInfo.Speed = 18 + rand() % 10;
	//spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	//spInfo.Y = 300 + 150 * (rand() % 2);
	//spInfo.Ratio = 3.0f;
	//npc->Initiate(spInfo);
	//c1p6_npcSet.push_back(npc);
	//npc->SetLayerTypeID(LAYER_NPC);
	//gameLayer.layer = npc;
	//gameLayer.type_id = LAYER_NPC;
	//gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	//gameLayer.layer->setZorder(gameLayer.z_order);
	//t_scene.Append(gameLayer);
}
void EngineConfig::Loadc2p1Npc()
{
	GAMELAYER gameLayer;
	SPRITEINFO spInfo;
	Npc* npc = new Npc(Npc3, nWALK);
	int Lbarrier = 0;

	spInfo.Active = false;
	spInfo.Alpha = 220;
	spInfo.Dead = false;
	spInfo.Dir = DIR_UP;
	spInfo.Level = 0;
	spInfo.Ratio = 3.0f;
	spInfo.Rotation = TRANS_NONE;
	spInfo.Score = 0;
	spInfo.Speed = 22 + rand() % 10;
	spInfo.Visible = true;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 350 + 100 * (rand() % 2);
	npc->Initiate(spInfo);
	c2p1_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc5, nWALK);
	spInfo.Speed = 22 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 2.5f;
	npc->Initiate(spInfo);
	c2p1_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc3, nWALK);
	spInfo.Speed = 22 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 3.0f;
	npc->Initiate(spInfo);
	c2p1_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc4, nWALK);
	spInfo.Speed = 22 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 2.2f;
	npc->Initiate(spInfo);
	c2p1_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);
}
void EngineConfig::Loadc2p2Npc()
{
	GAMELAYER gameLayer;
	SPRITEINFO spInfo;
	Npc* npc = new Npc(Npc4, nWALK);
	int Lbarrier = 0;

	spInfo.Active = false;
	spInfo.Alpha = 220;
	spInfo.Dead = false;
	spInfo.Dir = DIR_UP;
	spInfo.Level = 0;
	spInfo.Ratio = 2.2f;
	spInfo.Rotation = TRANS_NONE;
	spInfo.Score = 0;
	spInfo.Speed = 22 + rand() % 10;
	spInfo.Visible = true;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 350 + 100 * (rand() % 2);
	npc->Initiate(spInfo);
	c2p2_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc4, nWALK);
	spInfo.Speed = 22 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 2.2f;
	npc->Initiate(spInfo);
	c2p2_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc4, nWALK);
	spInfo.Speed = 22 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 2.2f;
	npc->Initiate(spInfo);
	c2p2_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);
}
void EngineConfig::Loadc2p3Npc()
{
	GAMELAYER gameLayer;
	SPRITEINFO spInfo;
	Npc* npc = new Npc(Npc3, nWALK);
	int Lbarrier = 0;

	spInfo.Active = false;
	spInfo.Alpha = 220;
	spInfo.Dead = false;
	spInfo.Dir = DIR_UP;
	spInfo.Level = 0;
	spInfo.Ratio = 3.0f;
	spInfo.Rotation = TRANS_NONE;
	spInfo.Score = 0;
	spInfo.Speed = 22 + rand() % 10;
	spInfo.Visible = true;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 350 + 100 * (rand() % 2);
	npc->Initiate(spInfo);
	c2p3_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc3, nWALK);
	spInfo.Speed = 22 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 3.0f;
	npc->Initiate(spInfo);
	c2p3_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc3, nWALK);
	spInfo.Speed = 22 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 3.0f;
	npc->Initiate(spInfo);
	c2p3_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);
}
void EngineConfig::Loadc2p4Npc()
{
	GAMELAYER gameLayer;
	SPRITEINFO spInfo;
	Npc* npc = new Npc(Npc3, nWALK);
	int Lbarrier = 0;

	spInfo.Active = false;
	spInfo.Alpha = 220;
	spInfo.Dead = false;
	spInfo.Dir = DIR_UP;
	spInfo.Level = 0;
	spInfo.Ratio = 3.0f;
	spInfo.Rotation = TRANS_NONE;
	spInfo.Score = 0;
	spInfo.Speed = 22 + rand() % 10;
	spInfo.Visible = true;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 350 + 100 * (rand() % 2);
	npc->Initiate(spInfo);
	c2p4_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc4, nWALK);
	spInfo.Speed = 22 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 2.2f;
	npc->Initiate(spInfo);
	c2p4_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc4, nWALK);
	spInfo.Speed = 22 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 2.2f;
	npc->Initiate(spInfo);
	c2p4_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);

	npc = new Npc(Npc3, nWALK);
	spInfo.Speed = 22 + rand() % 10;
	spInfo.X = -300 + Lbarrier + (1504 * (rand() % 2));
	spInfo.Y = 300 + 150 * (rand() % 2);
	spInfo.Ratio = 3.0f;
	npc->Initiate(spInfo);
	c2p4_npcSet.push_back(npc);
	npc->SetLayerTypeID(LAYER_NPC);
	gameLayer.layer = npc;
	gameLayer.type_id = LAYER_NPC;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);
}
//加载Boss1
void EngineConfig::LoadBoss1()
{
	GAMELAYER gameLayer1;
	SPRITEINFO spInfo1;
	boss1 = new Boss(Boss1, bWALK);

	spInfo1.Active = false;
	spInfo1.Alpha = 220;
	spInfo1.Dead = false;
	spInfo1.Dir = DIR_LEFT;
	spInfo1.Level = 0;
	spInfo1.Ratio = 1.5f;
	spInfo1.Rotation = TRANS_NONE;
	spInfo1.Score = 0;
	spInfo1.Speed = 30;
	spInfo1.Visible = true;
	spInfo1.X = 500;
	spInfo1.Y = 400;
	boss1->Initiate(spInfo1);
	boss1->SetLayerTypeID(LAYER_NPC);
	gameLayer1.layer = boss1;
	gameLayer1.type_id = LAYER_NPC;
	gameLayer1.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer1.layer->setZorder(gameLayer1.z_order);
	t_scene.Append(gameLayer1);
}
//加载Boss1
void EngineConfig::LoadBoss2()
{
	GAMELAYER gameLayer1;
	SPRITEINFO spInfo1;
	boss2 = new Boss(Boss2, bWALK);

	spInfo1.Active = false;
	spInfo1.Alpha = 220;
	spInfo1.Dead = false;
	spInfo1.Dir = DIR_UP;
	spInfo1.Level = 0;
	spInfo1.Ratio = 3.0f;
	spInfo1.Rotation = TRANS_NONE;
	spInfo1.Score = 0;
	spInfo1.Speed = 30;
	spInfo1.Visible = true;
	spInfo1.X = 500;
	spInfo1.Y = 400;
	boss2->Initiate(spInfo1);
	boss2->SetLayerTypeID(LAYER_NPC);
	gameLayer1.layer = boss2;
	gameLayer1.type_id = LAYER_NPC;
	gameLayer1.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer1.layer->setZorder(gameLayer1.z_order);
	t_scene.Append(gameLayer1);
}
//加载Boss3
void EngineConfig::LoadBoss3()
{
	GAMELAYER gameLayer1;
	SPRITEINFO spInfo1;
	boss3 = new Boss(Boss3, bWALK);

	spInfo1.Active = false;
	spInfo1.Alpha = 220;
	spInfo1.Dead = false;
	spInfo1.Dir = DIR_UP;
	spInfo1.Level = 0;
	spInfo1.Ratio = 2.0f;
	spInfo1.Rotation = TRANS_NONE;
	spInfo1.Score = 0;
	spInfo1.Speed = 30;
	spInfo1.Visible = true;
	spInfo1.X = 500;
	spInfo1.Y = 400;
	boss3->Initiate(spInfo1);
	boss3->SetLayerTypeID(LAYER_NPC);
	gameLayer1.layer = boss3;
	gameLayer1.type_id = LAYER_NPC;
	gameLayer1.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer1.layer->setZorder(gameLayer1.z_order);
	t_scene.Append(gameLayer1);
}
//加载Boss4
void EngineConfig::LoadBoss4()
{
	GAMELAYER gameLayer1;
	SPRITEINFO spInfo1;
	boss4 = new Boss(Boss4, bWALK);

	spInfo1.Active = false;
	spInfo1.Alpha = 200;
	spInfo1.Dead = false;
	spInfo1.Dir = DIR_UP;
	spInfo1.Level = 0;
	spInfo1.Ratio = 3.0f;
	spInfo1.Rotation = TRANS_NONE;
	spInfo1.Score = 0;
	spInfo1.Speed = 30;
	spInfo1.Visible = true;
	spInfo1.X = 500;
	spInfo1.Y = 400;
	boss4->Initiate(spInfo1);
	boss4->SetLayerTypeID(LAYER_NPC);
	gameLayer1.layer = boss4;
	gameLayer1.type_id = LAYER_NPC;
	gameLayer1.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer1.layer->setZorder(gameLayer1.z_order);
	t_scene.Append(gameLayer1);
}


//清理关卡缓存
void EngineConfig::Clearpoint(int Checkpoint1, int Checkpoint2, int Checkpoint3)
{
	vector<Npc*> x;
	if (Checkpoint1 == 1) {
		vNpcSet::iterator e = c1p1_npcSet.begin();
		for (; e != c1p1_npcSet.end();)
		{
			SCENE_LAYERS::iterator lp;
			for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
			{
				if ((*lp).layer == (*e))
				{
					lp = t_scene.getSceneLayers()->erase(lp);
					break;
				}
			}
			delete (*e);
			e = c1p1_npcSet.erase(e);
		}
		c1p1_npcSet.clear();			c1p1_npcSet.swap(x);
	}
	else if (Checkpoint1 == 2) {
		vNpcSet::iterator e = c1p2_npcSet.begin();
		for (; e != c1p2_npcSet.end();)
		{
			SCENE_LAYERS::iterator lp;
			for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
			{
				if ((*lp).layer == (*e))
				{
					lp = t_scene.getSceneLayers()->erase(lp);
					break;
				}
			}
			delete (*e);
			e = c1p2_npcSet.erase(e);
		}
		c1p2_npcSet.clear();			c1p2_npcSet.swap(x);
	}
	else if (Checkpoint1 == 3) {
		vNpcSet::iterator e = c1p3_npcSet.begin();
		for (; e != c1p3_npcSet.end();)
		{
			SCENE_LAYERS::iterator lp;
			for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
			{
				if ((*lp).layer == (*e))
				{
					lp = t_scene.getSceneLayers()->erase(lp);
					break;
				}
			}
			delete (*e);
			e = c1p3_npcSet.erase(e);
		}
		c1p3_npcSet.clear();			c1p3_npcSet.swap(x);
	}
	else if (Checkpoint1 == 4) {
		vNpcSet::iterator e = c1p4_npcSet.begin();
		for (; e != c1p4_npcSet.end();)
		{
			SCENE_LAYERS::iterator lp;
			for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
			{
				if ((*lp).layer == (*e))
				{
					lp = t_scene.getSceneLayers()->erase(lp);
					break;
				}
			}
			delete (*e);
			e = c1p4_npcSet.erase(e);
		}
		c1p4_npcSet.clear();			c1p4_npcSet.swap(x);
	}
	else if (Checkpoint1 == 5) {
		vNpcSet::iterator e = c1p5_npcSet.begin();
		for (; e != c1p5_npcSet.end();)
		{
			SCENE_LAYERS::iterator lp;
			for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
			{
				if ((*lp).layer == (*e))
				{
					lp = t_scene.getSceneLayers()->erase(lp);
					break;
				}
			}
			delete (*e);
			e = c1p5_npcSet.erase(e);
		}
		c1p5_npcSet.clear();			c1p5_npcSet.swap(x);
	}
	else if (Checkpoint1 == 6) {
		vNpcSet::iterator e = c1p6_npcSet.begin();
		for (; e != c1p6_npcSet.end();)
		{
			SCENE_LAYERS::iterator lp;
			for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
			{
				if ((*lp).layer == (*e))
				{
					lp = t_scene.getSceneLayers()->erase(lp);
					break;
				}
			}
			delete (*e);
			e = c1p6_npcSet.erase(e);
		}
		c1p6_npcSet.clear();			c1p6_npcSet.swap(x);
	}
	else if (Checkpoint1 == 7) {
		SCENE_LAYERS::iterator lp;
		for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
		{
			if ((*lp).layer == (boss1))
			{
				lp = t_scene.getSceneLayers()->erase(lp);
				break;
			}
		}
//		if (boss1 != nullptr)
//		{
//			delete boss1;
//			boss1 = NULL;
//		}
	}
	else if (Checkpoint2 == 1) {
		vNpcSet::iterator e = c2p1_npcSet.begin();
		for (; e != c2p1_npcSet.end();)
		{
			SCENE_LAYERS::iterator lp;
			for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
			{
				if ((*lp).layer == (*e))
				{
					lp = t_scene.getSceneLayers()->erase(lp);
					break;
				}
			}
			delete (*e);
			e = c2p1_npcSet.erase(e);
		}
		c2p1_npcSet.clear();			c2p1_npcSet.swap(x);
	}
	else if (Checkpoint2 == 2) {
		vNpcSet::iterator e = c2p2_npcSet.begin();
		for (; e != c2p2_npcSet.end();)
		{
			SCENE_LAYERS::iterator lp;
			for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
			{
				if ((*lp).layer == (*e))
				{
					lp = t_scene.getSceneLayers()->erase(lp);
					break;
				}
			}
			delete (*e);
			e = c2p2_npcSet.erase(e);
		}
		c2p2_npcSet.clear();			c2p2_npcSet.swap(x);
	}
	else if (Checkpoint2 == 3) {
		vNpcSet::iterator e = c2p3_npcSet.begin();
		for (; e != c2p3_npcSet.end();)
		{
			SCENE_LAYERS::iterator lp;
			for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
			{
				if ((*lp).layer == (*e))
				{
					lp = t_scene.getSceneLayers()->erase(lp);
					break;
				}
			}
			delete (*e);
			e = c2p3_npcSet.erase(e);
		}
		c2p3_npcSet.clear();			c2p3_npcSet.swap(x);
	}
	else if (Checkpoint2 == 4) {
		vNpcSet::iterator e = c2p4_npcSet.begin();
		for (; e != c2p4_npcSet.end();)
		{
			SCENE_LAYERS::iterator lp;
			for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
			{
				if ((*lp).layer == (*e))
				{
					lp = t_scene.getSceneLayers()->erase(lp);
					break;
				}
			}
			delete (*e);
			e = c2p4_npcSet.erase(e);
		}
		c2p4_npcSet.clear();			c2p4_npcSet.swap(x);
	}
	else if (Checkpoint2 == 5) {
		SCENE_LAYERS::iterator lp;
		for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
		{
			if ((*lp).layer == (boss2))
			{
				lp = t_scene.getSceneLayers()->erase(lp);
				break;
			}
		}
//		if (boss2 != nullptr)
//		{
//			delete boss2;
//			boss2 = NULL;
//		}
	}
	else if (Checkpoint3 == 1) {
		SCENE_LAYERS::iterator lp;
		for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
		{
			if ((*lp).layer == (boss3))
			{
				lp = t_scene.getSceneLayers()->erase(lp);
				break;
			}
		}
//		if (boss3 != nullptr)
//		{
//			delete boss3;
//			boss3 = NULL;
//		}
	}
	else if (Checkpoint3 == 2) {
		SCENE_LAYERS::iterator lp;
		for (lp = t_scene.getSceneLayers()->begin(); lp != t_scene.getSceneLayers()->end(); lp++)
		{
			if ((*lp).layer == (boss4))
			{
				lp = t_scene.getSceneLayers()->erase(lp);
				break;
			}
		}
//		if (boss4 != nullptr)
//		{
//			delete boss4;
//			boss4 = NULL;
//		}
	}
}

//更新关卡
void EngineConfig::updateGate(int new_level, int new_point) {
	curLevel = new_level;
	if (curLevel == 1 && new_point == 1)
	{
		Checkpoint1 = new_point;
		Loadc1p1Npc();
	}
	else if (curLevel == 1 && new_point == 2)
	{
		Checkpoint1 = new_point;
		Loadc1p2Npc();
		cout << c1p2_npcSet.back()->GetX() <<  c1p2_npcSet.back()->GetY() << endl;
		Clearpoint(1, 0, 0);
	}
	else if (curLevel == 1 && new_point == 3)
	{
		Checkpoint1 = new_point;
		Loadc1p3Npc();
		cout << c1p3_npcSet.back()->GetX() << c1p3_npcSet.back()->GetY() << endl;
		Clearpoint(2, 0, 0);
	}
	else if (curLevel == 1 && new_point == 4)
	{
		Checkpoint1 = new_point;
		Loadc1p4Npc();
		cout << c1p4_npcSet.back()->GetX() << c1p4_npcSet.back()->GetY() << endl;
		Clearpoint(3, 0, 0);
	}
	else if (curLevel == 1 && new_point == 5)
	{
		Checkpoint1 = new_point;
		Loadc1p5Npc();
		Clearpoint(4, 0, 0);
	}
	else if (curLevel == 1 && new_point == 6)
	{
		Checkpoint1 = new_point;
		Loadc1p6Npc();
		Clearpoint(5, 0, 0);
	}
	else if (curLevel == 1 && new_point == 7)
	{
		Checkpoint1 = new_point;
		LoadBoss1();
		Clearpoint(6, 0, 0);
	}

	//*************************
	else if (curLevel == 2 && new_point == 1)
	{
		Checkpoint2 = new_point;
		Loadc2p1Npc();
		Clearpoint(7, 0, 0);
	}
	else if (curLevel == 2 && new_point == 2)
	{
		Checkpoint2 = new_point;
		Loadc2p2Npc();
		Clearpoint(0, 1, 0);
	}
	else if (curLevel == 2 && new_point == 3)
	{
		Checkpoint2 = new_point;
		Loadc2p3Npc();
		Clearpoint(0, 2, 0);
	}
	else if (curLevel == 2 && new_point == 4)
	{
		Checkpoint2 = new_point;
		Loadc2p4Npc();
		Clearpoint(0, 3, 0);
	}
	else if (curLevel == 2 && new_point == 5)
	{
		Checkpoint2 = new_point;
		LoadBoss2();
		Clearpoint(0, 4, 0);
	}
	else if (curLevel == 3 && new_point == 1)
	{
		Checkpoint3 = new_point;
		LoadBoss3();
		Clearpoint(0, 5, 0);
	}
	else if (curLevel == 3 && new_point == 2)
	{
		Checkpoint3 = new_point;
		LoadBoss4();
		Clearpoint(0, 0, 1);
	}
	else if (curLevel == 3 && new_point == 999)
	{
		Checkpoint3 = new_point;
		LoadBoss1();
		LoadBoss2();
		LoadBoss3();
		LoadBoss4();
	}
}
//检测攻击
void EngineConfig::CheckAttack() {
	//第一关第一关卡攻击检测
	if (curLevel == 1 && Checkpoint1 == 1)
	{
		for (vNpcSet::iterator p = c1p1_npcSet.begin(); p != c1p1_npcSet.end(); ++p)
		{
			if (player1->playerAttack(*p) && (*p)->getState() != nDEATH) {
				(*p)->setState(nHINT);
				(*p)->subBlood(1);
				if (player1->getState() == BOX2) {
					if (player1->GetRotation() == TRANS_NONE) (*p)->Move(30, 0);
					else (*p)->Move(-30, 0);
				}
			}
			if ((*p)->npcAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
			{
				player1->subBlood(1);
				keyValid1 = true;
				if ((*p)->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
				{
					player1->setState(BACKHIT);
				}
				else if (player1->getState() != FRONTHIT)
				{
					player1->setState(FRONTHIT);
				}
			}
		}

	}
	//第一关第二关卡攻击检测
	if (curLevel == 1 && Checkpoint1 == 2)
	{
		for (vNpcSet::iterator p = c1p2_npcSet.begin(); p != c1p2_npcSet.end(); ++p)
		{
			if (player1->playerAttack(*p) && (*p)->getState() != nDEATH) {
				(*p)->setState(nHINT);
				(*p)->subBlood(1);
				if (player1->getState() == BOX2) {
					if (player1->GetRotation() == TRANS_NONE) (*p)->Move(30, 0);
					else (*p)->Move(-30, 0);
				}
			}
			if ((*p)->npcAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
			{
				player1->subBlood(1);
				keyValid1 = true;
				if ((*p)->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
				{
					player1->setState(BACKHIT);
				}
				else if (player1->getState() != FRONTHIT)
				{
					player1->setState(FRONTHIT);
				}
			}
		}

	}
	//第一关第三关卡攻击检测
	if (curLevel == 1 && Checkpoint1 == 3)
	{
		for (vNpcSet::iterator p = c1p3_npcSet.begin(); p != c1p3_npcSet.end(); ++p)
		{
			if (player1->playerAttack(*p) && (*p)->getState() != nDEATH) {
				(*p)->setState(nHINT);
				(*p)->subBlood(1);
				if (player1->getState() == BOX2) {
					if (player1->GetRotation() == TRANS_NONE) (*p)->Move(30, 0);
					else (*p)->Move(-30, 0);
				}
			}
			if ((*p)->npcAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
			{
				player1->subBlood(1);
				keyValid1 = true;
				if ((*p)->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
				{
					player1->setState(BACKHIT);
				}
				else if (player1->getState() != FRONTHIT)
				{
					player1->setState(FRONTHIT);
				}
			}
		}

	}
	//第一关第四关卡攻击检测
	if (curLevel == 1 && Checkpoint1 == 4)
	{
		for (vNpcSet::iterator p = c1p4_npcSet.begin(); p != c1p4_npcSet.end(); ++p)
		{
			if (player1->playerAttack(*p) && (*p)->getState() != nDEATH) {
				(*p)->setState(nHINT);
				(*p)->subBlood(1);
				keyValid1 = true;
				if (player1->getState() == BOX2) {
					if (player1->GetRotation() == TRANS_NONE) (*p)->Move(30, 0);
					else (*p)->Move(-30, 0);
				}
			}
			if ((*p)->npcAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
			{
				player1->subBlood(1);
				keyValid1 = true;
				if ((*p)->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
				{
					player1->setState(BACKHIT);
				}
				else if (player1->getState() != FRONTHIT)
				{
					player1->setState(FRONTHIT);
				}
			}
		}
	}
	//第一关第五关卡攻击检测
	if (curLevel == 1 && Checkpoint1 == 5)
	{
		for (vNpcSet::iterator p = c1p5_npcSet.begin(); p != c1p5_npcSet.end(); ++p)
		{
			if (player1->playerAttack(*p) && (*p)->getState() != nDEATH) {
				(*p)->setState(nHINT);
				(*p)->subBlood(1);
				if (player1->getState() == BOX2) {
					if (player1->GetRotation() == TRANS_NONE) (*p)->Move(30, 0);
					else (*p)->Move(-30, 0);
				}
			}
			if ((*p)->npcAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
			{
				player1->subBlood(1);
				keyValid1 = true;
				if ((*p)->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
				{
					player1->setState(BACKHIT);
				}
				else if (player1->getState() != FRONTHIT)
				{
					player1->setState(FRONTHIT);
				}
			}
		}
	}
	//第一关第六关卡攻击检测
	if (curLevel == 1 && Checkpoint1 == 6)
	{
		for (vNpcSet::iterator p = c1p6_npcSet.begin(); p != c1p6_npcSet.end(); ++p)
		{
			if (player1->playerAttack(*p) && (*p)->getState() != nDEATH) {
				(*p)->setState(nHINT);
				(*p)->subBlood(1);
				if (player1->getState() == BOX2) {
					if (player1->GetRotation() == TRANS_NONE) (*p)->Move(30, 0);
					else (*p)->Move(-30, 0);
				}
			}
			if ((*p)->npcAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
			{
				player1->subBlood(1);
				keyValid1 = true;
				if ((*p)->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
				{
					player1->setState(BACKHIT);
				}
				else if (player1->getState() != FRONTHIT)
				{
					player1->setState(FRONTHIT);
				}
			}
		}
	}
	//第一关第七关卡攻击检测
	if (curLevel == 1 && Checkpoint1 == 7)
	{
		if (player1->playerAttack(boss1) && (boss1)->getState() != bDEATH) {
			(boss1)->setState(bHINT);
			(boss1)->subBlood(3);
			if (player1->getState() == BOX2) {
				if (player1->GetRotation() == TRANS_NONE) (boss1)->Move(60, 0);
				else (boss1)->Move(-60, 0);
			}
			if (boss1->bossAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
			{
				player1->subBlood(1);
				keyValid1 = true;
				if (boss1->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
				{
					player1->setState(BACKHIT);
				}
				else if (player1->getState() != FRONTHIT)
				{
					player1->setState(FRONTHIT);
				}
			}
		}
	}
	//第二关第一关卡攻击检测
	if (curLevel == 2 && Checkpoint2 == 1)
	{
		for (vNpcSet::iterator p = c2p1_npcSet.begin(); p != c2p1_npcSet.end(); ++p)
		{
			if (player1->playerAttack(*p) && (*p)->getState() != nDEATH) {
				(*p)->setState(nHINT);
				(*p)->subBlood(1);
				if (player1->getState() == BOX2) {
					if (player1->GetRotation() == TRANS_NONE) (*p)->Move(30, 0);
					else (*p)->Move(-30, 0);
				}
			}
			if ((*p)->npcAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
			{
				player1->subBlood(1);
				keyValid1 = true;
				if ((*p)->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
				{
					player1->setState(BACKHIT);
				}
				else if (player1->getState() != FRONTHIT)
				{
					player1->setState(FRONTHIT);
				}
			}
		}
	}
	//第二关第二关卡攻击检测
	if (curLevel == 2 && Checkpoint2 == 2)
	{
		for (vNpcSet::iterator p = c2p2_npcSet.begin(); p != c2p2_npcSet.end(); ++p)
		{
			if (player1->playerAttack(*p) && (*p)->getState() != nDEATH) {
				(*p)->setState(nHINT);
				(*p)->subBlood(1);
				if (player1->getState() == BOX2) {
					if (player1->GetRotation() == TRANS_NONE) (*p)->Move(30, 0);
					else (*p)->Move(-30, 0);
				}
			}
			if ((*p)->npcAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
			{
				player1->subBlood(1);
				keyValid1 = true;
				if ((*p)->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
				{
					player1->setState(BACKHIT);
				}
				else if (player1->getState() != FRONTHIT)
				{
					player1->setState(FRONTHIT);
				}
			}
		}
	}
	//第二关第三关卡攻击检测
	if (curLevel == 2 && Checkpoint2 == 3)
	{
		for (vNpcSet::iterator p = c2p3_npcSet.begin(); p != c2p3_npcSet.end(); ++p)
		{
			if (player1->playerAttack(*p) && (*p)->getState() != nDEATH) {
				(*p)->setState(nHINT);
				(*p)->subBlood(1);
				if (player1->getState() == BOX2) {
					if (player1->GetRotation() == TRANS_NONE) (*p)->Move(30, 0);
					else (*p)->Move(-30, 0);
				}
			}
			if ((*p)->npcAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
			{
				player1->subBlood(1);
				keyValid1 = true;
				if ((*p)->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
				{
					player1->setState(BACKHIT);
				}
				else if (player1->getState() != FRONTHIT)
				{
					player1->setState(FRONTHIT);
				}
			}
		}
	}
	//第二关第四关卡攻击检测
	if (curLevel == 2 && Checkpoint2 == 4)
	{
		for (vNpcSet::iterator p = c2p4_npcSet.begin(); p != c2p4_npcSet.end(); ++p)
		{
			if (player1->playerAttack(*p) && (*p)->getState() != nDEATH) {
				(*p)->setState(nHINT);
				(*p)->subBlood(1);
				if (player1->getState() == BOX2) {
					if (player1->GetRotation() == TRANS_NONE) (*p)->Move(30, 0);
					else (*p)->Move(-30, 0);
				}
			}
			if ((*p)->npcAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
			{
				player1->subBlood(1);
				keyValid1 = true;
				if ((*p)->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
				{
					player1->setState(BACKHIT);
				}
				else if (player1->getState() != FRONTHIT)
				{
					player1->setState(FRONTHIT);
				}
			}
		}
	}
	//第二关第五关卡攻击检测
	if (curLevel == 2 && Checkpoint2 == 5)
	{
		if (player1->playerAttack(boss2) && (boss2)->getState() != bDEATH) {
			(boss2)->setState(bHINT);
			(boss2)->subBlood(3);
			if (player1->getState() == BOX2) {
				if (player1->GetRotation() == TRANS_NONE) (boss2)->Move(60, 0);
				else (boss2)->Move(-60, 0);
			}
		}
		if (boss2->bossAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
		{
			player1->subBlood(1);
			keyValid1 = true;
			if (boss2->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
			{
				player1->setState(BACKHIT);
			}
			else if (player1->getState() != FRONTHIT)
			{
				player1->setState(FRONTHIT);
			}
		}
	}
	//第三关第一关卡攻击检测
	if (curLevel == 3 && Checkpoint3 == 1)
	{
		if (player1->playerAttack(boss3) && (boss3)->getState() != bDEATH) {
			(boss3)->setState(bHINT);
			(boss3)->subBlood(10);
			if (player1->getState() == BOX2) {
				if (player1->GetRotation() == TRANS_NONE) (boss3)->Move(60, 0);
				else (boss3)->Move(-60, 0);
			}
		}
		if (boss3->bossAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
		{
			player1->subBlood(1);
			keyValid1 = true;
			if (boss3->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
			{
				player1->setState(BACKHIT);
			}
			else if (player1->getState() != FRONTHIT)
			{
				player1->setState(FRONTHIT);
			}
		}
	}
	//第三关第二关卡攻击检测
	if (curLevel == 3 && Checkpoint3 == 2)
	{
		if (player1->playerAttack(boss4) && (boss4)->getState() != bDEATH) {
			(boss4)->setState(bHINT);
			(boss4)->subBlood(3);
			if (player1->getState() == BOX2) {
				if (player1->GetRotation() == TRANS_NONE) (boss4)->Move(60, 0);
				else (boss4)->Move(-60, 0);
			}
		}
		if (boss4->bossAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
		{
			player1->subBlood(1);
			keyValid1 = true;
			if (boss4->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
			{
				player1->setState(BACKHIT);
			}
			else if (player1->getState() != FRONTHIT)
			{
				player1->setState(FRONTHIT);
			}
		}
	}
	//大乱斗模式攻击检测
	if (curLevel == 3 && Checkpoint3 == 999)
	{
		if (player1->playerAttack(boss1) && (boss1)->getState() != bDEATH) {
			(boss1)->setState(bHINT);
			(boss1)->subBlood(3);
			if (player1->getState() == BOX2) {
				if (player1->GetRotation() == TRANS_NONE) (boss1)->Move(60, 0);
				else (boss1)->Move(-60, 0);
			}
		}
		if (player1->playerAttack(boss2) && (boss2)->getState() != bDEATH) {
			(boss2)->setState(bHINT);
			(boss2)->subBlood(3);
			if (player1->getState() == BOX2) {
				if (player1->GetRotation() == TRANS_NONE) (boss2)->Move(60, 0);
				else (boss2)->Move(-60, 0);
			}
		}
		if (player1->playerAttack(boss3) && (boss3)->getState() != bDEATH) {
			(boss3)->setState(bHINT);
			(boss3)->subBlood(3);
			if (player1->getState() == BOX2) {
				if (player1->GetRotation() == TRANS_NONE) (boss3)->Move(60, 0);
				else (boss3)->Move(-60, 0);
			}
		}
		if (player1->playerAttack(boss4) && (boss4)->getState() != bDEATH) {
			(boss4)->setState(bHINT);
			(boss4)->subBlood(3);
			if (player1->getState() == BOX2) {
				if (player1->GetRotation() == TRANS_NONE) (boss4)->Move(60, 0);
				else (boss4)->Move(-60, 0);
			}
		}

		if (boss1->bossAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
		{
			player1->subBlood(1);
			keyValid1 = true;
			if (boss1->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
			{
				player1->setState(BACKHIT);
			}
			else if (player1->getState() != FRONTHIT)
			{
				player1->setState(FRONTHIT);
			}
		}
		if (boss2->bossAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
		{
			player1->subBlood(1);
			keyValid1 = true;
			if (boss2->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
			{
				player1->setState(BACKHIT);
			}
			else if (player1->getState() != FRONTHIT)
			{
				player1->setState(FRONTHIT);
			}
		}
		if (boss3->bossAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
		{
			player1->subBlood(1);
			keyValid1 = true;
			if (boss3->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
			{
				player1->setState(BACKHIT);
			}
			else if (player1->getState() != FRONTHIT)
			{
				player1->setState(FRONTHIT);
			}
		}
		if (boss4->bossAttack(player1) && !player1->IsDead() && !player1->IsInvincible())
		{
			player1->subBlood(1);
			keyValid1 = true;
			if (boss4->GetRotation() == player1->GetRotation() && player1->getState() != BACKHIT)
			{
				player1->setState(BACKHIT);
			}
			else if (player1->getState() != FRONTHIT)
			{
				player1->setState(FRONTHIT);
			}
		}
	}
}
//更新NPC位置
void EngineConfig::UpdateNpcPos()
{
	//构造AI对象
	T_AI *spAi = new T_AI(4);

	//第一关第一关卡
	if (curLevel == 1 && Checkpoint1 == 1)
	{
		if (c1p1_npcSet.size()>0) {
			int npc_method;
			for (vNpcSet::iterator p = c1p1_npcSet.begin(); p != c1p1_npcSet.end(); ++p)
			{
				//随机npc行为
				npc_method = rand() % 5;
				if (npc_method == 0) spAi->Chase(*p, player1); //小概率追踪
				else spAi->Roam(*p, player1, 0, 1024);  //大概率漫游
			}
		}
	}
	//第一关第二关卡
	if (curLevel == 1 && Checkpoint1 == 2)
	{
		if (c1p2_npcSet.size()>0) {
			int npc_method;
			for (vNpcSet::iterator p = c1p2_npcSet.begin(); p != c1p2_npcSet.end(); ++p)
			{
				//随机npc行为
				npc_method = rand() % 5;
				if (npc_method == 0) spAi->Chase(*p, player1); //小概率追踪
				else spAi->Roam(*p, player1, 928, 1952);  //大概率漫游
			}
		}
	}
	//第一关第三关卡
	if (curLevel == 1 && Checkpoint1 == 3)
	{
		if (c1p3_npcSet.size()>0) {
			for (vNpcSet::iterator p = c1p3_npcSet.begin(); p != c1p3_npcSet.end(); ++p)
			{
				spAi->Chase(*p, player1); //追踪(为了躲避石块障碍)
			}
		}
	}
	//第一关第四关卡
	if (curLevel == 1 && Checkpoint1 == 4)
	{
		if (c1p4_npcSet.size()>0) {
			int npc_method;
			for (vNpcSet::iterator p = c1p4_npcSet.begin(); p != c1p4_npcSet.end(); ++p)
			{
				spAi->Chase(*p, player1); //追踪(为了躲避石块障碍)
			}
		}
	}
	//第一关第五关卡
	if (curLevel == 1 && Checkpoint1 == 5)
	{
		if (c1p5_npcSet.size()>0) {
			for (vNpcSet::iterator p = c1p5_npcSet.begin(); p != c1p5_npcSet.end(); ++p)
			{
				spAi->Chase(*p, player1); //追踪(为了躲避石块障碍)
			}
		}
	}
	//第一关第六关卡
	if (curLevel == 1 && Checkpoint1 == 6)
	{
		if (c1p6_npcSet.size()>0) {
			int npc_method;
			for (vNpcSet::iterator p = c1p6_npcSet.begin(); p != c1p6_npcSet.end(); ++p)
			{
				//随机npc行为
				npc_method = rand() % 5;
				if (npc_method == 0) spAi->Chase(*p, player1); //小概率追踪
				else spAi->Roam(*p, player1, 4770, 5794);  //大概率漫游
			}
		}
	}
	//第一关Boss
	if (curLevel == 1 && Checkpoint1 == 7)
	{
		spAi->Charge(boss1, player1);
	}

	//**************************************************************

	//第二关第一关卡
	if (curLevel == 2 && Checkpoint2 == 1)
	{
		if (c2p1_npcSet.size()>0) {
			int npc_method;
			for (vNpcSet::iterator p = c2p1_npcSet.begin(); p != c2p1_npcSet.end(); ++p)
			{
				//随机npc行为
				npc_method = rand() % 5;
				if (npc_method == 0) spAi->Chase(*p, player1); //小概率追踪
				else spAi->Roam(*p, player1, 0, 1024);  //大概率漫游
			}
		}
	}
	//第二关第二关卡
	if (curLevel == 2 && Checkpoint2 == 2)
	{
		if (c2p2_npcSet.size()>0) {
			int npc_method;
			for (vNpcSet::iterator p = c2p2_npcSet.begin(); p != c2p2_npcSet.end(); ++p)
			{
				//随机npc行为
				npc_method = rand() % 5;
				if (npc_method == 0) spAi->Chase(*p, player1); //小概率追踪
				else spAi->Roam(*p, player1, 1100, 2124);  //大概率漫游
			}
		}
	}
	//第二关第三关卡
	if (curLevel == 2 && Checkpoint2 == 3)
	{
		if (c2p3_npcSet.size()>0) {
			int npc_method;
			for (vNpcSet::iterator p = c2p3_npcSet.begin(); p != c2p3_npcSet.end(); ++p)
			{
				//随机npc行为
				npc_method = rand() % 5;
				if (npc_method == 0) spAi->Chase(*p, player1); //小概率追踪
				else spAi->Roam(*p, player1, 2200, 3224);  //大概率漫游
			}
		}
	}
	//第二关第四关卡
	if (curLevel == 2 && Checkpoint2 == 4)
	{
		if (c2p4_npcSet.size()>0) {
			int npc_method;
			for (vNpcSet::iterator p = c2p4_npcSet.begin(); p != c2p4_npcSet.end(); ++p)
			{
				//随机npc行为
				npc_method = rand() % 5;
				if (npc_method == 0) spAi->Chase(*p, player1); //小概率追踪
				else spAi->Roam(*p, player1, 3300, 4324);  //大概率漫游
			}
		}
	}
	//第二关第五关卡
	if (curLevel == 2 && Checkpoint2 == 5)
	{
		spAi->Charge(boss2, player1);
	}
	//第三关第一关卡
	if (curLevel == 3 && Checkpoint3 == 1)
	{

		spAi->Charge(boss3, player1);
	}
	//第三关第二关卡
	if (curLevel == 3 && Checkpoint3 == 2)
	{
		spAi->Charge(boss4, player1);
	}

	//大乱斗模式
	if (curLevel == 3 && Checkpoint3 == 999)
	{
		//其中三个boss以漫游+追踪
		int boss_method = rand() % 5;
		if (boss_method == 0) {
			spAi->Charge(boss1, player1);
			spAi->Charge(boss2, player1);
			spAi->Charge(boss3, player1);
		}
		else {
			spAi->BossRoam(boss1, player1, 200, 800);
			spAi->BossRoam(boss2, player1, 200, 800);
			spAi->BossRoam(boss3, player1, 200, 800);
		}
		//一个boss追踪
		spAi->Charge(boss4, player1);
	}

	delete spAi;
}

//关卡切换
void EngineConfig::LevelChange(HDC hdc)
{
	/*demo->SetFrame(2);
	player->SetStartTime(GetTickCount());
	registerNum = 0;
	overStage = 0;*/

	T_Graph* p;
	if (overStage == 0 && !player1->IsDead()) {
		//胜利没死
		WhichPlayer who = player1->getWho();
		int c = 2;
		if (who == Jack) {
			c = 3;
		}
		else if (who == Luan) {
			c = 4;
		}
		if (registerNum1 == c - 1) {
			if ((GetTickCount() - player1->GetStartTime()) > 3000) {
				overStage++;
				registerNum1 = 0;
				player1->SetStartTime(GetTickCount());
				pGame->SetFrame(300);
				return;
			}
		}
		p = new T_Graph(actor[who][0]);
		T_Graph::PaintRegion(p->GetBmpHandle(), hdc, player1->GetX(), player1->GetY() + player1->GetRatioSize().cy - p->GetImageHeight() * 3.0, actorParams[who][0][0] * registerNum1, 0, actorParams[who][0][0], actorParams[who][0][1], 3.0, 0, 255);
		if (registerNum1 < c - 1) {
			registerNum1++;
			registerNum2 = GetRandomNum(2, 3);
		}
		else {
			int y = player1->GetY() + player1->GetRatioSize().cy - p->GetImageHeight() * 3.0 - MENU_SPACE;
			delete p;
			p = new T_Graph(actor[who][registerNum2]);
			T_Graph::PaintRegion(p->GetBmpHandle(), hdc, player1->GetX(), y - 2.0 * p->GetImageHeight(), 0, 0, p->GetImageWidth(), p->GetImageHeight(), 2.0, 0, 255);
		}
		delete p;
	}
	else {
		//分数递减
//		T_Graph::PaintBlank(hdc, 0, 0, wndWidth, wndHeight, Color::White, 255);
		p = new T_Graph(actor[who][1]);
		T_Graph::PaintRegion(p->GetBmpHandle(), hdc, (wndWidth - actorParams[who][1][0] * 3.0) / 2, (wndHeight - p->GetImageHeight() * 3.0) / 2, actorParams[who][1][0] * registerNum1, 0, actorParams[who][1][0], actorParams[who][1][1], 3.0, 0, 255);
		if ((GetTickCount() - player1->GetStartTime()) > 500) {
			registerNum1++;
			registerNum1 %= 3;
			player1->SetStartTime(GetTickCount());
		}
		if (player1->GetScore() >= 0) {
			RectF textRec;
			wchar_t buf[256];
			wsprintf(buf, L"TOTAL\n%d", player1->GetScore());
			int y = (wndHeight - p->GetImageHeight() * 3.0) / 2 + 210;
			for (int i = 0; i < 3; i++) {
				textRec.X = (float)i;
				textRec.Y = (float)(y + i);
				textRec.Width = (float)wndWidth;
				textRec.Height = (float)wndHeight / 5;
				T_Graph::PaintText(hdc, textRec, buf, 42, L"黑体", Color::Black, FontStyleBold, StringAlignmentCenter);
			}
			textRec.X = 4;
			textRec.Y = y + 4;
			textRec.Width = (float)wndWidth;
			textRec.Height = (float)wndHeight / 5;
			T_Graph::PaintText(hdc, textRec, buf, 42, L"黑体", Color::White, FontStyleBold, StringAlignmentCenter);
			if (player1->GetScore() == 0) {
				if (player1->IsDead())
				{
					//死了
					GameState = GAME_OVER;
				}
				else
				{
					//没死
					if (curLevel == 3 && curStage == 999 && boss1->getState() == bDEATH && boss2->getState() == bDEATH && boss3->getState() == bDEATH && boss4->getState() == bDEATH)
					{
						//BOSS死了
						GameState = GAME_OVER;
					}
					else
					{
						GameState = GAME_RUN;
						player1->SetVisible(true);
						t_scene.RemoveAll();
						GameBegin();
					}
				}
				player1->SetStartTime(GetTickCount());
			}
			int s = player1->GetScore() - GetRandomNum(900, 999);
			player1->SetScore(s < 0 ? 0 : s);
		}
	}
	p = NULL;
}

//初始化地图
void EngineConfig::LoadMap()
{
	char mapPath[256];
	sprintf_s(mapPath, "./MapData/map%d.txt", curLevel);
	t_scene.LoadTxtMap(mapPath);
	scn_width = t_scene.getSceneLayers()->back().layer->GetWidth();
	scn_height = t_scene.getSceneLayers()->back().layer->GetHeight();
	//初始位置以地图作为参照
//	const int scn_x = (wndWidth - scn_width) / 2;
//	const int scn_y = (wndHeight - scn_height) / 2;
	const int scn_x = 0;
	const int scn_y = 0;
	//初始化到中央
	t_scene.InitScene(scn_x, scn_y, scn_width, scn_height, wndWidth, wndHeight);
	for (SCENE_LAYERS::iterator p = t_scene.getSceneLayers()->begin(); p != t_scene.getSceneLayers()->end() ; ++p)
	{
		string s = p->layer->ClassName();
		if (p->layer->ClassName() == "T_Map")
		{
			p->layer->SetPosition(scn_x, scn_y);
		}
	}
}

//初始化玩家
void EngineConfig::LoadPlayer()
{
	GAMELAYER gameLayer;
	SPRITEINFO spInfo;
	player1 = new Player(who, STAND);
	if (loadPlayer2)
	{
		player2 = new Player(Luan, STAND);
	}
	spInfo.Active = true;
	spInfo.Dead = false;
	spInfo.Dir = DIR_RIGHT;
	spInfo.Rotation = TRANS_NONE;
	spInfo.Ratio = 2.0f;
	spInfo.Level = 0;
	spInfo.Score = 0;
	spInfo.Speed = 10;
	spInfo.Alpha = 255;
	spInfo.X = wndWidth / 4;
	spInfo.Y = wndHeight / 3;
	spInfo.Visible = true;
	player1->Initiate(spInfo);
	player1->SetLayerTypeID(LAYER_PLY);

	gameLayer.layer = player1;
	gameLayer.type_id = LAYER_PLY;
	gameLayer.z_order = player1->GetY() + player1->GetRatioSize().cy;
	//gameLayer.layer->setZorder(gameLayer.z_order);
		gameLayer.layer->setZorder(500);
	t_scene.Append(gameLayer);
	
	if (loadPlayer2)
	{
		player2->Initiate(spInfo);
		player2->SetLayerTypeID(LAYER_PLY);

		gameLayer.layer = player2;
		gameLayer.type_id = LAYER_PLY;
		gameLayer.z_order = player2->GetY() + player2->GetRatioSize().cy;
		gameLayer.layer->setZorder(gameLayer.z_order);
		t_scene.Append(gameLayer);
	}
}


void EngineConfig::LoadMenus()
{
	int x = 0, y = 0;
	int btn_width = 0, btn_height = 0;
	Color normalClr, focusClr;
	normalClr = Color::Black;
	focusClr = Color::White;
	wstring mainMenu[] = { L"开始", L"关于", L"帮助",L"退出" };
	wstring aboutMenu[] = { L"返回", L"开始", L"退出" };
	wstring pauseMenu[] = { L"继续", L"帮助", L"菜单",L"退出" };
	wstring helpMenu[] = { L"返回", L"开始", L"退出" };
	wstring choosePlayerMenu[] = { L"返回", L"开始", L"退出" };
	wstring overMenu[] = { L"再来一局", L"主菜单", L"退出" };

	main = new T_Menu();
	about = new T_Menu();
	pause = new T_Menu();
	help = new T_Menu();
	choosePlayer = new T_Menu();
	over = new T_Menu();

	MENU_INFO menuInfo;
	menuInfo.align = 1;
	menuInfo.space = MENU_SPACE;
	menuInfo.fontName = L"黑体";
	menuInfo.isBold = true;
	menuInfo.normalTextColor = normalClr;
	menuInfo.focusTextColor = focusClr;

	btn_width = 200;
	btn_height = 60;
	menuInfo.width = btn_width;
	menuInfo.height = btn_height;
	main->SetMenuBkg(L".\\res\\Pics\\bkg2.png", 255);
	main->SetBtnBmp(L".\\res\\Pics\\blueButton.png", btn_width, btn_height);
	main->SetMenuInfo(menuInfo);

	for (int i = 0; i < 4; i++) {
		x = MENU_SPACE * 6;
		y = i*(btn_height + MENU_SPACE) + wndHeight / 3;
		MENUITEM menuItem;
		menuItem.pos.x = x;
		menuItem.pos.y = y - 40;
		menuItem.ItemName = mainMenu[i];
		main->AddMenuItem(menuItem);
	}

	menuInfo.width = btn_width;
	menuInfo.height = btn_height;
	about->SetMenuBkg(L".\\res\\Pics\\bk3.jpg", 200);
	about->SetBtnBmp(L".\\res\\Pics\\blueButton.png", btn_width, btn_height);
	about->SetMenuInfo(menuInfo);

	for (int i = 0; i < 3; i++) {
		x = i*(btn_width + MENU_SPACE) + (wndWidth - 3 * btn_width - 2 * MENU_SPACE) / 2;
		y = wndHeight - btn_height * 2;
		MENUITEM menuItem;
		menuItem.pos.x = x;
		menuItem.pos.y = y;
		menuItem.ItemName = aboutMenu[i];
		about->AddMenuItem(menuItem);
	}

	menuInfo.width = btn_width;
	menuInfo.height = btn_height;
	help->SetMenuBkg(L".\\res\\Pics\\bk4.jpg", 200);
	help->SetBtnBmp(L".\\res\\Pics\\blueButton.png", btn_width, btn_height);
	help->SetMenuInfo(menuInfo);

	for (int i = 0; i < 3; i++) {
		x = i*(btn_width + MENU_SPACE) + (wndWidth - 3 * btn_width - 2 * MENU_SPACE) / 2;
		y = wndHeight - btn_height * 2;
		MENUITEM menuItem;
		menuItem.pos.x = x;
		menuItem.pos.y = y;
		menuItem.ItemName = helpMenu[i];
		help->AddMenuItem(menuItem);
	}

	menuInfo.width = btn_width;
	menuInfo.height = btn_height;
	pause->SetBtnBmp(L".\\res\\Pics\\blueButton.png", btn_width, btn_height);
	pause->SetMenuInfo(menuInfo);

	for (int i = 0; i < 4; i++) {
		x = (wndWidth - btn_width) / 2;
		y = i*(btn_height + MENU_SPACE) + wndHeight / 3;
		MENUITEM menuItem;
		menuItem.pos.x = x;
		menuItem.pos.y = y - 40;
		menuItem.ItemName = pauseMenu[i];
		pause->AddMenuItem(menuItem);
	}

	menuInfo.width = btn_width;
	menuInfo.height = btn_height;
	choosePlayer->SetMenuBkg(L".\\res\\Pics\\bk4.jpg", 180);
	choosePlayer->SetBtnBmp(L".\\res\\Pics\\blueButton.png", btn_width, btn_height);
	choosePlayer->SetMenuInfo(menuInfo);

	for (int i = 0; i < 3; i++) {
		x = i*(btn_width + MENU_SPACE) + (wndWidth - 3 * btn_width - 2 * MENU_SPACE) / 2;
		y = wndHeight - btn_height;
		MENUITEM menuItem;
		menuItem.pos.x = x;
		menuItem.pos.y = y - 40;
		menuItem.ItemName = choosePlayerMenu[i];
		choosePlayer->AddMenuItem(menuItem);
	}

	menuInfo.width = btn_width;
	menuInfo.height = btn_height;
	over->SetBtnBmp(L".\\res\\Pics\\blueButton.png", btn_width, btn_height);
	over->SetMenuInfo(menuInfo);

	for (int i = 0; i < 3; i++) {
		x = (wndWidth - btn_width) / 2;
		y = i*(btn_height + MENU_SPACE) + wndHeight / 2;
		MENUITEM menuItem;
		menuItem.pos.x = x;
		menuItem.pos.y = y - 40;
		menuItem.ItemName = overMenu[i];
		over->AddMenuItem(menuItem);
	}
}

//加载飞斧
void EngineConfig::LoadBomb(T_Sprite* sp, vSpritSet& bombset, const int offset, const int iTime)
{
	sp->SetEndTime(GetTickCount());
	if (sp->GetEndTime() - sp->GetStartTime() >= DWORD(iTime))
	{
		sp->SetStartTime(sp->GetEndTime());
		GAMELAYER gameLayer;
		SPRITEINFO bombInfo;
		int m_dir = sp->GetDir();
		bombset.push_back(new T_Sprite(L"./res/Pics/feifu.png"));
		T_Sprite* bomb = bombset.back();
		bombInfo.Active = true;
		bombInfo.Dead = false;
		bombInfo.Dir = sp->GetRotation() == TRANS_NONE ? DIR_RIGHT : DIR_LEFT;
		bombInfo.Rotation = sp->GetRotation();
		bombInfo.Ratio = 3;
		bombInfo.Level = 0;
		bombInfo.Score = 0;
		bombInfo.Speed = 50;
		bombInfo.Alpha = 255;
		switch (sp->GetRotation())
		{
		case TRANS_VFLIP_ROT180:
			bombInfo.X = sp->GetX() + 10;
			bombInfo.Y = sp->GetY() + sp->GetRatioSize().cy / 2 - offset;
			break;
		case TRANS_NONE:
			bombInfo.X = sp->GetX() + sp->GetRatioSize().cx - 10;
			bombInfo.Y = sp->GetY() + sp->GetRatioSize().cy / 2 - offset;
			break;
		default:
			break;
		}
		bombInfo.Visible = true;
		bomb->Initiate(bombInfo);
		gameLayer.layer = bomb;
		if (bombset == player_bomb_set)
		{
			gameLayer.type_id = LAYER_PLY_BOMB;
			gameLayer.layer->SetLayerTypeID(LAYER_PLY_BOMB);
		}
		gameLayer.z_order = t_scene.GetTotalLayers() + 1;
		gameLayer.layer->setZorder(gameLayer.z_order);
		t_scene.Append(gameLayer);
	}
}
//加载Boss火球
void EngineConfig::LoadBossBomb(T_Sprite* sp, vSpritSet& bombset, int offset)
{
	GAMELAYER gameLayer;
	SPRITEINFO bombInfo;
	int m_dir = sp->GetDir();
	bombset.push_back(new T_Sprite(L"./res/Pics/huoqiu.png"));
	T_Sprite* bomb = bombset.back();
	bombInfo.Active = true;
	bombInfo.Dead = false;
	bombInfo.Dir = m_dir;
	bombInfo.Rotation = m_dir == DIR_LEFT ? TRANS_VFLIP_ROT180 : TRANS_NONE;
	bombInfo.Ratio = 3;
	bombInfo.Level = 0;
	bombInfo.Score = 0;
	bombInfo.Speed = 35;
	bombInfo.Alpha = 255;
	switch (m_dir)
	{
	case DIR_LEFT:
		bombInfo.X = sp->GetX() + 10;
		bombInfo.Y = sp->GetY() + sp->GetRatioSize().cy / 2 - offset;
		break;
	case DIR_RIGHT:
		bombInfo.X = sp->GetX() + sp->GetRatioSize().cx - 10;
		bombInfo.Y = sp->GetY() + sp->GetRatioSize().cy / 2 - offset;
		break;
	default:
		break;
	}
	bombInfo.Visible = true;
	bomb->Initiate(bombInfo);
	gameLayer.layer = bomb;
	if (bombset == boss_bomb_set)
	{
		gameLayer.type_id = LAYER_NPC_BOMB;
		gameLayer.layer->SetLayerTypeID(LAYER_NPC_BOMB);
	}
	gameLayer.z_order = t_scene.GetTotalLayers() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);
}


//加载游戏声音
void EngineConfig::LoadMusic()
{
	bk1_buffer.LoadWave(ds, L"./res/sound/bk1.wav");
	bk2_buffer.LoadWave(ds, L"./res/sound/bk2.wav");
	bk3_buffer.LoadWave(ds, L"./res/sound/bk3.wav");
	box1_buffer.LoadWave(ds, L"./res/sound/box1.wav");
	box2_buffer.LoadWave(ds, L"./res/sound/box2.wav");
	gun1_buffer.LoadWave(ds, L"./res/sound/s686.wav");
	gun2_buffer.LoadWave(ds, L"./res/sound/m4a1.wav");
	walk_buffer.LoadWave(ds, L"./res/sound/walk.wav");
	mousedown_buffer.LoadWave(ds, L"./res/sound/mousedown.wav");
	mouseover_buffer.LoadWave(ds, L"./res/sound/mouseover.wav");
}

void EngineConfig::AddRandomResource(int x, int y)
{
	if (!(GetRandomNum(0, 9) < LUCKY_LEVEL)) {
		return;
	}
	Resource* tmp = NULL;
//	int flag = 9;
	int flag = GetRandomNum(1, 10);
	//4 
	//这里设置随机值来判断是否掉落奖励，掉落何种奖励等，不同奖励的加血量不同
	//6成的概率获取食品
	if (flag < 11) {
		//随机掉落食物，吃掉食物可以加血量
		int reward = 5;
		ResourceType type = (ResourceType)GetRandomNum(2, FOOD_NUM - 1);
		//掉落弹药，此时设置blood值为BULLETS，玩家拾取弹药时可以加满弹药
		if (type == BULLETS) {
			reward = AMMO;
		}
		else if (type < 3) {
			reward = 20;
		}
		if(type < 2)
		{
			tmp = new Resource(bonus[type], bonusParams[type][0], bonusParams[type][1], 3.0);
		}
		else
		{
			tmp = new Resource(bonus[type], 3.0);
		}
		tmp->setReward(reward);
	}
	else if (flag < 11) {
		//4成的概率掉落枪支
		int reward;
		GunType type;
		if (who == Jack) {
//			type = (GunType)1;
			type = (GunType)GetRandomNum(0, 1);
			reward = type == KAR98K ? 10 : 40;
			tmp = new Resource(guns[type], 3.0);
		}
		else if (who == Luan) {
			type = (GunType)GetRandomNum(2, WEAPON_NUM - 1);
			reward = type == S686 ? 8 : 48;
			tmp = new Resource(guns[type], 3.0);
		}
		else if (who == zy) {
			type = (GunType)GetRandomNum(2, WEAPON_NUM - 1);
			reward = type == S686 ? 8 : 48;
			tmp = new Resource(guns[type], 3.0);
		}
		//tmp->setReward(reward);
	}
	else {
		return;
	}
	GAMELAYER gameLayer;

	if (x <= 100) x = 100;
	if (x + tmp->getRatioWidth() > wndWidth - 20) x = wndWidth - 20;
	if (y <= wndHeight / 2 + 100) y = wndHeight / 2 + 100;
	if (y >= wndHeight - 20) y = wndHeight - 20;
	tmp->SetPosition(x, y);
	tmp->SetVisible(true);
	tmp->SetLayerTypeID(LAYER_BONUS);
	resource.push_back(tmp);

	gameLayer.layer = tmp;
	gameLayer.type_id = LAYER_BONUS;
	gameLayer.z_order = t_scene.getSceneLayers()->size() + 1;
	gameLayer.layer->setZorder(gameLayer.z_order);
	t_scene.Append(gameLayer);
}

//绘制血量和分数
void EngineConfig::PaintBlood(HDC hdc)
{
	//绘制玩家的血量
	if (bloodBk != NULL) {
		bloodBk->PaintRegion(bloodBk->GetBmpHandle(), hdc, MENU_SPACE, MENU_SPACE * 2, 0, 0, bloodBk->GetImageWidth(), bloodBk->GetImageHeight(), 4.0, 0, 255);
		RectF textRec;
		wchar_t buf[256];
		wsprintf(buf, L"%d", player1->GetScore());
		for (int i = 0; i < 2; i++) {
			textRec.X = (float)((wndWidth / 2 - MENU_SPACE * 21) + i);
			textRec.Y = (float)(MENU_SPACE * 2 - i);
			textRec.Width = (float)wndWidth / 4;
			textRec.Height = (float)40;
			T_Graph::PaintText(hdc, textRec, buf, 30, L"黑体", Color::Black, FontStyleBold, StringAlignmentNear);
		}
		textRec.X = (float)((wndWidth / 2 - MENU_SPACE * 21) + 2);
		textRec.Y = (float)(MENU_SPACE * 2);
		textRec.Width = (float)wndWidth / 4;
		textRec.Height = (float)40;
		T_Graph::PaintText(hdc, textRec, buf, 30, L"黑体", Color::White, FontStyleBold, StringAlignmentNear);
		if (player1->IsDead() || player1->getBlood() == 0) {
			for (int i = 0; i < 25; i++) {
				life->PaintRegion(life->GetBmpHandle(), hdc, 502 - i * 16, 88, 84, 0, 4, 6, 4.0, 0, 255);
			}
			life->PaintRegion(life->GetBmpHandle(), hdc, 114, 88, 84, 0, 1, 6, 4.0, 0, 255);
		}
		else {
			//绘制血条背景(黄色)
			for (int i = 0; i < 25; i++) {
				life->PaintRegion(life->GetBmpHandle(), hdc, 502 - i * 16, 88, 72, 0, 4, 6, 4.0, 0, 255);
			}
			life->PaintRegion(life->GetBmpHandle(), hdc, 114, 88, 72, 0, 4, 6, 4.0, 0, 255);
			//绘制血条前景(红色)
			for (int i = 0; i <= 25 - player1->getBlood() && player1->getBlood() > 0; i++) {
				life->PaintRegion(life->GetBmpHandle(), hdc, 502 - i * 16, 88, 84, 0, 4, 6, 4.0, 0, 255);
			}
		}
	}
	if (curLevel == 1)
	{
		if (curStage == sizeof(map1) / sizeof(map1[0]))
		{
			PaintBossBlood(hdc, boss1);
		}
		else if (isAttacked1)
		{
			vNpcSet* nSet = nullptr;
			switch (curStage)
			{
			case 1:
				nSet = &c1p1_npcSet;
				break;
			case 2:
				nSet = &c1p2_npcSet;
				break;
			case 3:
				nSet = &c1p3_npcSet;
				break;
			case 4:
				nSet = &c1p4_npcSet;
				break;
			case 5:
				nSet = &c1p5_npcSet;
				break;
			case 6:
				nSet = &c1p6_npcSet;
				break;
			default:
				break;
			}
			for (vNpcSet::iterator p = nSet->begin(); p != nSet->end(); ++p)
			{
				if ((*p)->getState() == nHINT)
				{
					PaintNpcBlood(hdc, *p);
					break;
				}
			}
		}
	}
	if (curLevel == 2)
	{
		if (curStage == sizeof(map2) / sizeof(map2[0]))
		{
			PaintBossBlood(hdc, boss2);
		}
		else if (isAttacked1)
		{
			vNpcSet* nSet = nullptr;
			switch (curStage)
			{
			case 1:
				nSet = &c2p1_npcSet;
				break;
			case 2:
				nSet = &c2p2_npcSet;
				break;
			case 3:
				nSet = &c2p3_npcSet;
				break;
			case 4:
				nSet = &c2p4_npcSet;
				break;
			default:
				break;
			}
			for (vNpcSet::iterator p = nSet->begin(); p != nSet->end(); ++p)
			{
				if ((*p)->getState() == nHINT)
				{
					PaintNpcBlood(hdc, *p);
					break;
				}
			}
		}
	}
	if (curLevel == 3)
	{
		if (Checkpoint3 == 1)
		{
			PaintBossBlood(hdc, boss3);
		}
		else if (Checkpoint3 == 2)
		{
			PaintBossBlood(hdc, boss4);
		}
		else if (Checkpoint3 == 999)
		{
			if (boss1->getState() == bHINT)
			{
				PaintBossBlood(hdc, boss1);
			}
			if (boss2->getState() == bHINT)
			{
				PaintBossBlood(hdc, boss2);
			}
			if (boss3->getState() == bHINT)
			{
				PaintBossBlood(hdc, boss3);
			}
			if (boss4->getState() == bHINT)
			{
				PaintBossBlood(hdc, boss4);
			}
		}
	}
}
void EngineConfig::PaintNpcBlood(HDC hdc, Npc* npc)
{
	//加载图像
	T_Graph* pic = new T_Graph(NpcBloodBk[0]);
	int blood = npc->getBlood();
	int all = 20;//总血量
//	blood = 50;//当前血量
	if (blood < 0) blood = 0;
	if (curLevel == 1) {
		switch (npc->getWho())
		{
		case Npc1:
			pic = new T_Graph(NpcBloodBk[0]);
			break;
		case Npc2:
			pic = new T_Graph(NpcBloodBk[1]);
			break;
		default:
			break;
		}
	}
	else if (curLevel == 2) {
		switch (npc->getWho())
		{
		case Npc3:
			pic = new T_Graph(NpcBloodBk[2]);
			break;
		case Npc4:
			pic = new T_Graph(NpcBloodBk[3]);
			break;
		default:
			break;
		}
	}
	else if (curLevel == 3) {
		if (npc->getWho()) {

		}
	}
	T_Graph::PaintRegion(pic->GetBmpHandle(), hdc, MENU_SPACE, bloodBk->GetImageHeight() * 4.0 + MENU_SPACE * 3, 0, 0, pic->GetImageWidth(), pic->GetImageHeight(), 3.0, 0, 255);
	T_Graph::PaintBlank(hdc, 82, 153, 306, 18, Color::Yellow);
	int width = (all - blood) * 306 / all;
	T_Graph::PaintBlank(hdc, 388 - width, 153, width, 18, Color::Red);
}
void EngineConfig::PaintBossBlood(HDC hdc, Boss* boss)
{
	//加载图像
	T_Graph* pic = nullptr;
	int blood = boss->getBlood();
	int all = 100;//总血量
//	blood = 50;//当前血量
	if (blood < 0) blood = 0;
	if (curLevel == 1) {
		pic = new T_Graph(NpcBloodBk[4]);
	}
	else if (curLevel == 2) {
		pic = new T_Graph(NpcBloodBk[5]);
	}
	else if (curLevel == 3) {
		if (boss->getWho() == Boss3) {
			pic = new T_Graph(NpcBloodBk[6]);
		}
		else
		{
			pic = new T_Graph(NpcBloodBk[7]);
		}
	}
	T_Graph::PaintRegion(pic->GetBmpHandle(), hdc, MENU_SPACE, bloodBk->GetImageHeight() * 4.0 + MENU_SPACE * 3, 0, 0, pic->GetImageWidth(), pic->GetImageHeight(), 3.0, 0, 255);
	T_Graph::PaintBlank(hdc, 82, 153, 306, 18, Color::Yellow);
	int width = (all - blood) * 306 / all;
	T_Graph::PaintBlank(hdc, 388 - width, 153, width, 18, Color::Red);
}

//更新玩家位置
void EngineConfig::UpdatePlayerPos()
{
	if (player1 == nullptr) return;
	int SpeedX, SpeedY, SpeedZ = 0;
	PlayerState state = player1->getState();
	switch (state) {
	case WALK:
		switch (player1->GetDir()) {
		case DIR_LEFT_UP:
			player1->SetYSpeed(-Y_WALK_SPEED);
			player1->SetXSpeed(-X_WALK_SPEED);
			break;
		case DIR_RIGHT_UP:
			player1->SetYSpeed(-Y_WALK_SPEED);
			player1->SetXSpeed(X_WALK_SPEED);
			break;
		case DIR_LEFT_DOWN:
			player1->SetYSpeed(Y_WALK_SPEED);
			player1->SetXSpeed(-X_WALK_SPEED);
			break;
		case DIR_RIGHT_DOWN:
			player1->SetYSpeed(Y_WALK_SPEED);
			player1->SetXSpeed(X_WALK_SPEED);
			break;
		case DIR_LEFT:
			player1->SetXSpeed(-X_WALK_SPEED);
			player1->SetYSpeed(0);
			break;
		case DIR_RIGHT:
			player1->SetXSpeed(X_WALK_SPEED);
			player1->SetYSpeed(0);
			break;
		case DIR_UP:
			player1->SetXSpeed(0);
			player1->SetYSpeed(-Y_WALK_SPEED);
			break;
		case DIR_DOWN:
			player1->SetXSpeed(0);
			player1->SetYSpeed(Y_WALK_SPEED);
			break;
		default:;
		}
		break;
	case RUN:
		switch (player1->GetDir()) {
		case DIR_LEFT_UP:
			player1->SetYSpeed(-Y_RUN_SPEED);
			player1->SetXSpeed(-X_RUN_SPEED);
			break;
		case DIR_RIGHT_UP:
			player1->SetYSpeed(-Y_RUN_SPEED);
			player1->SetXSpeed(X_RUN_SPEED);
			break;
		case DIR_LEFT_DOWN:
			player1->SetYSpeed(Y_RUN_SPEED);
			player1->SetXSpeed(-X_RUN_SPEED);
			break;
		case DIR_RIGHT_DOWN:
			player1->SetYSpeed(Y_RUN_SPEED);
			player1->SetXSpeed(X_RUN_SPEED);
			break;
		case DIR_LEFT:
			player1->SetXSpeed(-X_RUN_SPEED);
			player1->SetYSpeed(0);
			break;
		case DIR_RIGHT:
			player1->SetXSpeed(X_RUN_SPEED);
			player1->SetYSpeed(0);
			break;
		case DIR_UP:
			player1->SetXSpeed(0);
			player1->SetYSpeed(-Y_RUN_SPEED);
			break;
		case DIR_DOWN:
			player1->SetXSpeed(0);
			player1->SetYSpeed(Y_RUN_SPEED);
			break;
		default:;
		}
		break;
	case JUMP:
		//why修改
		//player1->SetZSpeed(Z_SPEED - GRAVITY * player1->GetForward());
		player1->SetYSpeed(0);
		break;
	default:
		player1->SetXSpeed(0);
		player1->SetYSpeed(0);
		player1->SetZSpeed(0);
	}
	if (!player1->IsDead()) {//边界检测
		state = player1->getState();
		bool isJump = false;
		if (state == JUMP) {
			isJump = true;
			SpeedZ = player1->GetZSpeed();
		}
		SpeedX = player1->GetXSpeed();
		SpeedY = player1->GetYSpeed();
		const int nextStepX = player1->GetX() + SpeedX;
		const int nextStepY = player1->GetY() + SpeedY;
		if (nextStepX <= 0 || nextStepX >= wndWidth - player1->GetRatioSize().cx)
			SpeedX = 0;
		if ((nextStepY >= wndHeight - player1->GetRatioSize().cy) || (nextStepY <= (wndHeight- player1->GetRatioSize().cy) / 3 && !isJump)) {
			SpeedY = 0;
		}
		//障碍检测
		if (checkBarrier(player1, nextStepX, nextStepY, stone1) && !isJump && curLevel == 1 || checkBarrier(player1, nextStepX, nextStepY, stone2) && !isJump && curLevel == 1)
		{
			SpeedX = 0;
			SpeedY = 0;
		}
		player1->Move(SpeedX, SpeedY - SpeedZ);
	}
	
	if (player2 == nullptr) return;
	SpeedX = 0;
	SpeedY = 0;
	SpeedZ = 0;
	state = player2->getState();
	switch (state) {
	case WALK:
		switch (player2->GetDir()) {
		case DIR_LEFT_UP:
			player2->SetYSpeed(-Y_WALK_SPEED);
			player2->SetXSpeed(-X_WALK_SPEED);
			break;
		case DIR_RIGHT_UP:
			player2->SetYSpeed(-Y_WALK_SPEED);
			player2->SetXSpeed(X_WALK_SPEED);
			break;
		case DIR_LEFT_DOWN:
			player2->SetYSpeed(Y_WALK_SPEED);
			player2->SetXSpeed(-X_WALK_SPEED);
			break;
		case DIR_RIGHT_DOWN:
			player2->SetYSpeed(Y_WALK_SPEED);
			player2->SetXSpeed(X_WALK_SPEED);
			break;
		case DIR_LEFT:
			player2->SetXSpeed(-X_WALK_SPEED);
			player2->SetYSpeed(0);
			break;
		case DIR_RIGHT:
			player2->SetXSpeed(X_WALK_SPEED);
			player2->SetYSpeed(0);
			break;
		case DIR_UP:
			player2->SetXSpeed(0);
			player2->SetYSpeed(-Y_WALK_SPEED);
			break;
		case DIR_DOWN:
			player2->SetXSpeed(0);
			player2->SetYSpeed(Y_WALK_SPEED);
			break;
		default:;
		}
		break;
	case RUN:
		switch (player2->GetDir()) {
		case DIR_LEFT_UP:
			player2->SetYSpeed(-Y_RUN_SPEED);
			player2->SetXSpeed(-X_RUN_SPEED);
			break;
		case DIR_RIGHT_UP:
			player2->SetYSpeed(-Y_RUN_SPEED);
			player2->SetXSpeed(X_RUN_SPEED);
			break;
		case DIR_LEFT_DOWN:
			player2->SetYSpeed(Y_RUN_SPEED);
			player2->SetXSpeed(-X_RUN_SPEED);
			break;
		case DIR_RIGHT_DOWN:
			player2->SetYSpeed(Y_RUN_SPEED);
			player2->SetXSpeed(X_RUN_SPEED);
			break;
		case DIR_LEFT:
			player2->SetXSpeed(-X_RUN_SPEED);
			player2->SetYSpeed(0);
			break;
		case DIR_RIGHT:
			player2->SetXSpeed(X_RUN_SPEED);
			player2->SetYSpeed(0);
			break;
		case DIR_UP:
			player2->SetXSpeed(0);
			player2->SetYSpeed(-Y_RUN_SPEED);
			break;
		case DIR_DOWN:
			player2->SetXSpeed(0);
			player2->SetYSpeed(Y_RUN_SPEED);
			break;
		default:;
		}
		break;
	case JUMP:
		player2->SetZSpeed(Z_SPEED - GRAVITY * player2->GetForward());
		player2->SetYSpeed(0);
		break;
	default:
		player2->SetXSpeed(0);
		player2->SetYSpeed(0);
		player2->SetZSpeed(0);
	}
	if (!player2->IsDead()) {//边界检测
		state = player2->getState();
		bool isJump = false;
		if (state == JUMP) {
			isJump = true;
			SpeedZ = player2->GetZSpeed();
		}
		SpeedX = player2->GetXSpeed();
		SpeedY = player2->GetYSpeed();
		const int nextStepX = player2->GetX() + SpeedX;
		const int nextStepY = player2->GetY() + SpeedY;
		if (nextStepX <= 0 || nextStepX >= wndWidth - player2->GetRatioSize().cx)
			SpeedX = 0;
		if ((nextStepY >= wndHeight - player2->GetRatioSize().cy) || (nextStepY <= wndHeight / 3 && !isJump)) {
			SpeedY = 0;
		}
		//障碍检测
		if (checkBarrier(player2, nextStepX, nextStepY, stone1) && !isJump && curLevel == 1 || checkBarrier(player2, nextStepX, nextStepY, stone2) && !isJump && curLevel == 1)
		{
			SpeedX = 0;
			SpeedY = 0;
		}
		player2->Move(SpeedX, SpeedY - SpeedZ);
	}

}
//障碍检测
bool EngineConfig::checkBarrier(T_Sprite* sp, int nextStepX, int nextStepY, Rect stone)
{
	if (sp != nullptr)
	{
		int x = nextStepX;
		int y = nextStepY;
		int width = sp->GetRatioSize().cx;
		int height = sp->GetRatioSize().cy;
		int scrollWidth = t_scene.getSceneX();
		RECT r = { x - scrollWidth ,y,width,2 };
		if (r.right + r.left  > stone.X &&
			stone.X + stone.Width  > r.left &&
			r.bottom + r.top > stone.Y &&
			stone.Y + stone.Height > r.top)
		{
			return true;
		}
//		std::cout << r.left << "\t" << r.top << endl;
	}
	return false;
}

//更新炮弹位置
void EngineConfig::UpdateBombPos(vSpritSet* bombset)
{
	if (bombset->size() == 0)return;
	vSpritSet::iterator itp = bombset->begin();
	for (; itp != bombset->end();)
	{
		if ((*itp)->IsVisible() && (*itp)->IsActive())
		{
			int SpeedX = 0, SpeedY = 0;
			switch ((*itp)->GetDir())
			{
			case DIR_LEFT:
				SpeedX = -(*itp)->GetSpeed();
				SpeedY = 0;
				break;
			case DIR_RIGHT:
				SpeedX = (*itp)->GetSpeed();
				SpeedY = 0;
				break;
			case DIR_UP:
				SpeedX = 0;
				SpeedY = -(*itp)->GetSpeed();
				break;
			case DIR_DOWN:
				SpeedX = 0;
				SpeedY = (*itp)->GetSpeed();
				break;
			default:
				break;
			}
			(*itp)->Move(SpeedX, SpeedY);
			BombCollide((*itp));
			if (GameState != GAME_RUN)return;
		}
		if (!(*itp)->IsVisible() || (*itp)->GetX() < 0 || (*itp)->GetY() < 0 || (*itp)->GetX() > wndWidth || (*itp)->GetY() > wndHeight)
		{
			for (SCENE_LAYERS::iterator p = t_scene.getSceneLayers()->begin(); p != t_scene.getSceneLayers()->end(); ++p)
			{
				if ((*p).layer == (*itp))
				{
					p = t_scene.getSceneLayers()->erase(p);
					break;
				}
			}
			delete (*itp);
			itp = bombset->erase(itp);
		}
		if (itp == bombset->end())break;
		++itp;
	}
}
//更新BOSS炮弹位置
void EngineConfig::UpdateBombPosBoss(vSpritSet* bombset)
{
	if (bombset->size() == 0)return;
	vSpritSet::iterator itp = bombset->begin();
	for (; itp != bombset->end();)
	{
		if ((*itp)->IsVisible() && (*itp)->IsActive())
		{
			int SpeedX = 0, SpeedY = 0;
			switch ((*itp)->GetDir())
			{
			case DIR_LEFT:
				SpeedX = -(*itp)->GetSpeed();
				SpeedY = 0;
				break;
			case DIR_RIGHT:
				SpeedX = (*itp)->GetSpeed();
				SpeedY = 0;
				break;
			case DIR_UP:
				SpeedX = 0;
				SpeedY = -(*itp)->GetSpeed();
				break;
			case DIR_DOWN:
				SpeedX = 0;
				SpeedY = (*itp)->GetSpeed();
				break;
			default:
				break;
			}
			(*itp)->Move(SpeedX, SpeedY);
			BombCollide_Boss((*itp));
			if (GameState != GAME_RUN)return;
		}
		if (!(*itp)->IsVisible() || (*itp)->GetX() < 0 || (*itp)->GetY() < 0 || (*itp)->GetX() > wndWidth || (*itp)->GetY() > wndHeight)
		{
			for (SCENE_LAYERS::iterator p = t_scene.getSceneLayers()->begin(); p != t_scene.getSceneLayers()->end(); ++p)
			{
				if ((*p).layer == (*itp))
				{
					p = t_scene.getSceneLayers()->erase(p);
					break;
				}
			}
			delete (*itp);
			itp = bombset->erase(itp);
		}
		if (itp == bombset->end())break;
		++itp;
	}
}

//处理炮弹爆炸
void EngineConfig::BombCollide(T_Sprite* bomb)
{
	if (bomb->IsActive() && bomb->IsVisible())
	{
		int flag = false;
		//判断是否击中障碍
		if (curLevel == 1)
		{
			switch (curStage)
			{
			case 1:
				flag = check_bomb_attack(&c1p1_npcSet, bomb);
				break;
			case 2:
				flag = check_bomb_attack(&c1p2_npcSet, bomb);
				break;
			case 3:
				flag = check_bomb_attack(&c1p3_npcSet, bomb);
				break;
			case 4:
				flag = check_bomb_attack(&c1p4_npcSet, bomb);
				break;
			case 5:
				flag = check_bomb_attack(&c1p5_npcSet, bomb);
				break;
			case 6:
				flag = check_bomb_attack(&c1p6_npcSet, bomb);
				break;
			case 7:
				flag = check_bomb_attack_boss(boss1, bomb);
			default:
				break;
			}
		}
		if (curLevel == 2)
		{
			switch (curStage)
			{
			case 1:
				flag = check_bomb_attack(&c2p1_npcSet, bomb);
				break;
			case 2:
				flag = check_bomb_attack(&c2p2_npcSet, bomb);
				break;
			case 3:
				flag = check_bomb_attack(&c2p3_npcSet, bomb);
				break;
			case 4:
				flag = check_bomb_attack(&c2p4_npcSet, bomb);
				break;
			case 5:
				flag = check_bomb_attack_boss(boss2, bomb);
				break;
			default:
				break;
			}
		}
		if (curLevel == 3)
		{
			if (boss4 != nullptr)
				flag |= check_bomb_attack_boss(boss4, bomb);
			if (boss3 != nullptr)
				flag |= check_bomb_attack_boss(boss3, bomb);
			if (boss2 != nullptr)
				flag |= check_bomb_attack_boss(boss2, bomb);
			if (boss1 != nullptr)
				flag |= check_bomb_attack_boss(boss1, bomb);

		}

		if (flag)
		{
			//击中目标
			bomb->SetActive(false);
			bomb->SetVisible(false);
		}
	}
}
void EngineConfig::BombCollide_Boss(T_Sprite* bomb)
{
	if (bomb->IsActive() && bomb->IsVisible())
	{
		int flag = false;
		flag = check_bomb_attack_player(player1, bomb);
		if (flag)
		{
			//击中目标
			bomb->SetActive(false);
			bomb->SetVisible(false);
		}
	}
}
bool EngineConfig::check_bomb_attack_boss(Boss* boss, T_Sprite* sp)
{
	bool flag = false;
	RECT spRect;
	spRect.left = sp->GetX();
	spRect.top = sp->GetY();
	spRect.right = spRect.left + sp->GetRatioSize().cx;
	spRect.bottom = spRect.top + sp->GetRatioSize().cy;

	RECT npcRect;
	npcRect.left = boss->GetX();
	npcRect.top = boss->GetY();
	npcRect.right = npcRect.left + boss->GetRatioSize().cx;
	npcRect.bottom = npcRect.top + boss->GetRatioSize().cy;

	if (spRect.left <= npcRect.right &&
		npcRect.left <= spRect.right &&
		spRect.top <= npcRect.bottom &&
		npcRect.top <= spRect.bottom && boss->getState() != bDEATH)
	{
		//击中
		flag = true;
			
		switch (type)
		{
		case AK:
			boss->subBlood(5);
			break;
		case KAR98K:
			boss->subBlood(12);
			break;
		case S686:
			boss->subBlood(20);
			break;
		case UZI:
			boss->subBlood(4);
			break;
		default:
			break;
		}
		//处理npc血量
		boss->setState(bHINT);
	}
	return flag;
}
bool EngineConfig::check_bomb_attack(vNpcSet* npc_set, T_Sprite* sp)
{
	bool flag = false;
	RECT spRect;
	spRect.left = sp->GetX();
	spRect.top = sp->GetY();
	spRect.right = spRect.left + sp->GetRatioSize().cx;
	spRect.bottom = spRect.top + sp->GetRatioSize().cy;

	RECT npcRect;
	for (vNpcSet::iterator p = npc_set->begin(); p != npc_set->end(); p++)
	{
		npcRect.left = (*p)->GetX();
		npcRect.top = (*p)->GetY();
		npcRect.right = npcRect.left + (*p)->GetRatioSize().cx;
		npcRect.bottom = npcRect.top + (*p)->GetRatioSize().cy;

		if (spRect.left <= npcRect.right &&
			npcRect.left <= spRect.right &&
			spRect.top <= npcRect.bottom &&
			npcRect.top <= spRect.bottom && (*p)->getState() != nDEATH)
		{
			//击中
			flag = true;
			
			switch (type)
			{
			case AK:
				(*p)->subBlood(5);
				break;
			case KAR98K:
				(*p)->subBlood(12);
				break;
			case S686:
				(*p)->subBlood(20);
				break;
			case UZI:
				(*p)->subBlood(4);
				break;
			default:
				break;
			}
			//处理npc血量
			
			(*p)->setState(nHINT);
			break;
		}
	}
	return flag;
}
bool EngineConfig::check_bomb_attack_player(Player* player, T_Sprite* sp)
{
	bool flag = false;
	RECT spRect;
	spRect.left = sp->GetX();
	spRect.top = sp->GetY();
	spRect.right = spRect.left + sp->GetRatioSize().cx;
	spRect.bottom = spRect.top + sp->GetRatioSize().cy;

	RECT npcRect;
	
	npcRect.left = player->GetX();
	npcRect.top = player->GetY();
	npcRect.right = npcRect.left + player->GetRatioSize().cx;
	npcRect.bottom = npcRect.top + player->GetRatioSize().cy;

	if (spRect.left <= npcRect.right &&
		npcRect.left <= spRect.right &&
		spRect.top <= npcRect.bottom &&
		npcRect.top <= spRect.bottom && player->getState() != DEATH)
	{
		//击中
		flag = true;
		player->subBlood(3);
				
		//处理npc血量
		if(player->GetRotation() == sp->GetRotation())
			player->setState(BACKHIT);
		else
			player->setState(FRONTHIT);
	}
	return flag;
}

//更新动画
void EngineConfig::UpdateAnimation()
{
	if (player1 != nullptr)
	{
		if (player1->IsActive() && player1->IsVisible())
		{
			PlayerState state = player1->getState();
			switch (player1->getState()) {
			case JUMP:
			case BOX1:
			case BOX2:
			case PICK:
			case FRONTHIT:
			case BACKHIT:
			case DEATH:
			case RESTAND:
				keyValid1 = player1->LoopFrameOnce();
				if (keyValid1) {
					if (state == BACKHIT || state == FRONTHIT)
					{
							player1->setState(STAND);
					}
					else if (state == DEATH)
					{
						GameChangeInit();
						GameState = GAME_LEVELCHANGE;
//						player1->SetDead(false);
//						player1->setBlood(26);
//						player1->setState(PICK);
//						player1->setInvincible(true);
//						type = NOGUN;
					}
					else
						//判断上一次的状态
					switch (player1->getLastState()) {
					case DEATH:
					case WALK:
					case RUN:
					case STAND:
						player1->setState(STAND);
						break;
					default:;
					}
				}
				break;
			default:
				player1->LoopFrame();
			}
		}
	}
	if (player2 != nullptr)
	{
		if (player2->IsActive() && player2->IsVisible())
		{
			switch (player2->getState()) {
			case JUMP:
			case BOX1:
			case BOX2:
				keyValid2 = player2->LoopFrameOnce();
				if (keyValid2) {
					switch (player2->getLastState()) {
					case WALK:
					case RUN:
					case STAND:
						player2->setState(STAND);
						break;
					default:;
					}
				}
				break;
			default:
				player2->LoopFrame();
			}
		}
	}


	//更新第一关第一关卡
	if (c1p1_npcSet.size()>0) {
		for (vNpcSet::iterator p = c1p1_npcSet.begin(); p != c1p1_npcSet.end(); ++p)
		{
			if ((*p)->getBlood() <= 0 && (*p)->getState() != nDEATH) {
				(*p)->setState(nDEATH);
				player1->addScore(1000);
				(*p)->SetPosition((*p)->GetX(), (*p)->GetY() + (*p)->GetRatioSize().cy / 2);  //死亡状态改变位置
				(*p)->setDeathTime(GetTickCount());
				AddRandomResource((*p)->GetX(), (*p)->GetY());
			}
			else {
				if ((*p)->getState() == nATTACK1 || (*p)->getState() == nATTACK2)
				{
					if ((*p)->LoopFrameOnce())    //攻击状态只播放一次，即转为行走状态
					{
						(*p)->setState(nWALK);
					}
				}
				else {
					(*p)->LoopFrame();
				}
			}
		}
	}

	//更新第一关第二关卡
	if (c1p2_npcSet.size()>0) {
		for (vNpcSet::iterator p = c1p2_npcSet.begin(); p != c1p2_npcSet.end(); ++p)
		{
			if ((*p)->getBlood() <= 0 && (*p)->getState() != nDEATH) {
				(*p)->setState(nDEATH);
				player1->addScore(1000);
				(*p)->SetPosition((*p)->GetX(), (*p)->GetY() + (*p)->GetRatioSize().cy / 2);  //死亡状态改变位置
				(*p)->setDeathTime(GetTickCount());
				AddRandomResource((*p)->GetX(), (*p)->GetY());
			}
			if ((*p)->getState() == nATTACK1 || (*p)->getState() == nATTACK2)
			{
				if ((*p)->LoopFrameOnce())
				{
					(*p)->setState(nWALK);
				}
			}
			else {
				(*p)->LoopFrame();
			}
		}
	}

	//更新第一关第三关卡
	if (c1p3_npcSet.size()>0) {
		for (vNpcSet::iterator p = c1p3_npcSet.begin(); p != c1p3_npcSet.end(); ++p)
		{
			if ((*p)->getBlood() <= 0 && (*p)->getState() != nDEATH) {
				(*p)->setState(nDEATH);
				player1->addScore(1000);
				(*p)->SetPosition((*p)->GetX(), (*p)->GetY() + (*p)->GetRatioSize().cy / 2);  //死亡状态改变位置
				(*p)->setDeathTime(GetTickCount());
				AddRandomResource((*p)->GetX(), (*p)->GetY());
			}
			if ((*p)->getState() == nATTACK1 || (*p)->getState() == nATTACK2)
			{
				if ((*p)->LoopFrameOnce())
				{
					(*p)->setState(nWALK);
				}
			}
			else {
				(*p)->LoopFrame();
			}
		}
	}
	//更新第一关第四关卡
	if (c1p4_npcSet.size()>0) {
		for (vNpcSet::iterator p = c1p4_npcSet.begin(); p != c1p4_npcSet.end(); ++p)
		{
			if ((*p)->getBlood() <= 0 && (*p)->getState() != nDEATH) {
				(*p)->setState(nDEATH);
				player1->addScore(1000);
				(*p)->SetPosition((*p)->GetX(), (*p)->GetY() + (*p)->GetRatioSize().cy / 2);  //死亡状态改变位置
				(*p)->setDeathTime(GetTickCount());
				AddRandomResource((*p)->GetX(), (*p)->GetY());
			}
			if ((*p)->getState() == nATTACK1 || (*p)->getState() == nATTACK2)
			{
				if ((*p)->LoopFrameOnce())
				{
					(*p)->setState(nWALK);
				}
			}
			else {
				(*p)->LoopFrame();
			}
		}
	}
	//更新第一关第五关卡
	if (c1p5_npcSet.size()>0) {
		for (vNpcSet::iterator p = c1p5_npcSet.begin(); p != c1p5_npcSet.end(); ++p)
		{
			if ((*p)->getBlood() <= 0 && (*p)->getState() != nDEATH) {
				(*p)->setState(nDEATH);
				player1->addScore(1000);
				(*p)->SetPosition((*p)->GetX(), (*p)->GetY() + (*p)->GetRatioSize().cy / 2);  //死亡状态改变位置
				(*p)->setDeathTime(GetTickCount());
				AddRandomResource((*p)->GetX(), (*p)->GetY());
			}
			if ((*p)->getState() == nATTACK1 || (*p)->getState() == nATTACK2)
			{
				if ((*p)->LoopFrameOnce())
				{
					(*p)->setState(nWALK);
				}
			}
			else {
				(*p)->LoopFrame();
			}
		}
	}
	//更新第一关第六关卡
	if (c1p6_npcSet.size()>0) {
		for (vNpcSet::iterator p = c1p6_npcSet.begin(); p != c1p6_npcSet.end(); ++p)
		{
			if ((*p)->getBlood() <= 0 && (*p)->getState() != nDEATH) {
				(*p)->setState(nDEATH);
				player1->addScore(1000);
				(*p)->SetPosition((*p)->GetX(), (*p)->GetY() + (*p)->GetRatioSize().cy / 2);  //死亡状态改变位置
				(*p)->setDeathTime(GetTickCount());
				AddRandomResource((*p)->GetX(), (*p)->GetY());
			}
			if ((*p)->getState() == nATTACK1 || (*p)->getState() == nATTACK2)
			{
				if ((*p)->LoopFrameOnce())
				{
					(*p)->setState(nWALK);
				}
			}
			else {
				(*p)->LoopFrame();
			}
		}
	}

	//更新第一关第七关卡
	if (curLevel == 1 && Checkpoint1 == 7)
	{
		if ((boss1)->getBlood() <= 0 && (boss1)->getState() != bDEATH) {
			(boss1)->setState(bDEATH);
			player1->addScore(5000);
			(boss1)->SetPosition((boss1)->GetX(), (boss1)->GetY() + (boss1)->GetRatioSize().cy / 2);  //死亡状态改变位置
			(boss1)->setDeathTime(GetTickCount());
		}
		else {
			if (boss1->getState() == bATTACK1 || boss1->getState() == bATTACK2) {
				if (boss1->LoopFrameOnce()) {
					boss1->setState(bWALK);
				}
			}
			else if (boss1->getState() == bATTACK3) {
				if (boss1->LoopFrameOnce())
				{
					LoadBossBomb(boss1, boss_bomb_set, 44);
					boss1->setState(bWALK);
				}
			}
			else {
				boss1->LoopFrame();
			}
			UpdateBombPosBoss(&boss_bomb_set);  //Boss炮弹动画更新
		}
	}



	//********************************
	//更新第二关第一关卡
	if (c2p1_npcSet.size()>0) {
		for (vNpcSet::iterator p = c2p1_npcSet.begin(); p != c2p1_npcSet.end(); ++p)
		{
			if ((*p)->getBlood() <= 0 && (*p)->getState() != nDEATH) {
				(*p)->setState(nDEATH);
				player1->addScore(1000);
				(*p)->SetPosition((*p)->GetX(), (*p)->GetY() + (*p)->GetRatioSize().cy / 2);  //死亡状态改变位置
				(*p)->setDeathTime(GetTickCount());
				AddRandomResource((*p)->GetX(), (*p)->GetY());
			}
			if ((*p)->getState() == nATTACK1 || (*p)->getState() == nATTACK2)
			{
				if ((*p)->LoopFrameOnce())
				{
					(*p)->setState(nWALK);
				}
			}
			else {
				(*p)->LoopFrame();
			}
		}
	}
	//更新第二关第二关卡
	if (c2p2_npcSet.size()>0) {
		for (vNpcSet::iterator p = c2p2_npcSet.begin(); p != c2p2_npcSet.end(); ++p)
		{
			if ((*p)->getBlood() <= 0 && (*p)->getState() != nDEATH) {
				(*p)->setState(nDEATH);
				player1->addScore(1000);
				(*p)->SetPosition((*p)->GetX(), (*p)->GetY() + (*p)->GetRatioSize().cy / 2);  //死亡状态改变位置
				(*p)->setDeathTime(GetTickCount());
				AddRandomResource((*p)->GetX(), (*p)->GetY());
			}
			if ((*p)->getState() == nATTACK1 || (*p)->getState() == nATTACK2)
			{
				if ((*p)->LoopFrameOnce())
				{
					(*p)->setState(nWALK);
				}
			}
			else {
				(*p)->LoopFrame();
			}
		}
	}
	//更新第二关第三关卡
	if (c2p3_npcSet.size()>0) {
		for (vNpcSet::iterator p = c2p3_npcSet.begin(); p != c2p3_npcSet.end(); ++p)
		{
			if ((*p)->getBlood() <= 0 && (*p)->getState() != nDEATH) {
				(*p)->setState(nDEATH);
				player1->addScore(1000);
				(*p)->SetPosition((*p)->GetX(), (*p)->GetY() + (*p)->GetRatioSize().cy / 2);  //死亡状态改变位置
				(*p)->setDeathTime(GetTickCount());
				AddRandomResource((*p)->GetX(), (*p)->GetY());
			}
			if ((*p)->getState() == nATTACK1 || (*p)->getState() == nATTACK2)
			{
				if ((*p)->LoopFrameOnce())
				{
					(*p)->setState(nWALK);
				}
			}
			else {
				(*p)->LoopFrame();
			}
		}
	}
	//更新第二关第四关卡
	if (c2p4_npcSet.size()>0) {
		for (vNpcSet::iterator p = c2p4_npcSet.begin(); p != c2p4_npcSet.end(); ++p)
		{
			if ((*p)->getBlood() <= 0 && (*p)->getState() != nDEATH) {
				(*p)->setState(nDEATH);
				player1->addScore(1000);
				(*p)->SetPosition((*p)->GetX(), (*p)->GetY() + (*p)->GetRatioSize().cy / 2);  //死亡状态改变位置
				(*p)->setDeathTime(GetTickCount());
				AddRandomResource((*p)->GetX(), (*p)->GetY());
			}
			if ((*p)->getState() == nATTACK1 || (*p)->getState() == nATTACK2)
			{
				if ((*p)->LoopFrameOnce())
				{
					(*p)->setState(nWALK);
				}
			}
			else {
				(*p)->LoopFrame();
			}
		}
	}
	//更新第二关第五关卡
	if (curLevel == 2 && Checkpoint2 == 5)
	{
		if ((boss2)->getBlood() <= 0 && (boss2)->getState() != bDEATH) {
			(boss2)->setState(bDEATH);
			player1->addScore(5000);
			(boss2)->SetPosition((boss2)->GetX(), (boss2)->GetY() + (boss2)->GetRatioSize().cy / 2);  //死亡状态改变位置
			(boss2)->setDeathTime(GetTickCount());
		}
		else {
			if (boss2->getState() == bATTACK1 || boss2->getState() == bATTACK2) {
				if (boss2->LoopFrameOnce()) {
					boss2->setState(bWALK);
				}
			}
			else if (boss2->getState() == bATTACK3) {
				if (boss2->LoopFrameOnce())
				{
//					LoadBossBomb(boss2, boss_bomb_set, 44);
					boss2->setState(bWALK);
				}
			}
			else {
				boss2->LoopFrame();
			}
//			UpdateBombPos(&boss_bomb_set);  //Boss炮弹动画更新
		}
	}
	//更新第三关第一关卡
	if (curLevel == 3 && Checkpoint3 == 1)
	{
		if ((boss3)->getBlood() <= 0 && (boss3)->getState() != bRESTAND) {
			(boss3)->setState(bRESTAND);
			player1->addScore(10000);
			(boss3)->setDeathTime(GetTickCount());
		}
		else {
			if (boss3->getState() == bATTACK1 || boss3->getState() == bATTACK2) {
				if (boss3->LoopFrameOnce()) {
					boss3->setState(bWALK);
				}
			}
			else if (boss3->getState() == bATTACK3) {
				if (boss3->LoopFrameOnce())
				{
					LoadBossBomb(boss3, boss_bomb_set, 44);
					boss3->setState(bWALK);
				}
			}
			else if (boss3->getState() == bRESTAND)
			{
				if (boss3->LoopFrameOnce())
				{
					updateGate(3, 2);
					boss4->SetPosition(boss3->GetX(), boss3->GetY());
				}
			}
			else {
				boss3->LoopFrame();
			}
			UpdateBombPosBoss(&boss_bomb_set);  //Boss炮弹动画更新
		}
	}
	if (curLevel == 3 && Checkpoint3 == 2)
	{
		if ((boss4)->getBlood() <= 0 && (boss4)->getState() != bDEATH) {
			(boss4)->setState(bDEATH);
			player1->addScore(10000);
			(boss4)->SetPosition((boss4)->GetX(), (boss4)->GetY() + (boss4)->GetRatioSize().cy);  //死亡状态改变位置
			(boss4)->setDeathTime(GetTickCount());
		}
		else {
			if (boss4->getState() == bATTACK1 || boss4->getState() == bATTACK2) {
				if (boss4->LoopFrameOnce()) {
					boss4->setState(bWALK);
				}
			}
			else if (boss4->getState() == bATTACK3) {
				if (boss4->LoopFrameOnce())
				{
					LoadBossBomb(boss4, boss_bomb_set, 44);
					boss4->setState(bWALK);
				}
			}
			else {
				boss4->LoopFrame();
			}
			UpdateBombPosBoss(&boss_bomb_set);  //Boss炮弹动画更新
		}
	}

	//大乱斗模式
	if (curLevel == 3 && Checkpoint3 == 999)
	{
		if ((boss1)->getBlood() <= 0 && (boss1)->getState() != bDEATH) {
			(boss1)->setState(bDEATH);
			(boss1)->SetPosition((boss1)->GetX(), (boss1)->GetY() + (boss1)->GetRatioSize().cy);  //死亡状态改变位置
			(boss1)->setDeathTime(GetTickCount());
		}
		else {
			if (boss1->getState() == bATTACK1 || boss1->getState() == bATTACK2) {
				if (boss1->LoopFrameOnce()) {
					boss1->setState(bWALK);
				}
			}
			else if (boss1->getState() == bATTACK3) {
				if (boss1->LoopFrameOnce())
				{
					LoadBossBomb(boss1, boss_bomb_set, 44);
					boss1->setState(bWALK);
				}
			}
			else {
				boss1->LoopFrame();
			}
		}
		if ((boss2)->getBlood() <= 0 && (boss2)->getState() != bDEATH) {
			(boss2)->setState(bDEATH);
			(boss2)->SetPosition((boss2)->GetX(), (boss2)->GetY() + (boss2)->GetRatioSize().cy);  //死亡状态改变位置
			(boss2)->setDeathTime(GetTickCount());
		}
		else {
			if (boss2->getState() == bATTACK1 || boss2->getState() == bATTACK2) {
				if (boss2->LoopFrameOnce()) {
					boss2->setState(bWALK);
				}
			}
			else if (boss2->getState() == bATTACK3) {
				if (boss2->LoopFrameOnce())
				{
					LoadBossBomb(boss2, boss_bomb_set, 44);
					boss2->setState(bWALK);
				}
			}
			else {
				boss2->LoopFrame();
			}
		}

		if ((boss3)->getBlood() <= 0 && (boss3)->getState() != bDEATH) {
			(boss3)->setState(bDEATH);
			(boss3)->setDeathTime(GetTickCount());
		}
		else {
			if (boss3->getState() == bATTACK1 || boss3->getState() == bATTACK2) {
				if (boss3->LoopFrameOnce()) {
					boss3->setState(bWALK);
				}
			}
			else if (boss3->getState() == bATTACK3) {
				if (boss3->LoopFrameOnce())
				{
					LoadBossBomb(boss3, boss_bomb_set, 44);
					boss3->setState(bWALK);
				}
			}
			else {
				boss3->LoopFrame();
			}
		}

		if ((boss4)->getBlood() <= 0 && (boss4)->getState() != bDEATH) {
			(boss4)->setState(bDEATH);
			(boss4)->SetPosition((boss4)->GetX(), (boss4)->GetY() + (boss4)->GetRatioSize().cy);  //死亡状态改变位置
			(boss4)->setDeathTime(GetTickCount());
		}
		else {
			if (boss4->getState() == bATTACK1 || boss4->getState() == bATTACK2) {
				if (boss4->LoopFrameOnce()) {
					boss4->setState(bWALK);
				}
			}
			else if (boss4->getState() == bATTACK3) {
				if (boss4->LoopFrameOnce())
				{
					LoadBossBomb(boss4, boss_bomb_set, 44);
					boss4->setState(bWALK);
				}
			}
			else {
				boss4->LoopFrame();
			}
		}
		UpdateBombPos(&boss_bomb_set);  //Boss炮弹动画更新
	}

}

void EngineConfig::UpdateResources()
{
	for (vector<Resource*>::iterator res = resource.begin(); res != resource.end(); ) {
		if ((*res)->isDead()) {
			res = resource.erase(res);
		}
		else {
			++res;
		}
	}
}

//游戏开始界面初始化
void EngineConfig::GameStartInit()
{
	registerNum1 = 0;
	registerNum2 = 0;
	registerNum4 = GetRandomNum(0, 1);
	if (registerNum4 == 0) {
		registerNum3 = -wndWidth / 4;
	}
	else {
		registerNum3 = wndWidth / 4 * 5;
	}
	startTime = GetTickCount();
	endTime = GetTickCount();
}

void EngineConfig::GameInit()
{
	//加载游戏界面和游戏角色
	InitParams();
	LoadMenus();
	if (!ds.CreateDS(m_hWnd))
	{
		return;
	}
	LoadMusic();
//	AddRandomResource(wndWidth / 4, wndHeight * 2 / 3);
//	AddRandomResource(wndWidth / 10, wndHeight * 2 / 3);
	//开始游戏
	GameState = GAME_START;

	GameStartInit();

	bk1_buffer.Play(true);
}

void EngineConfig::InitParams()
{
	who = zy;
	canScroll = false;
	startTime = endTime = GetTickCount();
	flag = false;
	keyValid1 = true;
	keyValid2 = true;
	curLevel = 1;
	checkClear = false;
	curStage = 1;//初始为第一关
	boss1 = boss2 = boss3 = boss4 = nullptr;
}

void EngineConfig::GameBegin()
{
	LoadMap();
	LoadPlayer();
	updateGate(curLevel, curStage);

	player1->setInvincible(false);

	keyValid1 = keyValid2 = true;

	holdGun = false;
	bullets = 0;
	type = NOGUN;

	scrollSprite = new T_Sprite();
	scrollSprite->SetDir(DIR_RIGHT);
	scrollSprite->SetRatio(player1->GetRatio());

	player1->setState(STAND);

	this->SetFrame(FRAME_SPEED);
	//why修改，加载血条
	bloodBk = new T_Graph(L".\\res\\Pics\\zyBlood.png");
	life = new T_Graph(L".\\res\\Pics\\life.png");
}

//返回是否可以滚动
bool EngineConfig::checkScreenScroll()
{
	bool flag = false;
	//判断是否清空小兵
	if (checkClear)
	{
		flag = true;
		//判断是否滚动到下一关卡位置
		if (abs(t_scene.getSceneX() + map1[curStage]) < 40)
		{
			//到达制定位置
			flag = false;
			checkClear = false;

			//更新关卡变量
			int levelCount;
			switch (curLevel)
			{
			case 1:
				//第一关
				levelCount = sizeof(map1) / sizeof(map1[0]);
				if (curStage == levelCount)
				{
					curLevel++;
					curStage = 1;
					t_scene.RemoveAll();
					GameBegin();
					return false;
				}
				else
				{
					curStage++;
				}
				break;
			case 2:
				//第二关
				levelCount = sizeof(map2) / sizeof(map2[0]);
				if (curStage == levelCount)
				{
					curLevel++;
					curStage = 1;
//					t_scene.RemoveAll();
					GameBegin();
					return false;
				}
				else
				{
					curStage++;
				}
				break;
			case 3:
				return false;
			default:
				break;
			}
			updateGate(curLevel, curStage);
		}
	}
	return flag;
}

//检查NPC是否清空
bool EngineConfig::checkNpcClear()
{
	if (curLevel == 1)
	{
		switch (curStage)
		{
		case 1:
			return check_npc_clear(&c1p1_npcSet);
		case 2:
			return check_npc_clear(&c1p2_npcSet);
		case 3:
			return check_npc_clear(&c1p3_npcSet);
		case 4:
			return check_npc_clear(&c1p4_npcSet);
		case 5:
			return check_npc_clear(&c1p5_npcSet);
		case 6:
			return check_npc_clear(&c1p6_npcSet);
		case 7:
			if (boss1->getState() == bDEATH)
			{
				curLevel++;
				curStage = 1;
				GameChangeInit();
				GameState = GAME_LEVELCHANGE;
				return true;

//				t_scene.RemoveAll();
//				GameBegin();
			}
			return false;
		default:
			break;
		}
	}
	if (curLevel == 2)
	{
		switch (curStage)
		{
		case 1:
			return check_npc_clear(&c2p1_npcSet);
		case 2:
			return check_npc_clear(&c2p2_npcSet);
		case 3:
			return check_npc_clear(&c2p3_npcSet);
		case 4:
			return check_npc_clear(&c2p4_npcSet);
		case 5:
			if (boss2->getState() == bDEATH)
			{
				curLevel++;
				curStage = 1;

				GameChangeInit();
				GameState = GAME_LEVELCHANGE;
				return true;
//				t_scene.RemoveAll();
//				GameBegin();
			}
		default:
			break;
		}
	}
	if (curLevel == 3 && curStage != 999)
	{
		if (player1->IsVisible() == false)
			player1->SetVisible(true);
		if (boss4 != nullptr)
		if (boss4->getState() == bDEATH)
		{
			curStage = 999;
			GameChangeInit();
			GameState = GAME_LEVELCHANGE;
		}
	}
	else if (curLevel == 3)
	{
		if (boss1->getBlood() <= 0 && boss2->getBlood() <= 0 && boss3->getBlood() <= 0 && boss4->getBlood() <= 0)
		{
			GameChangeInit();
			GameState = GAME_LEVELCHANGE;
		}
	}

	return false;
}
bool EngineConfig::check_npc_clear(vNpcSet* npc_set)
{
	bool flag = true;
	for (vNpcSet::iterator p = npc_set->begin(); p != npc_set->end(); p++)
	{
		if ((*p)->getState() != nDEATH)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

//检测人物攻击
bool EngineConfig::checkPlayerAttack(vNpcSet* npc_set)
{
	bool flag = false;
	for (vNpcSet::iterator p = npc_set->begin(); p != npc_set->end(); ++p)
	{
		if ((*p)->getState() == nHINT)
		{
			flag = true;
		}
	}
	return flag;
}

void EngineConfig::GameChangeInit(){
	
	GameState = GAME_LEVELCHANGE;
	pGame->SetFrame(6);
	player1->SetStartTime(GetTickCount());
	registerNum1 = 0;
	overStage = 0;
	player1->SetVisible(false);
}

void EngineConfig::GameLogic()
{
	if (GameState != GAME_PAUSE && GameState != GAME_LEVELCHANGE && GameState == GAME_RUN)
	{
		if (player1->GetY() < (wndHeight-player1->GetRatioSize().cy) / 3 && player1->getState() != JUMP)
		{
			player1->SetPosition(player1->GetX(), (wndHeight - player1->GetRatioSize().cy) / 3);
		}

		//无敌
		if (player1->IsInvincible())
		{
			if (GetTickCount() - player1->getInvincibleTime() > 5000)
			{
				player1->setInvincible(false);
			}
		}

		//TODO:
		GameKeyAction();
		UpdateNpcPos();


		if (player1->IsActive() || player2->IsActive())
		{
			UpdatePlayerPos();	//移动玩家角色
		}

		UpdateBombPos(&player_bomb_set);

		checkClear = checkNpcClear();

		canScroll = checkScreenScroll();

		//滚动屏幕
		if (canScroll)
		{
			if (player1->GetDir() == DIR_RIGHT || player1->GetDir() == DIR_RIGHT_UP || player1->GetDir() == DIR_RIGHT_DOWN)
			{
				scrollSprite->SetWidth(player1->GetWidth());
				scrollSprite->SetSpeed(player1->GetXSpeed());
				scrollSprite->SetPosition(player1->GetX(), player1->GetY());
				t_scene.ScrollScene(scrollSprite);
				
			}
			if (player2 != nullptr)
			{
				if (player2->GetDir() == DIR_RIGHT || player2->GetDir() == DIR_RIGHT_UP || player2->GetDir() == DIR_RIGHT_DOWN)
				{
					scrollSprite->SetWidth(player2->GetWidth());
					scrollSprite->SetSpeed(player2->GetXSpeed());
					scrollSprite->SetPosition(player2->GetX(), player2->GetY());
					if (player1 != nullptr)
					{
						if (player1->GetX() > 10 && player2->GetXSpeed() > 0 ||
							player1->GetX() < wndWidth - 10 - player2->GetRatioSize().cx && player2->GetXSpeed() < 0)
						{
							t_scene.ScrollScene(scrollSprite);
						}
					}
					else
					{
						t_scene.ScrollScene(scrollSprite);
					}
				}
			}
		}

		//检查玩家攻击
		CheckAttack();


		if (curLevel == 1)
		{
			switch (curStage)
			{
			case 1:
				isAttacked1 = checkPlayerAttack(&c1p1_npcSet);
				break;
			case 2:
				isAttacked1 = checkPlayerAttack(&c1p2_npcSet);
				break;
			case 3:
				isAttacked1 = checkPlayerAttack(&c1p3_npcSet);
				break;
			case 4:
				isAttacked1 = checkPlayerAttack(&c1p4_npcSet);
				break;
			case 5:
				isAttacked1 = checkPlayerAttack(&c1p5_npcSet);
				break;
			case 6:
				isAttacked1 = checkPlayerAttack(&c1p6_npcSet);
				break;
			case 7:
				isAttacked1 = player1->playerAttack(boss1);
			default:
				break;
			}
		}

		if (curLevel == 2)
		{
			switch (curStage)
			{
			case 1:
				isAttacked1 = checkPlayerAttack(&c2p1_npcSet);
				break;
			case 2:
				isAttacked1 = checkPlayerAttack(&c2p2_npcSet);
				break;
			case 3:
				isAttacked1 = checkPlayerAttack(&c2p3_npcSet);
				break;
			case 4:
				isAttacked1 = checkPlayerAttack(&c2p4_npcSet);
				break;
			case 5:
				isAttacked1 = player1->playerAttack(boss2);
			default:
				break;
			}
		}

		if (curLevel == 3 && Checkpoint3 == 1)
		{
			isAttacked1 = player1->playerAttack(boss3);
			cout << "boss3"<< isAttacked1 << endl;
		}
		if (curLevel == 3 && Checkpoint3 == 2)
		{
			isAttacked1 == player1->playerAttack(boss4);
			cout<< "boss4" << isAttacked1 << endl;
		}
		if (curLevel == 3 && Checkpoint3 == 999)
		{
			if (boss1->getState() != bDEATH)
			{
				isAttacked1 |= player1->playerAttack(boss1);
			}
			if (boss2->getState() != bDEATH)
			{
				isAttacked1 |= player1->playerAttack(boss2);
			}
			if (boss3->getState() != bDEATH)
			{
				isAttacked1 |= player1->playerAttack(boss3);
			}
			if (boss4->getState() != bDEATH)
			{
				isAttacked1 |= player1->playerAttack(boss4);
			}
		}


		//死亡
		if (player1->getBlood() <= 0 && !player1->IsDead())
		{
			player1->SetDead(true);
			player1->setState(DEATH);
		}

		if ((curLevel == 1 && curStage == 7) || (curLevel == 2 && curStage == 5) || curLevel == 3)
		{
			if(GetTickCount() - resource_interval > RESOURCE_INTERVAL)
			{
				AddRandomResource(GetRandomNum(100, wndWidth - 100), GetRandomNum(wndHeight / 2, wndHeight - 50));
				resource_interval = GetTickCount();
			}
		}

		UpdateResources();
	}
	UpdateAnimation();
}

//销毁函数
void EngineConfig::Destroy()
{
	t_scene.RemoveAll();
	
}

void EngineConfig::GameEnd()
{
	Destroy();
}


void EngineConfig::GamePaint(const HDC hdc)
{
	if (GameState == GAME_START) {
		main->DrawMenu(hdc);

		T_Graph* p = NULL;
		if ((GetTickCount() - endTime) > 200) {
			registerNum2++;
			registerNum2 %= 7;
			if (registerNum4 == 0) {
				registerNum3 += 50;
			}
			else {
				registerNum3 -= 50;
			}
			if (registerNum3 <= -wndWidth / 2 || registerNum3 >= wndWidth * 5 / 4) {
				registerNum4 = GetRandomNum(0, 1);
				if (registerNum4 == 0) {
					registerNum3 = -wndWidth / 4;
				}
				else {
					registerNum3 = wndWidth * 5 / 4;
				}
			}
			endTime = GetTickCount();
		}
		delete p;
		p = NULL;

		RectF textRec;
		for (int i = 0; i < 3; i++) {
			textRec.X = (float)(MENU_SPACE * 4 + i);
			textRec.Y = (float)(MENU_SPACE * 3 + i);
			textRec.Width = (float)wndWidth;
			textRec.Height = (float)wndHeight / 5;
			T_Graph::PaintText(hdc, textRec, L"三国战纪 [v-0.1.2]", 36, L"黑体", Color::White, FontStyleBold, StringAlignmentNear);
		}
		textRec.X = MENU_SPACE * 4 + 4;
		textRec.Y = MENU_SPACE * 3 + 4;
		textRec.Width = (float)wndWidth;
		textRec.Height = (float)wndHeight / 5;
		T_Graph::PaintText(hdc, textRec, L"三国战纪 [v-0.1.2]", 36, L"黑体", Color::Black, FontStyleBold, StringAlignmentNear);
	}
	else if (GameState == GAME_ABOUT) {
		about->DrawMenu(hdc);
		mask.PaintBlank(hdc, wndWidth / 8, wndHeight / 6, wndWidth * 3 / 4, wndHeight * 2 / 3, Color::Black, 80);
		RectF textRec;
		for (int i = 0; i < 3; i++) {
			textRec.X = (float)(i);
			textRec.Y = (float)(i);
			textRec.Width = (float)wndWidth;
			textRec.Height = (float)wndHeight / 5;
			T_Graph::PaintText(hdc, textRec, L"三国战纪 [v-0.1.2]", 36, L"黑体", Color::White, FontStyleBold, StringAlignmentCenter);
		}
		textRec.X = 4;
		textRec.Y = 4;
		textRec.Width = (float)wndWidth;
		textRec.Height = (float)wndHeight / 5;
		T_Graph::PaintText(hdc, textRec, L"三国战纪 [v-0.1.2]", 36, L"黑体", Color::Black, FontStyleBold, StringAlignmentCenter);

		T_Graph* p = NULL;
		for (int i = 0; i < 2; i++) {
			p = new T_Graph(members[i]);
			p->PaintRegion(p->GetBmpHandle(), hdc, wndWidth / 8 + (wndWidth / 4 - p->GetImageWidth() * 0.25) / 2 + i * wndWidth / 4, wndHeight / 5 + 3 * MENU_SPACE, 0, 0, p->GetImageWidth(), p->GetImageHeight(), 0.25, 0, 255);
			delete p;
			textRec.X = wndWidth / 8 + wndWidth / 4 * i;
			textRec.Y = wndHeight / 3;
			textRec.Width = (float)wndWidth / 4;
			textRec.Height = (float)wndHeight / 2;
			T_Graph::PaintText(hdc, textRec, intros[i], 15, L"黑体", Color::White, FontStyleBold, StringAlignmentCenter);
		}
	}
	else if (GameState == GAME_HELP) {
		help->DrawMenu(hdc);
		mask.PaintBlank(hdc, wndWidth / 6, wndHeight / 6, wndWidth * 2 / 3, wndHeight * 2 / 3, Color::Black, 80);
		RectF textRec;
		for (int i = 0; i < 3; i++) {
			textRec.X = (float)(i);
			textRec.Y = (float)(i);
			textRec.Width = (float)wndWidth;
			textRec.Height = (float)wndHeight / 5;
			T_Graph::PaintText(hdc, textRec, L"三国战纪 [v-0.1.2]", 36, L"黑体", Color::White, FontStyleBold, StringAlignmentCenter);
		}
		textRec.X = 4;
		textRec.Y = 4;
		textRec.Width = (float)wndWidth;
		textRec.Height = (float)wndHeight / 5;
		T_Graph::PaintText(hdc, textRec, L"三国战纪 [v-0.1.2]", 36, L"黑体", Color::Black, FontStyleBold, StringAlignmentCenter);

		textRec.X = 0;
		textRec.Y = wndHeight / 4;
		textRec.Width = (float)wndWidth;
		textRec.Height = (float)wndHeight / 2;
		T_Graph::PaintText(hdc, textRec, L"键位控制\n\n\nW   向上\nS   向下\nA   向左\nD   向右\nK   跳跃\nP   暂停\n   J  攻击 / 拾取", 20, L"黑体", Color::White, FontStyleBold, StringAlignmentCenter);
	}
	else if (GameState == GAME_CHOOSEPLAYER) {
		choosePlayer->DrawMenu(hdc);
		RectF textRec;

		for (int i = 0; i < 3; i++) {
			textRec.X = (float)(i);
			textRec.Y = (float)(MENU_SPACE + i);
			textRec.Width = (float)wndWidth;
			textRec.Height = (float)wndHeight / 5;
			T_Graph::PaintText(hdc, textRec, L"三国战纪 [v-0.1.2]", 36, L"黑体", Color::Black, FontStyleBold, StringAlignmentCenter);
		}
		textRec.X = 4;
		textRec.Y = (float)(MENU_SPACE + 4);
		textRec.Width = (float)wndWidth;
		textRec.Height = (float)wndHeight / 5;
		T_Graph::PaintText(hdc, textRec, L"三国战纪 [v-0.1.2]", 36, L"黑体", Color::White, FontStyleBold, StringAlignmentCenter);

		T_Graph* pic;
		wstring path;
		//why修改 选择角色
		path = L".\\res\\Pics\\Luan.png";
		pic = new T_Graph(path);
		pic->PaintRegion(pic->GetBmpHandle(), hdc, ((wndWidth - pic->GetImageWidth() * 2) / 2), wndHeight / 6, 0, 0, pic->GetImageWidth(), pic->GetImageHeight(), 1.8, 0, 255);

		startTime = GetTickCount();
		if (startTime - endTime > 600) {
			endTime = startTime;
			flag = !flag;
		}
		if (flag) {
			for (int i = 0; i < 2; i++) {
				textRec.X = (float)(4 * i);
				textRec.Y = (float)(wndHeight / 3 * 2 + 4 * i);
				textRec.Width = (float)wndWidth;
				textRec.Height = (float)wndHeight / 5;
				T_Graph::PaintText(hdc, textRec, L"CHOOSE YOUR CHARACTER", 30, L"黑体", i == 1 ? Color::White : Color::Black, FontStyleBold, StringAlignmentCenter);

				textRec.X = (float)(4 * i);
				textRec.Y = (float)(3.5 * MENU_SPACE + wndHeight / 3 * 2 + 4 * i);
				textRec.Width = (float)wndWidth;
				textRec.Height = (float)wndHeight / 5;
				T_Graph::PaintText(hdc, textRec, L"PRESS [A] OR [D] TO CHOOSE", 30, L"黑体", i == 1 ? Color::White : Color::Black, FontStyleBold, StringAlignmentCenter);
			}
		}
	}
	else if (GameState == GAME_LEVELCHANGE)
	{
		t_scene.Draw(hdc, 0, 0);
		PaintBlood(hdc);
		LevelChange(hdc);
	}
	else if (GameState == GAME_PAUSE) {
		t_scene.Draw(hdc, 0, 0);
		PaintBlood(hdc);
		mask.PaintBlank(hdc, 0, 0, wndWidth, wndHeight, Color::Black, 100);
		pause->DrawMenu(hdc, 255, true);
	}
	else if (GameState == GAME_OVER)
	{
		t_scene.Draw(hdc, 0, 0);
		PaintBlood(hdc);
		mask.PaintBlank(hdc, 0, 0, wndWidth, wndHeight, Color::Black, 100);
		over->DrawMenu(hdc, 255, true);
	}
	else if (GameState == GAME_RUN) {
		t_scene.Draw(hdc, 0, 0);
		PaintBlood(hdc);
	}
}
//画子弹
void EngineConfig::paintBullets(const HDC hdc)
{
	gun->PaintRegion(gun->GetBmpHandle(), hdc, MENU_SPACE, wndHeight - gun->GetImageHeight() * 3.5, 0, 0, gun->GetImageWidth(), gun->GetImageHeight(), 3.0, 0, 255);
	RectF textRec;
	wchar_t buf[256];
	wsprintf(buf, L"BULLETS:  %d", bullets);
	for (int i = 0; i < 2; i++) {
		textRec.X = (float)(gun->GetImageWidth() * 3.0 + 3 * MENU_SPACE + i);
		textRec.Y = (float)(wndHeight - gun->GetImageHeight() * 3.5 + i);
		textRec.Width = (float)wndWidth;
		textRec.Height = gun->GetImageHeight() * 3.0;
		T_Graph::PaintText(hdc, textRec, buf, 30, L"黑体", Color::Black, FontStyleBold, StringAlignmentNear);
	}
	textRec.X = (float)(gun->GetImageWidth() * 3.0 + 3 * MENU_SPACE + 2);
	textRec.Y = (float)(wndHeight - gun->GetImageHeight() * 3.5 + 2);
	textRec.Width = (float)wndWidth;
	textRec.Height = gun->GetImageHeight() * 3.0;
	T_Graph::PaintText(hdc, textRec, buf, 30, L"黑体", Color::White, FontStyleBold, StringAlignmentNear);
}

//检查捡东西
//TODO:
bool EngineConfig::checkPickItems(Player* p)
{
	bool flag = false;
	const int y = p->GetY() + p->GetRatioSize().cy;
	const int x = p->GetX() + p->GetRatioSize().cx / 2;
	for (vector<Resource*>::iterator res = resource.begin(); res != resource.end(); ++res) {
		if ((*res)->IsVisible() && x >= (*res)->GetX() && x <= (*res)->GetX() + (*res)->getRatioWidth() && y >= (*res)->GetY() && y <= (*res)->GetY() + (*res)->getRatioHeight())
		{
			flag = true;
			(*res)->setDead(true);
			(*res)->SetVisible(false);
			int x = (*res)->getReward();
			player1->addBlood((*res)->getReward());
			break;
		}
	}
	return flag;
}

void EngineConfig::GameKeyAction(const int ActionType)
{
	if (GameState == GAME_START) {
		if (GetAsyncKeyState(VK_UP) < 0)
			main->MenuKeyDown(VK_UP);
		if (GetAsyncKeyState(VK_DOWN) < 0)
			main->MenuKeyDown(VK_DOWN);
		if (GetAsyncKeyState(VK_LEFT) < 0)
			main->MenuKeyDown(VK_LEFT);
		if (GetAsyncKeyState(VK_RIGHT) < 0)
			main->MenuKeyDown(VK_RIGHT);
		if (GetAsyncKeyState(VK_RETURN) < 0) {
			if (main->GetMenuIndex() >= 0) {
				switch (main->GetMenuIndex()) {
				case 0:
					GameState = GAME_CHOOSEPLAYER;
					break;
				case 1:
					GameState = GAME_ABOUT;
					break;
				case 2:
					GameState = GAME_HELP;
					break;
				case 3:
					SendMessage(m_hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
					break;
				}
			}
		}
	}
	else if (GameState == GAME_ABOUT) {
		if (GetAsyncKeyState(VK_UP) < 0)
			about->MenuKeyDown(VK_UP);
		if (GetAsyncKeyState(VK_DOWN) < 0)
			about->MenuKeyDown(VK_DOWN);
		if (GetAsyncKeyState(VK_LEFT) < 0)
			about->MenuKeyDown(VK_LEFT);
		if (GetAsyncKeyState(VK_RIGHT) < 0)
			about->MenuKeyDown(VK_RIGHT);
		if (GetAsyncKeyState(VK_RETURN) < 0) {
			if (about->GetMenuIndex() >= 0) {
				switch (about->GetMenuIndex()) {
				case 0:
					GameStartInit();
					GameState = GAME_START;
					break;
				case 1:
					GameState = GAME_CHOOSEPLAYER;
					break;
				case 2:
					GameState = GAME_HELP;
					break;
				case 3:
					SendMessage(m_hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
					break;
				}
			}
		}
	}
	else if (GameState == GAME_HELP) {
		if (GetAsyncKeyState(VK_UP) < 0)
			help->MenuKeyDown(VK_UP);
		if (GetAsyncKeyState(VK_DOWN) < 0)
			help->MenuKeyDown(VK_DOWN);
		if (GetAsyncKeyState(VK_LEFT) < 0)
			help->MenuKeyDown(VK_LEFT);
		if (GetAsyncKeyState(VK_RIGHT) < 0)
			help->MenuKeyDown(VK_RIGHT);
		if (GetAsyncKeyState(VK_RETURN) < 0) {
			if (help->GetMenuIndex() >= 0) {
				switch (help->GetMenuIndex()) {
				case 0:
					GameStartInit();
					GameState = GAME_START;
					break;
				case 1:
					GameState = GAME_CHOOSEPLAYER;
					break;
				case 2:
					SendMessage(m_hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
					break;
				}
			}
		}
	}
	else if (GameState == GAME_PAUSE) {
		if (GetAsyncKeyState(VK_UP) < 0)
			pause->MenuKeyDown(VK_UP);
		if (GetAsyncKeyState(VK_DOWN) < 0)
			pause->MenuKeyDown(VK_DOWN);
		if (GetAsyncKeyState(VK_LEFT) < 0)
			pause->MenuKeyDown(VK_LEFT);
		if (GetAsyncKeyState(VK_RIGHT) < 0)
			pause->MenuKeyDown(VK_RIGHT);
		if (GetAsyncKeyState(VK_RETURN) < 0) {
			if (pause->GetMenuIndex() >= 0) {
				switch (pause->GetMenuIndex()) {
				case 0:
					GameState = GAME_RUN;
					break;
				case 1:
					GameState = GAME_HELP;
					break;
				case 2:
					GameStartInit();
					GameState = GAME_START;
					break;
				case 3:
					SendMessage(m_hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
					break;
				}
			}
		}
	}
	else if (GameState == GAME_OVER) {
		if (GetAsyncKeyState(VK_UP) < 0)
			over->MenuKeyDown(VK_UP);
		if (GetAsyncKeyState(VK_DOWN) < 0)
			over->MenuKeyDown(VK_DOWN);
		if (GetAsyncKeyState(VK_LEFT) < 0)
			over->MenuKeyDown(VK_LEFT);
		if (GetAsyncKeyState(VK_RIGHT) < 0)
			over->MenuKeyDown(VK_RIGHT);
		if (GetAsyncKeyState(VK_RETURN) < 0) {
			if (over->GetMenuIndex() >= 0) {
				switch (over->GetMenuIndex()) {
				case 0:
					Destroy();
					GameBegin();
					GameState = GAME_CHOOSEPLAYER;
					break;
				case 1:
					GameStartInit();
					GameState = GAME_START;
					break;
				case 2:
					SendMessage(m_hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
					break;
				}
			}
		}
	}
	else if (GameState == GAME_CHOOSEPLAYER) {
		if (CheckKey(0x41)) {
			who = Jack;
		}
		else if (CheckKey(0x44)) {
			who = Luan;
		}
		if (GetAsyncKeyState(VK_UP) < 0)
			choosePlayer->MenuKeyDown(VK_UP);
		if (GetAsyncKeyState(VK_DOWN) < 0)
			choosePlayer->MenuKeyDown(VK_DOWN);
		if (GetAsyncKeyState(VK_LEFT) < 0)
			choosePlayer->MenuKeyDown(VK_LEFT);
		if (GetAsyncKeyState(VK_RIGHT) < 0)
			choosePlayer->MenuKeyDown(VK_RIGHT);
		if (GetAsyncKeyState(VK_RETURN) < 0) {
			if (choosePlayer->GetMenuIndex() >= 0) {
				switch (choosePlayer->GetMenuIndex()) {
				case 0:
					GameStartInit();
					GameState = GAME_START;
					break;
				case 1:
					GameBegin();
					GameState = GAME_RUN;
					break;
				case 2:
					SendMessage(m_hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
					break;
				}
			}
		}
	}
	else if (GameState == GAME_RUN)
	{
		if (ActionType == KEY_SYS_NONE) {
			if (CheckKey(0x50)) {
				GameState = GAME_PAUSE;
				return;
			}
			// 0x57 W 0x41 A 0x53 S 0x44 D 0x4A J 0x4B K
			//跳
			if (CheckKey(0x4B) && keyValid1 && !player1->IsDead()) {
				player1->setState(JUMP);
				keyValid1 = false;
				return;
			}
			if (CheckKey(VK_NUMPAD2) && keyValid2 && player2 != nullptr) {
				player2->setState(JUMP);
				keyValid2 = false;
				return;
			}

			//攻击1
			if (CheckKey(0x4A) && keyValid1 && !player1->IsDead()) {
				//判断是否捡东西
				if(checkPickItems(player1))
				{
					int x = player1->GetX(), y;
					y = player1->GetY();
					player1->SetPosition(x, y);
					player1->setState(PICK);
				}
				else if (isAttacked1)
				{
					box2_buffer.Restore();
					box2_buffer.Play(false);
//					player1->setBlood(player1->getBlood() - 2);
					player1->setState(BOX1);
				}
				else
				{
					box1_buffer.Restore();
					box1_buffer.Play(false);
//					player1->setBlood(player1->getBlood() - 2);
					player1->setState(BOX1);
				}
				keyValid1 = false;
				return;
			}
			//攻击  u
			if (CheckKey(0x55) && keyValid1 && !player1->IsDead()) {
				if (isAttacked1)
				{
					box2_buffer.Restore();
					box2_buffer.Play(false);
					//					player1->setBlood(player1->getBlood() - 2);
					player1->setState(BOX2);
				}
				else
				{
					box2_buffer.Restore();
					box2_buffer.Play(false);
					//					player1->setBlood(player1->getBlood() - 2);
					player1->setState(BOX2);
				}
				keyValid1 = false;
				return;
			}



			if (CheckKey(VK_NUMPAD1) && keyValid2 && player2 != nullptr) {
				//判断是否捡东西
				if (checkPickItems(player1))
				{
					int x = player1->GetX();
					player1->setState(PICK);
				}
				else
				{
					player2->setState(BOX1);
				}
				keyValid2 = false;
				return;
			}

			//左
			if (CheckKey(0x41) && keyValid1 && !player1->IsDead()) {
				if (CheckKey(0x57)) {
					player1->SetDir(DIR_LEFT_UP);
					player1->SetRotation(TRANS_VFLIP_ROT180);
				}
				else if (CheckKey(0x53)) {
					player1->SetDir(DIR_LEFT_DOWN);
					player1->SetRotation(TRANS_VFLIP_ROT180);
				}
				else {
					player1->SetDir(DIR_LEFT);
					player1->SetRotation(TRANS_VFLIP_ROT180);
				}
				WalkOrRun1();
			}
			//右
			else if (CheckKey(0x44) && keyValid1 && !player1->IsDead()) {
				if (CheckKey(0x57)) {
					player1->SetDir(DIR_RIGHT_UP);
					player1->SetRotation(TRANS_NONE);
				}
				else if (CheckKey(0x53)) {
					player1->SetDir(DIR_RIGHT_DOWN);
					player1->SetRotation(TRANS_NONE);
				}
				else {
					player1->SetDir(DIR_RIGHT);
					player1->SetRotation(TRANS_NONE);
				}
				WalkOrRun1();
			}
			//上
			else if (CheckKey(0x57) && keyValid1 && !player1->IsDead()) {
				player1->SetDir(DIR_UP);
				WalkOrRun1();
			}
			//下
			else if (CheckKey(0x53) && keyValid1 && !player1->IsDead()) {
				player1->SetDir(DIR_DOWN);
				WalkOrRun1();
			}
			else if (!player1->IsDead()){
				switch (player1->getState()) {
				case WALK:
				case RUN:
					player1->setState(STAND);
					if ((player1->getLastState() == WALK )) {
						last_dir1 = player1->GetDir();
						player1->SetStartTime(GetTickCount());
					}
					break;
				default:
					break;
				}
			}

			if (CheckKey(VK_LEFT) && keyValid2 && player2 != nullptr) {
				if (CheckKey(VK_UP)) {
					player2->SetDir(DIR_LEFT_UP);
					player2->SetRotation(TRANS_VFLIP_ROT180);
				}
				else if (CheckKey(VK_DOWN)) {
					player2->SetDir(DIR_LEFT_DOWN);
					player2->SetRotation(TRANS_VFLIP_ROT180);
				}
				else {
					player2->SetDir(DIR_LEFT);
					player2->SetRotation(TRANS_VFLIP_ROT180);
				}
				WalkOrRun2();
			}
			else if (CheckKey(VK_RIGHT) && keyValid2 && player2 != nullptr) {
				if (CheckKey(VK_UP)) {
					player2->SetDir(DIR_RIGHT_UP);
					player2->SetRotation(TRANS_NONE);
				}
				else if (CheckKey(VK_DOWN)) {
					player2->SetDir(DIR_RIGHT_DOWN);
					player2->SetRotation(TRANS_NONE);
				}
				else {
					player2->SetDir(DIR_RIGHT);
					player2->SetRotation(TRANS_NONE);
				}
				WalkOrRun2();
			}
			else if (CheckKey(VK_UP) && keyValid2 && player2 != nullptr) {
				player2->SetDir(DIR_UP);
				WalkOrRun2();
			}
			else if (CheckKey(VK_DOWN) && keyValid2 && player2 != nullptr) {
				player2->SetDir(DIR_DOWN);
				WalkOrRun2();
			}
			else if (player2 != nullptr)
			{
			
				
			}
		}
	}
}

void EngineConfig::WalkOrRun1() const
{
	const PlayerState state = player1->getState();
	PlayerState lastState = player1->getLastState();
	if (player1->GetDir() == last_dir1 && (state == WALK ) && (GetTickCount() - player1->GetStartTime()) < INTERVAL) {
			player1->setState(RUN);
	}
	else {
		switch (state) {
		case STAND:
			player1->setState(WALK);
			break;
		default:;
		}
	}
}

void EngineConfig::WalkOrRun2() const
{
	const PlayerState  state = player2->getState();
	PlayerState lastState = player2->getLastState();
}

void EngineConfig::GameMouseAction(int x, int y, int Action)
{
	if (GameState == GAME_START) {
		if (Action == MOUSE_MOVE) {
			main->MenuMouseMove(x, y);
		}
		if (Action == MOUSE_LCLICK) {
			int index = main->MenuMouseClick(x, y);
			if (index >= 0) {
				switch (index) {
				case 0:
					GameBegin();
					GameState = GAME_CHOOSEPLAYER;
					GameState = GAME_RUN;
					break;
				case 1:
					GameState = GAME_ABOUT;
					break;
				case 2:
					GameState = GAME_HELP;
					break;
				case 3:
					SendMessage(m_hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
					break;
				}
			}
		}
	}
	else if (GameState == GAME_ABOUT) {
		if (Action == MOUSE_MOVE) {
			about->MenuMouseMove(x, y);
		}
		if (Action == MOUSE_LCLICK) {
			int index = about->MenuMouseClick(x, y);
			if (index >= 0) {
				switch (index) {
				case 0:
					GameStartInit();
					GameState = GAME_START;
					break;
				case 1:
					GameState = GAME_CHOOSEPLAYER;
					break;
				case 2:
					SendMessage(m_hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
					break;
				}
			}
		}
	}
	else if (GameState == GAME_HELP) {
		if (Action == MOUSE_MOVE) {
			help->MenuMouseMove(x, y);
		}
		if (Action == MOUSE_LCLICK) {
			int index = help->MenuMouseClick(x, y);
			if (index >= 0) {
				switch (index) {
				case 0:
					GameStartInit();
					GameState = GAME_START;
					break;
				case 1:
					GameState = GAME_CHOOSEPLAYER;
					break;
				case 2:
					SendMessage(m_hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
					break;
				}
			}
		}
	}
	else if (GameState == GAME_PAUSE) {
		if (Action == MOUSE_MOVE) {
			pause->MenuMouseMove(x, y);
		}
		if (Action == MOUSE_LCLICK) {
			int index = pause->MenuMouseClick(x, y);
			if (index >= 0) {
				switch (index) {
				case 0:
					GameState = GAME_RUN;
					break;
				case 1:
					GameState = GAME_HELP;
					break;
				case 2:
					GameStartInit();
					GameState = GAME_START;
					break;
				case 3:
					SendMessage(m_hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
					break;
				}
			}
		}
	}
	else if (GameState == GAME_OVER) {
		if (Action == MOUSE_MOVE) {
			over->MenuMouseMove(x, y);
		}
		if (Action == MOUSE_LCLICK) {
			int index = over->MenuMouseClick(x, y);
			if (index >= 0) {
				switch (index) {
				case 0:
					t_scene.RemoveAll();
					GameBegin();
					GameState = GAME_RUN;
					break;
				case 1:
					GameStartInit();
					GameState = GAME_START;
					break;
				case 2:
					SendMessage(m_hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
					break;
				}
			}
		}
	}
	else if (GameState == GAME_CHOOSEPLAYER) {
		if (Action == MOUSE_MOVE) {
			choosePlayer->MenuMouseMove(x, y);
		}
		if (Action == MOUSE_LCLICK) {
			int index = choosePlayer->MenuMouseClick(x, y);
			if (index >= 0) {
				switch (index) {
				case 0:
					GameStartInit();
					GameState = GAME_START;
					break;
				case 1:
					GameBegin();
					GameState = GAME_RUN;
					break;
				case 2:
					SendMessage(m_hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
					break;
				}
			}
		}
	}
	else if (GameState == GAME_RUN) {

	}
}
