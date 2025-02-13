#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>

struct Sales_data {
	//�Ű����� �ڿ� const�� �ξ� this�� const�� ���� ���������� ��Ÿ��
	std::string isbn() const { return this->bookNo; } //Ŭ������ �����Ϸ��� �ɹ����� �� �Լ��� ó�������� bookNo�� ����� �� �ִ�.
	Sales_data& combine(const Sales_data&);
	double avg_price()const;
	//������ ���
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);


Sales_data& Sales_data::combine(const Sales_data& lv) {
	units_sold += lv.units_sold; //lv�� �ɹ��� ��ü �ڽ��� �ɹ��� ���Ѵ�
	revenue += lv.revenue;
	return *this; //�� �Լ��� ȣ���� ��ü�� ��ȯ�Ѵ�
}

double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
#endif // !SALES_DATA_H