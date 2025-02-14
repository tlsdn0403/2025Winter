#include<iostream>

using namespace std;

void swap(int& a, int& b) {
	if (a == b) {
		return; //답이 같으면 스왑 할 필요가 없다
	}
	int c = a;
	a = b;
	b = c;
	//명시적으로 반환하지 않아도 된다
}

int main() {
	int c = 4;
	int d = 8;
	swap(c, d);
	cout << c << " " << d;
}