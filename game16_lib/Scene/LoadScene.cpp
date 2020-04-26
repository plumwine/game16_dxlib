#include "LoadScene.h"
#include "../Device/Loader/TextuerLoad.h"

LoadScene::LoadScene()
{
}


LoadScene::~LoadScene()
{
}

void LoadScene::initialize()
{	
	TextuerLoad::createInstance();   //�e�N�X�`�����[�h���쐬
	TextuerLoad::getInstance().add("tank","img/TankATK.png");  //�摜�̒ǉ��i�e�X�g�j
	//�Q�[���V�[��
	TextuerLoad::getInstance().add("player", "img/F4.png");
	TextuerLoad::getInstance().add("enemy", "img/TankATKR.png");
	TextuerLoad::getInstance().add("bullet", "img/Bullet.png");
	CWindow::getInstance().log("�ǂݍ��݂��I������̂ŏI�����܂�");
	isSceneEnd = true;       //�����܂ŃG���[���Ȃ�������I����Ԃɂ���
}

void LoadScene::update(float deltaTime)
{
}

void LoadScene::draw(Renderer* renderer)
{
}

void LoadScene::shutdown()
{
}

bool LoadScene::isEnd()
{
	return isSceneEnd;
}

std::string LoadScene::nextScene()
{
	return "title";       //�I��������title�ɍs��
}
