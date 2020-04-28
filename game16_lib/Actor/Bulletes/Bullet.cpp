#include "Bullet.h"
#include"../../GameBase/WindowInfo.h"

Bullet::Bullet(Vector2 pos,CharactorManager* c)
{
	b_mPosittion = Vector2(pos);
	b_mVelocity = Vector2(0, 0);
	
}

Bullet::~Bullet()
{
	delete rend;
}

void Bullet::initialize()
{
	b_mType = Type::PLAYER_BULLET;
}

void Bullet::update(float deltaTime)
{
	b_mVelocity.y -= 2;
	b_mPosittion += b_mVelocity;
	
	if (b_mPosittion.y > WindowInfo::WindowHeight
		|| b_mPosittion.y<0
		|| b_mPosittion.x>WindowInfo::WindowWidth
		|| b_mPosittion.x<0)
	{
		b_mIsDeath = true;
	}
}

void Bullet::draw(Renderer * renderer)
{
	rend->draw2D("bullet", Vector2(b_mPosittion.x, b_mPosittion.y), Vector2(0, 0), Vector2(64, 64));
}

void Bullet::hit(BaseObject & other)
{
	if (other.getType() != Type::PLAYER)
	{
		b_mIsDeath = true;
		CWindow::getInstance().log("’…’e");
	}
	
}

bool Bullet::getIsDeath() const
{
	return b_mIsDeath;
}

Type Bullet::getType() const
{
	return PLAYER_BULLET;
}

Vector2 Bullet::getPpstion() const
{
	return Vector2();
}

float Bullet::getCircleSize() const
{
	return b_mCircleSize;
}

Type Bullet::ChangeType()
{
	return Type();
}

