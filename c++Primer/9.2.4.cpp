#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	vector<string> v1={ "acd","an","awes" };
	list<string> l1 = { "asdasd","vadsa","asdw"};
	list <string> l2(l1); //l2�� l1�� ���纻
	//�����Ϸ��� ����� Ÿ�԰� �����̳��� Ÿ���� ��ġ�ؾ��Ѵ�

	//��� �ʱ�ȭ
	list<string> autors = { "Milton","shakespeare" };

	//���� ũ�� �����̳� ������
	vector<int> ivec(10, -1);
	list<string> svec(10, "hi");
	vector<int> ivec2(14); //��Ҵ� 10 �� ���� 0���� �ʱ�ȭ

	for (auto i : ivec) {
		cout << i << " ";
	}
	cout << endl;
	for (auto i : ivec2) {
		cout << i << " ";
	}
	cout << endl;
	//swap ����ϱ�
	swap(ivec, ivec2); //��� ��ü�� ��ȯ���� �ʰ� ���� ������ ������ ��ȯ������ ������

	for (auto i : ivec) {
		cout << i << " ";
	}
	cout << endl;
	for (auto i : ivec2) {
		cout << i << " ";
	}
	cout << endl;
}