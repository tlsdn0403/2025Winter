#include<iostream>
#include<string>
using namespace std;
//int�� ���� �����ڸ� ���ϰ� ��� ��ü�� 0 ���� �ʱ�ȭ �ϴ� �Լ�
void reset(int& ir) //ir�� ���� reset�� �����ϴ� ��ü�� �ٸ� �̸��̴�
{
	ir = 0;
}
void reset(int* ip)
{
	*ip = 0; //ip�� ����Ű�� ��ü ���� ����
	ip = 0;  //ip�� ���� ���纻�� �����ϸ� ���ڴ� �������� �ʴ´�
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
	int i = 0;
	const int ci = i;
	string::size_type ctr = 0;
	reset(&i); //�Ű������� int*�� reset ������ ȣ��
	reset(i); //�Ű������� int&�� reset ������ ȣ��
	find_char("Hello world", 'o', ctr); //ù �Ű������� const������ ����� �־ ��
	string s = "Hello world";
	makeBig(s);
	cout << ctr << endl;
	cout << s;
}