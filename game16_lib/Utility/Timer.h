#pragma once
#ifndef _TIMER_H_
#define _TIMER_H_

//���Ԍo�ߔ��f
class Timer
{
public:
	Timer();
	~Timer();
	//������
	void initialize();
	//�X�V
	void update(float deltaTime);
	//�^�C�}�[�Z�b�g�F���b�҂��@�o�߂���܂�false
	bool timerSet(float setTime);
private:
	float mCurrentTime;   //���݂̎���
};

#endif // !_TIMER_H_