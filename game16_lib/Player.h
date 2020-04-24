#pragma once
#include"DxLib.h"
#include "Vector3.h"
class Player
{
public:
	Player(Vector3 pos);
	~Player();
	void Init();
	void Update();
	void Render();
	void Change();

private:
	Vector3 playerPos;
	bool MoveFlag;
	//ƒ‚ƒfƒ‹ƒnƒ“ƒhƒ‹
	int playerM;
};
