#include "Enemy.h"
#include "../Player/Player.h"

Enemy::Enemy(Vector2 pos)
{
}

Enemy::~Enemy()
{
	delete input;
}

void Enemy::Init()
{
	enemyM = LoadGraph("img\\TankATKR.png");
	enemyPos = Vector2(400,100);
	MoveFlag = FALSE;
	input = new Input;
	input->init();
	rend = new Renderer;

}

void Enemy::Update()
{
	
	if (input->isKeyDown(KEYCORD::X))
	{
		Change();
	}
	
	if (MoveFlag)
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
		enemyPos += Velocity;
	
	}
}

void Enemy::Render()
{
	DrawRotaGraph(enemyPos.x, enemyPos.y, 1.0f, 180/180.0f*DX_PI_F, enemyM, TRUE, FALSE);
	//rend->draw2D("img\\TankATKR.png", Vector2(enemyPos.x, enemyPos.y), Vector2(1, 1), Vector2(1, 1), true, false);
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
