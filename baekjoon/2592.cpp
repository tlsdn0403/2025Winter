#include<iostream>
#include<string>

using namespace std;
struct fre {
	int count;
	float num;
};
int main() {
	float num[10];
	fre f[10];
	for (int i = 0; i < 10; i++) {
		cin >> num[i];
	}
	float sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += num[i];
	}
	float frequence;
	int maxCount = 0;
	for (int i = 0; i < 10; i++) {
		f[i].num = num[i];
		f[i].count++;
		for (int j = 0; j < 10; j++) {
			if (f[i].num == num[j]) {
				f[i].count++;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		maxCount = max(maxCount, f[i].count);
	}
	
	float ave = sum / 10;
	cout << ave;
	for (int i = 0; i < 10; i++) {
		if (f[i].count == maxCount) {
			cout << f[i].num;
		}

	}
}