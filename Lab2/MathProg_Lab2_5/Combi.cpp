#include "stdafx.h"
#include <iostream>
#include "Combi.h"

namespace combiSoch
{
	int fact(int N, int M) // факториал
	{
		if (N == M)
			return 1;
		else
			return(N * fact(N - 1, M));
	}
	int fact(int N) // факториал
	{
		if (N == 0)
			return 1;
		else
			return(N * fact(N - 1));
	}


	Init Initialized(int size, int Soch) // вывод инфы на коноль и заполнение полей класса
	{
		Init k;
		k.size = size;
		k.amm = fact(k.size, (k.size - Soch)) / fact(Soch);	//количество конечных вариантов
		k.amount = pow(2, k.size);								// количество вариантов, которые нужно перебрать
		k.buf = new char[k.size];								// просто буфер
		k.end = new int[k.size];
		return k;
	}

	void Sochet(int Soch, Init k, int *weight, int *cost, int maxW)
	{
		int Sweight = 0;
		int endWeigth = 0;
		int sum = 0; // по идее должен будет считать самое выгодное предложение
		int maxSum = 0;
		int arrcount = 0; // это кароч счетчик для строк массива 
		int count = 0;	// счетчик для того, чтобы считать совпадает ли к-во единиц в числе и заданное
		double i = 0;
		while (i < k.amount)
		{
				itoa(i, k.buf, 2);	// переводим в двочиную систему число

				k.a = new int[k.size]; // выделяем память для хранения этого числа

				for (int j = 0; j < k.size; j++)
				{
					if (k.buf[j] == '1') // если это в его составе есть единица, то 
					{
						k.a[j] = 1;		// записываем её в массив
						count++;			// счетчик единиц уеличиваем
					}
					else if (k.buf[j] == '0')	// если это 0
						k.a[j] = 0;	// то просто записываем
					if (count == 6)
						break;
				}
				if (count == Soch)
				{
					// фича
					//Выбрать из множества   элементы с  номерами   для которых   Полученное подмножество будет
					//являться элементом булеана   В первом случае не будет выбран ни один элемент (пустое подмножество) 
					//множества   так как исходная последовательность   состоит только из нулей.  
					for (int j = 0; j < k.size; j++)
					{
						if (k.a[j] != 0)
							if (k.a[j] != 1)
							{
								for (int z = j; z > 0; z--)
								{
									int b = k.a[z - 1];
									k.a[z - 1] = k.a[z];
									k.a[z] = b;
								}
								k.a[0] = 0;
							}
					}

					
					for (int j = 0; j < k.size; j++)
					{
						if (k.a[j] == 1)
						{
							Sweight += weight[j];
							sum += cost[j];
						}
					}
					if (maxW >= Sweight && sum > maxSum)
					{
						for (int j = 0; j < k.size; j++)
						{
							k.end[j] = k.a[j];
						}
						maxSum = sum;
						endWeigth = Sweight;
					}
				}
				sum = 0;
				Sweight = 0;
				delete(k.a);
				count = 0;
				i++;
		}

		std::cout << std::endl << "- вес контейнеров                 : ";
		for (int i = 0; i < k.size; i++) std::cout << weight[i] << " ";
		std::cout << std::endl << "- доход от перевозки              : ";
		for (int i = 0; i < k.size; i++) std::cout << cost[i] << " ";
		std::cout << std::endl << "- выбраны контейнеры (0,1,...,m-1): ";
		for (int i = 0; i < k.size; i++) 
			if (k.end[i] == 1 )
				std::cout << i+1 << " ";
		std::cout << std::endl << "- доход от перевозки              : " << maxSum;
		std::cout << std::endl << "- общий вес выбранных контейнеров : " << endWeigth;
		std::cout << std::endl << std::endl;
	}
}