#include<iostream>
#include <initializer_list>
using namespace std;

//인자수가 가변일 때 오류 메세지를 출력하는 함수
void error_msg(initializer_list<string> il)
{
	for (auto beg = il.begin(); beg != il.end(); beg++) {
		cout << *beg << " ";
	}
	cout << endl;
}
int main()
{
	string s = "함수 "; // 초기화된 string 값
	error_msg({ "sinwoo","2개를 넣어도 된당", s});    // {} 안에 string 타입으로 통일
}