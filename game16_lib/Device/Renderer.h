#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "Loader/TextuerLoad.h"
#include "../Math/Vector2.h"
//�`��@�\lib�Ȃ̂�lib�̋@�\�����b�v���邾���ɂ���(2D)
class Renderer
{
public:
	Renderer();
	~Renderer();
	//2D�`��
	/*textureName :�e�N�X�`���̖��O�@position :���W�@drawSize : �摜���̂ǂ�����`�悷�邩�̍�����W�i�j�@textureSize :�e�N�X�`���̃T�C�Y�@isTransparency:�����x��L���ɂ��邩�ǂ���(Def ture)�@isTurn:���]���邩�ǂ���(Def false)*/
	void draw2D(std::string textureName,
		Vector2 position,
		Vector2 drawPos,
		Vector2 textureSize,
		bool isTransparency = true,
		bool isTurn = false);
	//textureName :�e�N�X�`���̖��O�@position :���W�@number�F�����@����
	void drawNumber(std::string textureName,Vector2 position,double number,unsigned int digits);
private:
	const int mNumTexture_Width = 24;     //�����摜�̉���
	const int mNumTexture_Height = 40;    //�����摜�̏c��

};

#endif // !_RENDERER_H_

