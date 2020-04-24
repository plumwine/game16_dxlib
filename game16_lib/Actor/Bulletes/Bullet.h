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

private:
	Vector2 bulletPos;
	bool Death;
	//���f���n���h��
	int bulletM;
};
