#include "Renderer.h"


//コンストラクタ
Renderer::Renderer()
{
}
//デスストラクタ
Renderer::~Renderer()
{
}
//2D描画
void Renderer::draw2D(std::string textureName, Vector2 position, Vector2 drawSize, Vector2 textureSize, bool isTransparency, bool isTurn)
{
	DrawRectGraph(
		(int)position.x, (int)position.y,
		(int)drawSize.x, (int)drawSize.y,
		(int)textureSize.x, (int)textureSize.y,
		//ここにハンドルが入る
		isTransparency, isTurn
	);
}
