#include "Title.h"
#include "../Device/Loader/TextuerLoad.h"
//�R���X�g���N�^
Title::Title()
{
}

//�f�X�X�g���N�^
Title::~Title()
{
	delete m_pInput;
}
//������
void Title::initialize()
{
	m_pInput = new Input;
	m_pInput->init();         //input������
	isSceneEnd = false;       //�ŏ���false
	CWindow::getInstance().log("���^�C�g���ɐ؂�ւ����");
}
//�X�V
void Title::update(float deltaTime)
{
	m_pInput->update();         //input�X�V
	if (m_pInput->isKeyDown(KEYCORD::Z))
	{
		isSceneEnd = true;    //Z�����ꂽ��V�[���I���i�������j
	}

}
//�`��
void Title::draw(Renderer* renderer)
{
	renderer->draw2D("tank", Vector2(200, 200), Vector2(0,0), Vector2(64,64));
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
