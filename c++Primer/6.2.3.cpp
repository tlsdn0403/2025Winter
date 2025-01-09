#include<iostream>
#include<string>
using namespace std;
//int에 대한 참조자를 취하고 대상 객체를 0 으로 초기화 하는 함수
void reset(int& ir) //ir은 단지 reset에 전달하는 객체에 다른 이름이다
{
	ir = 0;
}
void reset(int* ip)
{
	*ip = 0; //ip로 가르키는 객체 값을 변경
	ip = 0;  //ip의 지역 복사본만 변경하며 인자는 변경하지 않는다
}
void swap_1(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
void makeBig(string &s) {
	for (auto &c : s) {
		c=tolower(c);
	}
}
string::size_type find_char(const string& s, char c, string::size_type& occurs)  //size_type은  수를 담음 int보다 많이 담을 수 있다
{
	auto ret = s.size(); //처음 나타난 위치
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size(); ++i) {
		if (s[i] == c) {
			if (ret == s.size()) {
				ret = i;
			}
			++occurs;
		}
	}
	return ret;
}
int main()
{
	int i = 0;
	const int ci = i;
	string::size_type ctr = 0;
	reset(&i); //매개변수가 int*인 reset 버전을 호출
	reset(i); //매개변수가 int&인 reset 버전을 호출
	find_char("Hello world", 'o', ctr); //첫 매개변수가 const임으로 상수를 넣어도 됨
	string s = "Hello world";
	makeBig(s);
	cout << ctr << endl;
	cout << s;
}