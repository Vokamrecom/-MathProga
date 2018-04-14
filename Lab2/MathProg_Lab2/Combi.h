#pragma once 

namespace combi
{
	class Subs
	{
	private:
		char **subs;  //наши подмножества
		int  amount;  //строчки
		int  size;  //колво эл-ов

	public:

		Subs(int size);


		void SetSubsInZero(); //нулями забиваем


		int GetAmount();
		int GetSize();
		char** GetSubs();


		void SetMasks();  // двоичные числа
	};
};