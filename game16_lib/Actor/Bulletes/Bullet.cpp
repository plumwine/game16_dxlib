#include "Bullet.h"

Bullet::Bullet(Vector2 pos)
{
	bulletPos = Vector2(pos);
}

Bullet::~Bullet()
{
	
}

void Bullet::initialize()
{
	
}

void Bullet::update(float deltaTime)
{
	bulletVel.y -= 6;
	bulletPos += bulletVel;
}

void Bullet::draw(Renderer & renderer)
{
	rend->draw2D("bullet", Vector2(bulletPos.x, bulletPos.y), Vector2(0, 0), Vector2(64, 64));
}

void Bullet::hit(BaseObject & other)
{
}
