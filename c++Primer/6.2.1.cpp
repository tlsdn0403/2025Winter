#include<iostream>

using namespace std;

int main() {
	int n = 0, i= 42;
	int* p = &n, * q = &i; //p�� n�� ����Ű�� q�� i�� ����Ų�� 
	*p = 11;
	p = q;
	cout << p<<' ' << q <<' ' << n << i;
}