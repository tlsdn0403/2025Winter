#include<iostream>

using namespace std;


//size_t는 C++에서 부호 없는 정수(unsigned integer)로 정의된 데이터 형식입니다. 주로 배열의 크기, 메모리 할당, 인덱스와 같이 음수가 아닌 크기 값을 나타내는 데 사용 
size_t count_calls() { 
	//static 사용해서 변수가 프로그램의 전체 실행 시간 동안 메모리에 유지
	//지역 static 객체는 함수를 마쳐도 소멸하지 않는다
	static size_t ctr = 0; 
	return ++ctr; //ctr++하면 0부터 순차적으로
}
int main() {
	for (size_t i = 0; i < 10; ++i) {
		cout << count_calls() << '\n';
	}
	return 0;
}