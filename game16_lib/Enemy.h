#pragma once
#include "DxLib.h"
#include"Vector3.h"

class Enemy
{
public:
	Enemy(Vector3 pos);
	~Enemy();
	void Init();
	void Update();
	void Render();
	void Change();
private:
	Vector3 enemyPos;
	bool MoveFlag;
	//ƒ‚ƒfƒ‹ƒnƒ“ƒhƒ‹
	int enemyM;
};
