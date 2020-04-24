#pragma once
#include"DxLib.h"
#include "../../Math/Vector2.h"
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
	//���f���n���h��
	int playerM;
};
