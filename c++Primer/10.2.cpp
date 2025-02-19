#include<iostream>
#include<vector>
#include<numeric>
#include<iterator>
using namespace std;
void accumlateInt()
{
	vector<int> vi = { 123,23,411,421,53,235,1234 };
	int sum = accumulate(vi.cbegin(), vi.cend(), 0);
	cout << sum << endl;
}
void accumlateDouble()
{
	vector<double> vi = { 123,23,411,421,53,235,1234 };
	double sum = accumulate(vi.cbegin(), vi.cend(), 0.0);
	cout << sum << endl;
}
void accumlateString()
{
	vector<string> vi = { "asd", "bsd" , "sinwoo" };
	string sum = accumulate(vi.cbegin(), vi.cend(), string(""));
	/*
	string sum = accumulate(vi.cbegin(), vi.cend(), "");  const char* Ÿ�Կ��� + �����ڰ� �������� string("")���� ���־�� �Ѵ�.
	*/ 
	cout << sum << endl;
}
void equalString()
{
	vector<const char*> vs1{ "asd","abc","sinwoo"};
	vector<string> vs2{"asd","abc","sinwoo","hello" };
	if (equal(vs1.cbegin(), vs1.cend(), vs2.cbegin())) {
		cout << "����" << endl;
	}
	else
		cout << "�ٸ��� " << endl;
}
void fill_int()
{
	vector<int> vi;
	vi.resize(10);
	fill(vi.begin(), vi.begin()+ vi.size()/2, 10);
	for (auto num : vi) {
		cout << num << " ";
	}
	cout << endl;
}
void fill_n_int()
{
	vector<int> vi;
	vi.resize(10);
	fill_n(vi.begin(),10, 10);
	for (auto num : vi) {
		cout << num << " ";
	}
	cout << endl;
}
void back_insert()
{
	vector<int> vi = { 12,33,44 };
	auto it = back_inserter(vi);
	cout << vi.data() << endl;
	*it = 23;
	*it = 48; //�Ҷ����� �߰���
	vector<int>::iterator v_i = vi.begin();

	cout << &(*v_i) << endl;//����� �ּҸ� �˰������ �������� �Ѵ�
	for (auto num : vi) {
		cout << num << " ";
	}
	cout << endl;
}
void copy_int()
{
	int ai[] = { 1,2,3,4,5,6,7,8 };
	int a2[sizeof(ai)/sizeof(*ai)];
	auto ret= copy(begin(ai), end(ai), a2);
	
	cout << ret;
}
int main() {
	copy_int();
}