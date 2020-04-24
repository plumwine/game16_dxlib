#pragma once
#include "DxLib.h"
#include "../../Math/Vector2.h"
#include "../../Device/Input.h"
#include"../../Device/Renderer.h"

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
	Input* input;
	Renderer* rend;
	//ƒ‚ƒfƒ‹ƒnƒ“ƒhƒ‹
	int enemyM;
};
