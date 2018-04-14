#include "stdafx.h"
#include <iostream>
#include "CombiPer.h"


namespace combiPer
{
	Init Initialized(char *set, int size)
	{
		Init k;
		std::cout << " --- ��������� ��������� ���� ����������� ---" << std::endl;
		//Func of start
		k.size = size;
		k.amount = pow(2, k.size);
		k.buf = new char[k.size];
		k.a = new int*[k.amount];
		//1.������������� �������� ��������� ���������   ������� � ����.
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
		std::cout << "���������� ����������� ������� ���������: " << k.amount << std::endl;
		std::cout << std::endl << "������������: " << std::endl;
		return k;
	}
	void Perest(char *set, Init k)
	{//2.������������ ������� ������������������   ��������� ��   �������� �����. ������������� �������� ���� ������������������ ������ ������, ������� � ����. 
		for (int i = k.amount - 1; i > 0; i--)
		{
			itoa(i, k.buf, 2);//�������� ����� ����� � ������
			for (int j = 0; j < k.size; j++)
			{
				if (k.buf[j] == '1')
					k.a[i][j] = 1;
				else if (k.buf[j] == '0')
					k.a[i][j] = 0;
			}
		}
		for (int i = k.amount - 1; i > 0; i--)
		{//4.	������� �� ���������   �������� �  ��������   ��� �������   ���������� ������������ ����� 
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