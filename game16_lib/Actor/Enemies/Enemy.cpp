#include "Enemy.h"
#include "../Player/Player.h"

Enemy::Enemy(Vector2 pos,CharactorManager *c)
{
	charaManager = c;
}

Enemy::~Enemy()
{
	delete input;
	delete rend;
}



void Enemy::initialize()
{
	b_mHp = 100;
	b_mPosittion = Vector2(500, 100);
	MoveFlag = FALSE;
	input = new Input;
	input->init();
	rend = new Renderer;
	b_mCircleSize = 32.0f;
	b_mType = Type::ENEMY;
}

void Enemy::update(float deltaTime)
{
	
	b_mVelocity = Vector2(0, 0);
	input->update();
	
	//æ‚ÁŽæ‚èŒã
	if (b_mType == Type::PLAYER)
	{

		if (input->isKeyState(KEYCORD::ARROW_UP))
		{
			b_mVelocity.y -= 4;
		}
		if (input->isKeyState(KEYCORD::ARROW_DOWN))
		{
			b_mVelocity.y += 4;
		}
		if (input->isKeyState(KEYCORD::ARROW_RIGHT))
		{
			b_mVelocity.x += 4;
		}
		if (input->isKeyState(KEYCORD::ARROW_LEFT))
		{
		    b_mVelocity.x -= 4;
		}
		if (input->isKeyDown(KEYCORD::SPACE))
		{
			Shot(Vector2(b_mPosittion.x, b_mPosittion.y));
		}
		if (input->isKeyDown(KEYCORD::X))
		{
			CShot(Vector2(b_mPosittion.x, b_mPosittion.y));
		}
		b_mPosittion += b_mVelocity;
	}
}

void Enemy::draw(Renderer * renderer)
{
	if (b_mType == Type::ENEMY)
	{
		DrawCircle(b_mPosittion.x+64/2 , b_mPosittion.y+32, b_mCircleSize, GetColor(255, 0, 0), FALSE);
	}
	else
	{
		DrawCircle(b_mPosittion.x+64/2, b_mPosittion.y+32, b_mCircleSize, GetColor(0, 0, 255), FALSE);
	}
	
	rend->draw2D("enemy", Vector2(b_mPosittion.x, b_mPosittion.y), Vector2(0, 0), Vector2(64, 64), Vector2(b_mCircleSize, b_mCircleSize), Vector2(1.0f, 1.0f), b_mAngle, 255);
	//rend->draw2D("enemy", Vector2(b_mPosittion.x, b_mPosittion.y), Vector2(0, 0), Vector2(64, 64));
}

void Enemy::hit(BaseObject & other)
{
	if (other.getType() == Type::PLAYER_BULLET&&b_mType == Type::ENEMY)
	{
		b_mHp -= 10;
		DrawCircle(b_mPosittion.x + 32, b_mPosittion.y + 32, b_mCircleSize, GetColor(255, 255, 0), TRUE);
		if (b_mHp <= 0)
		{
			b_mIsDeath = true;
		}
	}
	
}

void Enemy::Shot(Vector2 pos)
{
	charaManager->add(new Bullet(pos, charaManager));
}

void Enemy::CShot(Vector2 pos)
{
	charaManager->add(new ChangeBullet(pos, charaManager));
}

bool Enemy::getIsDeath() const
{
	return b_mIsDeath;
}

Type Enemy::getType() const
{
	return b_mType;
}

Vector2 Enemy::getPpstion() const
{
	return Vector2();
}

float Enemy::getCircleSize() const
{
	return b_mCircleSize;
}

Type Enemy::ChangeType() 
{
	b_mType = Type::PLAYER;
	return b_mType;
}
