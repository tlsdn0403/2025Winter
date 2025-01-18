#include<iostream>
#include<vector>

using namespace std;

int n = 0;
int main() {
	cin >> n;
	int num = 10;
	if (n <= 10) {
		cout << n;
		return 0;
	}
	
	int k = 2;
	vector <vector<int>> v(10, vector<int>(10, 0)); //(k,i)
	for (int i = 0; i < 10; i++) {
		v[1][i] = 1;
	}
	while (k < 10) {
		for (int i = k-1; i < 10; i++) {
			v[k][i] = (i + 2 - k) * v[k - 1][i - 1];
			num += v[k][i];
			if (num >= n) {
				cout << num-n << endl;
				cout << i;
				return 0;
			}
		}
		++k;
	}
	
	return 0;
}