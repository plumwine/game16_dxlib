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
	
	//�Q�[���V�[��
	TextuerLoad::getInstance().add("bullet", "img/Bullet.png");
	TextuerLoad::getInstance().add("player", "img/F4.png");
	TextuerLoad::getInstance().add("enemy", "img/TankATK.png");
	TextuerLoad::getInstance().add("enemy2", "img/RedBTM.png");
	TextuerLoad::getInstance().add("enemy3", "img/RedATK.png");
	TextuerLoad::getInstance().add("Font", "Resouce/Texture/font_just.png");
	TextuerLoad::getInstance().add("hpNumber", "Resouce/Texture/denColor.png");
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
