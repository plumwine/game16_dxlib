#include "Enemy.h"
#include "../Player/Player.h"

Enemy::Enemy(Vector2 pos)
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	enemyM = LoadGraph("img\\TankATKR.png");
	enemyPos = Vector2(400,100);
	MoveFlag = FALSE;
}

void Enemy::Update()
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (key&PAD_INPUT_1)//ZÉLÅ[
	{
		Change();
	}
	
	if (MoveFlag)
	{
		

		Vector2 Velocity = Vector2(0, 0);

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

		enemyPos += Velocity;
	
	}
}

void Enemy::Render()
{
	DrawRotaGraph(enemyPos.x, enemyPos.y, 1.0f, 180/180.0f*DX_PI_F, enemyM, TRUE, FALSE);
}

void Enemy::Change()
{
	if (!MoveFlag)
	{
		MoveFlag = TRUE;
	}
	else
	{
		MoveFlag = FALSE;
	}
}
