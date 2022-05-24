#include <Arduino.h>
/*
//Ejemplo simple ADC:
int lectura = 0; //variable para almacenar el valor del ADC

void setup() 
{
  Serial.begin(9600); //Configura la UART para enviar datos a la PC
} 

void loop() 
{
  lectura = analogRead(0);  //lee el valor del sensor
  Serial.println(lectura) ; //enviamos el valor al monitor serial
  delay(1000);   //para que no tome muestras continuamente
}
*/

/***********************************************************************************************************/

//Tiempo de muestreo
/*
void setup() 
{
  Serial.begin(9600); //Configura la UART para enviar datos a la PC
} 

unsigned long T;
int n;

void loop() 
{
  n = 0;
  T = millis();
  while (millis() <= (T + 1000) )
  {
    analogRead(0);  //lee el valor del sensor
    n++; //contamos cada vez que se realiza un lectura
  }
  Serial.println(n) ; //enviamos el valor al monitor serial
}*/

/***********************************************************************************************************/

/*
//Ejemplo ADC: sensor de temperatura + Umbral
#define SENSOR  0   //pin de entrada para el sensor
#define LED     13  //pin de salida para el led
#define UMBRAL  25  //umbral en el cual se activa/desactiva el led
#define T_MUESTREO 1000  //tiempo para que no tome muestras continuamente

int lectura = 0; //variable para almacenar el valor del ADC
float voltaje = 0;
float temp = 0;

void setup() 
{
  Serial.begin(9600); //Configura la UART para enviar datos a la PC
  pinMode(LED,OUTPUT); //Configura la salida del LED de umbral
} 

void loop() 
{
  lectura = analogRead(SENSOR);  //lee el valor del sensor
  voltaje = 5.0 /1023 * lectura ; // ¿porque con 5.0/1023?
  temp = voltaje * 100 ; //para el LM35DZ 
  Serial.println(temp) ; //enviamos el valor al monitor serial
  if (temp >= UMBRAL){      //si supera el umbral enciende el led, sino se apaga
    digitalWrite(LED, HIGH);
  }   
  else{
    digitalWrite(LED,LOW); 
  } 
  delay(T_MUESTREO);   //para que no tome muestras continuamente
}
*/

/***********************************************************************************************************/

/*
//PWM sin usar PWM
#define PIN  13

void setup() 
  {
  pinMode(PIN,OUTPUT);
  }

void loop()
  {
  digitalWrite(PIN,1);
  delay(23); //probar con 120  10  1 12 23
  digitalWrite(PIN,0);
  delay(1); //probar con 120  230  23 12 1 

  ///
  }
  */

/***********************************************************************************************************/

/*
//PWM simple
#define SENSOR  0   //pin de entrada para el sensor
#define LED     5  //pin de salida para el led

void setup()                                           
{  
  pinMode(LED,OUTPUT);
  analogWrite(LED,25);   //Configura el PWM con un duty del 50%
}

void loop()
{
  //nada
}
*/

/***********************************************************************************************************/

// PWM + ADC. Ejemplo: modifica brillo de un led
#define SENSOR  0   //pin de entrada para el sensor
#define LED     13  //pin de salida para el led
#define T_MUESTREO 20  //tiempo para que no tome muestras continuamente

float conversion = 0;
int lectura = 0;

void setup()                                           
{  
  pinMode(LED,OUTPUT);  
}

void loop()
{
  lectura = analogRead(SENSOR); //lee el pin analógico
  conversion = (lectura*255)/1023; //Para adecuar la resolución de 10 bits del ADC a la de 8 bits del PWM
  analogWrite(LED,conversion);   //Configura el PWM con el valor de la lectura
  delay(T_MUESTREO);
}