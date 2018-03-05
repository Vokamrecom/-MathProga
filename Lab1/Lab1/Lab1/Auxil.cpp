#include "stdafx.h"
#include "Auxil.h"

//RAND_MAX = 32767
namespace auxil
{
	void start()
	{
		srand((unsigned)time(NULL));// старт  генератора сл. чисел
	}

	double dget(double rmin, double rmax)// получить случайное число
	{
		return (double)rand() / RAND_MAX * (rmax - rmin) + rmin;
	}

	int iget(int rmin, int rmax)// получить случайное число
  
	{
		return (int)dget((double)rmin, (double)rmax);
	}
}