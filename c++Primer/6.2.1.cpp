#include<iostream>

using namespace std;

int main() {
	int n = 0, i= 42;
	int* p = &n, * q = &i; //p는 n을 가르키고 q는 i를 가르킨다 
	*p = 11;
	p = q;
	cout << p<<' ' << q <<' ' << n << i;
}