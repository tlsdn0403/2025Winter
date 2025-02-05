#include<iostream>
#include<vector>
using namespace std;

int n;
int house[1000][3];
int result = 0;
void DP(int h[1000][3], int num) {
	if (num > n) {

		return;
	}
	if (num == 0) {
		++num;
		DP(h, num);
		return;
	}
	else {
		h[num][0] += min(h[num - 1][1], h[num - 1][2]);
		h[num][1] += min(h[num - 1][2], h[num - 1][3]);
		h[num][2] += min(h[num - 1][0], h[num - 1][1]);
		++num;
		result = min(h[num][0], h[num][1], h[num][2]);
		DP(h, num);
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); //c와 c++ 입출력 동기화 해제
	cin.tie(0); cout.tie(0); //cin과 cout의 묶음을 풀어줌
	cin >> n;
	for (int i = 0; i < n; i++) {
		int red, green, blue;
		cin >> red >> green >> blue;
		house[i][0] = red;
		house[i][1] = green;
		house[i][2] = blue;
	}
	DP(house, n);
	cout << result;
}