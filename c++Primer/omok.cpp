#include<stdio.h>
#include<Windows.h>

void gotoxy(int x, int y);

int main(void) {
    char key = 0;
    int i, j, x, y, count = 0;
    for (i = 1; i <= 18; i++) {
        for (j = 1; j <= 18; j++) {
            gotoxy(i, j);
            printf(" +");
        }
    }


    while (true) {
        gotoxy(5, 20);
        printf("좌표를 입력하시오(x, y)(좌상귀 0,0/우하귀 18,18) : ");
        scanf_s("%d %d", &x, &y);

        if (count % 2 == 0) {
            gotoxy(x, y);
            printf("●");
            count++;
            gotoxy(6, 21);
            printf("검은돌 개수 : %d", count / 2 + 1);

        }
        else if (count % 2 == 1) {
            gotoxy(x, y);
            printf("○");
            count++;
            gotoxy(6, 22);
            printf("하얀돌 개수 : %d", count / 2);
        }
        else if (x <= 0 || x > 18 || y <= 0 || y > 18) {
            gotoxy(6, 23);
            printf("다시 입력하시오.");
        }
        continue;
    }

    return 0;
}

void gotoxy(int x, int y) {
    COORD c = { x * 2,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}