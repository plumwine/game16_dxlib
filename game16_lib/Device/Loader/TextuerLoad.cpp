#include "TextuerLoad.h"
#include "../../Support/CWindow.h"

//コンストラクタ
TextuerLoad::TextuerLoad()
{
}

//デスストラクタ
TextuerLoad::~TextuerLoad()
{
	storageTexturesMap.clear();  //終了時に空にする
	callTextureMap.clear();		 //終了時に空にする
}
//テクスチャの追加
void TextuerLoad::add(std::string callName, const TCHAR* textureName)
{
	if (!(storageTexturesMap.size() == 0))
	{
		CWindow::getInstance().log("すでに登録されているから消す");
		auto result = storageTexturesMap.find(textureName);
		if (result != storageTexturesMap.end()) return;
	}
	
	
	////追加
	storageTexturesMap.emplace(textureName, callName);      //引数情報を追加
	int gra = LoadGraph(textureName);                       //テクスチャをロードする
	CWindow::getInstance().log("登録しました%d:",gra,callName);
	callTextureMap.emplace(callName, gra);               //作った番号と呼び出し名を追加
}
//テクスチャを呼ぶ
int TextuerLoad::set(std::string callName)
{
	return callTextureMap.at(callName);
}
