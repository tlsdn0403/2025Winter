#include<iostream>
#include<string>
#include"Sales_data.h"
using namespace std;

int main()
{
    // �⺻ ������ ���
    Sales_data total;
    cout << "�⺻ ������ ���: " << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;

    // ���ڿ��� ���ڷ� �޴� ������ ���
    Sales_data book1("12345");
    cout << "���ڿ� ������ ���: " << book1.bookNo << " " << book1.units_sold << " " << book1.revenue << endl;

    // ���ڿ�, unsigned, double�� ���ڷ� �޴� ������ ���
    Sales_data book2("67890", 10, 29.99);
    cout << "���ڿ�, unsigned, double ������ ���: " << book2.bookNo << " " << book2.units_sold << " " << book2.revenue << endl;

    // �Է� ��Ʈ���� ���ڷ� �޴� ������ ���
    cout << "å ������ �Է��ϼ��� (����: ISBN �Ǹŷ� ����): ";
    Sales_data book3(cin);
    cout << "�Է� ��Ʈ�� ������ ���: " << book3.bookNo << " " << book3.units_sold << " " << book3.revenue << endl;

    return 0;
}