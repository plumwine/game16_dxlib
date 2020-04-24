#include "DxLib.h"
#include <crtdbg.h>
#include"Player.h"
#include"Enemy.h"


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//メモリリーク検出
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//テストコミット

	//	Windowモードの設定とWindowタイトルを設定する
	ChangeWindowMode(true);
	SetMainWindowText("game16");

	//宣言（仮）
	
	//	画面サイズを設定
	SetGraphMode(800, 600, 16);
	if (DxLib_Init() == -1)	// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}

	
	//	描画先を指定
	SetDrawScreen(DX_SCREEN_BACK);

	//	画面背景の色を設定する
	SetBackgroundColor(0, 255, 100);


	
	DxLib_End();            // ＤＸライブラリ使用の終了処理

	return 0;               // ソフトの終了 
}
