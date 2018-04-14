#include "stdafx.h"
#include "Combi.h"
#include <iostream>

int main()
{//перестановок

//Алгоритм подразумевает, что все элементы множеств vj;yj перечислить в порядке возрастания
	setlocale(LC_ALL, "rus");
	char  set[] = { 'A', 'B', 'C', 'D', 'H' };
	combi::start(combi::Initialized(set, sizeof(set)), set, sizeof(set));
}