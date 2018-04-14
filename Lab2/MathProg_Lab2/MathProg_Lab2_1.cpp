#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "CombiPer.h"
//TODO somethink with functions
int _tmain(int argc, _TCHAR* argv[])
{//генератор подмножеств заданного множества
	setlocale(LC_ALL, "rus");
	char set[] = { 'A', 'B', 'C', 'D', 'H' };
	
	Perest(set, combiPer::Initialized(set, sizeof(set)));

	system("pause");
	return 0;
}