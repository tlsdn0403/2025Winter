#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>

struct Sales_data {
	Sales_data() = default; //�⺻ �����ڸ� �����Ѵ�.
	//( )�߰�ȣ ���̿� �ִ� �ڵ�� ������ �ʱ� �� ����̴�.
	Sales_data(const std:: string&s): bookNo(s){ }
	Sales_data(const std::string &s, unsigned n ,double p): bookNo(s), units_sold(n), revenue(p*n) { }

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


Sales_data& Sales_data::combine(const Sales_data& lv)
{
	units_sold += lv.units_sold; //lv�� �ɹ��� ��ü �ڽ��� �ɹ��� ���Ѵ�
	revenue += lv.revenue;
	return *this; //�� �Լ��� ȣ���� ��ü�� ��ȯ�Ѵ�
}

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
std::istream& read(std::istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
std::ostream& print(std::ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}
Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs; //lhs���� sum�� ������ �ִ´�
	sum.combine(rhs); //rhs�� ���� sum�� ���Ͽ� �ִ´�
	return sum;
}
#endif // !SALES_DATA_H