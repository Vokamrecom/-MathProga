#include "stdafx.h"
#include "Combi.h"

#include <iostream>

namespace combi
{

	int fact(int N)
	{
		if (N == 0)
			return 1;
		else
			return(N * fact(N - 1));
	}

	int getSize(char *set)
	{
		return sizeof(set);
	}

	int getAmount(int size)
	{
		return fact(size);
	}

	a** Initialized(char *set, int size)
	{
		std::cout << std::endl << " --- ��������� ������������ ---";
		std::cout << std::endl << "�������� ���������: ";
		std::cout << "{ ";
		for (int i = 0; i < size; i++)
			std::cout << set[i] << " ";
		std::cout << "}" << std::endl;
		a **array = new a*[getAmount(size)];
		a *q = new a[size];
		std::cout << "���������� ��������: " << getAmount(size) << std::endl;
		for (int i = 0; i < getAmount(size); i++)
		{
			array[i] = new a[size];
			//1.	��������� ������ ������������. ������ ������������ � ��� ������������������ ����
			//��������� ���������   ������������� � ������� �����������. ������� ���� ��������� ������������������ 
			//���������� �����. 
			for (int j = 0; j < size; j++)
			{
				array[i][j].value = 0;
				array[i][j].direction = false;
			}
		}
		for (int j = 0; j < size; j++)
		{
			array[0][j].value = j;
		}
		return array;
	}


	void print(a **b, char *set, int size)
	{
		int z = 0;
		for (int i = 0; i < getAmount(size); i++)
		{
			std::cout << ++z << ") { ";
			for (int j = 0; j < size; j++)
			{
				std::cout << set[b[i][j].value] << " ";
			}
			std::cout << "}" << std::endl;
		}
	}

	void dothis(a *b, a *c, int some, int size, char *set)
	{
		for (int i = 0; i < size; i++)
		{
			if (b[i].value == some) // some - �������������� ������������ �����
			{
				if ((i == 0 && b[i].direction == false) || (i == (size - 1) && b[i].direction == true))	//���� ��� ��������� � ������� �������
				{																					// �� ���� ������ �������
					dothis(b, c, some - 1, size, set);
					break;
				}
				else
				{//2.	����� ���������� ��������� ������� � ������� ������������. ���� � ������������������ ��� ���������� ��������, �� ��������� ��� 
					//������������ ��������� ���������   � �������� �������� ���� ������. 
					if (b[i].direction == false && (b[i].value < b[i - 1].value) || b[i].direction == true && (b[i].value < b[i + 1].value))
					{																							// ���� ��������� �����, � �������
						dothis(b, c, some - 1, size, set);													// �� ��������� ������
						break;																						// �� ���� ������ �������
					}
					else
					{
						//3�������� ������� ���������� ��������� ������� � �������, �� ������� ��������� ������� ����������� ���������� ��������.
						for (int k = 0; k < size; k++)
						{
							c[k].value = b[k].value;
							c[k].direction = b[k].direction;
						}
						if (b[i].direction == false)
						{
							c[i - 1].direction = b[i].direction;
							c[i - 1].value = b[i].value;
							c[i].direction = b[i - 1].direction;
							c[i].value = b[i - 1].value;
						}
						else
						{
							c[i + 1].direction = b[i].direction;
							c[i + 1].value = b[i].value;
							c[i].direction = b[i + 1].direction;
							c[i].value = b[i + 1].value;
						}//����� ��� ��������, �������, ��� ��������� ������� (���� ��� ����) � �������� �� ������� �� ��������������� �����������. 
						for (int k = 0; k < size; k++)
						{
							if (c[k].value > some)
							{
								if (c[k].direction)
									c[k].direction = false;
								else
									c[k].direction = true;
							}
						}
					}
				}
			}
		}
	}


	void start(a **b, char *set, int size)
	{
		for (int i = 0; i < getAmount(size); i++)
		{
			dothis(b[i], b[i + 1], size - 1, size, set);
		}
		print(b, set, size);
	}


}