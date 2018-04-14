#include "stdafx.h"
#include <iostream>
#include "CombiPer.h"


namespace combiPer
{
	Init Initialized(char *set, int size)
	{
		Init k;
		std::cout << " --- Генератор множества всех подмножеств ---" << std::endl;
		//Func of start
		k.size = size;
		k.amount = pow(2, k.size);
		k.buf = new char[k.size];
		k.a = new int*[k.amount];
		//1.Пронумеровать элементы заданного множества   начиная с нуля.
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
		std::cout << "Количество подмножеств данного множества: " << k.amount << std::endl;
		std::cout << std::endl << "Подмножества: " << std::endl;
		return k;
	}
	void Perest(char *set, Init k)
	{//2.Сформировать битовую последовательность   состоящую из   двоичных нулей. Пронумеровать элементы этой последовательности справа налево, начиная с нуля. 
		for (int i = k.amount - 1; i > 0; i--)
		{
			itoa(i, k.buf, 2);//преобраз целое число в строку
			for (int j = 0; j < k.size; j++)
			{
				if (k.buf[j] == '1')
					k.a[i][j] = 1;
				else if (k.buf[j] == '0')
					k.a[i][j] = 0;
			}
		}
		for (int i = k.amount - 1; i > 0; i--)
		{//4.	Выбрать из множества   элементы с  номерами   для которых   Полученное подмножество будет 
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
		print(k, set);
	}

	void print(Init k, char *set)
	{
		for (int i = 0; i < k.amount; i++)
		{
			std::cout << i + 1 << ")   " << "{ ";
			for (int j = 0; j < k.size; j++)
			{
				if (k.a[i][j] == 1)
					std::cout << set[j] << " ";
			}
			std::cout << "} ";
			std::cout << std::endl;
		}
	}
}