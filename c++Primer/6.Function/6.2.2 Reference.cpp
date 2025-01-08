#include<iostream>

using namespace std;
//int에 대한 참조자를 취하고 대상 객체를 0 으로 초기화 하는 함수
void reset(int& ir) //ir은 단지 reset에 전달하는 객체에 다른 이름이다
{
	ir = 0;
}
void swap_1(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
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
	int n = 0, i = 22;
	int& r = n; //r은 n과 결합한다 (r은 n의 다른이름)
	r = 42; //n은 이제 42
	r = i;
	reset(i);
	cout << "n :" << n << ", i : " << i << endl;
	swap_1(n, i);
	cout << "n :" << n << ", i : " << i << endl;

	string s = "abksdsssef";
	string::size_type num = 0;
	auto index = find_char(s, 's', num);
	cout <<"first s intdex :"<< index<<", s count :"<<num;
}