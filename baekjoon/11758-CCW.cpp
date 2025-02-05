#include<iostream>
using namespace std;

pair<int, int> position[3];
int CCW(pair<int, int> p0, pair<int, int> p1, pair<int, int> p2) {
	return (p0.first * p1.second) + (p1.first * p2.second) + (p2.first * p0.second)
		- (p0.second * p1.first) - (p1.second * p2.first) - (p2.second * p0.first);
}

int main()
{
	for (int i = 0; i < 3; i++) {
		cin >> position[i].first >> position[i].second;
	}
	int result = CCW(position[0], position[1], position[2]);
	if (result > 0) {
		cout << 1;
	}
	else if (result < 0) {
		cout << -1;
	}
	else {
		cout << 0;
	}
}