#include<iostream>

using namespace std;

void reset(int* ip)
{	

	*ip = 0; //ip로 가르키는 객체 값을 변경
	ip = 0;  //ip의 지역 복사본만 변경하며 인자는 변경하지 않는다
}
void swap_1(int* a, int* b) {
	int c = *a; //c는 a가 가르키는 값 
	*a = *b; //a가 가르키는 값을 b가 가르키는 값으로 바꿈
	*b = c;  //b가 가르키는 값을 c의 값(a가 가르키던 값)으로 변경
}
int main()
{
	int n = 0, i= 42;
	int* p = &n, * q = &i; //p는 n을 가르키고 q는 i를 가르킨다 
	*p = 11;
	p = q;
	cout << p << ' ' << q << ' ' << i << n << endl;
	//reset(&i);  //i는 변경하지만 i의 주소는 변경하지 않는다.
	cout << i<<endl;
	swap_1(&i,& n); //i와 n은 변경하지만 주소는 변경하지 않는다.
	cout << i << ' ' << n;
}