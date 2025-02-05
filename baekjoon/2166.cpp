#include<iostream>
using namespace std;

int n;
pair<long long, long long > position[10000];
long long CCW(pair<long long, long long> p0, pair<long long, long long> p1, pair<long long, long long> p2) {
	return (p0.first * p1.second) + (p1.first * p2.second) + (p2.first * p0.second)
		- (p0.second * p1.first) - (p1.second * p2.first) - (p2.second * p0.first);
}
int main()
{
	ios_base::sync_with_stdio(false); //c�� c++ ����� ����ȭ ����
	cin.tie(0); cout.tie(0); //cin�� cout�� ������ Ǯ����
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> position[i].first >> position[i].second;
	}
	long long result = 0;
	for (int i = 1; i < n-1; i++) {
		result += CCW(position[0], position[i], position[i + 1]);
	}
	result /= 2;
	cout << fixed; //����������
	cout.precision(1); // �Ҽ��� 1�ڸ� ����
	cout << abs(result);
}