#include<iostream>

using namespace std;
char chess[51][51];
char white_board[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};
char black_board[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};
int m, n= 0;
class Board
{
public:
	char bigBoard[51][51];
	int wrongCount = 0;
	void sperateBoard() {
		int minCount = 64;
		for (int i = 0; i <= m - 8; i++) {
			for (int j = 0; j <= n - 8; j++) {
				minCount = min(countBoard(i, j), minCount);
			}
		}
		cout << minCount;
	}
private:
	int startWhite(int x, int y) {
		int whiteCount = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j<8; j++) {
				if (bigBoard[i+x][j+y] != white_board[i][j]) {
					whiteCount++;
				}
			}
		}
		return whiteCount;
	}
	int startBlack(int x, int y) {
		int blackCount = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (bigBoard[i+x][j+y] != black_board[i][j]) {
					blackCount++;
				}
			}
		}
		return blackCount;
	}
	int countBoard(int x, int y) {
		int whiteCount, blackCount = 64;
		int count = 0;
		whiteCount = startWhite(x,y);
		blackCount = startBlack(x,y);
		count = min(whiteCount, blackCount);
		return count;
	}
	
		
	
};
int main(){
	cin >> m >> n;
	Board board;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			board.bigBoard[i][j] = c;
		}
	}
	board.sperateBoard();
	
}