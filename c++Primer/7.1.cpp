#include<iostream>
#include<string>
#include"Sales_data.h"

using namespace std;
int main()
{
	Sales_data total; //ó�� ���� ���� ������ ����

	if (read(cin, total)) {
		Sales_data trans; //���� �ŷ� ������ ���� ����
		//�����ִ� �ŷ� ������ �а� ó���Ѵ�
		while (read(cin, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total);
				total = trans;
			}
		}
		print(cout, total);
	}
	else {
		std::cerr << "No data" << std::endl;
		return -1;
	}

}