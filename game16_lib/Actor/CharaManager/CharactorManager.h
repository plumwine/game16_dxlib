#pragma once

#ifndef _CHARACTORMANAGER_H_
#define _CHARACTORMANAGER_H_
#include <vector>
#include "BaseObject.h"
//�I�u�W�F�N�g�̊Ǘ�
class CharactorManager
{
public:
	CharactorManager();
	~CharactorManager();
	//���X�g�̃N���A
	void clear();
	//���X�g�ւ̒ǉ�
	void add(BaseObject* addObj);
	//�X�V
	void update(float deltaTime);
#pragma region update����
	void addList_update();
	void objectsManager_update(float deltaTime);
	void removeList_update();
#pragma endregion
	//�`��
	void draw(Renderer& renderer);
private:
	std::vector<BaseObject*> mObjectsList;        //�I�u�W�F�N�g�̃��X�g
	std::vector<BaseObject*> mAddObjectsList;     //�ǉ�����I�u�W�F�N�g
};

#endif // !_CHARACTORMANAGER_H_