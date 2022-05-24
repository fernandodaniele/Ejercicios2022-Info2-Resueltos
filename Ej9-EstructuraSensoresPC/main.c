#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
Para caracteres especiales
á –> \xA0; 
é –> \x82; 
í –> \xA1; 
ó –> \xA2; 
ú –> \xA3; 
ñ –> \xA4; 
Ñ –> \xA5;
*/

struct sensores
{
    char nombre;    // 1 byte
    int valor;      // 4 byte
    long tiempo;    // 4 byte
}ldr;

struct sensoresb
{
    uint32_t tiempo;    //4
    uint16_t valor;     //2
    char nombre;        //1
}temperatura;

int main()
{

    printf("El tama\xA4o de la estructura es %d\n",sizeof(ldr));

    printf("El tama\xA4o de la estructura con tipos de datos estandar es %d\n",sizeof(temperatura));

    return 0;
}