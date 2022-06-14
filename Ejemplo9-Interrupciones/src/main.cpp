//==================== Inclusiones =====================
#include <Arduino.h>

//==================== Variables =====================
volatile int contador = 0;
int n = contador ;
unsigned long T0=0;

//==================== Prototipos =====================
void InterrupcionPulsador();

//==================== Configuraciones =====================
void setup()
{
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600); 
  attachInterrupt(0, InterrupcionPulsador, FALLING); //habilita la interrupción 0, que están en pin2
} 

//==================== Función principal =====================
void loop()
{
  if (n != contador){
    Serial.println(contador);
    n = contador ;
  }
}

//==================== Funciones =====================
//función ISR para atender la interrupción
void InterrupcionPulsador()
{
    contador++ ;
}

/*
//Alternativa para antirrebote
void InterrupcionPulsador()
{
  if(millis()> (T0+50) )
  {
    contador++;
    T0 = millis();
  }
}
*/
