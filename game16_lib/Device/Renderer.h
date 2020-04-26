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
	//2D�`��ꖇ�G�p
	/*textureName :�e�N�X�`���̖��O�@position :���W�@drawSize : �摜���̂ǂ�����`�悷�邩�̍�����W�@textureSize :�e�N�X�`���̃T�C�Y�@isTransparency:�����x��L���ɂ��邩�ǂ���(Def ture)�@isTurn:���]���邩�ǂ���(Def false)*/
	void draw2D(std::string textureName,
		Vector2 position,
		Vector2 drawPos,
		Vector2 textureSize,
		bool isTransparency = true,
		bool isTurn = false);
	//2D�`��I�[�o�[���[�h�A�ԗp
	/*textureName :�e�N�X�`���̖��O�@position :���W�@drawSize : �摜���̂ǂ�����`�悷�邩�̍�����W�@textureSize :�ǂ��܂ŕ`�悷�邩�E�����W�@angleCenter�F��]���S�ʒu�@scale�F�g��k���iDef 1.0�����{�j�@angle�F�p�x�i�x���@�@Def 0�j�@alpha�F�����l�iDef 255 min 0,max 255�j�@isTransparency:�����x��L���ɂ��邩�ǂ���(Def ture)�@isTurn:���]���邩�ǂ���(Def false)*/
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

	//angleCenter�͌��ߑł��@�傫���͂܂�����Ă��Ȃ�
	/*textureName :�e�N�X�`���̖��O�@position :���W�@number�F�����@digits�F���������@angleCenter�F��]���S�ʒu�@scale�F�g��k���iDef 1.0�����{�j�@angle�F�p�x�i�x���@�@Def 0�j�@alpha�F�����l�iDef 255 min 0,max 255�j*/
	void drawNumber(std::string textureName,Vector2 position,double number,unsigned int digits,
		Vector2 angleCenter = Vector2(0.0,0.0), Vector2 scale = Vector2(1.0,1.0),  float angle = 0, int alpha = 255);

	//�����`��@�傫���͂܂�����Ă��Ȃ����s�i�D�ł���@�N�����Ԋu�̕���������Ăق���
	/*textureName :�e�N�X�`���̖��O�@writeString�F���e�@position :���W�@angleCenter�F��]���S�ʒu�@scale�F�g��k���iDef 1.0�����{�j�@angle�F�p�x�i�x���@�@Def 0�j�@alpha�F�����l�iDef 255 min 0,max 255�j*/
	void drawText(std::string textureName,std::string writeString, Vector2 position,
		Vector2 angleCenter = Vector2(0, 0), Vector2 scale = Vector2(1.0, 1.0), float angle = 0, int alpha = 255);

private:
	const int mNumTexture_Width = 24;     //�����摜�̉���
	const int mNumTexture_Height = 40;    //�����摜�̏c��
	const float pi;                       //�~����

	//�Œ�l
	const int mFontTexture_Big_Width = 40;
	const int mFontTexture_Big_Height = 50;
	const int mFontTexture_Small_Width = 40;
	const int mFontTexture_Small_Height = 60;
	const int mFontTexture_Symbol_Width = 25;
	const int mFontTexture_Symbol_Height = 80;

};

#endif // !_RENDERER_H_

