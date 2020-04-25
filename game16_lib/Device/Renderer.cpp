#include "Renderer.h"
#include <string>
#include <math.h>
//�R���X�g���N�^
Renderer::Renderer()
{
}
//�f�X�X�g���N�^
Renderer::~Renderer()
{
}
//2D�`��
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
//�����`��
void Renderer::drawNumber(std::string textureName, Vector2 position, double number, unsigned int digits)
{
	//�����𕶎��ɕϊ�
	std::string stringNum = std::to_string(number);
	int dot = stringNum.find('.');          //�u.�v��T��
	//�ϊ����������ƃh�b�g�̒������ׂď��Ȃ����𒲂ׂĂ�{����
	int numberLength = std::fminf(stringNum.length(), dot) + digits;
	Vector2 basePos = position - Vector2((float)numberLength* mNumTexture_Width, 0);

	for (int i = 0; i <= numberLength; i++)
	{
		//�ϊ�����������������ׂ�
		auto character = stringNum[i];
		//�������u.�v�ł͂Ȃ�������
		if (character != '.')
		{
			draw2D(textureName, position,
				basePos + Vector2(i* mNumTexture_Width, 0),
				Vector2(mNumTexture_Width, mNumTexture_Height));
		}
		else
		{
			//��ԍŌ�ɂ��邩��10
			draw2D(textureName, position,
				basePos + Vector2(10 * mNumTexture_Width, 0),
				Vector2(mNumTexture_Width, mNumTexture_Height));
		}
	}
}
