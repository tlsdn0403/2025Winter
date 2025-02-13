#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>

struct Sales_data {
	//매개변수 뒤에 const를 두어 this가 const에 대한 포인터임을 나타냄
	std::string isbn() const { return this->bookNo; } //클래스는 컴파일러가 맴버선언 후 함수를 처리함으로 bookNo를 사용할 수 있다.
	Sales_data& combine(const Sales_data&);
	double avg_price()const;
	//데이터 멤버
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);


Sales_data& Sales_data::combine(const Sales_data& lv) {
	units_sold += lv.units_sold; //lv의 맴버를 객체 자신의 맴버에 더한다
	revenue += lv.revenue;
	return *this; //이 함수를 호출한 객체를 반환한다
}

double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
#endif // !SALES_DATA_H