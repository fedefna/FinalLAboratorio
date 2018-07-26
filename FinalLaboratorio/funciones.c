#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

eEmpleado* newEmpleado(){
    eEmpleado* retorno;

    retorno= (eEmpleado*) malloc(sizeof(eEmpleado));

    if(retorno!=NULL){
        strcpy(retorno->direccion," ");
        strcpy(retorno->nombre," ");
        retorno->id=-1;
        retorno->horas=0;
        retorno->sueldo=0;
    }
    return retorno;
}
//GUETERS Y SETERS
int setId(eEmpleado* pEmpleado, int id){
    int retorno=-1;
    if(pEmpleado!=NULL){
        pEmpleado->id=id;
        retorno=0;
    }
    return retorno;
}

int getId(eEmpleado* pEmpleado){
    int retorno=-1;
    if(pEmpleado!=NULL){
        retorno=pEmpleado->id;
    }
    return retorno;
}

int setNombre(eEmpleado* pEmpleado, char* nombre){
    int retorno=-1;
    if(pEmpleado!=NULL){
        strcpy(pEmpleado->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

char* getNombre(eEmpleado* pEmpleado){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pEmpleado!=NULL && retorno!=NULL){
        strcpy(retorno,pEmpleado->nombre);
    }
    return retorno;
}

//MENU
int menu(void)
{
    int opcion;

    system ("cls");
    printf("--- SELECCIONE OPCION DESEADA ---\n\n");
    printf("1- Cargar depositos\n");
    printf("2- Listar productos de deposito\n");
    printf("3- Mover productos a deposito\n");
    printf("4- Descontar productos de deposito\n");
    printf("5- Agregar productos a deposito\n");
    printf("6- Salir\n");
    printf("\n");

    scanf("%d",&opcion);
    return opcion;
}

int subMenu()
{
    int opcion;
    printf("1. Deposito 1\n");
    printf("2. Deposito 2\n");
    printf("\n");
    scanf("%d", &opcion);
    while (1>opcion>2)
    {
        printf("La opcion seleccionada no es valida. Intente nuevamente.\n\n");
        scanf("%d", &opcion);
    }
    return opcion;
}

//PARSER
int parser(ArrayList* lista,char* path){
    int status = -1;
    FILE* f;
    int cant = 0;
    char bufferProducto[3];
    char bufferDescripcion[20];
    char bufferCantidad[4];
    eProducto* auxProducto;

    if (lista != NULL)
    {
        f = fopen(path, "r");
        if (f == NULL)
        {
            printf("Error al abrir archivo");
            system("Pause");
            exit(-2);
        }
        status = 0;
        while (!feof(f))
        {
            cant = fscanf(f, "%[^,],%[^,],%[^\n]\n", bufferProducto, bufferDescripcion, bufferCantidad);
            auxProducto = nuevoProducto();
            if (cant != 3)
            {
                if (feof(f))
                {
                    status = 1;
                    break;
                }
                else
                {
                    printf("Error al leer archivo");
                    system("Pause");
                    status = -3;
                }
            }
            setProducto(auxProducto, atoi(bufferProducto));
            setDescripcion(auxProducto, bufferDescripcion);
            setCantidad(auxProducto, atoi(bufferCantidad));
            lista->add(lista, auxProducto);
            }
    }
    fclose(f);
    return status;
}
