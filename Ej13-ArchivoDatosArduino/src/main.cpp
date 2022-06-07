#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

/*
Conexiones con Arduino UNO
--SCK  PIN 13
--MISO PIN 12
--MOSI PIN 11
--CS   Ver variable chipSelect
--5 V
--GND
*/

const int chipSelect = 4;
File archivo;

struct EDatos{
  char nombre;
  int16_t sensor;
  int32_t tiempo;
};

void setup()
{
  Serial.begin(9600);
  Serial.print("Iniciando tarjeta SD...");
  if (!SD.begin(chipSelect))
  {
    Serial.println("Error con la tarjeta SD");
    while (1);
  }
  Serial.println("Tarjeta iniciada");
}

struct EDatos info;
unsigned long T;

void loop()
{
  info.nombre = 'A';
  info.sensor = 25000;
  info.tiempo = 15000000;
  //Modo lento
  archivo = SD.open("ejemplo.txt", FILE_WRITE);
  if (archivo)
  {
    Serial.print("Escribiendo...");
    T = millis();
    for(int i=0;i<1000;i++)
    {
      archivo.print(info.nombre);
      archivo.print(info.sensor); //de esta forma es 8 veces más lento
      archivo.print(info.tiempo);
    }
    T = millis()- T;  
    delay(1000);
    archivo.close();
    Serial.print("listo. \n El tiempo medido es: "); //Alrededor de 730
    Serial.println(T);
  } 
  else
  {
    Serial.println("error abriendo el archivo");
  }

  //Modo rápido
  archivo = SD.open("archivo.dat", FILE_WRITE);
  if (archivo)
  {
    Serial.print("Escribiendo...");
    T = millis();
    for(int i=0;i<1000;i++)
    {
      archivo.write((const uint8_t *)&info, sizeof(info));
    }
    T = millis()- T;  
    delay(1000);
    archivo.close();
    Serial.print("listo. \n El tiempo medido es: "); //Alrededor de 90
    Serial.println(T);
  } 
  else
  {
    Serial.println("error abriendo el archivo");
  }

  //Finalizar el programa
  if(Serial.available()) //para finalizar el programa si se presiona f
  {
    if(Serial.read()=='f')
    {
      Serial.println("Programa finalizado, reinicie para volver a ejectuar");
      Serial.flush();
      exit(0);  
    }
  }
}
