#pragma once
#include"DxLib.h"
#include"Vector3.h"

class Bullet
{
public:
	Bullet(Vector3 pos);
	~Bullet();
	void Init();
	void Update();
	void Render();

private:
	Vector3 bulletPos;
	bool Death;
	//ƒ‚ƒfƒ‹ƒnƒ“ƒhƒ‹
	int bulletM;
};
