#include <Arduino.h>

#define LED       13
#define BUTTON    6
#define T_BUTTON  50

bool estado = 1 ;
bool estado_anterior = 1 ;

void setup()
{ 
  pinMode(BUTTON, INPUT_PULLUP);        //Con resistencia de pullup interna
  pinMode(LED, OUTPUT);
}

void loop()
{
  estado = digitalRead(BUTTON);
  if (estado != estado_anterior)      //hay cambio : Han pulsado o soltado
  {
    if (estado == LOW)            //Al pulsar botón cambiar LED, pero no al soltar
      digitalWrite(LED, !digitalRead(LED));
    estado_anterior = estado ;     // Para recordar el ultimo valor
    delay (T_BUTTON);
  }
}