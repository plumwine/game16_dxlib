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
	/*textureName :テクスチャの名前　position :座標　drawSize : 画像内のどこから描画するかの左上座標　textureSize :どこまで描画するか右下座標　angleCenter：回転中心位置　scale：拡大縮小（Def 1.0＝等倍）　angle：角度（度数法　Def 0）　alpha：透明値（Def 255 min 0,max 255）　isTransparency:透明度を有効にするかどうか(Def ture)　isTurn:反転するかどうか(Def false)*/
	void draw2D(std::string textureName,
		Vector2 position,
		Vector2 drawPos,
		Vector2 textureSize,
		Vector2 angleCenter,
		Vector2 scale = Vector2(1.0,1.0),
		float angle = 0,
		int alpha = 255,
		bool isTransparency = true,
		bool isTurn = false);

	//angleCenterは決め打ち　大きさはまだやっていない
	/*textureName :テクスチャの名前　position :座標　number：数字　digits：少数桁数　angleCenter：回転中心位置　scale：拡大縮小（Def 1.0＝等倍）　angle：角度（度数法　Def 0）　alpha：透明値（Def 255 min 0,max 255）*/
	void drawNumber(std::string textureName,Vector2 position,double number,unsigned int digits,
		Vector2 angleCenter = Vector2(0.0,0.0), Vector2 scale = Vector2(1.0,1.0),  float angle = 0, int alpha = 255);

	//文字描画　大きさはまだやっていないし不格好である　誰か等間隔の文字を作ってほしい
	/*textureName :テクスチャの名前　writeString：内容　position :座標　angleCenter：回転中心位置　scale：拡大縮小（Def 1.0＝等倍）　angle：角度（度数法　Def 0）　alpha：透明値（Def 255 min 0,max 255）*/
	void drawText(std::string textureName,std::string writeString, Vector2 position,
		Vector2 angleCenter = Vector2(0, 0), Vector2 scale = Vector2(1.0, 1.0), float angle = 0, int alpha = 255);

private:
	const int mNumTexture_Width = 24;     //数字画像の横幅
	const int mNumTexture_Height = 40;    //数字画像の縦幅
	const float pi;                       //円周率

	//固定値
	const int mFontTexture_Big_Width = 40;
	const int mFontTexture_Big_Height = 50;
	const int mFontTexture_Small_Width = 40;
	const int mFontTexture_Small_Height = 60;
	const int mFontTexture_Symbol_Width = 25;
	const int mFontTexture_Symbol_Height = 80;

};

#endif // !_RENDERER_H_

