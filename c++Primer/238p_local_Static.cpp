#include<iostream>

using namespace std;


//size_t�� C++���� ��ȣ ���� ����(unsigned integer)�� ���ǵ� ������ �����Դϴ�. �ַ� �迭�� ũ��, �޸� �Ҵ�, �ε����� ���� ������ �ƴ� ũ�� ���� ��Ÿ���� �� ��� 
size_t count_calls() { 
	//static ����ؼ� ������ ���α׷��� ��ü ���� �ð� ���� �޸𸮿� ����
	//���� static ��ü�� �Լ��� ���ĵ� �Ҹ����� �ʴ´�
	static size_t ctr = 0; 
	return ++ctr; //ctr++�ϸ� 0���� ����������
}
int main() {
	for (size_t i = 0; i < 10; ++i) {
		cout << count_calls() << '\n';
	}
	return 0;
}