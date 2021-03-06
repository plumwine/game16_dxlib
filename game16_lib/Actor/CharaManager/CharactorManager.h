#pragma once

#ifndef _CHARACTORMANAGER_H_
#define _CHARACTORMANAGER_H_
#include <vector>
#include "BaseObject.h"
#include"../../Support/CWindow.h"
//オブジェクトの管理
class CharactorManager
{
public:
	CharactorManager();
	~CharactorManager();
	
	//リストのクリア
	void clear();
	//リストへの追加
	void add(BaseObject* addObj);
	//更新
	void update(float deltaTime);
	
#pragma region update分割
	void addList_update();
	void objectsManager_update(float deltaTime);
	void removeList_update();
#pragma endregion
	//描画
	void draw(Renderer* renderer);

	//乗っ取り後処理
	void ChangeAfter();
private:
	std::vector<BaseObject*> mObjectsList;        //オブジェクトのリスト
	std::vector<BaseObject*> mAddObjectsList;     //追加するオブジェクト
};

#endif // !_CHARACTORMANAGER_H_