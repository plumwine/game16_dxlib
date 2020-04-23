#include "SceneManager.h"


//�R���X�g���N�^  ����������
SceneManager::SceneManager():
	currentScene(nullptr)
{
}

//�f�X�X�g���N�^
SceneManager::~SceneManager()
{
	//�V�[���̍폜
	for (auto scene : scenes)
	{
		delete scene.second;
	}
}
//�V�[���̒ǉ�
void SceneManager::add(std::string name, BaseScene * addScene)
{
	//���łɃV�[�����o�^����Ă����牽�����Ȃ�
	if (!(scenes.size() == 0))
	{
		auto result = scenes.find(name);
		if (result != scenes.end()) return;
	}
	//�V�[���̒ǉ�
	scenes.emplace(name, addScene);

}
//�V�[���̐؂�ւ�
void SceneManager::change(std::string name)
{
	//���݂̃V�[����NULL��������I���������s��
	if (currentScene != nullptr)
	{
		currentScene->shutdown();
	}
	currentScene = scenes[name];     //�V�[����؂�ւ���
	currentScene->initialize();      //�V�[����������
}
//�X�V
void SceneManager::update(float deltaTime)
{
	if (currentScene == nullptr) return;   //���݂̃V�[�����Ȃ���Α������^�[��
	currentScene->update(deltaTime);       //���݂̃V�[�����X�V
	if (currentScene->isEnd())             //�I�������玟�̃V�[���ɐ؂�ւ���
	{
		change(currentScene->nextScene());
	}
}

void SceneManager::Draw()
{
}
