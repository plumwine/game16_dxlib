#pragma once
#ifndef _TEXTURELOAD_H_
#define _TEXTURELOAD_H_
#include <DxLib.h>
#include <string>
#include<unordered_map>
#include "../../Support/Singleton.h"

//�e�N�X�`����ǂݍ��݊Ǘ�����   �V���O���g��
class TextuerLoad : public Singleton<TextuerLoad>
{
protected:
	TextuerLoad();
	virtual ~TextuerLoad();

public:
	friend class Singleton<TextuerLoad>;       //Singleton�ł̃C���X�^���X�쐬�͋���
	//�e�N�X�`���̒ǉ��@�i�����������O , �e�N�X�`���̖��O�i�p�X���܂߂�j�j
	void add(std::string callName, const TCHAR* textureName);
	//�e�N�X�`���̌Ăяo���@�i�o�^���Ă��鈵���������O�j
	int set(std::string callName);
	
private:
	std::unordered_map<const TCHAR*,std::string> storageTexturesMap;  //�e�N�X�`���i�[�p
	std::unordered_map<std::string,int> callTextureMap;               //�e�N�X�`���Ăяo���p
};

#endif // ! _TEXTURELOAD_H_

