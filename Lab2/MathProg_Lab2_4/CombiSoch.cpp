#include "stdafx.h"
#include <iostream>
#include "CombiSoch.h"

namespace combiSoch
{

	int fact(int N)
	{
		if (N == 0)
			return 1;
		else
			return(N * fact(N - 1));
	}

	int getAmount(int size, int Soch)
	{
		return (fact(size) / (fact(Soch)*fact(size - Soch)));
	}

	Init Initialized(char *set, int size, int Soch) // вывод инфы на коноль и заполнение полей класса
	{
		std::cout << " --- √енератор сочетаний ---" << std::endl;
		Init k;
		k.size = size;
		k.amm = getAmount(size, Soch);
		k.amount = pow(2, k.size);// количество вариантов, которые нужно перебрать
		k.buf = new char[k.size];
		k.a = new int*[k.amount];
		k.end = new char*[k.amm];
		std::cout << "»сходное множество: { ";
		for (int i = 0; i < k.size; i++)
		{
			std::cout << set[i] << " ";
		}
		std::cout << "}" << std::endl;
		for (int i = 0; i < k.amount; i++)
		{
			k.a[i] = new int[k.size];
		}
		for (int i = 0; i < k.amm; i++)
		{
			k.end[i] = new char[Soch];
		}
		std::cout << " оличество сочетаний: " << k.amm << std::endl;
		std::cout << std::endl << "ћножества: " << std::endl;
		return k;
	}

	char** Sochet(char *set, int Soch, Init k)
	{
		// перевод в двоичную, а из неЄ в массив int
		//—формировать битовую последовательность   состо€щую из   двоичных нулей. ѕронумеровать элементы этой последовательности справа налево, начина€ с нул€. 
		for (int i = k.amount - 1; i > 0; i--)
		{
			itoa(i, k.buf, 2);

			for (int j = 0; j < k.size; j++)
			{
				if (k.buf[j] == '1')
					k.a[i][j] = 1;
				else if (k.buf[j] == '0')
					k.a[i][j] = 0;
			}
		}
		//фича
		for (int i = k.amount - 1; i > 0; i--)
		{//¬ыбрать из множества   элементы с  номерами   дл€ которых   ѕолученное подмножество будет
				//€вл€тьс€ элементом булеана   ¬ первом случае не будет выбран ни один элемент (пустое подмножество) 
				//множества   так как исходна€ последовательность   состоит только из нулей.  
			for (int j = 0; j < k.size; j++)
			{
				if (k.a[i][j] != 0)
					if (k.a[i][j] != 1)
					{
						for (int z = j; z > 0; z--)
						{
							int b = k.a[i][z - 1];
							k.a[i][z - 1] = k.a[i][z];
							k.a[i][z] = b;
						}
						k.a[i][0] = 0;
					}
			}
		}
		int count = 0;
		int counti = 0; 
		int countj = 0;
		int numberOfCondition = 0;
		for (int i = 0; i < k.amount; i++)
		{
			for (int j = 0; j < k.size; j++) //подсчет к-ва единиц в двоичной форме числа
				if (k.a[i][j] == 1)
					count++;


			if (count == Soch) // если к-во единиц в массиве совпадает с нужным выводим
			{
				numberOfCondition++;
				std::cout << numberOfCondition << ")   " << "{ ";
				for (int j = 0; j < k.size; j++)
				{
					if (k.a[i][j] == 1)
					{
						k.end[counti][countj++] = set[j];
						std::cout << set[j] << " ";
					}
				}
				countj = 0; counti++;
				std::cout << "} ";
				std::cout << std::endl;
			}
			count = 0;
		}
		return k.end;
	}
}