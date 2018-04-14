#pragma once

namespace combiPer
{
	class Init
	{
	public:
		int size;
		int amount;//кол-во
		char *buf;
		int **a;
	};

	Init Initialized(char *set, int size);
	void Perest(char *set, Init k);
	void print(Init k, char *set);
}
