#include<iostream>

using namespace std;

char board[18][18];
void resetBoard(char board[18][18]);
void printBoard(char board[18][18]);
void imformation(int& x, int& y);


int main() {

	resetBoard(board);
	printBoard(board);

	while (true) {
		int x=0, y = 0;
		imformation(x, y);
		cout << x << " ," << y << endl;
	}
}


void resetBoard(char board[18][18])
{
	for (int i = 0; i < 18; ++i) {
		for (int j = 0; j < 18; ++j) {
			board[i][j] = '+';
		}
	}
}
void printBoard(char board[18][18])
{
	for (int i = 0; i < 18; ++i) {
		for (int j = 0; j < 18; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
void imformation(int& x, int& y)
{
	cout << "��ǥ�� �Է��Ͻÿ�(x, y)(�»�� 0,0/���ϱ� 18,18) : " << endl;
	cin >> x;
	cin >> y;
	while (x > 18 || y > 18) {
		cout << "�߸��� �Է��Դϴ�. ��ǥ�� �ٽ� �Է��Ͻÿ�(x, y)(�»�� 0,0/���ϱ� 18,18) : " << endl;
		cin >> x;
		cin >> y;
	}
}