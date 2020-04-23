#include "Ending.h"



Ending::Ending()
{
}


Ending::~Ending()
{
}

void Ending::initialize()
{
	input = new Input;
	input->init();            //input������
	isSceneEnd = false;       //�ŏ���false
	CWindow::getInstance().log("���G���f�B���O�ɐ؂�ւ����");
}

void Ending::update(float deltaTime)
{
	input->update();         //input�X�V
	if (input->isKeyDown(KEYCORD::Z))
	{
		isSceneEnd = true;    //Z�����ꂽ��V�[���I���i�������j
	}
}

void Ending::draw()
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