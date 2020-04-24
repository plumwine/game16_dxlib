#pragma once
#ifndef _TEXTURELOAD_H_
#define _TEXTURELOAD_H_
#include <DxLib.h>
#include <vector>
#include <string>
#include "../../Support/Singleton.h"

//�e�N�X�`����ǂݍ��݊Ǘ�����   �V���O���g��
class TextuerLoad : public Singleton<TextuerLoad>
{
protected:
	TextuerLoad();
	virtual ~TextuerLoad();

public:
	friend class Singleton<TextuerLoad>;       //Singleton�ł̃C���X�^���X�쐬�͋���

	void add(std::string, const TCHAR*);

	int set(std::string);
	
private:
	//std::vector<std::string, const TCHAR*> storageTextures;  //�e�N�X�`���i�[�p
	//std::vector<int, std::string> callTexture;               //�e�N�X�`���Ăяo���p
};

#endif // ! _TEXTURELOAD_H_

