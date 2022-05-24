#include <stdio.h>

int main()
{
    //a
    char f [8] = {'a','b','c','d','e','f','g','h'};
    printf("El septimo valor del arreglo f es %c ",f[6]);

    //b
    float b [8];
    b[4] = 5,3;

    //c
    int g[8];
    for(int i = 0; i < 8; i++)
    {
        g[i] = 8;
    } 

    //d
    float c[100];
    int suma = 0;
    for(int i = 0; i< 100; i++)
    {
        suma += c[i];
    }

    //e
    double a[11], b[34];

    for(int i = 0; i< 11; i++)
    {
        b[i] = a[i];
    }

    return 0;
}