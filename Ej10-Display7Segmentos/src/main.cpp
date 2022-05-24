#include <Arduino.h>

#define T_ENCENDIDO 1000

void setup()
{
  DDRD= DDRD | B11111111; // puerto D0-D como salida. 
}

byte ledEncendido;
int i=0;

void loop()
{
  for (ledEncendido = B00000001; ledEncendido <= B10000000; ledEncendido = ledEncendido<<1)
  { 
    PORTD=ledEncendido;
    delay(T_ENCENDIDO);
  }
}
