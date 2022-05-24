/*Cálculo del interés compuesto */
#include <stdio.h>
#include <math.h>

/* la función main comienza la ejecución del programa */
int main()
{
    double monto; /* monto del depósito */
    double principal = 1000.0; /* monto principal */
    double tasa = .05; /* interés compuesto anual */
    int anio; /* contador de años */

    /* calcula el monto del depósito para cada uno de los diez años */
    for(tasa = .05; tasa < 0.11; tasa += 0.01)
    {
        /* muestra el encabezado de salida de la tabla */
        printf( "%4s %21s %20s\n", "Anio", "Monto del deposito", "Tasa" );
        for ( anio = 1; anio <= 10; anio++ ) {
            /* calcula el nuevo monto para el año especificado */
            monto = principal * pow( 1.0 + tasa, anio );
            /* muestra una línea de la tabla */
            printf( "%4d %21.2f %20.2f\n", anio, monto, tasa );
        } /* fin de for */
    }
    return 0; /* indica terminación exitosa del programa */
} /* fin de la función main */