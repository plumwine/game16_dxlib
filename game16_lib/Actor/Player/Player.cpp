#include "Player.h"



Player::Player(Vector2 pos,CharactorManager *c)
{
	charaManager = c;
}

Player::~Player()
{
	delete input;
	delete rend;
}

void Player::initialize()
{
	b_mPosittion = Vector2(400, 500);
	MoveFlag = FALSE;
	input = new Input;
	input->init();
	rend = new Renderer;
	b_mCircleSize = 32.0f;
	b_mType = Type::PLAYER;
	b_mHp = 100;
}

void Player::update(float deltaTime)
{
	
	b_mVelocity = Vector2(0, 0);
	input->update();

	

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

void Player::draw(Renderer * renderer)
{
	if (b_mType == Type::PLAYER)
	{
		DrawCircle(b_mPosittion.x + 64 / 2, b_mPosittion.y+32, b_mCircleSize, GetColor(0, 0, 255), FALSE);
	}
	else
	{
		DrawCircle(b_mPosittion.x + 64 / 2, b_mPosittion.y+32, b_mCircleSize, GetColor(255, 0, 0), FALSE);
	}
	
	rend->draw2D("player", Vector2(b_mPosittion.x, b_mPosittion.y), Vector2(0, 0), Vector2(64, 64));
}

void Player::Shot(Vector2 pos)
{
	charaManager->add(new Bullet(pos, charaManager));
	CWindow::getInstance().log("”­ŽË");
}

void Player::CShot(Vector2 pos)
{
	charaManager->add(new ChangeBullet(pos, charaManager));
}


void Player::hit(BaseObject & other)
{
	if (other.getType() == Type::ENEMY||other.getType()==Type::ENEMY_BULLET)
	{
		b_mHp -= 20;
		DrawCircle(b_mPosittion.x + 64 / 2, b_mPosittion.y + 32, b_mCircleSize, GetColor(255, 255, 0), TRUE);
		if (b_mHp <= 0)
		{
			b_mIsDeath = true;
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
	return Vector2();
}

float Player::getCircleSize() const
{
	return b_mCircleSize;
}

Type Player::ChangeType()
{
	return b_mType;
}


