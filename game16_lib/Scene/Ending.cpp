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
	input->init();            //input初期化
	isSceneEnd = false;       //最初はfalse
	CWindow::getInstance().log("今エンディングに切り替わった");
}

void Ending::update(float deltaTime)
{
	input->update();         //input更新
	if (input->isKeyDown(KEYCORD::Z))
	{
		isSceneEnd = true;    //Z押されたらシーン終了（今だけ）
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
