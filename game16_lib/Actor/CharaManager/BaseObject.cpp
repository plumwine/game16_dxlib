#include "BaseObject.h"


//�R���X�g���N�^
BaseObject::BaseObject()
{
}

//�f�X�X�g���N�^
BaseObject::~BaseObject()
{
}
//�~���m�̓����蔻��
bool BaseObject::circle_circle_Collision(BaseObject& other)
{
	//�����Ƒ���̋������v�Z
	float length = Vector2((b_mPosittion - other.b_mPosittion)).length();
	float radiusSum = b_mCircleSize+ other.b_mCircleSize;     //��̔��a�𑫂�
	//��������̔��a���傫����Γ������Ă���
	if (length <= radiusSum)
	{
		return true;
	}
	return false;
}
