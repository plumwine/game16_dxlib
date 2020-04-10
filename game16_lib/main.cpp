#include "DxLib.h"
#include <crtdbg.h>


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//メモリリーク検出
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//	Windowモードの設定とWindowタイトルを設定する
	ChangeWindowMode(true);
	SetMainWindowText("game16");

	//	画面サイズを設定
	SetGraphMode(840, 640, 16);
	if (DxLib_Init() == -1)	// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}

	//	描画先を指定
	SetDrawScreen(DX_SCREEN_BACK);

	//	画面背景の色を設定する
	SetBackgroundColor(100, 100, 2);
	WaitKey();              // キー入力待ち

	DxLib_End();            // ＤＸライブラリ使用の終了処理

	return 0;               // ソフトの終了 
}
