#include "Player.h"



Player::Player(Vector2 pos,CharactorManager *c) :mTimer(new Timer())
{
	charaManager = c;
	b_mPosittion = pos;

}

Player::~Player()
{
	delete input;
	delete rend;
}

void Player::initialize()
{
	DamgeFlag = FALSE;
	input = new Input;
	input->init();
	rend = new Renderer;
	b_mCircleSize = 16.0f;
	b_mType = Type::PLAYER;
	b_mHp = 3;
	b_mSpeed = 40.0f;
	mTimer->initialize();
	
}

void Player::update(float deltaTime)
{
	
	b_mVelocity = Vector2(0, 0);
	input->update();
	mTimer->update(deltaTime);

	//–³“GŽžŠÔ
	if (DamgeFlag&&mTimer->timerSet(2))
	{
		DamgeFlag = FALSE;
	}
	
	
	if (input->isKeyDown(KEYCORD::V)&&SubNull())
	{
		SubChange();
	}
	
	if (b_mType == Type::SUB_PLAYER)
	{
		b_mPosittion = charaManager->searchPlayer()+Vector2(30,30);
	}

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
		if ( b_mHp <= 0)
		{
			b_mEndFlag = true;
		}
		b_mPosittion += b_mVelocity*deltaTime*b_mSpeed;
		
	}
	
	
}

void Player::draw(Renderer * renderer)
{
	
	if (b_mType == Type::PLAYER&& !b_mEndFlag)
	{
		if (DamgeFlag)
		{
			b_mArpha = 155;
		}
		else
		{
			b_mArpha = 255;
		}
		
		DrawCircle(b_mPosittion.x + 64/2, b_mPosittion.y+16, b_mCircleSize, GetColor(0, 0, 255), FALSE);
		rend->draw2D("player", Vector2(b_mPosittion.x, b_mPosittion.y), Vector2(0, 0), Vector2(64, 64), Vector2(32, 32), Vector2(1.0f, 1.0f), b_mAngle, b_mArpha);
		rend->drawNumber("hpNumber", Vector2(150, 10), b_mHp, 0, Vector2(0, 0), Vector2(1, 1), 0.0f, 255);
	}
	if(b_mType == Type::SUB_PLAYER)
	{
		rend->draw2D("player", Vector2(b_mPosittion.x, b_mPosittion.y), Vector2(0, 0), Vector2(64, 64), Vector2(32, 32), Vector2(1.0f, 1.0f), b_mAngle, b_mArpha);
	}


	if (b_mEndFlag)
	{
		rend->drawText("Font", "GAMEOVER", Vector2(100, 450), Vector2(0, 0), Vector2(1, 1), 0.0f, 255);
	}
}

void Player::Shot(Vector2 pos)
{
	charaManager->add(new Bullet(pos, charaManager,b_mType,0.0f));
}

void Player::CShot(Vector2 pos)
{
	charaManager->add(new ChangeBullet(pos, charaManager));
}


void Player::hit(BaseObject & other)
{
	if (!DamgeFlag)
	{
		if (other.getType() == Type::ENEMY_BULLET)
		{
			b_mHp -= 1;
			DrawCircle(b_mPosittion.x + 64 / 2, b_mPosittion.y + 16, b_mCircleSize, GetColor(255, 255, 0), TRUE);
			mTimer->initialize();
			DamgeFlag = TRUE;
		}

		if (other.getType() == Type::ENEMY)
		{
			b_mHp -= 1;
			DrawCircle(b_mPosittion.x + 64 / 2, b_mPosittion.y + 16, b_mCircleSize, GetColor(255, 255, 0), TRUE);
			mTimer->initialize();
			DamgeFlag = TRUE;
		}
	}
	
}

bool Player::getIsDeath() const
{
	return b_mIsDeath;
}

Type Player::getType() const
{
	return b_mType;
}

Vector2 Player::getPpstion() const
{
	return b_mPosittion;
}



float Player::getCircleSize() const
{
	return b_mCircleSize;
}

void Player::setIsDeath(bool isDeath)
{
	b_mIsDeath = isDeath;
}

bool Player::SubNull()
{
	for (auto object : charaManager->getUseList())
	{
		if (object->getType() == Type::SUB_PLAYER)
		{
			return true;
		}
	}
	return false;
}

void Player::SubChange()
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


