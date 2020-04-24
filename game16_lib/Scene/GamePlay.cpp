#include "GamePlay.h"

GamePlay::GamePlay()
{
}


GamePlay::~GamePlay()
{
	delete input;
}

void GamePlay::initialize()
{
	input = new Input;
	input->init();            //input初期化
	isSceneEnd = false;        //最初はfalse
	CWindow::getInstance().log("今ゲームプレイに切り替わった");
	player = new Player(Vector2(0,0));
	player->Init();
	enemy = new Enemy(Vector2(0, 0));
	enemy->Init();

}

void GamePlay::update(float deltaTime)
{
	input->update();//input更新
	player->Update();
	enemy->Update();

	player->Render();
	enemy->Render();
	if (input->isKeyDown(KEYCORD::Z))
	{
		isSceneEnd = true;    //Z押されたらシーン終了（今だけ）
	}
	SetBackgroundColor(0, 255, 255);
}

void GamePlay::draw()
{
	
}

void GamePlay::shutdown()
{
}
//シーンを終える
bool GamePlay::isEnd()
{
	return isSceneEnd;
}
//次のシーン（誤字には気お付ける）
std::string GamePlay::nextScene()
{
	return "ending";
}
