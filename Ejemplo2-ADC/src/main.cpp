//======= INCLUDES ===============================
#include <Arduino.h>

//======= EXAMPLE SELECTOR =======================
#define EXAMPLE_ADC   0
#define EXAMPLE_TIME  1
#define EXAMPLE_LDR   0
#define EXAMPLE_LM35  0

//======= EXAMPLE ADC ===========================

#if EXAMPLE_ADC

//======= DEFINES ===============================
#define T_ADC     1000    //tiempo entre muestras
#define ADC_PIN   0       //pin del ADC
//======= PROTOTYPES ===========================
float VRead();
//======= GLOBAL VARIABLES =====================
float voltValue;    //valor en voltios del ADC
const float adcMax = 1023; //Valor maximo del ADC segun la resolucion configurada
const float vcc = 5;  //Valor máximo de tensión del ADC
//======= SETUP ================================
void setup() {
  Serial.begin(115200);
}
//======= INFINITE LOOP ========================
void loop()
{ 
  voltValue = VRead();
  Serial.println(voltValue);
  delay(T_ADC);
}
//======= FUNCTIONS ============================
float VRead()
{
  int value;       
  float volt;
  value = analogRead(ADC_PIN);      // lee el valor del potenciómetro
  volt = ( value* vcc)/adcMax;      //la alimentación es de 5 V, el adc es de 10 bits
  return volt;                      // devuelve el valor final
}

#endif

//======= EXAMPLE ADC ===========================

#if EXAMPLE_TIME

//======= DEFINES ===============================
#define ADC_PIN   0       //pin del ADC
#define ONE_SECOND 1000
//======= GLOBAL VARIABLES =====================
uint32_t nSamples;
uint32_t t;

//======= SETUP ================================
void setup() {
  Serial.begin(9600);
}
//======= INFINITE LOOP ========================
void loop()
{
  nSamples = 0;
  t = millis();
  while (millis() <= (t + ONE_SECOND))
  {
    analogRead(ADC_PIN);
    nSamples++;
  }

  Serial.println(nSamples);  //Imprime el número de muestras en 1 segundo
}

#endif
//================= EXAMPLE LDR =======================

#if EXAMPLE_LDR

#define sensor  0 
int umbral=25;
int lectura;
float parcial,luz;

void setup() 
  {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  }
  
void loop() 
  {
  lectura = analogRead(sensor);
  parcial=(90*(1023/lectura)-1);
  luz=pow(parcial,1.428);
  Serial.println(luz);
  if (luz <= umbral) 
    digitalWrite(11, HIGH); 
  else 
    digitalWrite(11,LOW); 
  delay(1000);   //para que no tome muestras continuamente
  }

 #endif

//================= EXAMPLE LM35 =======================

#if EXAMPLE_LM35

 int Sensor = 0 ; 
int umbral = 25 ; 
void setup() 
  { Serial.begin(9600);
  pinMode(11,OUTPUT); } 
void loop() 
{ int lectura = analogRead(Sensor);
 float voltaje = 5.0 /1023 * lectura ; // probar con 5/1024
float temp = voltaje * 100 ; //para el LM35DZ 
Serial.println(temp) ;
 if (temp >= umbral) 
  digitalWrite(11, HIGH) ; 
else 
  digitalWrite(11,LOW); 
delay(1000);   //para que no tome muestras continuamente
}

#endif