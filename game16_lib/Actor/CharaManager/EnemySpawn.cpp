#include "EnemySpawn.h"
#include <random>
#include "../Enemies/Enemy.h"


EnemySpawn::EnemySpawn(CharactorManager& charactorManager):
	mCharactorManager(&charactorManager),
	mTimer(new Timer())
{
}


EnemySpawn::~EnemySpawn()
{
	delete mTimer;
}

void EnemySpawn::initialize()
{
	mTimer->initialize();  //�^�C�}�[��������
}

void EnemySpawn::update(float deltaTime)
{
	mTimer->update(deltaTime);
}

void EnemySpawn::spawn()
{
	//5�b�����ɓG�����������
	if (mTimer->timerSet(5))
	{
		//�^�������ɏ����V�[�h��^����
		std::mt19937 mt{ std::random_device{}() };
		//�f�B�X�g���r���[�V�������g���Ĕ͈͎w��i�����j
		std::uniform_int_distribution<int> spawnNum(1, 10);

		for (int i = 0; i < spawnNum(mt); i++)
		{
			//mCharactorManager->add(new Enemy(Vector2((i + 1) * 100, 50)));
		}

	}

}
