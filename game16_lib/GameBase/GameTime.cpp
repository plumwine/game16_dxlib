#include "GameTime.h"



GameTime::GameTime()
{
}


GameTime::~GameTime()
{
}
//�X�V
void GameTime::update()
{
	clock_t mCurrentTime = clock();//���݂̎���
	//1�t���[���ɂ����鎞�ԁ@���@�i���݂̎��ԁ@�[1�t���[���O�̎��ԁj/�b�ɕϊ�
	deltaTime = (float)(mCurrentTime - mPreviousTime) / 1000.0;
	mPreviousTime = mCurrentTime;  //1�t���[���O���X�V
}
//1�t���[���ɂ����鎞��
float GameTime::getDeltaTime() const
{
	return deltaTime;
}
