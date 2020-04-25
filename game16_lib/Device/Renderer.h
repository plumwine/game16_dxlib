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
	/*textureName :�e�N�X�`���̖��O�@position :���W�@drawSize : �摜���̂ǂ�����`�悷�邩�̍�����W�@textureSize :�ǂ��܂ŕ`�悷�邩�E�����W�@angleCenter�F��]���S�ʒu�@scale�F�g��k���iDef 1.0�����{�j�@angle�F�p�x�i�x���@�@Def 0�j�@isTransparency:�����x��L���ɂ��邩�ǂ���(Def ture)�@isTurn:���]���邩�ǂ���(Def false)*/
	void draw2D(std::string textureName,
		Vector2 position,
		Vector2 drawPos,
		Vector2 textureSize,
		Vector2 angleCenter,
		Vector2 scale = Vector2(1.0,1.0),
		float angle = 0,
		bool isTransparency = true,
		bool isTurn = false);

	//angleCenter�͌��ߑł�
	/*textureName :�e�N�X�`���̖��O�@position :���W�@number�F�����@digits�F�����@angleCenter�F��]���S�ʒu�@scale�F�g��k���iDef 1.0�����{�j�@angle�F�p�x�i�x���@�@Def 0�j*/
	void drawNumber(std::string textureName,Vector2 position,double number,unsigned int digits,
		Vector2 angleCenter = Vector2(12,40), Vector2 scale = Vector2(1.0,1.0),  float angle = 0);
private:
	const int mNumTexture_Width = 24;     //�����摜�̉���
	const int mNumTexture_Height = 40;    //�����摜�̏c��
	const float pi;                            //�~����

};

#endif // !_RENDERER_H_

