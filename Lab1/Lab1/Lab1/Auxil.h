#pragma once
#include "stdafx.h"
#include <cstdlib>
#include <ctime>

namespace auxil
{
	void   start();                         // старт  генератора сл. чисел
	double dget(double rmin, double rmax); // получить случайное число 
	int    iget(int rmin, int rmax);        // получить  случайное число

}