#pragma once
#ifndef _TEXTURELOAD_H_
#define _TEXTURELOAD_H_
#include <DxLib.h>
#include <vector>
#include <string>
#include "../../Support/Singleton.h"

//テクスチャを読み込み管理する   シングルトン
class TextuerLoad : public Singleton<TextuerLoad>
{
protected:
	TextuerLoad();
	virtual ~TextuerLoad();

public:
	friend class Singleton<TextuerLoad>;       //Singletonでのインスタンス作成は許可

	void add(std::string, const TCHAR*);

	int set(std::string);
	
private:
	//std::vector<std::string, const TCHAR*> storageTextures;  //テクスチャ格納用
	//std::vector<int, std::string> callTexture;               //テクスチャ呼び出し用
};

#endif // ! _TEXTURELOAD_H_

