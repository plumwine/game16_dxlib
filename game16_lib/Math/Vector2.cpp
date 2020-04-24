#include "Vector2.h"
#include <cmath>

//�f�t�H���g�R���X�g���N�^
Vector2::Vector2() :
	x(0), y(0)
{
}
//�R���X�g���N�^
Vector2::Vector2(float X, float Y)
	: x(X), y(Y)

{
}
//����
float Vector2::length() const
{
	return (float)std::sqrtf(x * x + y * y);
}
//���K��
Vector2 & Vector2::normalize()
{
	float len;

	if ((len = length()) != 0)
		*this /= len;

	return *this;
}
//����
float Vector2::dot(const Vector2 & v) const
{
	float result = x * v.x + y * v.y;
	return result;
}
//�O��
float Vector2::cross(const Vector2 & v) const
{
	float result = x * v.y - y * v.x;
	return result;
}

//�P�����Z�q�I�[�o�[���[�h�{
Vector2 Vector2::operator+() const
{
	return *this;
}
//�P�����Z�q�I�[�o�[���[�h�[
Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}
//������Z�q�{
Vector2 & Vector2::operator+=(const Vector2 & v)
{
	x += v.x;
	y += v.y;
	return *this;
}
//������Z�q�[
Vector2 & Vector2::operator-=(const Vector2 & v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}
//������Z�q��
Vector2 & Vector2::operator*=(float s)
{
	x *= s;
	y *= s;
	return *this;
}
//������Z�q/
Vector2 & Vector2::operator/=(float s)
{
	if (s == 0)
	{
		x = x;
		y = y;
	}
	else
	{
		x /= s;
		y /= s;
	}

	return *this;
}


//�񍀉��Z�q�{
const Vector2 operator+(const Vector2 & v1, const Vector2 & v2)
{
	return Vector2(v1.x + v2.x, v1.y + v2.y);
}
//�񍀉��Z�q�[
const Vector2 operator-(const Vector2 & v1, const Vector2 & v2)
{
	return Vector2(v1.x - v2.x, v1.y - v2.y);
}
//�񍀉��Z�q��
const Vector2 operator*(const Vector2 & v, float s)
{
	return Vector2(v.x *s, v.y*s);
}
//�񍀉��Z�q��
const Vector2 operator*(float s, const Vector2 & v)
{
	return Vector2(v.x *s, v.y*s);
}
//�񍀉��Z�q/
const Vector2 operator/(const Vector2 & v, float s)
{
	return  Vector2(v.x / s, v.y / s);
}
