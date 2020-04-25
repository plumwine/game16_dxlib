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
	//2D描画一枚絵用
	/*textureName :テクスチャの名前　position :座標　drawSize : 画像内のどこから描画するかの左上座標　textureSize :テクスチャのサイズ　isTransparency:透明度を有効にするかどうか(Def ture)　isTurn:反転するかどうか(Def false)*/
	void draw2D(std::string textureName,
		Vector2 position,
		Vector2 drawPos,
		Vector2 textureSize,
		bool isTransparency = true,
		bool isTurn = false);
	//2D描画オーバーロード連番用
	/*textureName :テクスチャの名前　position :座標　drawSize : 画像内のどこから描画するかの左上座標　textureSize :どこまで描画するか右下座標　angleCenter：回転中心位置　scale：拡大縮小（Def 1.0＝等倍）　angle：角度（度数法　Def 0）　isTransparency:透明度を有効にするかどうか(Def ture)　isTurn:反転するかどうか(Def false)*/
	void draw2D(std::string textureName,
		Vector2 position,
		Vector2 drawPos,
		Vector2 textureSize,
		Vector2 angleCenter,
		Vector2 scale = Vector2(1.0,1.0),
		float angle = 0,
		bool isTransparency = true,
		bool isTurn = false);

	//angleCenterは決め打ち
	/*textureName :テクスチャの名前　position :座標　number：数字　digits：桁数　angleCenter：回転中心位置　scale：拡大縮小（Def 1.0＝等倍）　angle：角度（度数法　Def 0）*/
	void drawNumber(std::string textureName,Vector2 position,double number,unsigned int digits,
		Vector2 angleCenter = Vector2(12,40), Vector2 scale = Vector2(1.0,1.0),  float angle = 0);
private:
	const int mNumTexture_Width = 24;     //数字画像の横幅
	const int mNumTexture_Height = 40;    //数字画像の縦幅
	const float pi;                            //円周率

};

#endif // !_RENDERER_H_

