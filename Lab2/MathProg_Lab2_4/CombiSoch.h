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
		char **end;
	};

	int getAmount(int size, int Soch);
	int fact(int N);
	Init Initialized(char *set, int size, int Soch);
	char** Sochet(char *set, int Soch, Init k);
}
