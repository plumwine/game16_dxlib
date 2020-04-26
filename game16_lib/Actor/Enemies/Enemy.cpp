#include "Enemy.h"
#include "../Player/Player.h"

Enemy::Enemy(Vector2 pos)
{
}

Enemy::~Enemy()
{
}

void Enemy::Change()
{
}

void Enemy::initialize()
{
}

void Enemy::update(float deltaTime)
{
}

void Enemy::draw(Renderer & renderer)
{
}

void Enemy::hit(BaseObject & other)
{
}

bool Enemy::getIsDeath() const
{
	return false;
}

Type Enemy::getType() const
{
	return Type();
}

Vector2 Enemy::getPpstion() const
{
	return Vector2();
}

float Enemy::getCircleSize() const
{
	return 0.0f;
}
