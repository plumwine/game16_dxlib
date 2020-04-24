#pragma once
#include"DxLib.h"
#include "../../Math/Vector2.h"
#include "../../Device/Input.h"
#include"../../Device/Renderer.h"

class Player
{
public:
	Player(Vector2 pos);
	~Player();
	void Init();
	void Update();
	void Render();
	void Change();

private:
	Vector2 playerPos;
	bool MoveFlag;
	Input* input;
	Renderer* rend;
	//ƒ‚ƒfƒ‹ƒnƒ“ƒhƒ‹
	int playerM;
};
