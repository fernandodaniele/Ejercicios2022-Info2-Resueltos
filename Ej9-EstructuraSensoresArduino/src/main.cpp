#include <Arduino.h>

//creamos la estructura sensores y declaramos la variable ldr
struct sensores
{
    char nombre;  // 1 byte
    int valor;    // 2
    long tiempo;  // 4
}ldr;

//creamos la estructura sensoresb con tipos de datos standar y declaramos la variable temperatura
struct sensoresb
{
    uint32_t tiempo;  //4
    uint16_t valor;   //2
    char nombre;      //1 byte 
}temperatura;

//Configuraciones
void setup() {
  Serial.begin(9600);
}

//Bucle principal
void loop() {
  Serial.print("El tamaño de la estructura es: ");
  int tamanio =sizeof(ldr); 
  Serial.println(tamanio);
  Serial.print("El tamaño de la estructura con tipos de datos estandar es: ");
  tamanio =sizeof(temperatura);
  Serial.println(tamanio);
  while(true); //no hacemos más nada
}