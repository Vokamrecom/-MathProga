#pragma once

namespace combiSoch
{
	class Boat
	{
	public:
		int maxcount; // к-во контейнеров, которые влезают на судно
		int maxWeightBoat; // максимальная масса контейнеров, которые влезают на судно
		int countContainers; // к-во контейнеров, которые у нас имеются
		int *weightOfContainer; // вес этих контейнеров
		int *moneyFromContainer; // // цена этих контейнеров
		int minMoney;
		int maxMoney;
		int minWeight;
		int maxWeight;

		Boat(int, int, int, int, int, int, int);

		void LargestSum();
	};
}