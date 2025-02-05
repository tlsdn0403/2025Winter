#include<iostream>
#include<vector>
using namespace std;

int n;
int house[1000][3];

int main()
{
	ios_base::sync_with_stdio(false); //c�� c++ ����� ����ȭ ����
	cin.tie(0); cout.tie(0); //cin�� cout�� ������ Ǯ����
	cin >> n;
	int result = 0;
	for (int i = 0; i < n; i++) {
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}
	for (int i = 1; i < n; i++) {
		house[i][0] += min(house[i - 1][1], house[i - 1][2]);
		house[i][1] += min(house[i - 1][0], house[i - 1][2]);
		house[i][2] += min(house[i - 1][0], house[i - 1][1]);
	}
	result = min({ house[n - 1][0], house[n - 1][1], house[n - 1][2] });
	cout << result;
}