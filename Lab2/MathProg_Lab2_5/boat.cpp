#include "stdafx.h"
#include <iostream>
#include "Combi.h"
#include "boat.h"
#include <ctime>

namespace combiSoch
{
	Boat::Boat(int NN, int N, int V, int MNV, int MXV, int MNM, int MXM)
	{
		maxcount = N;//�-�� ���� �� �����
		countContainers = NN;//�-�� containers
		maxWeightBoat = V;// ������������ ��� �����
		minWeight = MNV;// ����������� ��� ����������
		maxWeight = MXV;// ������������ ��� ����������
		minMoney = MNM;// ����������� ���� ��������� ����������
		maxMoney = MXM;// ����������� ���� ��������� ����������
	}

	void Boat::LargestSum()
	{
		srand(time(NULL));
		weightOfContainer = new int[countContainers];
		moneyFromContainer = new int[countContainers];
		for (int i = 0; i < countContainers; i++)
		{
			weightOfContainer[i] = rand() % maxWeight + minWeight;
			moneyFromContainer[i] = rand() % maxMoney + minMoney;
		}
		combiSoch::Sochet(maxcount, combiSoch::Initialized(countContainers, maxcount), weightOfContainer, moneyFromContainer, maxWeightBoat);
	}

}