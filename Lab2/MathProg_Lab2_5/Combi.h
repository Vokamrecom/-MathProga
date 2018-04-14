#pragma once

namespace combiSoch
{
	class Init
	{
	public:
		long long size;
		long long amm;
		double amount;
		char *buf;
		int *a;
		int *end;
	};

	int fact(int N);
	Init Initialized(int size, int Soch);
	void Sochet(int Soch, Init k, int *weight, int *cost, int maxW);
}
