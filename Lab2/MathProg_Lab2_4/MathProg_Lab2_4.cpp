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
{//Генерация  требуется сначала сгенерировать все сочетания по m   элементов из множества   а затем все перестановки элементов для каждого сочетания.
	//перестановки* сочетания=Размещ
	setlocale(LC_ALL, "rus");
	char set[] = { 'A', 'B', 'C', 'D' };	//исходный массив
	int Soch = 3;							//сочетания по ?
	char** resultSoch;						//результат функции сочетания

	resultSoch = combiSoch::Sochet(set, Soch, combiSoch::Initialized(set, sizeof(set), Soch));

	for (int i = 0; i < combiSoch::getAmount(sizeof(set), Soch); i++)
	{
		combi::start(combi::Initialized(resultSoch[i], Soch), resultSoch[i], Soch);
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}