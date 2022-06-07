/**************************************************
Ejemplo modificado del archivo demo_tx.c
Trasmite datos al puerto serie y los imprime en pantalla
Compilar con: gcc demo_tx.c rs232.c -Wall -Wextra -o2 -o test_tx
**************************************************/

//================== Inclusiones ==========================
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "rs232.h"

//================== Definiciones ==========================

//================== Programa principal ==========================
int main()
{
  int puertoCOM=2;             //Número de puerto. 6 es para el COM7 en windows
  int baudios=9600;            //Velocidad en baudios
  char modo[]={'8','N','1',0}; // 8 bits de datos, no paridad, 1 bit de parada

  char str[2][512];

  strcpy(str[0], "Hola");
  strcpy(str[1], "Informatica II\n");

  if(RS232_OpenComport(puertoCOM, baudios, modo, 0)) //Prueba abrir el puerto, devuelve 1 en caso de error
  {
    printf("No se puede abrir el puerto COM\n");
    return(0);
  }

  while(TRUE)
  {
    //Envía un string sobre el puerto COM elegido
    RS232_cputs(puertoCOM, str[0]);

    printf("Envíado: %s\n", str[0]);

    Sleep(1000); //Retardo de 1000 ms

    RS232_cputs(puertoCOM, str[1]);
    
    printf("Envíado: %s\n", str[1]);

    Sleep(1000); //Retardo de 1000 ms
  }

  return(0);
}

