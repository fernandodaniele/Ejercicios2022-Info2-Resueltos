#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
// Tipo de datos para la variable de estados
typedef enum{
    PANTALLA_INICIAL,
    PANTALLA_1,
    PANTALLA_2,
    PANTALLA_3,
	PANTALLA_4,
	PANTALLA_5,
	PANTALLA_6
} pantalla_t;

// Variable de estado (global)
pantalla_t pantallaActual;

uint8_t opcion = 0;

// Prototipos de funciones
void IniciarMenu(void );
void ActualizarMenu(void);

void mostrarPantallaInicial (void);
void mostrarPantalla1 (void);
void mostrarPantalla2 (void);
void mostrarPantalla3 (void);
void mostrarPantalla4 (void);
void mostrarPantalla5 (void);
void mostrarPantalla6 (void);

// Programa principal
int main (void){
	
	IniciarMenu();
	
	while(1){
		
		ActualizarMenu();
		
	}
	return 0;
}

// Función Inicializar MEF
void IniciarMenu(void){
	 pantallaActual = PANTALLA_INICIAL;
    // Resto de la inicializacion
}

// Función Actualizar MEF
void ActualizarMenu(void)
{
	switch (pantallaActual) {
		case PANTALLA_INICIAL:
        {
            // Actualizar salida del estado
			mostrarPantallaInicial();
    		// Chequear condiciones de transición de estado
			scanf("%d",&opcion);
			switch(opcion){
				case 1:
				{
					pantallaActual = PANTALLA_1;
				}
				break;
				case 2:
				{
					pantallaActual = PANTALLA_2;
				}
				break;
				case 0:
				{
					pantallaActual = PANTALLA_INICIAL;
					exit(0);
				}
				break;
				default:
				break;
			}
		}
		break;
		case PANTALLA_1:{
			mostrarPantalla1();
    		// Chequear condiciones de transición de estado
			scanf("%d",&opcion);
			switch(opcion){
				case 1:
				{
					pantallaActual = PANTALLA_3;
				}
				break;
				case 2:
				{
					pantallaActual = PANTALLA_4;
				}
				break;
				case 0:
				{
					pantallaActual = PANTALLA_INICIAL;
				}
				break;
				default:
				break;
			}
		}
		break;
		case PANTALLA_2:{
			mostrarPantalla2();
    		// Chequear condiciones de transición de estado
			scanf("%d",&opcion);
			switch(opcion){
				case 1:
				{
					pantallaActual = PANTALLA_5;
				}
				break;
				case 2:
				{
					pantallaActual = PANTALLA_6;
				}
				break;
				case 0:
				{
					pantallaActual = PANTALLA_INICIAL;
				}
				break;
				default:
				break;
			}
		}
		break;
		case PANTALLA_3:{
			mostrarPantalla3();
    		// Chequear condiciones de transición de estado
			scanf("%d",&opcion);
			switch(opcion){
				case 0:
				{
					pantallaActual = PANTALLA_1;
				}
				break;
				default:
				break;
			}
		}
		break;
		case PANTALLA_4:{
			mostrarPantalla4();
    		// Chequear condiciones de transición de estado
			scanf("%d",&opcion);
			switch(opcion){
				case 0:
				{
					pantallaActual = PANTALLA_1;
				}
				break;
				default:
				break;
			}
		}
		break;
		case PANTALLA_5:{
			mostrarPantalla5();
    		// Chequear condiciones de transición de estado
			scanf("%d",&opcion);
			switch(opcion){
				case 0:
				{
					pantallaActual = PANTALLA_2;
				}
				break;
				default:
				break;
			}
		}
		break;
		case PANTALLA_6:{
			mostrarPantalla6();
    		// Chequear condiciones de transición de estado
			scanf("%d",&opcion);
			switch(opcion){
				case 0:
				{
					pantallaActual = PANTALLA_2;
				}
				break;
				default:
				break;
			}
		}
		break;
		default:{
			//Si cae en un estado no valido, reinicio
			IniciarMenu();
		}
		break;
	}	
}

void mostrarPantallaInicial (void)
{
	printf("Esta es la pantalla inicial\n");
	printf("Ingrese 1 para ir a PANTALLA_1\n");
	printf("Ingrese 2 para ir a PANTALLA_2\n");
	printf("Ingrese 0 para salir del programa\n");
}
void mostrarPantalla1 (void)
{
	printf("Esta es la pantalla 1\n");
	printf("Ingrese 1 para ir a PANTALLA_3\n");
	printf("Ingrese 2 para ir a PANTALLA_4\n");
	printf("Ingrese 0 para volver a PANTALLA_INICIAL\n");
}
void mostrarPantalla2 (void)
{
	printf("Esta es la pantalla 2\n");
	printf("Ingrese 1 para ir a PANTALLA_5\n");
	printf("Ingrese 2 para ir a PANTALLA_6\n");
	printf("Ingrese 0 para volver a PANTALLA_INICIAL\n");
}
void mostrarPantalla3 (void)
{
	printf("Esta es la pantalla 3\n");
	printf("Ingrese 0 para volver a PANTALLA_1\n");
}
void mostrarPantalla4 (void)
{
	printf("Esta es la pantalla 4\n");
	printf("Ingrese 0 para volver a PANTALLA_1\n");
}
void mostrarPantalla5 (void)
{
	printf("Esta es la pantalla 5\n");
	printf("Ingrese 0 para volver a PANTALLA_2\n");
}
void mostrarPantalla6 (void)
{
	printf("Esta es la pantalla 6\n");
	printf("Ingrese 0 para volver a PANTALLA_2\n");
}