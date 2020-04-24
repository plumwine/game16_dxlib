#pragma once
#ifndef _BASESCENE_H_
#define _BASESCENE_H_
#include <string>
#include "../Device/Input.h"
#include "../Support/CWindow.h"
//シーンの基底クラス(abstract)   実装はない
class BaseScene
{
public:
	//コンストラクタ
	BaseScene() {};	               //cpp書かないのでここで書いちゃう
	//デスストラクタ
	virtual ~BaseScene() {};       //cpp書かないのでここで書いちゃう
	//初期化
	virtual void initialize() = 0;
	//更新
	virtual void update(float deltaTime) = 0;
	//描画
	virtual void draw() = 0;
	//終了処理
	virtual void shutdown() = 0;
	//終了したかどうか
	virtual bool isEnd() = 0;
	//次のシーン
	virtual std::string nextScene() = 0;
protected:
	bool isSceneEnd;               //シーンが終了したかどうか
	Input* input;                  //input機能
};

#endif // !_BASESCENE_H