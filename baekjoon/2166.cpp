#include<iostream>
using namespace std;

int n;
pair<float, float > position[10000];
int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> position[i].first >> position[i].second;
	}
	for (int i = 0; i < n; i++) {
		cout << position[i].first << ' ' << position[i].second << endl;
	}
}