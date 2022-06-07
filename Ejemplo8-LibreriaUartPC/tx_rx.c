/**************************************************
Ejemplo que une demo_rx y demo_tx
Compilar con: gcc tx_rx.c rs232.c -Wall -Wextra -o2 -o tx_rx
**************************************************/

//================== Inclusiones ==========================
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "rs232.h"

//================== Definiciones ==========================
#define LONG_BUFFER 4096

//================== Programa principal ==========================
int main()
{
  //---------------- Configuraciones ------------------------
  int puertoCOM=2;             //Número de puerto. 6 es para el COM7 en windows
  int baudios=9600;            //Velocidad en baudios
  char modo[]={'8','N','1',0}; // 8 bits de datos, no paridad, 1 bit de parada

  unsigned char bufferRecepcion[LONG_BUFFER];
  int cantidadBytes;

  char str[512];
  strcpy(str, "Hola Informatica II\n");

  if(RS232_OpenComport(puertoCOM, baudios, modo, 0)) //Prueba abrir el puerto, devuelve 1 en caso de error
  {
    printf("No se puede abrir el puerto COM\n");
    return(0);
  }

  //---------------- Bucle infinito ------------------------
  while(TRUE)
  {
    //Envía un string sobre el puerto COM elegido
    RS232_cputs(puertoCOM, str);
    printf("Envíado: %s\n", str);

    Sleep(100); //Retardo de 100 ms
    //Lee los datos almacenados en el buffer del puerto COM y los guarda en bufferRecepcion
    //Devuelve la cantidad de bytes leídos
    cantidadBytes = RS232_PollComport(puertoCOM, bufferRecepcion, LONG_BUFFER-1);

    if(cantidadBytes > 0)
    {
      bufferRecepcion[cantidadBytes] = 0;   // Poner un NULL al final del string

      printf("Se recibieron %i bytes: %s\n", cantidadBytes, (char *)bufferRecepcion);
    }

    Sleep(1000); //Retardo de 1000 ms
  }

  return(0);
}