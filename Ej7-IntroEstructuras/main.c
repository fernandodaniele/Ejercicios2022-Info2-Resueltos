#include <stdio.h>

int main ()
{
    struct cliente {
        char apellido[ 15 ];
        char nombre[ 15 ];
        int numeroCliente;
        struct {
            char numeroTelefonico[ 11 ];
            char direccion[ 50 ];
            char ciudad[ 15 ];
            char estado[ 3 ];
            char codigoPostal[ 6 ];
        } personal;
    } registroCliente, *ptrCliente;
    
    ptrCliente = &registroCliente;

    //a
    printf("a-Ingrese su apellido \n");
    scanf("%s",registroCliente.apellido);
    printf("Su apellido es: %s\n",registroCliente.apellido);
    //b
    printf("b-Ingrese su apellido \n");
    scanf("%s",ptrCliente->apellido);
    printf("Su apellido es: %s\n",ptrCliente->apellido);
    printf("Su apellido es: %s\n",registroCliente.apellido);
    //c
    printf("c-Ingrese su nombre \n");
    scanf("%s",registroCliente.nombre);
    printf("Su nombre es: %s\n",registroCliente.nombre);
    //d
    printf("d-Ingrese su nombre \n");
    scanf("%s",ptrCliente->nombre);
    printf("Su nombre es: %s\n",ptrCliente->nombre);
    //e
    printf("e-Ingrese su numero \n");
    scanf("%d",&registroCliente.numeroCliente); //atencion!!
    printf("Su numero es: %d\n",registroCliente.numeroCliente); 
    //f
    printf("f-Ingrese su numero \n");
    scanf("%d",&ptrCliente->numeroCliente); //atencion!!
    printf("Su numero es: %d\n",ptrCliente->numeroCliente);
    //g
    printf("g-Ingrese su numero telefonico\n");
    scanf("%s",registroCliente.personal.numeroTelefonico);
    printf("Su numero telefonico es: %s\n",registroCliente.personal.numeroTelefonico);
    //h
    printf("h-Ingrese su numero telefonico\n");
    scanf("%s",ptrCliente->personal.numeroTelefonico);
    printf("Su numero telefonico es: %s\n",ptrCliente->personal.numeroTelefonico);
    //i
    printf("i-Ingrese su direccion\n");
    scanf("%s",registroCliente.personal.direccion);
    printf("Su direccion es: %s\n",registroCliente.personal.direccion);
    //j
    printf("j-Ingrese su direccion\n");
    scanf("%s",ptrCliente->personal.direccion);
    printf("Su direccion es: %s\n",ptrCliente->personal.direccion);
    //k
    printf("k-Ingrese su ciudad\n");
    scanf("%s",registroCliente.personal.ciudad);
    printf("Su ciudad es: %s\n",registroCliente.personal.ciudad);
    //l
    printf("l-Ingrese su ciudad\n");
    scanf("%s",ptrCliente->personal.ciudad);
    printf("Su ciudad es: %s\n",ptrCliente->personal.ciudad);
    //m
    printf("m-Ingrese su estado\n");
    scanf("%s",registroCliente.personal.estado);
    printf("Su estado es: %s\n",registroCliente.personal.estado);
    //n
    printf("n-Ingrese su estado\n");
    scanf("%s",ptrCliente->personal.estado);
    printf("Su estado es: %s\n",ptrCliente->personal.estado);
    //o
    printf("o-Ingrese su codigo postal\n");
    scanf("%s",registroCliente.personal.codigoPostal);
    printf("Su codigo postal es: %s\n",registroCliente.personal.codigoPostal);
    //p
    printf("p-Ingrese su codigo postal\n");
    scanf("%s",ptrCliente->personal.codigoPostal);
    printf("Su codigo postal es: %s\n",ptrCliente->personal.codigoPostal);

   return 0;
}