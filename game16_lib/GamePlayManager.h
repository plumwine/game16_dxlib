#pragma once
#include "DxLib.h"
#include "Vector3.h"

#define arrWidth 12
#define arrHeight  22

 enum InArray//�Q�[���Ŏg�p����z��
{
	//�X�e�[�W�X�e�[�^�X
	Space,
	OutOfOil,
	UpWall,

	Cube,
	Wall,
	DownFixedBlock,//���ŌŒ肳�ꂽ�u���b�N
	UpFixedBlock,
	Zero,//count0
	Death,//���񂾃u���b�N

	Ready,//������

	None,

};

 class GamePlayManager
{
public:
	
	float speed;
	bool moveOk;
#pragma region �z��



	Vector3 worldPos[arrWidth][arrHeight] =
	{
		{Vector3(0,0,0)}
	};
	
	InArray inArrays[arrWidth][arrHeight] =
	{
		{InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space},
		{InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space},
		{InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space},
		{InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space},
		
		{InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space},
		{InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space},
		{InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space},
		{InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space},

		{InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space},
		{InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space},
		{InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space},
		{InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space,InArray::Space},

	};

#pragma endregion
	
	
public:
	GamePlayManager();
	~GamePlayManager();
	void Init();
	void Update();
	void NowTime();
	void Turn();
	void UseObj();//gameObj�N���X�����K�v����
	bool ZeroDeathArea(Vector3 p);
	bool NotZeroAreaArray(Vector3 p);
	void ZeroOrCube();//�������[������Ȃ���space�ł�wall�ł��Ȃ��ꍇ   �[���ȊO�f�X�ɂ���
	bool IsDesth();//Arrays��Desth��Ԃ����邩
	void ZeroDesthChangeSpace();//Desth��Ԃ̂��̂�Space��ԂɈڍs
	InArray SelfState(Vector3 p);//�����̏���Ԃ�
	void PreviousArray();//�O�̏�������
	void OutOfOil(int ax, int ay, int w, int h);
	bool OutOfOilChack(int ax, int ay, int w, int h, Vector3 p);//�I�C���O���ǂ���
	void DownFixedBlock(Vector3 p);
	void UpFixedBlock(Vector3 p);
	void NotFixedBlock(Vector3 p);
	bool OnBlockCheck(Vector3 p, Vector3 next);
	bool OnCubeOfWallCheck(Vector3 p, Vector3 next);
	bool CheckOil(Vector3 p, Vector3 next);//���̏ꏊ���I�C���Ȃ�
	void SelfZero(Vector3 p);
	void inCubeArray(Vector3 p, Vector3 Previous);//����ւ�cube space
	//bool NotOnSpace(InArray ina[arrWidth][arrHeight]);
	//bool DownZeroBlock(InArray ina[arrWidth][arrHeight]);
	bool DownZeroBlockChild(InArray ina[arrWidth][arrHeight], Vector3 p);

	void inOilOutArray(Vector3 p, Vector3 Previous);
	void inZeroArray(Vector3 p, Vector3 Previous);
	void inReadyArray(Vector3 p, Vector3 Previous);
	void inSpaceArray();//�Ƃ肠�������ׂĂ�space�̏��ɂ����B
	//InArray inBlocks [arrWidth][arrHeight] inSpaceBlocks(InArray[arrWidth][arrHeight],inBlocks);
	bool InInArray(Vector3 p);//�z������H
	//bool DownReadyOrZero(InArray[arrWidth][arrHeight]);
	void SelfReady(Vector3 p);//����������
	void SelfDeath(Vector3 p);
	void SelfSpace(Vector3 p);
	//void ReMoveUseList()
	void WallArray();//�ǂ̏���t����
	//InArray[arrWidth][arrHeight] GetInArrays();
	int Sort(); //��ԉ��̏�����u���b�N��y�ʒu���擾
private:
	float time;
	int currenTime;
	
};
