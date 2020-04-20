#include "GamePlayManager.h"


GamePlayManager::GamePlayManager()
{
	
	
	for (int y = 0; y < arrHeight; y++)
	{
		
		for (int x = 0; x < arrWidth; x++)
		{
			worldPos[x][y] = Vector3(x,y,0);
		}
	}

	/*previousArray[arrWidth][arrHeight] = new InArray[arrWidth][arrHeight];
	wallAndSpaceArrays[arrWidth][arrHeight] = new InArray[arrWidth][arrHeight];*/
	speed = 2.0f;
	
}


GamePlayManager::~GamePlayManager()
{
}

void GamePlayManager::Init()
{
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			worldPos[x][y] = Vector3(x, y, 0);
		}
	}
	inSpaceArray();
	WallArray();
	//wallAndSpaceArrays = inArrays;
	OutOfOil(1, 18, arrWidth - 1, arrHeight - 1);
	//previousArray = wallAndSpaceArrays;
	time = 0;
	currenTime = 0;
	moveOk = false;


}

void GamePlayManager::Update()
{
	NowTime();
}

void GamePlayManager::NowTime()
{
	moveOk = false;
	time += 60 * speed;
	if (time >= 1)
	{
		currenTime += (int)time;
		time = 0;
		moveOk = true;
	}
}

void GamePlayManager::Turn()
{
	//�ۗ�
}

void GamePlayManager::UseObj()
{
	//�ۗ�
}

bool GamePlayManager::ZeroDeathArea(Vector3 p)
{
	int px = (int)p.x;
	int py = (int)p.y;
	if (InInArray(p))
	{
		for (int x = 0; x < arrWidth; x++)
		{
			if (inArrays[x][py] == InArray::Zero || inArrays[x] [py] == InArray::Death)
			{
				return true;
			}
		}
	}
	return false;
}

bool GamePlayManager::NotZeroAreaArray(Vector3 p)
{

	int px = (int)p.x;
	int py = (int)p.y;
	if (InInArray(p))
	{
		for (int x = 0; x < arrWidth; x++)
		{
			if (inArrays[x] [py] == InArray::UpFixedBlock && inArrays[x] [py] == InArray::Cube)
			{
				return true;
			}
		}
	}
	return false;
}

void GamePlayManager::ZeroOrCube()
{
	for (int y = 0; y < arrHeight; y++)
	{
		for (int x = 0; x < arrWidth; x++)
		{
			//�������[������Ȃ���space�ł�wall�ł��Ȃ��ꍇ
			if (inArrays[x] [y] != InArray::Zero && inArrays[x][y] != InArray::Space && inArrays[x] [y] != InArray::Wall)
			{
				if (ZeroDeathArea(worldPos[x] [y]))
				{
					//�f�X������
					inArrays[x][y] = InArray::Death;
				}
			}
		}
	}
}

bool GamePlayManager::IsDesth()
{
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			if (inArrays[x] [y] == InArray::Death || inArrays[x] [y] == InArray::Zero)
			{
				return true;
			}
		}
	}
	return false;
}

void GamePlayManager::ZeroDesthChangeSpace()
{
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			if (inArrays[x] [y] == InArray::Death || inArrays[x][y] == InArray::Zero)
			{
				inArrays[x][y] = InArray::Space;
			}
		}
	}
}

InArray GamePlayManager::SelfState(Vector3 p)
{
	InArray i = InArray::Space;

	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			if (p == worldPos[x][y])
			{
				i = inArrays[x][y];
			}
		}
	}
	return i;
}
//
//void GamePlayManager::PreviousArray()
//{
//	previousArray = inArrays;
//}

void GamePlayManager::OutOfOil(int ax, int ay, int w, int h)
{
	for (int x = ax; x < w; x++)
	{
		for (int y = ay; y < h; y++)
		{
			inArrays[x][y] = InArray::OutOfOil;
		}
	}
}

bool GamePlayManager::OutOfOilChack(int ax, int ay, int w, int h, Vector3 p)
{
	if (p.x >= ax && p.x < w && p.y >= ay && p.y < h)
	{
		return true;
	}
	return false;
}

void GamePlayManager::DownFixedBlock(Vector3 p)
{
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			if (p == worldPos[x][y])
			{
				inArrays[(int)p.x][ (int)p.y] = InArray::DownFixedBlock;
			}
		}
	}
}

void GamePlayManager::UpFixedBlock(Vector3 p)
{
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			if (p == worldPos[x][ y])
			{
				if (inArrays[x][y] == InArray::Zero)
				{
					return;
				}
				else
				{
					inArrays[(int)p.x][ (int)p.y] = InArray::UpFixedBlock;
				}
			}
		}
	}
}

void GamePlayManager::NotFixedBlock(Vector3 p)
{
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			if (p == worldPos[x][y])
			{
				inArrays[(int)p.x][ (int)p.y] = InArray::Cube;
			}
		}
	}
}

bool GamePlayManager::OnBlockCheck(Vector3 p, Vector3 next)
{
	int nx = (int)next.x;
	int ny = (int)next.y;

	int dx = nx - (int)p.x;
	int dy = ny - (int)p.y;
	//��
	if (dy < 0 && dx == 0)
	{
		for (int y = ny; y >= 0; y--)
		{
			//������
			for (int xb = 0; xb < arrWidth; ++xb)
			{
				for (int yb = 0; yb < arrHeight; ++yb)
				{
					if (next == worldPos[xb][yb])
					{
						if (inArrays[nx][y] == InArray::Space)
						{
							return false;
						}
						else if (inArrays[nx][y] == InArray::Wall)
						{
							return true;
						}
						else if (inArrays[nx][y] == InArray::DownFixedBlock)//���łɌŒ肳�ꂽ
						{
							return true;
						}
						else if (inArrays[nx][y] == InArray::Zero)
						{
							return true;
						}
					}
				}
			}
		}
	}
	//�� 
	else if (dy > 0 && dx == 0)
	{
		for (int y = ny; y < arrHeight; y++)
		{
			//������
			for (int xb = 0; xb < arrWidth; ++xb)
			{
				for (int yb = 0; yb < arrHeight; ++yb)
				{
					if (next == worldPos[xb][yb])
					{
						//��ł���Ƀu���b�N������΂����Ȃ�
						if (inArrays[nx][y] == InArray::Space)
						{
							return false;
						}
						else if (inArrays[nx][y] == InArray::UpFixedBlock)
						{
							return true;
						}
						else if (inArrays[nx][y] == InArray::DownFixedBlock)//���łɌŒ肳�ꂽ
						{
							return true;
						}
						else if (inArrays[nx][ y] == InArray::OutOfOil)
						{
							return true;
						}
						else if (inArrays[nx][y] == InArray::UpWall)
						{
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}

bool GamePlayManager::OnCubeOfWallCheck(Vector3 p, Vector3 next)
{
	int nx = (int)next.x;
	int ny = (int)next.y;

	int dx = nx - (int)p.x;
	int dy = ny - (int)p.y;

	//�ړ��ʂ��[���̎�
	if (dx == 0 && dy == 0)
	{
		return true;
	}

	//�E
	if (dx > 0)
	{
		for (int x = nx; x < arrWidth; x++)
		{
			//������
			for (int xb = 0; xb < arrWidth; ++xb)
			{
				for (int yb = 0; yb < arrHeight; ++yb)
				{
					if (next == worldPos[xb][ yb])
					{
						if (inArrays[x][ ny] == InArray::Space)
						{
							return true;
						}
						else if (inArrays[x][ ny] == InArray::Wall)
						{
							return false;
						}
						else if (inArrays[x][ ny] == InArray::DownFixedBlock)
						{
							return false;
						}
					}
				}
			}
		}
	}
	//��
	else if (dx < 0)
	{
		for (int x = nx; x >= 0; x--)
		{
			//������
			for (int xb = 0; xb < arrWidth; ++xb)
			{
				for (int yb = 0; yb < arrHeight; ++yb)
				{
					if (next == worldPos[xb][yb])
					{
						if (inArrays[x][ ny] == InArray::Space)
						{
							return true;
						}
						else if (inArrays[x][ ny] == InArray::Wall)
						{
							return false;
						}
						else if (inArrays[x][ ny] == InArray::DownFixedBlock)
						{
							return false;
						}
					}
				}
			}
		}
	}

	
		//��
	else if (dy < 0)
	{
		for (int y = ny; y >= 0; y--)
		{
			//������
			for (int xb = 0; xb < arrWidth; ++xb)
			{
				for (int yb = 0; yb < arrHeight; ++yb)
				{
					if (next == worldPos[xb][ yb])
					{

						if (inArrays[nx][ y] == InArray::Space)
						{
							return true;
						}
						else if (inArrays[nx][ y] == InArray::Wall)
						{
							return false;
						}
						else if (inArrays[nx][y] == InArray::DownFixedBlock)
						{
							return false;
						}
						else if (inArrays[nx][y] == InArray::Zero)
						{
							return false;
						}
					}
				}
			}
		}
	}
	//��
	else if (dy > 0)
	{
		for (int y = ny; y < arrHeight; y++)
		{
			//������  �����̓�\for���ނ�
			for (int xb = 0; xb < arrWidth; ++xb)
			{
				for (int yb = 0; yb < arrHeight; ++yb)
				{
					if (next == worldPos[xb][ yb])
					{
						//�����܂ŋC�ɂ����
						//space���������ꍇ������
						if (inArrays[nx][ y] == InArray::Space)
						{
							return true;
						}
						//Map�̏�ɌŒ肳�ꂽ�u���b�N������ꍇ
						else if (inArrays[nx][y] == InArray::UpFixedBlock)
						{
							return false;
						}
						else if (inArrays[nx][ y] == InArray::DownFixedBlock)
						{
							return false;
						}
						else if (inArrays[nx][ y] == InArray::OutOfOil)
						{
							return false;
						}
						else if (inArrays[nx][y] == InArray::Wall)
						{
							return false;
						}
						else if (inArrays[nx][ y] == InArray::UpWall)
						{
							return false;
						}
					}
				}
			}
		}
	}
	

		return false;
}

bool GamePlayManager::CheckOil(Vector3 p, Vector3 next)
{
	int nx = (int)next.x;
	int ny = (int)next.y;

	int dx = nx - (int)p.x;
	int dy = ny - (int)p.y;
	//��
	if (dy > 0)
	{
		for (int y = ny; y < arrHeight; y++)
		{
			//������  �����̓�\for���ނ�
			for (int xb = 0; xb < arrWidth; ++xb)
			{
				for (int yb = 0; yb < arrHeight; ++yb)
				{
					if (next == worldPos[xb][ yb])
					{
						//�����܂ŋC�ɂ����
						if (inArrays[nx][ y] == InArray::OutOfOil)
						{
							return true;
						}
						else if (inArrays[nx][ y] == InArray::Space)
						{
							return false;
						}
					}
				}
			}
		}
	}

	return false;
}

void GamePlayManager::SelfZero(Vector3 p)
{
	//������
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			if (p == worldPos[x][ y])
			{
				inArrays[x][y] = InArray::Zero;
			}
		}
	}
}

void GamePlayManager::inCubeArray(Vector3 p, Vector3 Previous)
{
	//for���ŉ񂷕K�v�߂����Ⴀ��
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			if (p == worldPos[x][ y])
			{
				inArrays[x][ y] = InArray::Cube;
			}

			if (Previous != p && Previous == worldPos[x][ y])
			{
				inArrays[x][y] = InArray::Space;
			}
		}
	}
}

bool GamePlayManager::DownZeroBlockChild(InArray ina[arrWidth][arrHeight], Vector3 p)
{
	int px = (int)p.x;
	int py = (int)p.y;

	if (inArrays[px][ py - 1] == InArray::Zero && ina[px][ py - 1] == InArray::Space)
	{                //Zero�u���b�N���������ꍇ
		return true;
	}
	return false;
}

void GamePlayManager::inOilOutArray(Vector3 p, Vector3 Previous)
{
	//for���ŉ񂷕K�v�߂����Ⴀ��
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			InArray ins = inArrays[x][ y];

			if (p == worldPos[x][ y])
			{
				inArrays[x][ y] = InArray::Cube;
			}

			if (Previous != p && Previous == worldPos[x][ y])
			{
				if (OutOfOilChack(1, 18, arrWidth - 1, arrHeight - 1, Previous))
				{
					inArrays[x][ y] = InArray::OutOfOil;
				}
				else
				{
					inArrays[x][ y] = InArray::Space;
				}
				
			}
		}
	}
}

void GamePlayManager::inZeroArray(Vector3 p, Vector3 Previous)
{
	//for���ŉ񂷕K�v�߂����Ⴀ��
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			if (p == worldPos[x][ y])
			{
				inArrays[x][ y] = InArray::Zero;
			}

			if (Previous != p && Previous == worldPos[x][ y])
			{
				inArrays[x][ y] = InArray::Space;
			}
		}
	}
}

void GamePlayManager::inReadyArray(Vector3 p, Vector3 Previous)
{
	//for���ŉ񂷕K�v�߂����Ⴀ��
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			if (p == worldPos[x][ y])
			{
				inArrays[x][ y] = InArray::Ready;
			}

			if (Previous != p && Previous == worldPos[x][ y])
			{
				inArrays[x][ y] = InArray::Space;
			}
		}
	}
}

void GamePlayManager::inSpaceArray()
{
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			inArrays[x][ y] = InArray::Space;
		}
	}
}

bool GamePlayManager::InInArray(Vector3 p)
{
	//�z�����
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			if (p == worldPos[x][ y])
			{
				return true;
			}
		}
	}
	return false;
}

void GamePlayManager::SelfReady(Vector3 p)
{
	inArrays[(int)p.x][ (int)p.y] = InArray::Ready;
}

void GamePlayManager::SelfDeath(Vector3 p)
{
	inArrays[(int)p.x][ (int)p.y] = InArray::Death;
}

void GamePlayManager::SelfSpace(Vector3 p)
{
	inArrays[(int)p.x][ (int)p.y] = InArray::Space;
}

void GamePlayManager::WallArray()
{

	for (int x = 0; x < arrWidth; ++x)
	{
		inArrays[x][ 0] = InArray::Wall;//��ԉ�

		inArrays[x][ arrHeight - 1] = InArray::UpWall;//��ԏ�
	}

	for (int y = 0; y < arrHeight; ++y)
	{
		inArrays[0][ y] = InArray::Wall;//��ԍ�

		inArrays[arrWidth - 1][ y] = InArray::Wall;//��ԉE
	}
}

int GamePlayManager::Sort()
{
	int a = 0;
	for (int x = 0; x < arrWidth; ++x)
	{
		for (int y = 0; y < arrHeight; ++y)
		{
			if (inArrays[x][ y] == InArray::Death ||
				inArrays[x][ y] == InArray::Zero)
			{
				if (a > y)
				{
					a = y;
				}
			}
		}
	}
	return a;
}
