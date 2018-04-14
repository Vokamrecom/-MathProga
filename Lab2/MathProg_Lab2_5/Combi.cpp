#include "stdafx.h"
#include <iostream>
#include "Combi.h"

namespace combiSoch
{
	int fact(int N, int M) // ���������
	{
		if (N == M)
			return 1;
		else
			return(N * fact(N - 1, M));
	}
	int fact(int N) // ���������
	{
		if (N == 0)
			return 1;
		else
			return(N * fact(N - 1));
	}


	Init Initialized(int size, int Soch) // ����� ���� �� ������ � ���������� ����� ������
	{
		Init k;
		k.size = size;
		k.amm = fact(k.size, (k.size - Soch)) / fact(Soch);	//���������� �������� ���������
		k.amount = pow(2, k.size);								// ���������� ���������, ������� ����� ���������
		k.buf = new char[k.size];								// ������ �����
		k.end = new int[k.size];
		return k;
	}

	void Sochet(int Soch, Init k, int *weight, int *cost, int maxW)
	{
		int Sweight = 0;
		int endWeigth = 0;
		int sum = 0; // �� ���� ������ ����� ������� ����� �������� �����������
		int maxSum = 0;
		int arrcount = 0; // ��� ����� ������� ��� ����� ������� 
		int count = 0;	// ������� ��� ����, ����� ������� ��������� �� �-�� ������ � ����� � ��������
		double i = 0;
		while (i < k.amount)
		{
				itoa(i, k.buf, 2);	// ��������� � �������� ������� �����

				k.a = new int[k.size]; // �������� ������ ��� �������� ����� �����

				for (int j = 0; j < k.size; j++)
				{
					if (k.buf[j] == '1') // ���� ��� � ��� ������� ���� �������, �� 
					{
						k.a[j] = 1;		// ���������� � � ������
						count++;			// ������� ������ ����������
					}
					else if (k.buf[j] == '0')	// ���� ��� 0
						k.a[j] = 0;	// �� ������ ����������
					if (count == 6)
						break;
				}
				if (count == Soch)
				{
					// ����
					//������� �� ���������   �������� �  ��������   ��� �������   ���������� ������������ �����
					//�������� ��������� �������   � ������ ������ �� ����� ������ �� ���� ������� (������ ������������) 
					//���������   ��� ��� �������� ������������������   ������� ������ �� �����.  
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

		std::cout << std::endl << "- ��� �����������                 : ";
		for (int i = 0; i < k.size; i++) std::cout << weight[i] << " ";
		std::cout << std::endl << "- ����� �� ���������              : ";
		for (int i = 0; i < k.size; i++) std::cout << cost[i] << " ";
		std::cout << std::endl << "- ������� ���������� (0,1,...,m-1): ";
		for (int i = 0; i < k.size; i++) 
			if (k.end[i] == 1 )
				std::cout << i+1 << " ";
		std::cout << std::endl << "- ����� �� ���������              : " << maxSum;
		std::cout << std::endl << "- ����� ��� ��������� ����������� : " << endWeigth;
		std::cout << std::endl << std::endl;
	}
}