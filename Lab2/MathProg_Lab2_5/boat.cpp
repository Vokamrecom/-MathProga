#include "stdafx.h"
#include <iostream>
#include "Combi.h"
#include "boat.h"
#include <ctime>

namespace combiSoch
{
	Boat::Boat(int NN, int N, int V, int MNV, int MXV, int MNM, int MXM)
	{
		maxcount = N;//к-во мест на судне
		countContainers = NN;//к-во containers
		maxWeightBoat = V;// максимальный вес судна
		minWeight = MNV;// минимальный вес контейнера
		maxWeight = MXV;// максимальный вес контейнера
		minMoney = MNM;// минимальная цена перевозки контейнера
		maxMoney = MXM;// минимальная цена перевозки контейнера
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