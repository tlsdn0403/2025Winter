#include<iostream>
using namespace std;


//���丮���� ������ִ� �Լ�
int fact(int val) {
	int ret = 1;//������� ��� ��������
	while (val > 1) {
		ret *= val--; //val���� ������ �Ŀ� 1�� �� (����������)
	}
	return ret;
}
int main() {
	int j = fact(5);
	cout << "j�� 5�� ���丮�� j�� ���� : " << j;
	return 0;
}