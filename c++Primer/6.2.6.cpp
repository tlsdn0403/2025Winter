#include<iostream>
#include <initializer_list>
using namespace std;

//���ڼ��� ������ �� ���� �޼����� ����ϴ� �Լ�
void error_msg(initializer_list<string> il)
{
	for (auto beg = il.begin(); beg != il.end(); beg++) {
		cout << *beg << " ";
	}
	cout << endl;
}
int main()
{
	string s = "�Լ� "; // �ʱ�ȭ�� string ��
	error_msg({ "sinwoo","2���� �־ �ȴ�", s});    // {} �ȿ� string Ÿ������ ����
}