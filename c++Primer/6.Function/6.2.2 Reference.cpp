#include<iostream>

using namespace std;
//int�� ���� �����ڸ� ���ϰ� ��� ��ü�� 0 ���� �ʱ�ȭ �ϴ� �Լ�
void reset(int& ir) //ir�� ���� reset�� �����ϴ� ��ü�� �ٸ� �̸��̴�
{
	ir = 0;
}
void swap_1(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
string::size_type find_char(const string& s, char c, string::size_type& occurs)  //size_type��  ���� ���� int���� ���� ���� �� �ִ�
{
	auto ret = s.size(); //ó�� ��Ÿ�� ��ġ
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
	int& r = n; //r�� n�� �����Ѵ� (r�� n�� �ٸ��̸�)
	r = 42; //n�� ���� 42
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