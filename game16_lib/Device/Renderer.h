#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "../Math/Vector2.h"
#include <string>
#include "DxLib.h"

//�`��@�\lib�Ȃ̂�lib�̋@�\�����b�v���邾���ɂ���(2D)
class Renderer
{
public:
	Renderer();
	~Renderer();
	//2D�`��
	/*textureName :�e�N�X�`���̖��O�@position    :���W�@drawSize    :�e�N�X�`���T�C�Y���̕`�悷��T�C�Y�@textureSize :�e�N�X�`���̃T�C�Y�@isTransparency:�����x��L���ɂ��邩�ǂ���(Def ture)�@isTurn:���]���邩�ǂ���(Def false)*/
	void draw2D(std::string textureName,
		Vector2 position,
		Vector2 drawSize,
		Vector2 textureSize,
		bool isTransparency = true,
		bool isTurn = false);
};

#endif // !_RENDERER_H_

