#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "CombiSoch.h"
//TODO somethink with functions
//��������� ���������

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	char set[] = { 'A', 'B', 'C', 'D', 'E'};//n=20
	int Soch = 2;//m=? �.�. ��������
	//��������� ���������   ����� ���� ������� � ��������� �������  � ������ �� ���� ���� ����������� � ���������   
	combiSoch::Sochet(set, Soch, combiSoch::Initialized(set, sizeof(set), Soch));

	system("pause");
	return 0;
}