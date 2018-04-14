#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Combi.h"
#include "boat.h"
#include <ctime>

#define NN 15 //�-�� containers
#define N 5 //�-�� ���� �� �����
#define V 1500 // ������������ ��� �����
#define MNV 100 // ����������� ��� ����������
#define MXV 300 // ������������ ��� ����������
#define MNM 10 // ����������� ���� ��������� ����������
#define MXM 150 // ����������� ���� ��������� ����������

int _tmain(int argc, _TCHAR* argv[])
{
	//int NN = 25;
	srand(time(0));
	setlocale(LC_ALL, "rus");
	combiSoch::Boat boat(NN, N, V, MNV, MXV, MNM, MXM); 
	std::cout << std::endl << "- ������ � ���������� ����������� �� �����";
	std::cout << std::endl << "- ����� ���������� �����������    : " << NN;
	std::cout << std::endl << "- ���������� ���� ��� ����������� : " << N;
	std::cout << std::endl << "- ����������� �� ���������� ����  : " << V;
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
