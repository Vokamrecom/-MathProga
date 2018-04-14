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

	Init Initialized(char *set, int size, int Soch) // ����� ���� �� ������ � ���������� ����� ������
	{
		std::cout << " --- ��������� ��������� ---" << std::endl;
		Init k;
		k.size = size;
		k.amm = getAmount(size, Soch);
		k.amount = pow(2, k.size);// ���������� ���������, ������� ����� ���������
		k.buf = new char[k.size];
		k.a = new int*[k.amount];
		k.end = new char*[k.amm];
		std::cout << "�������� ���������: { ";
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
		std::cout << "���������� ���������: " << k.amm << std::endl;
		std::cout << std::endl << "���������: " << std::endl;
		return k;
	}

	char** Sochet(char *set, int Soch, Init k)
	{
		// ������� � ��������, � �� �� � ������ int
		//������������ ������� ������������������   ��������� ��   �������� �����. ������������� �������� ���� ������������������ ������ ������, ������� � ����. 
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
		//����
		for (int i = k.amount - 1; i > 0; i--)
		{//������� �� ���������   �������� �  ��������   ��� �������   ���������� ������������ �����
				//�������� ��������� �������   � ������ ������ �� ����� ������ �� ���� ������� (������ ������������) 
				//���������   ��� ��� �������� ������������������   ������� ������ �� �����.  
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
			for (int j = 0; j < k.size; j++) //������� �-�� ������ � �������� ����� �����
				if (k.a[i][j] == 1)
					count++;


			if (count == Soch) // ���� �-�� ������ � ������� ��������� � ������ �������
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