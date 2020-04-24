#include "Player.h"

Player::Player(Vector3 pos)
{
}

Player::~Player()
{
}

void Player::Init()
{
	playerM = LoadGraph("img\\F4.png");
	playerPos = Vector3(400, 500, 0);
	MoveFlag = FALSE;

}

void Player::Update()
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (key&PAD_INPUT_1)//ZÉLÅ[
	{
		Change();
	}
	
	if (!MoveFlag)
	{

		Vector3 Velocity = Vector3(0, 0, 0);

		if (key&PAD_INPUT_UP)
		{
			Velocity.y -= 4;
		}
		if (key&PAD_INPUT_DOWN)
		{
			Velocity.y += 4;
		}
		if (key&PAD_INPUT_RIGHT)
		{
			Velocity.x += 4;
		}
		if (key&PAD_INPUT_LEFT)
		{
			Velocity.x -= 4;
		}

		playerPos += Velocity;
	
	}

}

void Player::Render()
{
	DrawRotaGraph(playerPos.x, playerPos.y, 1.0f, 0, playerM, TRUE,FALSE);
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
