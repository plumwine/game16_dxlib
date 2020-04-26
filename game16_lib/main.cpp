#include "GameBase/WindowInfo.h"
#include "GameBase/GameManager.h"
#include "GameBase/GameTime.h"
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
	//動作、デバッグに必要なものを初期化
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ChangeWindowMode(true);
	SetMainWindowText("game16");
	SetGraphMode(WindowInfo::WindowWidth, WindowInfo::WindowHeight, 16);
	SetBackgroundColor(0, 50, 50);
	if (DxLib_Init() == -1)	return false;
	//各クラスの生成・初期化
	CWindow::createInstance();
	CWindow::getInstance().showConsole();
	GameManager::createInstance();
	GameManager::getInstance().initialize(); 
	GameTime::createInstance();
	input = new Input();
	input->init();
	return true;
}

//ループ処理
void gameUpdate()
{

	while (ProcessMessage() == 0)
	{
		if (input->isKeyDown(KEYCORD::ESCAPE))
			return;
		input->update();
		//背景をクリアに
		ClearDrawScreen();
		GameTime::getInstance().update();
		GameManager::getInstance().update();
		ScreenFlip();
	}
}
//解放
void release()
{
	delete input;
}

//WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (!initialize()) return 0;
	gameUpdate();
	DxLib_End();
	release();
	return 0;
}
