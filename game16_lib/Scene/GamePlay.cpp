#include "GamePlay.h"

GamePlay::GamePlay()
{
}


GamePlay::~GamePlay()
{
	delete m_pInput;
}

void GamePlay::initialize()
{
	charaManager = new CharactorManager();
	charaManager->clear();
	m_pInput = new Input;
	m_pInput->init();          //input初期化
	isSceneEnd = false;   //最初はfalse
	
	charaManager->add(new Player(Vector2(0, 0), charaManager));
	charaManager->add(new Enemy(Vector2(0, 0), charaManager));
	
	
	//CWindow::getInstance().log("今ゲームプレイに切り替わった");
}

void GamePlay::update(float deltaTime)
{
	charaManager->update(deltaTime);
	m_pInput->update();         //input更新
	if (m_pInput->isKeyDown(KEYCORD::Z))
	{
		isSceneEnd = true;    //Z押されたらシーン終了（今だけ）
	}
	SetBackgroundColor(0, 0, 0);
}

void GamePlay::draw(Renderer* renderer)
{
	charaManager->draw(renderer);
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
