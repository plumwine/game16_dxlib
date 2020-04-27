#pragma once
#ifndef _ENEMYSPAWN_H_
#define _ENEMYSPAWN_H_
#include "CharactorManager.h"
#include "../../Utility/Timer.h"

//�G�����N���X
class EnemySpawn
{
public:
	EnemySpawn(CharactorManager& charactorManager);
	~EnemySpawn();
	//������
	void initialize();
	//�X�V
	void update(float deltaTime);
	//����
	void spawn();
private:
	CharactorManager* mCharactorManager;   //�L�����N�^�[�}�l�W���[
	Timer* mTimer;                         //�^�C�}�[
};

#endif // !_ENEMYSPAWN_H_
