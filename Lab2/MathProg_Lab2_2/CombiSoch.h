#pragma once

namespace combiSoch
{
	class Init
	{
	public:
		int size;
		int amm;
		int amount;
		char *buf;
		int **a;
	};

	int fact(int N);
	Init Initialized(char *set, int size, int Soch);
	void Sochet(char *set, int Soch, Init k);
}
