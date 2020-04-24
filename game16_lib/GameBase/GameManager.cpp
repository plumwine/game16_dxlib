#include "GameManager.h"
#include "../Scene/SceneManager.h"
#include "../Scene/Title.h"
#include "../Scene/GamePlay.h"
#include "../Scene/Ending.h"

//�R���X�g���N�^
GameManager::GameManager()
{
}

//�f�X�X�g���N�^
GameManager::~GameManager()
{
}
//������
void GameManager::initialize()
{
	sceneInitialize();   //�V�[���֌W��������
}
void GameManager::sceneInitialize()
{
	//�V�[���}�l�[�W���[�̏�����
	SceneManager::createInstance();  //�V�[���}�l�[�W���[�̐���
	//�V�[���̒ǉ�
	SceneManager::getInstance().add("title"   , new Title);
	SceneManager::getInstance().add("gameplay", new GamePlay);
	SceneManager::getInstance().add("ending"  , new Ending);
	SceneManager::getInstance().change("title");      //�ŏ��̓^�C�g���ɐݒ�
}
//�X�V
void GameManager::update()
{
	//�V�[���}�l�[�W���[�̍X�V����
	SceneManager::getInstance().update(0);  //�Ƃ肠�����X�V
}
