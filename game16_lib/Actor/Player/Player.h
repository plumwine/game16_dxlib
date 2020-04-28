#pragma once
#include"DxLib.h"
#include "../../Math/Vector2.h"
#include "../../Device/Input.h"
#include"../../Device/Renderer.h"
#include"../CharaManager/BaseObject.h"
#include"../CharaManager/CharactorManager.h"
#include<list>
#include"../Bulletes/Bullet.h"
#include"../../Actor/Enemies/Enemy.h"
#include "../../Support/CWindow.h"

class Player:public BaseObject
{
public:
	Player(Vector2 pos,CharactorManager *c);
	~Player();

	void Change();
	void Shot(Vector2 pos);


	// BaseObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual void initialize() override;

	virtual void update(float deltaTime) override;

	virtual void draw(Renderer * renderer) override;

	virtual void hit(BaseObject & other) override;

	virtual bool getIsDeath() const override;

	virtual Type getType() const override;

	virtual Vector2 getPpstion() const override;

	virtual float getCircleSize() const override;

	virtual void ChangePlayer(BaseObject& other) override;

	
	
private:
	
	bool MoveFlag;
	Input* input;
	Renderer* rend;
	CharactorManager* charaManager;


};
