#include<iostream>
#include<vector>
#include<numeric>
#include<iterator>
#include<list>
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
	string sum = accumulate(vi.cbegin(), vi.cend(), "");  const char* 타입에는 + 연산자가 없음으로 string("")으로 해주어야 한다.
	*/ 
	cout << sum << endl;
}
void equalString()
{
	vector<const char*> vs1{ "asd","abc","sinwoo"};
	vector<string> vs2{"asd","abc","sinwoo","hello" };
	if (equal(vs1.cbegin(), vs1.cend(), vs2.cbegin())) {
		cout << "같다" << endl;
	}
	else
		cout << "다르다 " << endl;
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
	*it = 48; //할때마다 추가됨
	vector<int>::iterator v_i = vi.begin();

	cout << &(*v_i) << endl;//요소의 주소를 알고싶으면 역참조를 한다
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
void copy_int_array()
{
	int a1[] = { 0,1,2,3,4,5,6 };
	int a2[sizeof(a1)/sizeof(int)];
	auto ret = copy(begin(a1), end(a1), a2); //ret은 포인터임
	for (auto num = 0; num < sizeof(a2) / sizeof(int); num++) {
		cout << a2[num];
	}
	cout << endl;
	cout << &a2[6] << endl;
	cout << ret; //ret은 복사한 값의 마지막 요소 바로 다음을 가르킨다
}
void practice_10_6_a()
{
	vector<int> vec; list<int>lst; int i;
	while (cin >> i) {
		lst.push_back(i);
	}
	vec.resize(size(lst));
	copy(lst.cbegin(), lst.cend(), vec.begin());
	for (int num : vec) {
		cout << num << " ";
	}
}
void practice_10_6_b()
{
	vector<int> vec;

	vector<int> vec1;
	cout << "vec :" << vec.data() << endl;
	vec.push_back(1);
	cout << "vec pushback:" << vec.data() << endl;
	vec.push_back(1);
	cout << "vec pushback:" << vec.data() << endl;

	cout << "vec1 :" << vec1.data() << endl;
	vec1.reserve(10);
	vec1.push_back(1);
	cout << "vec1 pushback:" << &(vec1[0]) << endl;
	vec1.push_back(1);
	cout << "vec1 pushback:" << vec1.data() << endl;

	/*vec.resize(10);
	fill_n(vec.begin(), 10, 0);
	for (int num : vec) {
		cout << num << " ";
	}*/
}
int main()
{
	practice_10_6_b();
}