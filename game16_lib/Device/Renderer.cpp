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
