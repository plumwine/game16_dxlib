#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "../Math/Vector2.h"
#include <string>
#include "DxLib.h"

//描画機能libなのでlibの機能をラップするだけにする(2D)
class Renderer
{
public:
	Renderer();
	~Renderer();
	//2D描画
	/*textureName :テクスチャの名前　position    :座標　drawSize    :テクスチャサイズ内の描画するサイズ　textureSize :テクスチャのサイズ　isTransparency:透明度を有効にするかどうか(Def ture)　isTurn:反転するかどうか(Def false)*/
	void draw2D(std::string textureName,
		Vector2 position,
		Vector2 drawSize,
		Vector2 textureSize,
		bool isTransparency = true,
		bool isTurn = false);
};

#endif // !_RENDERER_H_

