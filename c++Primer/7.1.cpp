#include<iostream>
#include<string>
#include"Sales_data.h"


int main()
{
	Sales_data data1, data2;
	std::cin >> data1.bookNo >> data1.revenue >> data1.units_sold;
	std::cin >> data2.bookNo >> data2.revenue >> data2.units_sold;
	if (data1.bookNo == data2.bookNo) {
		std::cout << (data1.revenue * data1.units_sold) + (data2.revenue * data2.units_sold) << std:: endl;
	}
	else {
		std::cout << "두 책이 다릅니다" << std::endl;
	}
}