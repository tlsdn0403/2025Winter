#include<iostream>
#include<string>

using namespace std;
int main() {
	int a, b, c,x;
	std::cin >> a >> b >> c;
	x = a * b * c;
	std::string s = to_string(x);
	int count[10] = {};
	for (char c : s) {
		count[c - 48]++;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << count[i] << '\n';
	}
	
}