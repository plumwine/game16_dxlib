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
	input->init();            //input������
	isSceneEnd = false;        //�ŏ���false
	CWindow::getInstance().log("���Q�[���v���C�ɐ؂�ւ����");
	player = new Player(Vector2(0,0));
	player->Init();
	enemy = new Enemy(Vector2(0, 0));
	enemy->Init();

}

void GamePlay::update(float deltaTime)
{
	input->update();//input�X�V
	player->Update();
	enemy->Update();

	player->Render();
	enemy->Render();
	if (input->isKeyDown(KEYCORD::Z))
	{
		isSceneEnd = true;    //Z�����ꂽ��V�[���I���i�������j
	}
	SetBackgroundColor(0, 255, 255);
}

void GamePlay::draw()
{
	
}

void GamePlay::shutdown()
{
}
//�V�[�����I����
bool GamePlay::isEnd()
{
	return isSceneEnd;
}
//���̃V�[���i�뎚�ɂ͋C���t����j
std::string GamePlay::nextScene()
{
	return "ending";
}
