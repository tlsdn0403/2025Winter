#include<iostream>
using namespace std;


//펙토리얼을 만들어주는 함수
int fact(int val) { //fact 함수를 호출 할 때 전달한 변수로 val변수를 초기화
	int ret = 1;//계산결과를 담는 지역변수
	while (val > 1) {
		ret *= val--; //val값을 대입한 후에 1을 뺌 (후위연산자)
	}
	return ret;
}
int main() {
	int k = 3.14; //산술변환이 일어남
	int j = fact(k); //함수를 호출할 때 int 변수 val 생성
	cout<<k << " 의 펙토리얼 j의 값은 : " << j;
	return 0;
}