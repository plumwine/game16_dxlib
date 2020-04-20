#pragma once
#include "DxLib.h"
#include "Vector3.h"

#define arrWidth 12
#define arrHeight  22

 enum InArray//ゲームで使用する配列名
{
	//ステージステータス
	Space,
	OutOfOil,
	UpWall,

	Cube,
	Wall,
	DownFixedBlock,//下で固定されたブロック
	UpFixedBlock,
	Zero,//count0
	Death,//死んだブロック

	Ready,//準備中

	None,

};

 class GamePlayManager
{
public:
	
	float speed;
	bool moveOk;
#pragma region 配列



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
	void UseObj();//gameObjクラスを作る必要あり
	bool ZeroDeathArea(Vector3 p);
	bool NotZeroAreaArray(Vector3 p);
	void ZeroOrCube();//自分がゼロじゃなくてspaceでもwallでもない場合   ゼロ以外デスにする
	bool IsDesth();//ArraysにDesth状態があるか
	void ZeroDesthChangeSpace();//Desth状態のものをSpace状態に移行
	InArray SelfState(Vector3 p);//自分の情報を返す
	void PreviousArray();//前の情報を入れる
	void OutOfOil(int ax, int ay, int w, int h);
	bool OutOfOilChack(int ax, int ay, int w, int h, Vector3 p);//オイル外かどうか
	void DownFixedBlock(Vector3 p);
	void UpFixedBlock(Vector3 p);
	void NotFixedBlock(Vector3 p);
	bool OnBlockCheck(Vector3 p, Vector3 next);
	bool OnCubeOfWallCheck(Vector3 p, Vector3 next);
	bool CheckOil(Vector3 p, Vector3 next);//次の場所がオイルなら
	void SelfZero(Vector3 p);
	void inCubeArray(Vector3 p, Vector3 Previous);//入れ替えcube space
	//bool NotOnSpace(InArray ina[arrWidth][arrHeight]);
	//bool DownZeroBlock(InArray ina[arrWidth][arrHeight]);
	bool DownZeroBlockChild(InArray ina[arrWidth][arrHeight], Vector3 p);

	void inOilOutArray(Vector3 p, Vector3 Previous);
	void inZeroArray(Vector3 p, Vector3 Previous);
	void inReadyArray(Vector3 p, Vector3 Previous);
	void inSpaceArray();//とりあえずすべてをspaceの情報にした。
	//InArray inBlocks [arrWidth][arrHeight] inSpaceBlocks(InArray[arrWidth][arrHeight],inBlocks);
	bool InInArray(Vector3 p);//配列内か？
	//bool DownReadyOrZero(InArray[arrWidth][arrHeight]);
	void SelfReady(Vector3 p);//自分をｃに
	void SelfDeath(Vector3 p);
	void SelfSpace(Vector3 p);
	//void ReMoveUseList()
	void WallArray();//壁の情報を付ける
	//InArray[arrWidth][arrHeight] GetInArrays();
	int Sort(); //一番下の消えるブロックのy位置を取得
private:
	float time;
	int currenTime;
	
};
