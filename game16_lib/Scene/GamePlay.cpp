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
}

void GamePlay::update(float deltaTime)
{
	input->update();         //input�X�V
	if (input->isKeyDown(KEYCORD::Z))
	{
		isSceneEnd = true;    //Z�����ꂽ��V�[���I���i�������j
	}
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
