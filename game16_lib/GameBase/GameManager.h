#pragma once
#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_
#include "../Support/Singleton.h"


//�Q�[���S�̊Ǘ�  �V���O���g��
class GameManager :public Singleton<GameManager>
{
protected:
	GameManager();
	virtual ~GameManager();
public:
	friend class Singleton<GameManager>;        //Singleton�ł̃C���X�^���X�쐬�͋���

	//������
	void initialize();
	void sceneInitialize();     //�V�[���̏�����

	//�X�V
	void update();
};

#endif // !_GAMEMANAGER_H_