#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    SYSTEMTIME fecha;

    GetLocalTime(&fecha);

    printf("Fecha: %02d/%02d/%d\n", fecha.wDay, fecha.wMonth, fecha.wYear);
    printf("Hora: %02d:%02d:%02d\n", fecha.wHour, fecha.wMinute, fecha.wSecond);

    return 0;
}
