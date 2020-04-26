#pragma once
#include "DxLib.h"
#include "../../Math/Vector2.h"
#include "../../Device/Input.h"
#include"../../Device/Renderer.h"
#include"../CharaManager/BaseObject.h"

class Enemy:public BaseObject
{
public:
	Enemy(Vector2 pos);
	~Enemy();

	void Change();
private:
	Vector2 enemyPos;
	bool MoveFlag;
	Input* input;
	Renderer* rend;
	

	// BaseObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual void initialize() override;

	virtual void update(float deltaTime) override;

	virtual void draw(Renderer & renderer) override;

	virtual void hit(BaseObject & other) override;

	virtual bool getIsDeath() const override;

	virtual Type getType() const override;

	virtual Vector2 getPpstion() const override;

	virtual float getCircleSize() const override;

};
