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
	mTimer->initialize();  //タイマーを初期化
}

void EnemySpawn::update(float deltaTime)
{
	mTimer->update(deltaTime);
}

void EnemySpawn::spawn()
{
	//5秒おきに敵が生成される
	if (mTimer->timerSet(5))
	{
		//疑似乱数に初期シードを与える
		std::mt19937 mt{ std::random_device{}() };
		//ディストリビューションを使って範囲指定（整数）
		std::uniform_int_distribution<int> spawnNum(1, 10);

		for (int i = 0; i < spawnNum(mt); i++)
		{
			//mCharactorManager->add(new Enemy(Vector2((i + 1) * 100, 50)));
		}

	}

}
