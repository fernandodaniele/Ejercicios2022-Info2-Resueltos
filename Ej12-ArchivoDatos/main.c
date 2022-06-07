#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdint.h>

struct EDatos{
  char nombre;
  int16_t sensor;
  uint32_t tiempo;
}info,infoLetura;
  
FILE *fpt;
int a=0;

int main()
{
    //Ingreso de datos
    printf("Ingrese la inicial del sensor:\n");
	scanf(" %c", &info.nombre);
	printf("Ingrese el valor del sensor:\n");
	scanf(" %d", &info.sensor);
	printf("Ingrese el tiempo:\n");
	scanf(" %ld", &info.tiempo);

    //Apertura de archivo como escritura
    if((fpt=fopen("ARCHIVO.DAT","w"))==NULL)
    {
        printf("\nERROR - No se puede abrir archivo especificado\n");
    }
    else
    {
        fwrite(&info, sizeof(struct EDatos) , 1, fpt);
        fclose(fpt);
    }
	
    //Apertura de archivo como lectura
    if((fpt=fopen("ARCHIVO.DAT","r"))==NULL)
    {
        printf("\nERROR - No se puede abrir archivo especificado\n");
    }
    else
    {
        a = sizeof(infoLetura);
        printf("Tamaño de la estructura: %d \n",a);

        while ( !feof( fpt ) ){
        fread((uint8_t*)&infoLetura,a,1,fpt);
        printf("Nombre %c\n",infoLetura.nombre);
        printf("Medicion %d\n",infoLetura.sensor);
        printf("Tiempo %lu\n",infoLetura.tiempo);
        }
        fclose(fpt);
    }

    return(0);
}