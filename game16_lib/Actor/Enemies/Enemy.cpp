#include "Enemy.h"
#include <random>


Enemy::Enemy(Vector2 pos, CharactorManager *c):mTimer(new Timer())
{
	charaManager = c;
	b_mPosittion = pos;
}

Enemy::~Enemy()
{
	delete input;
	delete rend;
	delete mTimer;
}



void Enemy::initialize()
{
	b_mHp = 2;
	input = new Input;
	input->init();
	rend = new Renderer;
	b_mCircleSize = 16.0f;
	b_mType = Type::ENEMY;
    b_mAngle = 180.0f;
	mTimer->initialize();
	b_mSpeed = 70.0f;

}

void Enemy::update(float deltaTime)
{
	mTimer->update(deltaTime);

	input->update();
	b_mVelocity = Vector2(0, 0);

	//–³“GŽžŠÔ
	if (DamgeFlag&&mTimer->timerSet(2))
	{
		DamgeFlag = FALSE;
	}

	if (input->isKeyDown(KEYCORD::V))
	{
		SubChange();
	}

	if (b_mType == Type::SUB_PLAYER)
	{
		b_mPosittion  =charaManager->searchPlayer()  + Vector2(30,30);
		if (input->isKeyDown(KEYCORD::C))
		{
			Jibaku(Vector2(b_mPosittion.x, b_mPosittion.y));
		}
	}
	
	if (b_mType == Type::ENEMY)
	{
		b_mVelocity.y += 2;
		if (mTimer->timerSet(2))
		{
			Shot(Vector2(b_mPosittion.x,b_mPosittion.y));
		}
		if (b_mHp <= 0)
		{
			b_mIsDeath = true;
		}
		if (b_mPosittion.y > WindowInfo::WindowHeight
			|| b_mPosittion.x > WindowInfo::WindowWidth
			|| b_mPosittion.x < 0)
		{
			b_mIsDeath = true;
		}
		b_mPosittion += b_mVelocity;
	}
	


	//æ‚ÁŽæ‚èŒã
	if (b_mType == Type::PLAYER&&!b_mEndFlag)
	{
		
		if (input->isKeyState(KEYCORD::ARROW_UP))
		{
			b_mVelocity.y -= 6;
		}
		if (input->isKeyState(KEYCORD::ARROW_DOWN))
		{
			b_mVelocity.y += 6;
		}
		if (input->isKeyState(KEYCORD::ARROW_RIGHT))
		{
			b_mVelocity.x += 6;
		}
		if (input->isKeyState(KEYCORD::ARROW_LEFT))
		{
			b_mVelocity.x -= 6;
		}
		if (input->isKeyDown(KEYCORD::SPACE))
		{
			Shot(Vector2(b_mPosittion.x, b_mPosittion.y));
		}
		if (input->isKeyDown(KEYCORD::X))
		{
			CShot(Vector2(b_mPosittion.x, b_mPosittion.y));
		}
		
		if (b_mHp <= 0)
		{
			b_mEndFlag = true;
		}
		
		b_mPosittion += b_mVelocity*deltaTime*b_mSpeed;
	}

	
	
	
}

void Enemy::draw(Renderer * renderer)
{

	if (b_mType == Type::ENEMY)
	{
		DrawCircle(b_mPosittion.x+64/2, b_mPosittion.y + 64/2, b_mCircleSize, GetColor(255, 0, 0), FALSE);
		rend->draw2D("enemy", Vector2(b_mPosittion.x, b_mPosittion.y), Vector2(0, 0), Vector2(64, 64), Vector2(32, 32), Vector2(1.0f, 1.0f), b_mAngle, 255);
	}
	else if(!b_mEndFlag)
	{
		if (DamgeFlag)
		{
			b_mArpha = 155;
		}
		else
		{
			b_mArpha = 255;
		}

		DrawCircle(b_mPosittion.x+64/2, b_mPosittion.y +64/2, b_mCircleSize, GetColor(0, 0, 255), FALSE);
		b_mAngle = 0.0f;
		rend->draw2D("enemy", Vector2(b_mPosittion.x, b_mPosittion.y), Vector2(0, 0), Vector2(64, 64), Vector2(32, 32), Vector2(1.0f, 1.0f), b_mAngle, b_mArpha);
		if (b_mType == Type::PLAYER)
		{
			rend->drawNumber("hpNumber", Vector2(150, 10), b_mHp, 0, Vector2(0, 0), Vector2(1, 1), 0.0f, 255);
		}
		
	}

	if (b_mEndFlag)
	{
		rend->drawText("Font", "GAMEOVER", Vector2(100, 450), Vector2(0, 0), Vector2(1, 1), 0.0f, 255);
	}
	
}

void Enemy::hit(BaseObject & other)
{
	if (other.getType() == Type::PLAYER_BULLET&&b_mType == Type::ENEMY)
	{
		b_mHp -= 1;
		DrawCircle(b_mPosittion.x + 64/2, b_mPosittion.y + 64/2, b_mCircleSize, GetColor(255, 255, 0), TRUE);
	}

	
		if (other.getType() == Type::ENEMY_BULLET&&b_mType == Type::PLAYER)
		{
			b_mHp -= 1;
			DrawCircle(b_mPosittion.x + 64 / 2, b_mPosittion.y + 64 / 2, b_mCircleSize, GetColor(255, 255, 0), TRUE);
			mTimer->initialize();
			DamgeFlag = TRUE;
		}

		if (other.getType() == Type::ENEMY&&b_mType == Type::PLAYER)
		{
			b_mHp -= 1;
			DrawCircle(b_mPosittion.x + 64 / 2, b_mPosittion.y + 64 / 2, b_mCircleSize, GetColor(255, 255, 0), TRUE);
			mTimer->initialize();
			DamgeFlag = TRUE;
		}
	
	
	if (other.getType() == Type::CHANGE_BULLET&&b_mType == Type::ENEMY)
	{
		//Å‰‚ÍT‚¦‚É
		b_mType = Type::SUB_PLAYER;
	}

}

void Enemy::Shot(Vector2 pos)
{
	charaManager->add(new Bullet(pos, charaManager,b_mType,0.0f));
}

void Enemy::CShot(Vector2 pos)
{
	charaManager->add(new ChangeBullet(pos, charaManager));
}

void Enemy::Jibaku(Vector2 pos)
{
	charaManager->add(new Bom(pos,charaManager));
	b_mIsDeath = true;
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
	return b_mPosittion;
}



float Enemy::getCircleSize() const
{
	return b_mCircleSize;
}

void Enemy::setIsDeath(bool isDeath)
{
	b_mIsDeath = isDeath;
}


void Enemy::SubChange()
{
	switch (b_mType)
	{
	case PLAYER:
		b_mType = Type::SUB_PLAYER;
		break;
	case SUB_PLAYER:
		b_mType = Type::PLAYER;
		b_mPosittion = charaManager->searchPlayer() + Vector2(-30, -30);
		break;
	default:
		break;
	}
}


