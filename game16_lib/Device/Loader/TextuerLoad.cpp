#include "TextuerLoad.h"
#include "../../Support/CWindow.h"

//�R���X�g���N�^
TextuerLoad::TextuerLoad()
{
}

//�f�X�X�g���N�^
TextuerLoad::~TextuerLoad()
{
	storageTexturesMap.clear();  //�I�����ɋ�ɂ���
	callTextureMap.clear();		 //�I�����ɋ�ɂ���
}
//�e�N�X�`���̒ǉ�
void TextuerLoad::add(std::string callName, const TCHAR* textureName)
{
	if (!(storageTexturesMap.size() == 0))
	{
		CWindow::getInstance().log("���łɓo�^����Ă��邩�����");
		auto result = storageTexturesMap.find(textureName);
		if (result != storageTexturesMap.end()) return;
	}
	
	
	////�ǉ�
	storageTexturesMap.emplace(textureName, callName);      //��������ǉ�
	int gra = LoadGraph(textureName);                       //�e�N�X�`�������[�h����
	CWindow::getInstance().log("�o�^���܂���%d:",gra,callName);
	callTextureMap.emplace(callName, gra);               //������ԍ��ƌĂяo������ǉ�
}
//�e�N�X�`�����Ă�
int TextuerLoad::set(std::string callName)
{
	return callTextureMap.at(callName);
}
