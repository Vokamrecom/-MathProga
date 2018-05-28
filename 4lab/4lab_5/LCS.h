#pragma once
#include <iostream>
#include <ctime>

namespace LCS
{
	struct Lev
	{
		int N;
		int M;
		char *a;
		char *b;
		int **array;
		char arr[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u', 'v', 'x', 'y', 'z' };

	};
	int max(int a, int b, int c);
	int max(int a, int b);
	Lev Initialized(int M, int N);
	void Start(Lev k, clock_t);
	int lcs(int lenx, char x[], int leny, char y[]);
}