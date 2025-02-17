#include<iostream>
#include"Sales_item.h"
int main()
{
	Sales_item total; //처리 중인 합을 보관할 변수

	if (std::cin >> total) {
		Sales_item trans; //다음 거래 내용을 담을 변수
		//남아있는 거래 내용을 읽고 처리한다
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