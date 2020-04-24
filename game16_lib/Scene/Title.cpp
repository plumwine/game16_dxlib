#include "Title.h"


//�R���X�g���N�^
Title::Title()
{
}

//�f�X�X�g���N�^
Title::~Title()
{
	delete input;
}
//������
void Title::initialize()
{
	input = new Input;
	input->init();            //input������
	isSceneEnd = false;       //�ŏ���false
	CWindow::getInstance().log("���^�C�g���ɐ؂�ւ����");
}
//�X�V
void Title::update(float deltaTime)
{
	input->update();         //input�X�V
	if (input->isKeyDown(KEYCORD::Z))
	{
		isSceneEnd = true;    //Z�����ꂽ��V�[���I���i�������j
	}

}
//�`��
void Title::draw()
{
}
//�I������
void Title::shutdown()
{
}
//�V�[�����I��������ǂ���
bool Title::isEnd()
{
	return isSceneEnd;
}
//���̃V�[��
std::string Title::nextScene()
{
	return "gameplay";
}
