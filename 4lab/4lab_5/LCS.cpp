#include "stdafx.h"
#include "LCS.h"

namespace LCS
{
	int max(int a, int b)
	{
		return a > b ? a : b;
	}

	int max(int a, int b, int c)
	{

		int max = a;
		max = max < b ? b : max;
		max = max < c ? c : max;
		return max;
	}

	Lev Initialized(int M, int N)
	{
		M = 6; N = 7;
		Lev k;
		k.M = M; k.N = N;
		k.a = new char[N + 1];
		k.b = new char[M + 1];
		k.array = new int*[M + 1];
		for (int i = 0; i < M + 1; i++)
		{
			k.array[i] = new int[N + 1];
		}

		k.a[0] = 'A'; k.a[1] = 'B'; k.a[2] = 'C'; k.a[3] = 'D'; k.a[4] = 'F'; k.a[5] = 'G'; k.a[6] = 'I';
		k.b[0] = 'E'; k.b[1] = 'A'; k.b[2] = 'T'; k.b[3] = 'U'; k.b[4] = 'F'; k.b[5] = 'I';
		for (int i = 0; i < N; i++)
		{
			//	k.a[i] = rand() % 26 + 'a';
			std::cout << k.a[i];
		}
		std::cout << std::endl;

		for (int i = 0; i < M; i++)
		{
			//	k.b[i] = rand() % 26 + 'a';
			std::cout << k.b[i];
		}
		std::cout << std::endl << std::endl;
		for (int i = 0; i < N + 1; i++)
		{
			k.array[0][i] = 0;
		}
		for (int i = 0; i < M + 1; i++)
		{
			k.array[i][0] = 0;
		}

		std::cout << "   ";
		for (int i = 0; i < N; i++)
		{
			if (i < 10)
				std::cout << " ";
			else
				std::cout << "  ";
			std::cout << k.a[i];
		}
		std::cout << std::endl << " ";

		for (int i = 0; i < N + 1; i++)
		{
			std::cout << " 0";
		}
		std::cout << std::endl;
		return k;
	}
	void Start(Lev k, clock_t t1)
	{
		for (int i = 0; i < k.M; i++)
		{
			std::cout << k.b[i] << " 0" << " ";
			for (int j = 0; j < k.N; j++)
			{
				if (k.b[i] == k.a[j])
				{
					k.array[i + 1][j + 1] = k.array[i][j] + 1;
				}
				else
				{
					k.array[i + 1][j + 1] = max(k.array[i][j], k.array[i + 1][j], k.array[i][j + 1]);
				}
				std::cout << k.array[i + 1][j + 1] << " ";
			}
			std::cout << std::endl;
		}
		clock_t t2 = clock();
		std::cout << std::endl << "Наибольшая общая подпоследовательность равна(ДП): " << k.array[k.M][k.N];
		std::cout << std::endl << "Время выполнения(ДП): " << t2 - t1 << std::endl;
		clock_t t3 = clock();
		std::cout << std::endl << "Наибольшая общая подпоследовательность равна(рекурсия): " << lcs(k.M, k.a, k.N, k.b) << std::endl;
		clock_t t4 = clock();
		std::cout << std::endl << "Время выполнения(рекурсия): " << t4 - t3 << std::endl;
	}
	int lcs(int lenx, char x[],
		int leny, char y[])
	{
		int rc = 0;
		if (lenx > 0 && leny > 0)
		{
			if (x[lenx - 1] == y[leny - 1]) rc = 1 + lcs(lenx - 1, x, leny - 1, y);
			else rc = max(lcs(lenx, x, leny - 1, y), lcs(lenx - 1, x, leny, y));
		}
		return rc;        //длина LCS
	}
}