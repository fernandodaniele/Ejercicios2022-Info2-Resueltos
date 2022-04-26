//================= INCLUDES =======================
#include <Arduino.h>

//============ EXAMPLE SELECTOR =======================
#define EXAMPLEA 1
#define EXAMPLEB 0

//================= DEFINES =======================
#define SENSOR  0
#define LED     13

//================= EXAMPLE A =======================
#if EXAMPLEA

void setup() 
{
  pinMode(LED,OUTPUT);    //Configuración de pin
}

void loop()
{
  digitalWrite(LED,1);
  delay(1); //probar con 120  10  1 12 23
  digitalWrite(LED,0);
  delay(23); //probar con 120  230  23 12 1 
}

#endif

//================= EXAMPLE B =======================
#if EXAMPLEB

uint8_t dutyCycle = 127;        //Variable para ciclo de trabajo

void setup() 
{
pinMode(LED,OUTPUT);            //Configuración de pin
analogWrite(LED, dutyCycle);    //Habilita PWM con un duty de aprox 50 %
}

void loop()                     //En loop no hacemos nada, o hacemos otra cosa
  {
  }

#endif