#include "D:\c++\Project1\project1\TXLib.h"
#include <iostream>
#include <conio.h>
#include <time.h>

const int widht = 2436;
const int vremyaIgry = 300000;

void upravlenie(int* x, int keyLeft, int keyRight)
{
    if (GetAsyncKeyState(keyLeft)) {
        *x -= 3;
    }
    if (GetAsyncKeyState(keyRight)) {
        *x += 3;
    }
}


int main()
{
    int time1 = 0;
    int x = 200;
    int x0 = 200;
    int y = 200;
    txCreateWindow (500, 596);
    HDC  fon = txLoadImage ("fon.bmp");

    txSetFillColor(TX_WHITE);
    txSelectFont ("Arial", 20, 0, FW_BOLD);
    txSetColor(TX_BLACK);

    txBitBlt (txDC(), 0, 0, widht, 648, fon, 0, 0);
    txTextOut (100, 100, "����� ������ ��� �������� �����");
    int ch1 = getch();
    txSleep(1000);
    txTextOut (100, 200, "� ������ ������");
    int ch2 = getch();

    while (!(GetAsyncKeyState(VK_ESCAPE) ||
             time1 > vremyaIgry)) {
        txSetFillColor(TX_WHITE);
        txSelectFont ("Arial", 40, 0, FW_BOLD);
        txSetColor(TX_BLACK);

        time1 = time1+50;
        upravlenie(&x, ch1, ch2);
        //upravlenie(&x, 'L', 'R');

        if ( x > widht - txGetExtentX()) {
            x = widht - txGetExtentX();
        }
        if ( x < 0) {
            x = 0;
        }
        txBitBlt (txDC(), -x, 0, widht, 648, fon, 0, 0);

        txSetFillColor(TX_RED);
        txCircle(x0, y, 20);

        time_t t;
        struct tm *t_m;
        t=time(NULL);
        t_m=localtime(&t);

        char vremya[100];
        sprintf (vremya, "����� = %d:%d:%d", t_m->tm_hour, t_m->tm_min, t_m->tm_sec);
        txTextOut (100, 100, vremya);

        txSleep(10);
    }

    if (time1 > vremyaIgry) {

        int seconds = time1 % 60;
        int minutes = ROUND(time1 / 60) % 60;
        int hours   = time1 / 3600;
        char gameover[3][100];
        sprintf (gameover[0], "������ ������!");
        sprintf (gameover[1], "��� ����� �����!");
        sprintf (gameover[2], "������ ��� = %d:%d:%d", hours, minutes, seconds);
        txTextOut (100, 200, gameover[0]);
        txTextOut (100, 250, gameover[1]);
        txTextOut (100, 300, gameover[2]);
    }

    txDeleteDC (fon);
    return 0;
}

