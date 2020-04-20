#include "Input.h"
// �R���X�g���N�^
Input::Input(void)
{
}
// �f�X�g���N�^
Input::~Input(void)
{
}

#pragma region �L�[�{�[�h�֘A


//�L�[�������ꂽ�u��
bool Input::isKeyDown(enum KEYCORD key)
{
	return (mCurrentKey[key] & inputNum) && !(mPreviousKey[key] & inputNum);
}
//�L�[��������Ă����
bool Input::isKeyState(enum KEYCORD key)
{
	return (mCurrentKey[key] & inputNum) && (mPreviousKey[key] & inputNum);
}
//�L�[�������ꂽ�u��   �Ȃ����@�\���Ȃ�
bool Input::isKeyUp(enum KEYCORD key)
{
	return !(mCurrentKey[key] & inputNum) && (mPreviousKey[key] & inputNum);
}

#pragma endregion

#pragma region �Q�[���p�b�h�֌W


//�{�^���������ꂽ�u��
bool Input::isGamePadBottonDown(enum GAMEPAD_KEYCORD button, int padNum)
{
	return (((m_CurrentJoyInfoExs[padNum].dwButtons & button) != 0) && !((m_PreviousJoyInfoExs[padNum].dwButtons & button) != 0));
}
//�{�^����������Ă����
bool Input::isGamePadBottonState(enum GAMEPAD_KEYCORD button, int padNum)
{
	return ((m_CurrentJoyInfoExs[padNum].dwButtons & button) != 0);
}
//�{�^����������ďu��
bool Input::isGamePadBottonUp(enum GAMEPAD_KEYCORD button, int padNum)
{
	return (!((m_CurrentJoyInfoExs[padNum].dwButtons & button) != 0) && ((m_PreviousJoyInfoExs[padNum].dwButtons & button) != 0));
}


//�\���L�[�������ꂽ�u��
bool Input::isGamePadCrossPadDown(enum GAMEPAD_KEYCORD button, int padNum)
{
	return ((m_CurrentJoyInfoExs[padNum].dwPOV == button) && !(m_PreviousJoyInfoExs[padNum].dwPOV == button));
}
//�\���L�[�����Ă����
bool Input::isGamePadCrossPadState(enum GAMEPAD_KEYCORD button, int padNum)
{
	return m_CurrentJoyInfoExs[padNum].dwPOV == button;
}
//�\���L�[�������ꂽ�u��
bool Input::isGamePadCrossPadUp(enum GAMEPAD_KEYCORD button, int padNum)
{
	return (!(m_CurrentJoyInfoExs[padNum].dwPOV == button) && (m_PreviousJoyInfoExs[padNum].dwPOV == button));
}


//���A�i���O�X�e�B�b�N�̌X�� X��
float Input::getGamePad_L_SticNum_X(int padNum)
{
	return (m_CurrentJoyInfoExs[padNum].dwXpos) / (65535 / 10);
}
//���A�i���O�X�e�B�b�N�̌X�� Y��
float Input::getGamePad_L_SticNum_Y(int padNum)
{
	return m_CurrentJoyInfoExs[padNum].dwYpos / (65535 / 10);
}
//�E�A�i���O�X�e�B�b�N�̌X�� X��
float Input::getGamePad_R_SticNum_X(int padNum)
{
	return m_CurrentJoyInfoExs[padNum].dwZpos / (65535 / 10);
}
//�E�A�i���O�X�e�B�b�N�̌X�� Y��
float Input::getGamePad_R_SticNum_Y(int padNum)
{
	return m_CurrentJoyInfoExs[padNum].dwRpos / (65535 / 10);
}

#pragma endregion



//�X�V
void Input::update()
{
	key_update();     //�L�[���X�V
	gamePad_update(); //�Q�[���p�b�h���X�V
}

void Input::init()
{
	//�����ݒ�
	for (int i = 0; i < 4; i++)
	{
		//���݂̓���
		m_CurrentJoyInfoExs[i].dwSize = sizeof(JOYINFOEX);
		m_CurrentJoyInfoExs[i].dwFlags = JOY_RETURNALL;
		//1�t���[���O�̂ɂ��傭
		m_PreviousJoyInfoExs[i].dwSize = sizeof(JOYINFOEX);
		m_PreviousJoyInfoExs[i].dwFlags = JOY_RETURNALL;
		//�ڑ��ɃG���[���Ȃ����ǂ���
		if (JOYERR_NOERROR == joyGetPosEx(i, &m_CurrentJoyInfoExs[i])) {}
	}
}
//�L�[�֌Wupdate
void Input::key_update()
{
	//1�t���[���O�̃L�[���X�V
	for (int i = 0; i < 256; i++)
	{
		mPreviousKey[i] = mCurrentKey[i];
	}
	//���ׂẲ��z�L�[�̏�Ԃ�ێ����� 256 �o�C�g�̔z��ւ̃|�C���^���w�肷��B
	GetKeyboardState(mCurrentKey);
}
//�Q�[���p�b�h�֌Wupdate
void Input::gamePad_update()
{
	//1�t���[���O�̏����X�V
	for (int i = 0; i < 4; i++)
	{
		m_PreviousJoyInfoExs[i] = m_CurrentJoyInfoExs[i];
	}

	//�ڑ�����Ă��镪�X�V     joyGetNumDevs()�@���Ȃ���16�ɂȂ��Ă����܂��̂Ŏg�����d���Ȃ�4�̍ő吔�ɂ���
	for (int i = 0; i < 4; i++)
	{
		//�ڑ��ɃG���[���Ȃ����ǂ���+�X�V�̖��� 1�t���[���O�̕���
		if (JOYERR_NOERROR == joyGetPosEx(i, &m_CurrentJoyInfoExs[i])) {}
	}
}