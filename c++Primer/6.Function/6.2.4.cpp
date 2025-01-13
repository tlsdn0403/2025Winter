#include<iostream>

using namespace std;
//size�� ��������� �����ϰ� ia��ҿ� ������ �����ϴ� �� ���
void print(const int ia[], size_t size) //const in ia[] �� const int *ia�� ����
{
	for (size_t i = 0; i != size; ++i) {
		cout << ia[i] << endl;
	}
}

void print(const int(&arr)[10])  //��ȣ�� arr�� �ѷ������ �Ѵ� arr�� int�� 10���� �迭�� ���� ������  �ȵѷ� ���ָ� arr�� ������ �迭�� �ȴ�.
{
	for (auto elem : arr) {
		cout << elem << endl;
	}
}
void print_1(const int ia[10]) //const in ia[] �� const int *ia�� ���� �Ű����� const int ia[10]���� �迭 ũ�� 10�� ���� ����ȭ �������� �ۼ��� ���̸�, 
//�����Ϸ��� �̸� �����Ѵ�. �� �Լ��� �迭�� ������ ũ�� 10���� Ȯ���� ����� ����.
{
	for (size_t i = 0; i != 10; ++i) {
		cout << ia[i] << endl;
	}
}
void returnBigValue(int* a) {
	*a += 1;
	cout << a;
}
int main()
{
	int a[10] = { 10,20 };
	int b[3] = { 10,20 };
	int k = 3;
	returnBigValue(&k);
	print(a, 12);
	print(a);
	print_1(b);
	cout << k;
}