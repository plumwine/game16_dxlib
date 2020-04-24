#pragma once
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

//Template��T!!
//�V���O���g���ɂ���e���v���[�g�@�\
//������p�����Ă�������
template <class T>
class Singleton
{
public:

	//�C���X�^���X����Ԃ�
	static inline T& getInstance()
	{
		static T instance;
		return instance;
	}
	//�V���O���g���̃C���X�^���X�𐶐�(���M��getInstance()�����b�v���Ă邾�������A�V���O���g���̃C���X�^���X�����Ƃ��Ė����I�Ȃ��̂�p�ӂ��邽��
	inline static void createInstance()
	{
		T::getInstance();
	}


protected:
	//�V���O���g���̃C���X�^���X
	static Singleton *s_pInstance;

	//�B���R���X�g���N�^
	Singleton() {};                            //�O���ł̃C���X�^���X�쐬���֎~����
	virtual ~Singleton() {}

private:
	void operator=(const Singleton& obj) {}     //����֎~
	Singleton(const Singleton &obj) {}          //�R�s�[�R���X�g���N�^���֎~
};
#endif // !_SINGLETON_H
