#pragma once

#include <Windows.h>
#pragma comment(lib,"winmm.lib")

#define KEY_MAX 256
//キー入力
class Input
{
public:
	Input(void);  //コンストラクタ
	~Input(void); //デスストラクタ

#pragma region キーボード関連
	// キーが押された瞬間
	bool isKeyDown(enum KEYCORD key);
	//キーが押されている間
	bool isKeyState(enum KEYCORD key);
	//キーが離された瞬間
	bool isKeyUp(enum KEYCORD key);
#pragma endregion


#pragma region ゲームパッド関係

	//ボタンが押された瞬間
	bool isGamePadBottonDown(enum GAMEPAD_KEYCORD button, int padNum);
	//ボタンが押されている間
	bool isGamePadBottonState(enum GAMEPAD_KEYCORD button, int padNum);
	//ボタンが離されて瞬間
	bool isGamePadBottonUp(enum GAMEPAD_KEYCORD button, int padNum);

	//ボタンが押された瞬間
	bool isGamePadCrossPadDown(enum GAMEPAD_KEYCORD button, int padNum);
	//ボタンが押されている間
	bool isGamePadCrossPadState(enum GAMEPAD_KEYCORD button, int padNum);
	//ボタンが離されて瞬間
	bool isGamePadCrossPadUp(enum GAMEPAD_KEYCORD button, int padNum);

	//左アナログスティックの傾き X軸
	float getGamePad_L_SticNum_X(int padNum);
	//左アナログスティックの傾き Y軸
	float getGamePad_L_SticNum_Y(int padNum);
	//右アナログスティックの傾き X軸
	float getGamePad_R_SticNum_X(int padNum);
	//右アナログスティックの傾き Y軸
	float getGamePad_R_SticNum_Y(int padNum);

#pragma endregion


	void update();   //更新

	void init();
private:

	//キー関係update
	void key_update();
	//ゲームパッド関係update
	void gamePad_update();


private:
	// キー情報
	BYTE mCurrentKey[KEY_MAX];
	// 前のキー情報
	BYTE mPreviousKey[KEY_MAX];
	//この値との論理積で入力を取る
	const int inputNum = 0x80;
	//ゲームパッド最大4つ(複数持っていいないのでテスト不可)
	JOYINFOEX m_CurrentJoyInfoExs[4];
	JOYINFOEX m_PreviousJoyInfoExs[4];
};