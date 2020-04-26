#include "LoadScene.h"
#include "../Device/Loader/TextuerLoad.h"

LoadScene::LoadScene()
{
}


LoadScene::~LoadScene()
{
}

void LoadScene::initialize()
{	
	TextuerLoad::createInstance();   //テクスチャロードを作成
	TextuerLoad::getInstance().add("tank","img/TankATK.png");  //画像の追加（テスト）
	//ゲームシーン
	TextuerLoad::getInstance().add("player", "img/F4.png");
	TextuerLoad::getInstance().add("enemy", "img/TankATKR.png");
	TextuerLoad::getInstance().add("bullet", "img/Bullet.png");
	CWindow::getInstance().log("読み込みが終わったので終了します");
	isSceneEnd = true;       //ここまでエラーがなかったら終了状態にする
}

void LoadScene::update(float deltaTime)
{
}

void LoadScene::draw(Renderer* renderer)
{
}

void LoadScene::shutdown()
{
}

bool LoadScene::isEnd()
{
	return isSceneEnd;
}

std::string LoadScene::nextScene()
{
	return "title";       //終了したらtitleに行く
}
