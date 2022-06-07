//=================== Inclusiones ======================
#include <Arduino.h>

//================= Configuraciones ====================
void setup()
{
  Serial.begin(115200); //Configuración del puerto serie
}

//============ Declaraciones de variables ==============
String datosRecibidos;  //Cadena de caracteres para almacenar los datos recibidos

//================= Bucle principal ====================
void loop()
{
  if (Serial.available()>0)
  {
     datosRecibidos = Serial.readString();  //Lectura de datos  
     Serial.println(datosRecibidos);        //Envío de datos
  }
}


/* //======================================================
//  Ejemplo envío de datos simple
//======================================================
//=================== Inclusiones ======================
#include <Arduino.h>

//================= Configuraciones ====================
void setup()
{
  Serial.begin(115200); //Configuración del puerto serie
}

//============ Declaraciones de variables ==============
uint16_t anio = 2021;  //Cadena de caracteres para almacenar los datos recibidos

//================= Bucle principal ====================
void loop()
{
  Serial.print("Informática II ");  //Envío de datos sin salto de linea  
  Serial.println(anio);             //Envío de datos con salto de linea
}
 */