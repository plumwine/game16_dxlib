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
int a = LoadGraph("img/TankATK.png");

//初期化
bool initialize()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CWindow::createInstance();               
	CWindow::getInstance().showConsole();

	ChangeWindowMode(true);
	SetMainWindowText("game16");

	SetGraphMode(840, 640, 16);
	if (DxLib_Init() == -1)	return false;
	SetBackgroundColor(0, 50, 50);
	GameManager::createInstance();           
	GameManager::getInstance().initialize(); 
	input = new Input();                     
	input->init();                           

	return true;
}

//ループ処理
void gameUpdate()
{
	while (ProcessMessage() == 0)
	{
		//背景をクリアに
		ClearDrawScreen();
		if (input->isKeyDown(KEYCORD::ESCAPE))
			return;
    
		input->update();
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
