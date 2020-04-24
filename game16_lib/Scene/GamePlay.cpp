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
	m_pInput = new Input;
	m_pInput->init();          //input������
	isSceneEnd = false;        //�ŏ���false
	CWindow::getInstance().log("���Q�[���v���C�ɐ؂�ւ����");
}

void GamePlay::update(float deltaTime)
{
	m_pInput->update();         //input�X�V
	if (m_pInput->isKeyDown(KEYCORD::Z))
	{
		isSceneEnd = true;    //Z�����ꂽ��V�[���I���i�������j
	}
}

void GamePlay::draw(Renderer* renderer)
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
