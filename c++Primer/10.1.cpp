#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	string vec = "asdasese";
	int val = 42;
	char c = 's';
	int result = count(vec.cbegin(), vec.cend(),c );
	cout<<result;
	int ia[]= { 12,33,44,41,42 };
	auto r = find(begin(ia), end(ia), val);
}