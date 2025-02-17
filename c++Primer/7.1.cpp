#include<iostream>
#include<string>
#include"Sales_data.h"

using namespace std;
int main()
{
	Sales_data total; //처리 중인 합을 보관할 변수

	if (read(cin, total)) {
		Sales_data trans; //다음 거래 내용을 담을 변수
		//남아있는 거래 내용을 읽고 처리한다
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