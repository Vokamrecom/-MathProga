#include "stdafx.h"
#include "Combi.h"
#include <algorithm>
#include "stdafx.h"
#include <iostream>

char  set[] = { 'A', 'B', 'C'/*, 'D'*/ };
int size = sizeof(set);
static int zz = 0;
struct a
{
	int q;
	bool p; // false - влево, true - вправо
};

void print(a *k)
{
	zz++;
	std::cout << zz << ") { ";
	for (int j = 0; j < size; j++)
	{
		std::cout << set[k[j].q] << " ";
	}
	std::cout << "} " << std::endl;
}

a search(a *k, int some)
{
	for (int j = 0; j < size; j++)
	{
		if (k[j].q == some)
		{
			if ((j == 0 && k[j].p == false) || (j == size - 1 && k[j].p == true))
			{
				some -= 1;
				search(k, some);
			}
			else
			{
				if (k[j].p)
					std::swap(k[j], k[j + 1]);
				else
					std::swap(k[j], k[j - 1]);

				for (int j = 0; j < size; j++)
				{
					if (k[j].q > some)
					{
						if (k[j].p == true)
							k[j].p = false;
						else
							k[j].p = true;
					}
				}
			}
		}
	}
	return *k;
}

int main()
{
	// инициализация
	setlocale(LC_ALL, "rus");
	int amount = 1;
	a *k;
	k = new a[size];
	for (int i = 0; i < size; i++)
	{
		k[i].p = false;
		k[i].q = i;
	}
	for (int i = 1; i <= size; i++)
		amount *= i;
	//информативные сообщения
	std::cout << " --- Генератор перестановок ---" << std::endl;
	std::cout << "Исходное множество: " << std::endl << "{ ";
	for (int i = 0; i < size; i++)
		std::cout << set[i] << " ";
	std::cout << "}" << std::endl;
	std::cout << "Количество перестановок: " << amount << std::endl;
	std::cout << "Перестановки:" << std::endl;
	//подсчёты
	int some;
	print(k);
	int somecount = 0;
	a *z = new a[size];
	for (int i = 0; i < amount - 1; i++)
	{
		for (int i = 0; i < size; i++)
		{
			z[i].p = k[i].p;
			z[i].q = k[i].q;
		}
		some = size - 1;
		*k = search(k, some);
		for (int i = 0; i < size; i++)
		{
			if ((z[i].p == k[i].p) && (z[i].q == k[i].q)) somecount++;
		}
		if (somecount != 4)
			print(k);
		somecount = 0;
	}
	system("pause");
	return 0;
}