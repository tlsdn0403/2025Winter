#include<iostream>
#include<string>
#include"Sales_data.h"
using namespace std;

int main()
{
    // 기본 생성자 사용
    Sales_data total;
    cout << "기본 생성자 사용: " << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;

    // 문자열을 인자로 받는 생성자 사용
    Sales_data book1("12345");
    cout << "문자열 생성자 사용: " << book1.bookNo << " " << book1.units_sold << " " << book1.revenue << endl;

    // 문자열, unsigned, double을 인자로 받는 생성자 사용
    Sales_data book2("67890", 10, 29.99);
    cout << "문자열, unsigned, double 생성자 사용: " << book2.bookNo << " " << book2.units_sold << " " << book2.revenue << endl;

    // 입력 스트림을 인자로 받는 생성자 사용
    cout << "책 정보를 입력하세요 (형식: ISBN 판매량 가격): ";
    Sales_data book3(cin);
    cout << "입력 스트림 생성자 사용: " << book3.bookNo << " " << book3.units_sold << " " << book3.revenue << endl;

    return 0;
}