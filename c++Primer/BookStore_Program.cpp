#include<iostream>
#include"Sales_item.h"
int main()
{
	Sales_item total; //ó�� ���� ���� ������ ����

	if (std::cin >> total) {
		Sales_item trans; //���� �ŷ� ������ ���� ����
		//�����ִ� �ŷ� ������ �а� ó���Ѵ�
		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn())
				total += trans;
			else {
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	}
	else {
		std::cerr << "No data" << std:: endl;
		return -1;
	}

}