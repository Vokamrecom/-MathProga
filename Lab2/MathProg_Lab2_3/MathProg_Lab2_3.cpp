#include "stdafx.h"
#include "Combi.h"
#include <iostream>

int main()
{//������������

//�������� �������������, ��� ��� �������� �������� vj;yj ����������� � ������� �����������
	setlocale(LC_ALL, "rus");
	char  set[] = { 'A', 'B', 'C', 'D', 'H' };
	combi::start(combi::Initialized(set, sizeof(set)), set, sizeof(set));
}