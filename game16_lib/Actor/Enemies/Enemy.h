#pragma once
#include "DxLib.h"
#include "../../Math/Vector2.h"

class Enemy
{
public:
	Enemy(Vector2 pos);
	~Enemy();
	void Init();
	void Update();
	void Render();
	void Change();
private:
	Vector2 enemyPos;
	bool MoveFlag;
	//ƒ‚ƒfƒ‹ƒnƒ“ƒhƒ‹
	int enemyM;
};
