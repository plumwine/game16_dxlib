#include "Title.h"


//コンストラクタ
Title::Title()
{
}

//デスストラクタ
Title::~Title()
{
	delete input;
}
//初期化
void Title::initialize()
{
	input = new Input;
	input->init();            //input初期化
	isSceneEnd = false;       //最初はfalse
	CWindow::getInstance().log("今タイトルに切り替わった");
}
//更新
void Title::update(float deltaTime)
{
	input->update();         //input更新
	if (input->isKeyDown(KEYCORD::Z))
	{
		isSceneEnd = true;    //Z押されたらシーン終了（今だけ）
	}

}
//描画
void Title::draw()
{
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
