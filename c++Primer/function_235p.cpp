#include<iostream>
using namespace std;


//펙토리얼을 만들어주는 함수
int fact(int val) {
	int ret = 1;//계산결과를 담는 지역변수
	while (val > 1) {
		ret *= val--; //val값을 대입한 후에 1을 뺌 (후위연산자)
	}
	return ret;
}
int main() {
	int j = fact(5);
	cout << "j는 5의 펙토리얼 j의 값은 : " << j;
	return 0;
}