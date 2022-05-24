/*//Programa simple que cumple con lo pedido
#include <Arduino.h>

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
}

int sentido = 0;

void loop()
{
  if (digitalRead(5) == LOW)
  {
    sentido = 0;
  }
  else if (digitalRead(6) == LOW)
  {
    sentido = 1;
  }

  if (sentido == 0)
  {
    digitalWrite(2,HIGH);
    delay(500);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    delay(500);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    delay(500);
    digitalWrite(4,LOW);
  }	
  else
  {
    digitalWrite(4,HIGH);
    delay(500);
    digitalWrite(4,LOW);
    digitalWrite(3,HIGH);
    delay(500);
    digitalWrite(3,LOW);
    digitalWrite(2,HIGH);
    delay(500);
    digitalWrite(2,LOW);
  }
}
*/

//Version con mejoras para satisfacer las preguntas planteadas y buenas prácticas de programación
#include <Arduino.h>
#define N_LED 		3   //Cantidad de leds
#define N_PULSADOR 	2 //Cantidad de pulsadores
#define T_ON		500   //tiempo aprox de encendido de cada LED
#define ASCENDENTE 0  //Sentido de la secuencia de encendido leds LED1-LED2-LED3
#define DESCENDENTE 1 //Sentido de la secuencia de encendido leds LED3-LED2-LED1

int led [N_LED] = {2, 3, 4};          //Arreglo con los pines donde estarán conectados los leds
int pulsador [N_PULSADOR] = {5, 6};   //Arreglo con los pines donde estarán conectados los pulsadores
int estado = 0, sentido = 0;

void setup() 
{
  //Configuración de los pines de salida
	for(int i = 0; i < N_LED; i++){
		pinMode(led[i], OUTPUT);
	}
	//Configuración de los pines de entrada
	for(int i = 0; i < N_PULSADOR; i++){
		pinMode(pulsador[i], INPUT_PULLUP);
	}
}

void loop() 
{
  //Si se presiona alguno de los pulsadores se asigna el sentido correspondiente
  if (digitalRead(pulsador[0]) == LOW)
  {
    sentido = ASCENDENTE;
  }
  else if (digitalRead(pulsador[1]) == LOW)
  {
    sentido = DESCENDENTE;
  }	

  //Segun el sentido se incrementa o decrementa la variable i
  if (sentido == ASCENDENTE)
  {
    digitalWrite(led[estado], LOW); //Apaga el led actualmente encendio
    estado++;                     //Cambia de estado
    if ( estado >= N_LED ){       //Si llegó al último led...
      estado = 0;                 //...vuelve a comenzar
    }
    digitalWrite(led[estado], HIGH); //Enciende el led correspondiente
  }
    else 
  {
    digitalWrite(led[estado], LOW); //Apaga el led actualmente encendido
    estado--;                     //Cambia de estado
    if ( estado < 0 ){            //Si llegó al primer led...
      estado = (N_LED-1);             //...vuelve al último
    }
    digitalWrite(led[estado], HIGH); //Enciende el led correspondiente
  }
  delay(T_ON);	//Retardo para que el led permanezca encendido. A este tiempo se le suma lo que tarda la ejecución de un ciclo del loop
}