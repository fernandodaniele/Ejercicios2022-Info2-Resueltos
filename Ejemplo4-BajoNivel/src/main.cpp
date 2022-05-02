/*
  Este programa es un encendido de diferentes secuencias de leds
  El objetivo es comparar la misma secuencia con funciones de Arduino
  y con manejo directo de puertos para ver la diferencia de tiempo
*/
//======= INCLUDES ===============================
#include <Arduino.h>
#include "stdint.h"

//======= GLOBAL VARIABLES =====================
uint32_t T0,TF;

//======= SETUP ================================
void setup()
{
  Serial.begin(9600); // Configuración de UART

  /* //Opción con funciones de Arduino
  for(int i=2;i<8;i++)
  {
    pinMode(i,OUTPUT);
  }
  */

  DDRD = DDRD | B11111100; // Utilizamos seis bits del puerto D (2 a 7) 
  //No usamos los pines 0 y 1 del Arduino para no interferir con el puerto serie. 
}

//======= INFINITE LOOP ========================
void loop()
{
  //Sección con funciones de Arduino
  T0=micros();    //cuenta el tiempo en microsegundos desde que se encendió Arduino. Similar a millis ()
  for(uint8_t i=2;i<8;i++){
      digitalWrite(i,1);
    }
  for(uint8_t i=2;i<8;i=i+2){
      digitalWrite(i,0);
    }
    for(uint8_t i=2;i<8;i=i+2){
      digitalWrite(i,1);
    }
    for(uint8_t i=3;i<8;i=i+2){
      digitalWrite(i,0);
    }
  for(uint8_t i=2;i<8;i=i+2){
      digitalWrite(i,0);
    }
  TF = micros()-T0;  //Calculo el tiempo que pasó desde que se tomó la muestra T0 hasta ahora
  Serial.print("El tiempo total en microsegundos con funciones Arduino es de: ");
  Serial.println(TF);  //alrededor de 76 us para Arduino Uno
  
  //Sección con manejo directo de puertos
  T0 = micros();
  PORTD= B11111100;
  PORTD= B10101000;
  PORTD= B01010100;
  PORTD= B00000000;
  TF = micros()-T0;   //alrededor de 4 us para Arduino Uno
  Serial.print("El tiempo total en microsegundos con manejo directo de puertos es de: ");
  Serial.println(TF);
}