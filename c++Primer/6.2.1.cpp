#include<iostream>

using namespace std;

void reset(int* ip)
{	

	*ip = 0; //ip�� ����Ű�� ��ü ���� ����
	ip = 0;  //ip�� ���� ���纻�� �����ϸ� ���ڴ� �������� �ʴ´�
}
void swap_1(int* a, int* b) {
	int c = *a; //c�� a�� ����Ű�� �� 
	*a = *b; //a�� ����Ű�� ���� b�� ����Ű�� ������ �ٲ�
	*b = c;  //b�� ����Ű�� ���� c�� ��(a�� ����Ű�� ��)���� ����
}
int main()
{
	int n = 0, i= 42;
	int* p = &n, * q = &i; //p�� n�� ����Ű�� q�� i�� ����Ų�� 
	*p = 11;
	p = q;
	cout << p << ' ' << q << ' ' << i << n << endl;
	//reset(&i);  //i�� ���������� i�� �ּҴ� �������� �ʴ´�.
	cout << i<<endl;
	swap_1(&i,& n); //i�� n�� ���������� �ּҴ� �������� �ʴ´�.
	cout << i << ' ' << n;
}