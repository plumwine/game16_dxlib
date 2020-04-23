#include "GameManager.h"
#include "../Scene/SceneManager.h"
#include "../Scene/Title.h"
#include "../Scene/GamePlay.h"
#include "../Scene/Ending.h"

//コンストラクタ
GameManager::GameManager()
{
}

//デスストラクタ
GameManager::~GameManager()
{
}
//初期化
void GameManager::initialize()
{
	sceneInitialize();   //シーン関係を初期化
}
void GameManager::sceneInitialize()
{
	//シーンマネージャーの初期化
	SceneManager::createInstance();  //シーンマネージャーの生成
	//シーンの追加
	SceneManager::getInstance().add("title"   , new Title);
	SceneManager::getInstance().add("gameplay", new GamePlay);
	SceneManager::getInstance().add("ending"  , new Ending);
	SceneManager::getInstance().change("title");      //最初はタイトルに設定
}
//更新
void GameManager::update()
{
	//シーンマネージャーの更新処理
	SceneManager::getInstance().update(0);  //とりあえず更新
}
