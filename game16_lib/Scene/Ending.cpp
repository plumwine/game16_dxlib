#include "Ending.h"



Ending::Ending()
{
}


Ending::~Ending()
{
}

void Ending::initialize()
{
	m_pInput = new Input;
	m_pInput->init();            //input������
	isSceneEnd = false;       //�ŏ���false
	CWindow::getInstance().log("���G���f�B���O�ɐ؂�ւ����");
}

void Ending::update(float deltaTime)
{
	m_pInput->update();         //input�X�V
	if (m_pInput->isKeyDown(KEYCORD::Z))
	{
		isSceneEnd = true;    //Z�����ꂽ��V�[���I���i�������j
	}
}

void Ending::draw(Renderer* renderer)
{
}

void Ending::shutdown()
{
}

bool Ending::isEnd()
{
	return isSceneEnd;
}

std::string Ending::nextScene()
{
	return "title";
}
