#include "DxLib.h"
#include <crtdbg.h>
#include"Player.h"
#include"Enemy.h"
#include "GameBase/GameManager.h"
#include "Support/CWindow.h"
#include "Device/Input.h"


//�֐��v���g�^�C�v�錾
bool initialize();  //������
void gameUpdate();	//���[�v����
void release();		//����

//�O���[�o���ϐ�
Input* input;

//������
bool initialize()
{
	//���������[�N���o
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CWindow::createInstance();               //�R���\�[���E�B���h�E�̐���
	CWindow::getInstance().showConsole();	 //�R���\�[���E�B���h�E�̕\��

	//	Window���[�h�̐ݒ���Window�^�C�g�����ݒ肷��
	ChangeWindowMode(true);
	SetMainWindowText("game16");

	//	���ʃT�C�Y���ݒ�
	SetGraphMode(840, 640, 16);
	// �c�w���C�u��������������
	if (DxLib_Init() == -1)	return false;    // �G���[���N�����璼���ɏI��

	//	�`�������w��
	SetDrawScreen(DX_SCREEN_BACK);
	//	���ʔw�i�̐F���ݒ肷��

	SetBackgroundColor(100, 100, 2);


	GameManager::createInstance();           //�Q�[���}�l�[�W���[�𐶐�
	GameManager::getInstance().initialize(); //�Q�[���}�l�[�W���[��������
	input = new Input();                     //input��new
	input->init();                           //input�̏�����

	return true;
}

//���[�v����
void gameUpdate()
{

	while (ProcessMessage() == 0)
	{
		//�I������
		if (input->isKeyDown(KEYCORD::ESCAPE))
			return;

		//�w�i���N���A
		ClearDrawScreen();
		input->update();                       //�X�V
		GameManager::getInstance().update();   //�X�V
	}
}
//����
void release()
{
	delete input;
}
// �v���O������ WinMain �����n�܂��܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (!initialize()) return -1;    //�������ł��Ȃ����ΏI��

	gameUpdate();                    //�Q�[�����[�v

	DxLib_End();                     // �c�w���C�u�����g�p�̏I������
	release();                       //����
	return 0;                        // �\�t�g�̏I��
}
