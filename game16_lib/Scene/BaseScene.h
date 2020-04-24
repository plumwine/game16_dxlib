#pragma once
#ifndef _BASESCENE_H_
#define _BASESCENE_H_
#include <string>
#include "../Device/Input.h"
#include "../Support/CWindow.h"
#include "../Device/Renderer.h"
//�V�[���̊��N���X
class BaseScene
{
public:
	//�R���X�g���N�^
	BaseScene() {};	               //cpp�����Ȃ��̂ł����ŏ������Ⴄ
	//�f�X�X�g���N�^
	virtual ~BaseScene() {};       //cpp�����Ȃ��̂ł����ŏ������Ⴄ
	//������
	virtual void initialize() = 0;
	//�X�V
	virtual void update(float deltaTime) = 0;
	//�`��
	virtual void draw(Renderer* renderer) = 0;
	//�I������
	virtual void shutdown() = 0;
	//�I���������ǂ���
	virtual bool isEnd() = 0;
	//���̃V�[��
	virtual std::string nextScene() = 0;
protected:
	bool isSceneEnd;                  //�V�[�����I���������ǂ���
	Input* m_pInput;                  //input�@�\
};

#endif // !_BASESCENE_H