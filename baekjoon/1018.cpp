#include<iostream>

using namespace std;
int m, n= 0;
int main(){
	cin >> m >> n;
	char board[50][50];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			board[i][j] = c;
		}
	}
	int wrongCount = 0;
	if (board[0][0] == 'W') {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i % 2 == 0) { //i°¡ Â¦¼ö
					if (j % 2 == 0) {
						if (board[i][j] == 'B') {
							wrongCount++;
						}
					}
					else {
						if (board[i][j] == 'W') {
							wrongCount++;
						}
					}
				}
				else {
					if (j % 2 == 0) {
						if (board[i][j] == 'W') {
							wrongCount++;
						}
					}
					else {
						if (board[i][j] == 'B') {
							wrongCount++;
						}
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i % 2 == 0) { //i°¡ Â¦¼ö
					if (j % 2 == 0) { //Â¦Â¦
						if (board[i][j] == 'W') {
							wrongCount++;
						}
					}
					else { //Â¦ È¦
						if (board[i][j] == 'B') {
							wrongCount++;
						}
					}
				}
				else {
					if (j % 2 == 0) { //È¦Â¦
						if (board[i][j] == 'B') {
							wrongCount++;
						}
					}
					else { //È¦È¦
						if (board[i][j] == 'W') {
							wrongCount++;
						}
					}
				}
			}
		}
	}

	cout << wrongCount;
}