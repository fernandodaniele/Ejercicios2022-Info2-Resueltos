#include <Arduino.h>

void setup()
{
  //para display de 7x5
  DDRD= DDRD | B01111111; // puerto D0-D6 como salida. -- Filas
  DDRB= DDRB | B00011111; // puerto B0-B4 como salida. -- Columnas
}
            
byte fila, columna;

void loop()
{
  for (columna = B00000001;columna <= B00010000; columna = columna<<1)
  {
    PORTB=columna; 
    for(fila = B0000001;fila <= B01000000; fila = fila<<1) 
    {
      PORTD=~fila;
      delay(500);
    }
  }
}
