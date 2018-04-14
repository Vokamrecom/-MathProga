#pragma once

namespace combi
{
	struct a
	{
		int value;
		bool direction; // false - влево, true - вправо
		int size;
		int amount;
	};

	int fact(int N);
	int getSize(char *set);
	int getAmount(int size);//кол-во
	a** Initialized(char *set, int a);
	void print(a **b, char *set, int size);
	void dothis(a *b, a *c, int some, int size, char *set);
	void start(a **b, char *set, int size);
};