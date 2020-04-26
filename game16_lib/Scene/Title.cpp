#include "Title.h"
#include"DxLib.h"

#include "../Device/Loader/TextuerLoad.h"

//コンストラクタ
Title::Title()
{
}

//デスストラクタ
Title::~Title()
{
	delete m_pInput;
}
//初期化
void Title::initialize()
{
	m_pInput = new Input;
	m_pInput->init();         //input初期化
	isSceneEnd = false;       //最初はfalse
	//CWindow::getInstance().log("今タイトルに切り替わった");
}
//更新
void Title::update(float deltaTime)
{
	m_pInput->update();         //input更新
	if (m_pInput->isKeyDown(KEYCORD::Z))
	{
		isSceneEnd = true;    //Z押されたらシーン終了（今だけ）
	}
	
}
//描画
void Title::draw(Renderer* renderer)
{
	renderer->draw2D("tank", Vector2(200, 200), Vector2(0,0), Vector2(64,64));
}
//終了処理
void Title::shutdown()
{
}
//シーンが終わったかどうか
bool Title::isEnd()
{
	return isSceneEnd;
}
//次のシーン
std::string Title::nextScene()
{
	return "gameplay";
}
