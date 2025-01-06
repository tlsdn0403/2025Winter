#include<iostream>

using namespace std;

int main() {
	int a, b, c, x;
	cin >> a >> b >> c;
	x = a * b * c;
	int count[10] = {};
	while (x > 0) {
		count[x % 10]++;
		x = x / 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << count[i] << '\n';
	}
}