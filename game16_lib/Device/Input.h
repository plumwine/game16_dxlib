#pragma once

#include <Windows.h>
#pragma comment(lib,"winmm.lib")

#define KEY_MAX 256
//�L�[����
class Input
{
public:
	Input(void);  //�R���X�g���N�^
	~Input(void); //�f�X�X�g���N�^

#pragma region �L�[�{�[�h�֘A
	// �L�[�������ꂽ�u��
	bool isKeyDown(enum KEYCORD key);
	//�L�[��������Ă����
	bool isKeyState(enum KEYCORD key);
	//�L�[�������ꂽ�u��
	bool isKeyUp(enum KEYCORD key);
#pragma endregion


#pragma region �Q�[���p�b�h�֌W

	//�{�^���������ꂽ�u��
	bool isGamePadBottonDown(enum GAMEPAD_KEYCORD button, int padNum);
	//�{�^����������Ă����
	bool isGamePadBottonState(enum GAMEPAD_KEYCORD button, int padNum);
	//�{�^����������ďu��
	bool isGamePadBottonUp(enum GAMEPAD_KEYCORD button, int padNum);

	//�{�^���������ꂽ�u��
	bool isGamePadCrossPadDown(enum GAMEPAD_KEYCORD button, int padNum);
	//�{�^����������Ă����
	bool isGamePadCrossPadState(enum GAMEPAD_KEYCORD button, int padNum);
	//�{�^����������ďu��
	bool isGamePadCrossPadUp(enum GAMEPAD_KEYCORD button, int padNum);

	//���A�i���O�X�e�B�b�N�̌X�� X��
	float getGamePad_L_SticNum_X(int padNum);
	//���A�i���O�X�e�B�b�N�̌X�� Y��
	float getGamePad_L_SticNum_Y(int padNum);
	//�E�A�i���O�X�e�B�b�N�̌X�� X��
	float getGamePad_R_SticNum_X(int padNum);
	//�E�A�i���O�X�e�B�b�N�̌X�� Y��
	float getGamePad_R_SticNum_Y(int padNum);

#pragma endregion


	void update();   //�X�V

	void init();
private:

	//�L�[�֌Wupdate
	void key_update();
	//�Q�[���p�b�h�֌Wupdate
	void gamePad_update();


private:
	// �L�[���
	BYTE mCurrentKey[KEY_MAX];
	// �O�̃L�[���
	BYTE mPreviousKey[KEY_MAX];
	//���̒l�Ƃ̘_���ςœ��͂����
	const int inputNum = 0x80;
	//�Q�[���p�b�h�ő�4��(���������Ă����Ȃ��̂Ńe�X�g�s��)
	JOYINFOEX m_CurrentJoyInfoExs[4];
	JOYINFOEX m_PreviousJoyInfoExs[4];
};