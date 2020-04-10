#include "DxLib.h"
#include <crtdbg.h>


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//���������[�N���o
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//	Window���[�h�̐ݒ��Window�^�C�g����ݒ肷��
	ChangeWindowMode(true);
	SetMainWindowText("game16");

	//	��ʃT�C�Y��ݒ�
	SetGraphMode(840, 640, 16);
	if (DxLib_Init() == -1)	// �c�w���C�u��������������
	{
		return -1;				// �G���[���N�����璼���ɏI��
	}

	//	�`�����w��
	SetDrawScreen(DX_SCREEN_BACK);

	//	��ʔw�i�̐F��ݒ肷��
	SetBackgroundColor(100, 100, 2);
	WaitKey();              // �L�[���͑҂�

	DxLib_End();            // �c�w���C�u�����g�p�̏I������

	return 0;               // �\�t�g�̏I�� 
}
