#pragma once 

namespace combi
{
	class Subs
	{
	private:
		char **subs;   //��� �������
		int  amount;  //���-�� �������
		int  size;  //��-��


		char **comb;   //��������� �������
		int combAmount;  //������� ��
		int sizeOfComb;  //�� ������� ��-��
	public:

		Subs(int size, int sizeOfComd);


		void SetSubsInZero();


		int GetAmount();
		int GetSize();
		char** GetSubs();
		int GetComdAmount();
		char** GetCombs();


		void Masks();  //�������� �������
		void SelectSubs(); //���� ������� ����
	};
};