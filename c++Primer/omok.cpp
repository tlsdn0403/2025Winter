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
        printf("��ǥ�� �Է��Ͻÿ�(x, y)(�»�� 0,0/���ϱ� 18,18) : ");
        scanf_s("%d %d", &x, &y);

        if (count % 2 == 0) {
            gotoxy(x, y);
            printf("��");
            count++;
            gotoxy(6, 21);
            printf("������ ���� : %d", count / 2 + 1);

        }
        else if (count % 2 == 1) {
            gotoxy(x, y);
            printf("��");
            count++;
            gotoxy(6, 22);
            printf("�Ͼᵹ ���� : %d", count / 2);
        }
        else if (x <= 0 || x > 18 || y <= 0 || y > 18) {
            gotoxy(6, 23);
            printf("�ٽ� �Է��Ͻÿ�.");
        }
        continue;
    }

    return 0;
}

void gotoxy(int x, int y) {
    COORD c = { x * 2,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}