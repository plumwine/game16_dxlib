#pragma once
#include"DxLib.h"
#include "../../Math/Vector2.h"
#include "../../Device/Input.h"
#include"../../Device/Renderer.h"
#include"../CharaManager/BaseObject.h"
#include"../CharaManager/CharactorManager.h"
#include<list>
#include"../Bulletes/Bullet.h"
#include "../../Support/CWindow.h"

class Player:public BaseObject
{
public:
	Player(Vector2 pos);
	~Player();
	void Init();
	void Update();
	void Render();
	void Change();
	void Shot(Vector2 pos);
	
	Vector2 PlayerPos() { return playerPos; }
	std::list<Bullet*> bulletList;
	Bullet* bullet;

private:
	Vector2 playerPos;
	bool MoveFlag;
	Input* input;
	Renderer* rend;
	CharactorManager* charaManager;
	
};
