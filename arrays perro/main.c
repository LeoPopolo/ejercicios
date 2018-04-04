#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void bordes();
void pintar();
void ocultar_cursor();
void gotoxy(int x,int y);

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void ocultar_cursor()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}

int main()
{
    ocultar_cursor();

    do
    {
        bordes();
        pintar();

        Sleep(100);
    }
    while(1);


    return 0;
}

void bordes()
{
    for(int i=0; i < 78; i++)
    {
        gotoxy(i, 0);
        printf("%c", 205);
    }
    for(int i=0; i < 20; i++)
    {
        gotoxy(0, i);
        printf("%c", 186);
    }
    for(int i=78; i > 0; i--)
    {
        gotoxy(i, 20);
        printf("%c", 205);
    }
    for(int i=20; i > 0; i--)
    {
        gotoxy(78, i);
        printf("%c", 186);
    }
    gotoxy(0,0);
    printf("%c", 201);
    gotoxy(0,20);
    printf("%c", 200);
    gotoxy(78,0);
    printf("%c", 187);
    gotoxy(78,20);
    printf("%c", 188);

}

void pintar()
{
    int x = 1, y = 1;

    gotoxy(x, y);
    printf("Leo");

    do
    {
        if(kbhit())
        {
            gotoxy(x, y);
            printf("   ");
            char tecla = getch();

            if (tecla == 75 && x>1) x--;
            if (tecla == 80 && y<19) y++;
            if (tecla == 72 && y>1) y--;
            if (tecla == 77 && x<75) x++;

            gotoxy(x, y);
            printf("Leo");
        }
    }
    while(1);
}
