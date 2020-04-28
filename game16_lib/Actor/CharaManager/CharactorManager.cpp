#include "CharactorManager.h"


//�R���X�g���N�^
CharactorManager::CharactorManager()
{
}

//�f�X�X�g���N�^
CharactorManager::~CharactorManager()
{
	//�ǉ�����I�u�W�F�N�g���c���Ă�����A���������������
	for (auto obj : mAddObjectsList)
	{
		if (obj != nullptr)
			delete obj;
	}
	mAddObjectsList.clear();      //��ɂ���

	//�I�u�W�F�N�g��null�ɂȂ����炻�̃����������
	for (auto object : mObjectsList)
	{
		if (object != nullptr)
			delete object;
	}
	mObjectsList.clear();

}
//���X�g�̃N���A
void CharactorManager::clear()
{
	//���X�g�̒�����ɂ���
	mObjectsList.clear();
	mAddObjectsList.clear();
}
//���X�g�ւ̒ǉ�
void CharactorManager::add(BaseObject * addObj)
{
	mAddObjectsList.emplace_back(addObj);
}
//�X�V
void CharactorManager::update(float deltaTime)
{
	addList_update();
	objectsManager_update(deltaTime);
	removeList_update();
}
#pragma region update����

//�ǉ����X�g�̍X�V����
void CharactorManager::addList_update()
{
	for (auto addObj : mAddObjectsList)
	{
		mObjectsList.emplace_back(addObj);
		addObj->initialize();             //������
	}
	mAddObjectsList.clear();              //��ɂ���
}
//�I�u�W�F�N�g���X�g�̊Ǘ��X�V
void CharactorManager::objectsManager_update(float deltaTime)
{
	for (auto object1 : mObjectsList)
	{
		//�I�u�W�F�N�g1��null������ł�����X�L�b�v
		if (object1 == nullptr || object1->getIsDeath()) continue;
		object1->update(deltaTime);   //�I�u�W�F�N�g1���X�V
		for (auto object2 : mObjectsList)
		{
			//�I�u�W�F�N�g2���unull,����ł���,�I�u�W�F�N�g1,2�v�������Ȃ�X�L�b�v
			if (object2 == nullptr ||
				object2->getIsDeath() ||
				object1 == object2)
				continue;
			//�~���m�̓����蔻��𒲂ׂē������Ă����痼����hit���Ă�
			if (object1->circle_circle_Collision(*object2))
			{
				object1->hit(*object2);
				object2->hit(*object1);
			}
		}
	}
}
//�I�u�W�F�N�g�̍폜�X�V
void CharactorManager::removeList_update()
{
	auto itr = mObjectsList.begin();
	while (itr != mObjectsList.end())
	{
		//�I�u�W�F�N�g��null������ł�����폜
		if (*itr == nullptr || (*itr)->getIsDeath())
			itr = mObjectsList.erase(itr);
		else
			itr++;        //����
	}
}
#pragma endregion
//�`��
void CharactorManager::draw(Renderer * renderer)
{
	for (auto object : mObjectsList)
	{
		if (object == nullptr) continue;  //�I�u�W�F�N�g��null�Ȃ�X�L�b�v
		//�I�u�W�F�N�g������łȂ���Ε`��A����ł���X�L�b�v
		if (!object->getIsDeath())
			object->draw(renderer);
		else
			continue;    
	}
}
