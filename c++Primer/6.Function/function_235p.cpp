#include<iostream>
using namespace std;


//���丮���� ������ִ� �Լ�
int fact(int val) { //fact �Լ��� ȣ�� �� �� ������ ������ val������ �ʱ�ȭ
	int ret = 1;//������� ��� ��������
	while (val > 1) {
		ret *= val--; //val���� ������ �Ŀ� 1�� �� (����������)
	}
	return ret;
}
int main() {
	int k = 3.14; //�����ȯ�� �Ͼ
	int j = fact(k); //�Լ��� ȣ���� �� int ���� val ����
	cout<<k << " �� ���丮�� j�� ���� : " << j;
	return 0;
}