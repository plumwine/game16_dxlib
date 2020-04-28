#include "EBullet.h"

EBullet::EBullet(Vector2 pos, CharactorManager * c)
{
	b_mPosittion = Vector2(pos);
	b_mVelocity = Vector2(0, 0);
}

EBullet::~EBullet()
{
	delete rend;
}

void EBullet::initialize()
{
}

void EBullet::update(float deltaTime)
{
	b_mVelocity.y -= 2;
	b_mPosittion += b_mVelocity;

	if (b_mPosittion.y > WindowInfo::WindowHeight
		|| b_mPosittion.y<0
		|| b_mPosittion.x>WindowInfo::WindowWidth
		|| b_mPosittion.x < 0)
	{
		b_mIsDeath = true;
	}
}

void EBullet::draw(Renderer * renderer)
{
	rend->draw2D("bullet", Vector2(b_mPosittion.x, b_mPosittion.y), Vector2(0, 0), Vector2(64, 64));
}

void EBullet::hit(BaseObject & other)
{
	if (other.getType() != Type::ENEMY)
	{
		b_mIsDeath = true;
	}

}

bool EBullet::getIsDeath() const
{
	return b_mIsDeath;
}

Type EBullet::getType() const
{
	return ENEMY_BULLET;
}

Vector2 EBullet::getPpstion() const
{
	return Vector2();
}

float EBullet::getCircleSize() const
{
	return b_mCircleSize;
}

void EBullet::ChangePlayer(BaseObject & other)
{
}
