#include "stdafx.h"
#include "Combi3.h"
#include "CombiSoch.h"

#include <iostream>


int fact(int N)
{
	if (N == 0)
		return 1;
	else return(N * fact(N - 1));
}

int main()
{//���������  ��������� ������� ������������� ��� ��������� �� m   ��������� �� ���������   � ����� ��� ������������ ��������� ��� ������� ���������.
	//������������* ���������=������
	setlocale(LC_ALL, "rus");
	char set[] = { 'A', 'B', 'C', 'D' };	//�������� ������
	int Soch = 3;							//��������� �� ?
	char** resultSoch;						//��������� ������� ���������

	resultSoch = combiSoch::Sochet(set, Soch, combiSoch::Initialized(set, sizeof(set), Soch));

	for (int i = 0; i < combiSoch::getAmount(sizeof(set), Soch); i++)
	{
		combi::start(combi::Initialized(resultSoch[i], Soch), resultSoch[i], Soch);
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}