#pragma once
#include <DirectXMath.h>
struct Vector3
{
	float x;
	float y;
	float z;

public:
	Vector3();
	Vector3(float X, float Y, float Z);
	//�ϊ�
	DirectX::XMVECTOR toXMVector();
	//�����o�֐�
	float length()const;                 //�m���������߂�
	Vector3& normalize();                //���K������
	float dot(const Vector3& v) const;   //����
	Vector3 cross(const Vector3& v) const; //�O��

	//�P�����Z�q�I�[�o�[���[�h
	Vector3 operator + ()const;
	Vector3 operator - ()const;
	bool operator == (Vector3 v)const;
	bool operator !=(Vector3 v)const;
	//������Z�q�I�[�o�[���[�h
	Vector3& operator += (const Vector3& v);
	Vector3& operator -= (const Vector3& v);
	Vector3& operator *= (float s);
	Vector3& operator /= (float s);
	

	//�񍀉��Z�q�I�[�o�[���[�h
	friend const Vector3 operator + (const Vector3& v1, const Vector3& v2);
	friend const Vector3 operator - (const Vector3& v1, const Vector3& v2);
	friend const Vector3 operator * (const Vector3& v, float s);
	friend const Vector3 operator * (float s, const Vector3& v);
	friend const Vector3 operator / (const Vector3& v, float s);
};