#include<iostream>

using namespace std;

char board[19][19];

void reset_board(char board[19][19]);
void print_board(char board[19][19]);

int main() {

	reset_board(board);
	int turn = 0;
	int blackCount = 0;
	int whiteCount = 0;
	while (true) {
		int x = 0, y = 0;
		print_board(board);
		cout << ("좌표를 입력하시오(x, y)(좌상귀 0,0/우하귀 18,18) : ") << '\n';
		while (true) {
			cin >> x;
			cin >> y;
			if (x < 19 || y < 19) {
				break;
			}
			else {
				cout << "오목판 안에 두어야 합니다 " << '\n';
			}
		}
		if (board[y][x] == '+') {
			if (turn % 2 == 0) {
				board[y][x] = '0';
				++turn;
				++blackCount;
			}
			else{
				board[y][x] = '1';
				++turn;
				++whiteCount;
			}
		}
		else {
			cout << "이미 돌을 둔 곳입니다" << endl;
		}
		cout << " 흑돌의 개수 :" << blackCount << " , 백돌의 개수 :" << whiteCount << endl;
	}
}

void reset_board(char board[19][19])
{
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			board[i][j] = '+';
		}
	}
}

void print_board(char board[19][19])
{
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
}
