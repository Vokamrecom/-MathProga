#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "CombiSoch.h"
//TODO somethink with functions
//генератор сочетаний

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	char set[] = { 'A', 'B', 'C', 'D', 'E'};//n=20
	int Soch = 2;//m=? т.е. мощность
	//генерация множества   может быть сведена к генерации булеана  и выбору из него всех подмножеств с мощностью   
	combiSoch::Sochet(set, Soch, combiSoch::Initialized(set, sizeof(set), Soch));

	system("pause");
	return 0;
}