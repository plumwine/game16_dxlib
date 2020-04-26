#pragma once
#include"DxLib.h"
#include "../../Math/Vector2.h"
#include"../CharaManager/CharactorManager.h"
#include"../../Device/Renderer.h"
#include"../CharaManager/BaseObject.h"


class Bullet:public BaseObject
{
public:
	Bullet(Vector2 pos);
	~Bullet();
	//‰Šú‰»
	virtual void initialize()override;
	//XV
	virtual void update(float deltaTime)override;
	//•`‰æ
	virtual void draw(Renderer& renderer)override;
	//“–‚½‚è‚½‚Ìˆ—
	virtual void hit(BaseObject& other) override;

	Vector2 BulletPos() { return bulletPos; }
	float Angle() { return angle; }
private:
	Vector2 bulletPos;
	Vector2 bulletVel;//ˆÚ“®—Ê
	float angle;
	bool Death;
	Renderer* rend;
};
