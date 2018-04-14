#pragma once

namespace combiSoch
{
	class Boat
	{
	public:
		int maxcount; // �-�� �����������, ������� ������� �� �����
		int maxWeightBoat; // ������������ ����� �����������, ������� ������� �� �����
		int countContainers; // �-�� �����������, ������� � ��� �������
		int *weightOfContainer; // ��� ���� �����������
		int *moneyFromContainer; // // ���� ���� �����������
		int minMoney;
		int maxMoney;
		int minWeight;
		int maxWeight;

		Boat(int, int, int, int, int, int, int);

		void LargestSum();
	};
}