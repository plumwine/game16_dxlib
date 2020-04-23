#include "DxLib.h"
#include <crtdbg.h>
#include "GameBase/GameManager.h"
#include "Support/CWindow.h"
#include "Device/Input.h"


//関数プロトタイプ宣言
bool initialize();  //初期化
void gameUpdate();	//ループ処理
void release();		//解放

//グローバル変数
Input* input;

//初期化
bool initialize()
{
	//メモリリーク検出
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CWindow::createInstance();               //コンソールウィンドウの生成
	CWindow::getInstance().showConsole();	 //コンソールウィンドウの表示

	//	Windowモードの設定とWindowタイトルを設定する
	ChangeWindowMode(true);
	SetMainWindowText("game16");
	//	画面サイズを設定
	SetGraphMode(840, 640, 16);
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)	return false;    // エラーが起きたら直ちに終了
	//	描画先を指定
	SetDrawScreen(DX_SCREEN_BACK);
	//	画面背景の色を設定する
	SetBackgroundColor(100, 100, 2);


	GameManager::createInstance();           //ゲームマネージャーを生成
	GameManager::getInstance().initialize(); //ゲームマネージャーを初期化
	input = new Input();                     //inputのnew
	input->init();                           //inputの初期化

	return true;
}

//ループ処理
void gameUpdate()
{
	
	while (ProcessMessage() == 0)
	{
		//終了処理
		if (input->isKeyDown(KEYCORD::ESCAPE))
			return;

		//背景をクリア
		ClearDrawScreen();
		input->update();                       //更新
		GameManager::getInstance().update();   //更新
	}
}
//解放
void release()
{
	delete input;
}
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (!initialize()) return -1;    //初期化できなければ終了

	gameUpdate();                    //ゲームループ

	DxLib_End();                     // ＤＸライブラリ使用の終了処理
	release();                       //解放
	return 0;                        // ソフトの終了 
}
