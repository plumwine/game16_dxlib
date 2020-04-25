#pragma once
#ifndef _GAMETIME_H_
#define _GAMETIME_H_
#include <time.h>
#include "../Support/Singleton.h"

//1�t���[���̎��ԂƎ��
class GameTime : public Singleton<GameTime>
{
protected:
	GameTime();
	virtual ~GameTime();
public:
	friend class Singleton<GameTime>;  //Singleton�ł̃C���X�^���X�쐬�͋���
	//�X�V
	void update();
	//1�t���[���ɂ����鎞��
	float getDeltaTime() const;
private:
	clock_t mPreviousTime = clock();   //1�t���[���O�̎��� �ŏ��ɐݒ肷��
	float deltaTime;
};
#endif // !_GAMETIME_H_

