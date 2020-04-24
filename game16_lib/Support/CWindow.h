#pragma once
#ifndef _CWINDOW_H
#define _CWINDOW_H





#include "Singleton.h"
#include <windows.h>
#include <iostream>

//�R���\�[���E�B���h�E�̕\��
class CWindow :public Singleton<CWindow>
{
protected:
	CWindow();
	virtual ~CWindow();
public:
	friend class Singleton<CWindow>;               //Singleton�ł̃C���X�^���X�쐬�͋���
	void showConsole();
	void log(const char *format, ...);
private:
	FILE* pFile;
};

#endif // !_CWINDOW_H

//��j
//CWindow::getInstance().log("float�̈���%f: int�̈���%d \n", 1.0,10);

//�w��
/*
�w��q	�Ή�����^	����
c	char	����
s	char *	������
d	int, short	10�i�̐���
u	unsigned int, unsigned short	10�i�̕����Ȃ�����
o	int, short,
unsigned int,
unsigned short	8�i�̐���
x	int, short,
unsigned int,
unsigned short	16�i�̐���
f	float	���������_��
e	float	���������_���̎w���\��
g	float	%e��������%f�̂ǂ��炩�œK�Ȍ`���̕��������_��
ld	long	10�i�̔{���x����
lu	unsinged long	10�i�̕����Ȃ��{���x����
lo	long, unsinged long	8�i�̔{���x����
lx	long, unsinged long	16�i�̔{���x����
lf	double	�{���x���������_��
a	double	16�i�̔{���x���������_��
*/


