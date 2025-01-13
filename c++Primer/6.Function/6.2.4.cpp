#include<iostream>

using namespace std;
//size를 명시적으로 전달하고 ia요소에 접근을 제어하는 데 사용
void print(const int ia[], size_t size) //const in ia[] 는 const int *ia와 같다
{
	for (size_t i = 0; i != size; ++i) {
		cout << ia[i] << endl;
	}
}

void print(const int(&arr)[10])  //괼호로 arr를 둘러싸줘야 한다 arr은 int가 10개인 배열에 대한 참조자  안둘러 싸주면 arr은 참조자 배열로 안다.
{
	for (auto elem : arr) {
		cout << elem << endl;
	}
}
void print_1(const int ia[10]) //const in ia[] 는 const int *ia와 같다 매개변수 const int ia[10]에서 배열 크기 10은 단지 문서화 목적으로 작성된 것이며, 
//컴파일러는 이를 무시한다. 즉 함수는 배열이 실제로 크기 10인지 확인할 방법이 없다.
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