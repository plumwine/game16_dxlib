#include "GameManager.h"
#include "GameTime.h"
#include "../Scene/SceneManager.h"
#include "../Scene/Title.h"
#include "../Scene/GamePlay.h"
#include "../Scene/Ending.h"
#include "../Scene/LoadScene.h"
//�R���X�g���N�^
GameManager::GameManager()
{

}

//�f�X�X�g���N�^
GameManager::~GameManager()
{
	delete m_pRenderer;
}
//������
void GameManager::initialize()
{
	m_pRenderer = new Renderer();
	sceneInitialize();   //�V�[���֌W��������
}
void GameManager::sceneInitialize()
{
	//�V�[���}�l�[�W���[�̏�����
	SceneManager::createInstance();  //�V�[���}�l�[�W���[�̐���
	//�V�[���̒ǉ�
	SceneManager::getInstance().add("load"   , new LoadScene);
	SceneManager::getInstance().add("title"   , new Title);
	SceneManager::getInstance().add("gameplay", new GamePlay);
	SceneManager::getInstance().add("ending"  , new Ending);
	SceneManager::getInstance().change("load");      //�ŏ��̓^�C�g���ɐݒ�
}
//�X�V
void GameManager::update()
{
	//�V�[���}�l�[�W���[�̍X�V����
	SceneManager::getInstance().update(GameTime::getInstance().getDeltaTime());  //�Ƃ肠�����X�V
	SceneManager::getInstance().draw(m_pRenderer);
}
