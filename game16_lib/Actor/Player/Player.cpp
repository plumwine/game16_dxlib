#include "Player.h"



Player::Player(Vector2 pos)
{
}

Player::~Player()
{
	delete input;
}

void Player::Init()
{
	
	playerM = LoadGraph("img\\F4.png");
	playerPos = Vector2(400, 500);
	MoveFlag = FALSE;
	input = new Input;
	input->init();
	rend = new Renderer;
}

void Player::Update()
{
	
	input->update();
	if (input->isKeyDown(KEYCORD::X))
	{
		Change();
	}
	
	if (!MoveFlag)
	{

		Vector2 Velocity = Vector2(0, 0);

		if (input->isKeyDown(KEYCORD::ARROW_UP))
		{
			Velocity.y -= 4;
		}
		if (input->isKeyDown(KEYCORD::ARROW_DOWN))
		{
			Velocity.y += 4;
		}
		if (input->isKeyDown(KEYCORD::ARROW_RIGHT))
		{
			Velocity.x += 4;
		}
		if (input->isKeyDown(KEYCORD::ARROW_LEFT))
		{
			Velocity.x -= 4;
		}

		playerPos += Velocity;
	
	}

}

void Player::Render()
{
	DrawRotaGraph(playerPos.x, playerPos.y, 1.0f, 0, playerM, TRUE,FALSE);
	//rend->draw2D("img\\F4.png",Vector2(playerPos.x,playerPos.y),Vector2(64,64),Vector2(64,64),TRUE,FALSE);
}

void Player::Change()
{
	if (MoveFlag)
	{
		MoveFlag = FALSE;
	}
	else
	{
		MoveFlag = TRUE;
	}
}
