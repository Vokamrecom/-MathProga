#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Combi.h"
#include "boat.h"
#include <ctime>

#define NN 15 //к-во containers
#define N 5 //к-во мест на судне
#define V 1500 // максимальный вес судна
#define MNV 100 // минимальный вес контейнера
#define MXV 300 // максимальный вес контейнера
#define MNM 10 // минимальная цена перевозки контейнера
#define MXM 150 // минимальная цена перевозки контейнера

int _tmain(int argc, _TCHAR* argv[])
{
	//int NN = 25;
	srand(time(0));
	setlocale(LC_ALL, "rus");
	combiSoch::Boat boat(NN, N, V, MNV, MXV, MNM, MXM); 
	std::cout << std::endl << "- Задача о размещении контейнеров на судне";
	std::cout << std::endl << "- общее количество контейнеров    : " << NN;
	std::cout << std::endl << "- количество мест для контейнеров : " << N;
	std::cout << std::endl << "- ограничение по суммарному весу  : " << V;
	//while (0 <= (28-NN))
	{
		unsigned int start_time = clock();

		boat.LargestSum();

		unsigned int end_time = clock();

		std::cout << "Time of " << NN << " = " << ((double)(end_time - start_time)/1000) << " seconds;" << std::endl;

		//NN++;
	}
	
	system("pause");
	return 0;
}
