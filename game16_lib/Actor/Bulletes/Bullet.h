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
	//初期化
	virtual void initialize()override;
	//更新
	virtual void update(float deltaTime)override;
	//描画
	virtual void draw(Renderer& renderer)override;
	//当たりた時の処理
	virtual void hit(BaseObject& other) override;

	Vector2 BulletPos() { return bulletPos; }
	float Angle() { return angle; }
private:
	Vector2 bulletPos;
	Vector2 bulletVel;//移動量
	float angle;
	bool Death;
	Renderer* rend;
};
