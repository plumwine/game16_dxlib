#pragma once
#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include <iostream>
#include <string>
#include <unordered_map>
#include "BaseScene.h"
#include "../Support/Singleton.h"


//�V�[���Ǘ�
class SceneManager :public Singleton<SceneManager>
{
	//�R���X�g���N�^
	SceneManager();
	//�f�X�X�g���N�^
	virtual ~SceneManager();
public:
	friend class Singleton<SceneManager>;                  //Singleton�ł̃C���X�^���X�쐬�͋���

	//�V�[���̒ǉ�
	void add(std::string name,BaseScene* addScene);
	//�V�[���̐؂�ւ�
	void change(std::string name);
	//�X�V
	void update(float deltaTime);
	//�`��
	void Draw();
private:
	std::unordered_map <std::string,BaseScene*> scenes;     //�V�[�����i�[
	BaseScene* currentScene;                                //���݂̃V�[��

};
#endif // !_SCENEMANAGER_H

