#include "stdafx.h"
#include "Combi.h"
#include <algorithm>

namespace combi
{
	Subs::Subs(int psize)
	{
		this->size = psize;
		this->amount = pow(2, this->size);
		subs = new char*[amount];
		for (int i = 0; i < amount; i++)
			subs[i] = new char[this->size];
	}
	void Subs::SetSubsInZero()
	{
		for (int i = 0; i < this->amount; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				subs[i][j] = '0';
			}
			subs[i][this->size] = '\0';

		}
	}
	void Subs::SetMasks()
	{
		char *buf = new char[this->size];
		for (int i = this->amount - 1; i >= 0; i--)
		{
			int z = this->size - 1;
			itoa(i, buf, 2);
			for (int j = this->size; j >= 0; j--)
			{
				if (buf[j] != '\0')
				{
					this->subs[i][z] = buf[j];
					z--;
				}
			}

		}
	}
	int Subs::GetAmount()
	{
		return this->amount;
	}
	int Subs::GetSize()
	{
		return this->size;
	}
	char** Subs::GetSubs()
	{
		return this->subs;
	}
};