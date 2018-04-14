#pragma once 

namespace combi
{
	class Subs
	{
	private:
		char **subs;   //все цепочки
		int  amount;  //кол-во цепочек
		int  size;  //эл-ты


		char **comb;   //результир цепочки
		int combAmount;  //сколько их
		int sizeOfComb;  //по сколько эл-ов
	public:

		Subs(int size, int sizeOfComd);


		void SetSubsInZero();


		int GetAmount();
		int GetSize();
		char** GetSubs();
		int GetComdAmount();
		char** GetCombs();


		void Masks();  //двоичная масочка
		void SelectSubs(); //ищем цепочки наши
	};
};