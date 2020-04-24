#include "Renderer.h"


//�R���X�g���N�^
Renderer::Renderer()
{
}
//�f�X�X�g���N�^
Renderer::~Renderer()
{
}
//2D�`��
void Renderer::draw2D(std::string textureName, Vector2 position, Vector2 drawSize, Vector2 textureSize, bool isTransparency, bool isTurn)
{
	DrawRectGraph(
		(int)position.x, (int)position.y,
		(int)drawSize.x, (int)drawSize.y,
		(int)textureSize.x, (int)textureSize.y,
		//�����Ƀn���h��������
		isTransparency, isTurn
	);
}
