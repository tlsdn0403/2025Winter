#include<iostream>

using namespace std;

void swap(int& a, int& b) {
	if (a == b) {
		return; //���� ������ ���� �� �ʿ䰡 ����
	}
	int c = a;
	a = b;
	b = c;
	//��������� ��ȯ���� �ʾƵ� �ȴ�
}

int main() {
	int c = 4;
	int d = 8;
	swap(c, d);
	cout << c << " " << d;
}