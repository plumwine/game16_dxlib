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

		if (input->isKeyState(KEYCORD::ARROW_UP))
		{
			Velocity.y -= 4;
		}
		if (input->isKeyState(KEYCORD::ARROW_DOWN))
		{
			Velocity.y += 4;
		}
		if (input->isKeyState(KEYCORD::ARROW_RIGHT))
		{
			Velocity.x += 4;
		}
		if (input->isKeyState(KEYCORD::ARROW_LEFT))
		{
			Velocity.x -= 4;
		}
		if (input->isKeyDown(KEYCORD::SPACE))
		{
			Shot(Vector2( playerPos.x,playerPos.y));
		}

		playerPos += Velocity;
	
	}

}

void Player::Render()
{
	//bullet->draw();
	rend->draw2D("player",Vector2(playerPos.x,playerPos.y),Vector2(0,0),Vector2(64,64));
	
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

void Player::Shot(Vector2 pos)
{
	
	bullet->update(0);
	CWindow::getInstance().log("”­ŽË");
}
