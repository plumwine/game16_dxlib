#pragma once
#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H
#include "../Support/Singleton.h"


//ゲーム全体管理  シングルトン
class GameManager :public Singleton<GameManager>
{
protected:
	GameManager();
	virtual ~GameManager();
public:
	friend class Singleton<GameManager>;        //Singletonでのインスタンス作成は許可

	//初期化
	void initialize();
	void sceneInitialize();     //シーンの初期化

	//更新
	void update();
};

#endif // !_GAMEMANAGER_H