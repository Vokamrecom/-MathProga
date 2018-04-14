#pragma once 

namespace combi
{
	class Subs
	{
	private:
		char **subs;  //���� ������������
		int  amount;  //�������
		int  size;  //����� ��-��

	public:

		Subs(int size);


		void SetSubsInZero(); //������ ��������


		int GetAmount();
		int GetSize();
		char** GetSubs();


		void SetMasks();  // �������� �����
	};
};