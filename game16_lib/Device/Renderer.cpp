#include "Renderer.h"
#include <string>
#include <math.h>
//コンストラクタ
Renderer::Renderer()
	:pi(3.1415926535897932f)
{
}
//デスストラクタ
Renderer::~Renderer()
{
}
//2D描画
void Renderer::draw2D(std::string textureName, Vector2 position, Vector2 drawPos, Vector2 textureSize, bool isTransparency, bool isTurn)
{
	DrawRectGraph(
		(int)position.x, (int)position.y,
		(int)drawPos.x, (int)drawPos.y,
		(int)textureSize.x, (int)textureSize.y,
		TextuerLoad::getInstance().set(textureName),
		isTransparency, isTurn
	);
}
void Renderer::draw2D(std::string textureName, Vector2 position, Vector2 drawPos, Vector2 textureSize, Vector2 angleCenter, Vector2 scale, float angle, bool isTransparency, bool isTurn)
{
	//指定した画像を切り取って新しい画像を作成（指定した画像は切り取られてはいない）
	int cutTexture = DerivationGraph(
		(int)drawPos.x, (int)drawPos.y,
		(int)textureSize.x, (int)textureSize.y,TextuerLoad::getInstance().set(textureName));

	//ラジアンを度に変換
	float deg = angle * (180 / pi);

	DrawRotaGraph3(
		(int)position.x, (int)position.y,
		(int)angleCenter.x, (int)angleCenter.y,
		(double)scale.x, (double)scale.y,
		(double)deg,
		cutTexture,
		isTransparency, isTurn);
	DeleteGraph(cutTexture);  //テストで置いとくここに置いておいたら描画されないかもしれない
}




//数字描画
void Renderer::drawNumber(std::string textureName, Vector2 position, double number, unsigned int digits, Vector2 scale, Vector2 angleCenter, float angle)
{
	//数字を文字に変換
	std::string stringNum = std::to_string(number);
	int dot = stringNum.find('.');          //「.」を探す
	//変換した文字とドットの長さを比べて少ない方を調べてる＋桁数
	int numberLength = std::fminf(stringNum.length(), dot) + digits;
	Vector2 basePos = position - Vector2((float)numberLength* mNumTexture_Width, 0);

	for (int i = 0; i <= numberLength; i++)
	{
		//変換した数字を一つずつ調べる
		auto character = stringNum[i];
		//文字が「.」ではなかったら
		if (character != '.')
		{
			draw2D(textureName, position,
				basePos + Vector2(i* mNumTexture_Width, 0),
				Vector2(mNumTexture_Width, mNumTexture_Height),
				angleCenter, scale, angle);
		}
		else
		{
			//一番最後にあるから10
			draw2D(textureName, position,
				basePos + Vector2(10 * mNumTexture_Width, 0),
				Vector2(mNumTexture_Width, mNumTexture_Height),
				angleCenter,scale,angle);
		}
	}
}
