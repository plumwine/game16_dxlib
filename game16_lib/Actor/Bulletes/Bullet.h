#pragma once
#include"DxLib.h"
#include "../../Math/Vector2.h"

class Bullet
{
public:
	Bullet(Vector2 pos);
	~Bullet();
	void Init();
	void Update();
	void Render();
	Vector2 BulletPos() { return bulletPos; }
private:
	Vector2 bulletPos;
	Vector2 bulletVel;//�ړ���
	bool Death;
	//���f���n���h��
	int bulletM;
};
