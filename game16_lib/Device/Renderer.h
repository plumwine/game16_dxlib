#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "Loader/TextuerLoad.h"
#include "../Math/Vector2.h"
//描画機能libなのでlibの機能をラップするだけにする(2D)
class Renderer
{
public:
	Renderer();
	~Renderer();
	//2D描画
	/*textureName :テクスチャの名前　position :座標　drawSize : 画像内のどこから描画するかの左上座標（）　textureSize :テクスチャのサイズ　isTransparency:透明度を有効にするかどうか(Def ture)　isTurn:反転するかどうか(Def false)*/
	void draw2D(std::string textureName,
		Vector2 position,
		Vector2 drawPos,
		Vector2 textureSize,
		bool isTransparency = true,
		bool isTurn = false);

};

#endif // !_RENDERER_H_

