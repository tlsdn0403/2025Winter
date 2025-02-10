#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	vector<string> v1={ "acd","an","awes" };
	list<string> l1 = { "asdasd","vadsa","asdw"};
	list <string> l2(l1); //l2는 l1의 복사본
	//복사하려면 요소의 타입과 컨테이너의 타입이 일치해야한다

	//목록 초기화
	list<string> autors = { "Milton","shakespeare" };

	//순차 크기 컨테이너 생성자
	vector<int> ivec(10, -1);
	list<string> svec(10, "hi");
	vector<int> ivec2(14); //요소는 10 개 각각 0으로 초기화

	for (auto i : ivec) {
		cout << i << " ";
	}
	cout << endl;
	for (auto i : ivec2) {
		cout << i << " ";
	}
	cout << endl;
	//swap 사용하기
	swap(ivec, ivec2); //요소 자체를 교환하지 않고 내부 데이터 구조를 교환함으로 빠르다

	for (auto i : ivec) {
		cout << i << " ";
	}
	cout << endl;
	for (auto i : ivec2) {
		cout << i << " ";
	}
	cout << endl;
}