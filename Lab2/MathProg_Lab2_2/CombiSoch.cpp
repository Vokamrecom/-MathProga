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

	Init Initialized(char *set, int size,int Soch) // вывод инфы на коноль и заполнение полей класса
	{
		std::cout << " --- Генератор сочетаний ---" << std::endl;
		Init k;
		k.size = size;
		k.amm = fact(k.size) / (fact(Soch)*fact(k.size - Soch));
		k.amount = pow(2, k.size);
		k.buf = new char[k.size];
		k.a = new int*[k.amount];
		std::cout << "Исходное множество: { ";
		for (int i = 0; i < k.size; i++)
		{
			std::cout << set[i] << " ";
		}
		std::cout << "}" << std::endl;
		for (int i = 0; i < k.amount; i++)
		{
			k.a[i] = new int[k.size];
		}
		std::cout << "Количество сочетаний: " << k.amm << std::endl;
		std::cout << std::endl << "Множества: " << std::endl;
		return k;
	}

	void Sochet(char *set, int Soch, Init k)
	{
		// перевод в двоичную, а из неё в массив int
		//Сформировать битовую последовательность   состоящую из   двоичных нулей. Пронумеровать элементы этой последовательности справа налево, начиная с нуля. 
		for (int i = k.amount - 1; i > 0; i--)
		{
			itoa(i, k.buf, 2);// переводим в двочиную систему число

			for (int j = 0; j < k.size; j++)
			{
				if (k.buf[j] == '1')
					k.a[i][j] = 1;// записываем её в массив
				else if (k.buf[j] == '0')
					k.a[i][j] = 0;
			}
		}
		//фича
		for (int i = k.amount - 1; i > 0; i--)
		{
			//Выбрать из множества   элементы с  номерами   для которых   Полученное подмножество будет
				//являться элементом булеана   В первом случае не будет выбран ни один элемент (пустое подмножество) 
				//множества   так как исходная последовательность   состоит только из нулей.  
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
		int numberOfCondition = 0;
		for (int i = 0; i < k.amount; i++)
		{
			for (int j = 0; j < k.size; j++) //подсчет к-ва единиц в двоичной форме числа
				if (k.a[i][j] == 1)
					count++;


			if (count == Soch) // если к-во единиц в массиве совпадает с нужным выводим
			{
				numberOfCondition++;//счетчик
				std::cout << numberOfCondition << ")   " << "{ ";
				for (int j = 0; j < k.size; j++)
				{
					if (k.a[i][j] == 1)
						std::cout << set[j] << " ";
				}
				std::cout << "} ";
				std::cout << std::endl;
			}
			count = 0;
		}

	}
}