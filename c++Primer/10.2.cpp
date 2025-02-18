#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
void accumlateInt() {
	vector<int> vi = { 123,23,411,421,53,235,1234 };
	int sum = accumulate(vi.cbegin(), vi.cend(), 0);
	cout << sum << endl;
}
void accumlateDouble() {
	vector<double> vi = { 123,23,411,421,53,235,1234 };
	double sum = accumulate(vi.cbegin(), vi.cend(), 0);
	cout << sum << endl;
}
void accumlateString() {
	vector<string> vi = { "asd", "bsd" , "sinwoo" };
	string sum = accumulate(vi.cbegin(), vi.cend(), string(""));
	/*
	string sum = accumulate(vi.cbegin(), vi.cend(), "");  const char* 타입에는 + 연산자가 없음으로 string("")으로 해주어야 한다.
	*/ 
	cout << sum << endl;
}
void equalString() {
	vector<const char*> vs1{ "asd","abc","sinwoo"};
	vector<string> vs2{"asd","abc","sinwoo","hello" };
	if (equal(vs1.cbegin(), vs1.cend(), vs2.cbegin())) {
		cout << "같다" << endl;
	}
	else
		cout << "다르다 " << endl;
}
void fill_int() {
	vector<int> vi;
	vi.resize(10);
	fill(vi.begin(), vi.begin()+ vi.size()/2, 10);
	for (auto num : vi) {
		cout << num << " ";
	}
	cout << endl;
}
void fill_n_int() {
	vector<int> vi;
	vi.resize(10);
	fill_n(vi.begin(),8, 10);
	for (auto num : vi) {
		cout << num << " ";
	}
	cout << endl;
}
int main() {
	fill_n_int();
}