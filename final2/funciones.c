#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "ArrayList.h"


eLlamada* newLlamada(){

    eLlamada* retorno;

    retorno= (eLlamada*) malloc(sizeof(eLlamada));

    if(retorno!=NULL){
        retorno->id=-1;
        strcpy(retorno->nombre," ");
        strcpy(retorno->email," ");
        retorno->dni=-1;
        strcpy(retorno->idProducto," ");
        strcpy(retorno->observaciones," ");
    }
    return retorno;
}
//**************GUETERS Y SETERS*****************
//**********ID***********
int setId(eLlamada* pLlamada, int id){
    int retorno=-1;
    if(pLlamada!=NULL){
        pLlamada->id=id;
        retorno=0;
    }
    return retorno;
}

int getId(eLlamada* pLlamada){
    int retorno=-1;
    if(pLlamada!=NULL){
        retorno=pLlamada->id;
    }
    return retorno;
}
//**********NOMBRE***********
int setNombre(eLlamada* pLlamada, char* nombre){
    int retorno=-1;
    if(pLlamada!=NULL){
        strcpy(pLlamada->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

char* getNombre(eLlamada* pLlamada){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pLlamada!=NULL && retorno!=NULL){
        strcpy(retorno,pLlamada->nombre);
    }
    return retorno;
}
//**********EMAIL***********
int setEmail(eLlamada* pLlamada, char* email){
    int retorno=-1;
    if(pLlamada!=NULL){
        strcpy(pLlamada->email,email);
        retorno=0;
    }
    return retorno;
}

char* getEmail(eLlamada* pLlamada){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pLlamada!=NULL && retorno!=NULL){
        strcpy(retorno,pLlamada->email);
    }
    return retorno;
}
//**********DNI***********
int setDni(eLlamada* pLlamada, int dni){
    int retorno=-1;
    if(pLlamada!=NULL){
        pLlamada->dni=dni;
        retorno=0;
    }
    return retorno;
}

int getDni(eLlamada* pLlamada){
    int retorno=-1;
    if(pLlamada!=NULL){
        retorno=pLlamada->dni;
    }
    return retorno;
}
//**********ID_PRODUCTO***********
int setIdProducto(eLlamada* pLlamada, char* idProducto){
    int retorno=-1;
    if(pLlamada!=NULL){
        strcpy(pLlamada->idProducto,idProducto);
        retorno=0;
    }
    return retorno;
}

char* getIdProducto(eLlamada* pLlamada){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pLlamada!=NULL && retorno!=NULL){
        strcpy(retorno,pLlamada->idProducto);
    }
    return retorno;
}
//**********Observaciones***********
int setObservaciones(eLlamada* pLlamada, char* observaciones){
    int retorno=-1;
    if(pLlamada!=NULL){
        strcpy(pLlamada->observaciones,observaciones);
        retorno=0;
    }
    return retorno;
}

char* getObservaciones(eLlamada* pLlamada){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*300);
    if(pLlamada!=NULL && retorno!=NULL){
        strcpy(retorno,pLlamada->observaciones);
    }
    return retorno;
}
//MENU
int menu(void)
{
    int opcion;

    system ("cls");
    printf("--- SELECCIONE OPCION DESEADA ---\n\n");
    printf("1- Cargar archivo.\n");
    printf("2- Imprimir llamadas.\n");
    printf("3- Imprimir estadisticas.\n"); //Cliente con mas llamados y producto mas consultado
    printf("4- Generar archivo de clientes.\n");
    printf("5- Salir\n");
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
    while (1>opcion || opcion>2)
    {
        printf("La opcion seleccionada no es valida. Intente nuevamente.\n\n");
        scanf("%d", &opcion);
    }
    return opcion;
}

//PARSER
//id,nombre,email,dni,ID_producto,observaciones
int parser(ArrayList* lista,char* path){
    int status = -1;
    FILE* f;
    int flag=1;
    int cant = 0;
    char bufferId[5];
    char bufferNombre[40];
    char bufferEmail[40];
    char bufferDni[10];
    char bufferIdProducto[40];
    char bufferObservaciones[300];
    eLlamada* auxLlamada;

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
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferEmail, bufferDni, bufferIdProducto, bufferObservaciones);
            auxLlamada= newLlamada();
            if (cant != 6)
            {
                if (feof(f))
                {
                    printf("Cant !=6");
                    system("Pause");
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
            if(flag==0){
                    //id,nombre,email,dni,ID_producto,observaciones
                setId(auxLlamada, atoi(bufferId));
                setNombre(auxLlamada, bufferNombre);
                setEmail(auxLlamada, bufferEmail);
                setDni(auxLlamada, atoi(bufferDni));
                setIdProducto(auxLlamada, bufferIdProducto);
                setObservaciones(auxLlamada, bufferObservaciones);
                lista->add(lista, auxLlamada);
            }else if(flag==1){
                    flag=0;
                }
            }
    }
    fclose(f);
    return status;
}

//Punto 1
int cargarArchivo(ArrayList* lista){
    int retorno=-1;
    char path[30];
    printf("Ingresar nombre del archivo: \n");
    fflush(stdin);
    gets(path);
    if(parser(lista,path)==0){
        retorno=0;
    }

    return retorno;
}

void imprimirLlamadas(ArrayList* lista){
    eLlamada* llamada;

    if (lista != NULL)
    {
        printf("ID          NOMBRE          EMAIL          DNI          ID_PRODUCTO\n\n");
        for (int i=0 ; i<(lista->len(lista)); i++)
        {
            llamada = lista->get(lista, i);
            imprimirLlamada(llamada);
        }
    }
}

void imprimirLlamada(eLlamada* llamada){
    printf("%d  %10s  %10s  %10d  %10s\n", getId(llamada),getNombre(llamada),getEmail(llamada),getDni(llamada),getIdProducto(llamada));
}

void imprimirEstadisticas(ArrayList* lista){
    mostrarProductoMasConsultado(lista);
    mostrarPersonaConMasLlamados(lista);
}

void mostrarProductoMasConsultado(ArrayList* lista){
    eLlamada* llamada;

    char auxProducto[40];
    int auxConsultas=0;
    char producto[40];
    int consultasMax=0;
    if (lista != NULL)
    {
        for (int i=0 ; i<(lista->len(lista)); i++)
        {
            llamada = lista->get(lista, i);
            strcpy(auxProducto,getIdProducto(llamada));
            auxConsultas=buscarProducto(lista,auxProducto);
            if(auxConsultas>consultasMax){
                strcpy(producto,auxProducto);
                consultasMax=auxConsultas;
            }
        }
    }
    printf("Producto mas consultado: %s\n",producto);
}

int buscarProducto(ArrayList* lista, char* idProducto){
    eLlamada* llamada;
    int contador=0;
    if (lista != NULL)
    {
        for (int i=0 ; i<(lista->len(lista)); i++)
        {
            llamada = lista->get(lista, i);
            if(strcmp(idProducto,getIdProducto(llamada))==0){
                contador++;
            }
        }
    }
    return contador;
}

void mostrarPersonaConMasLlamados(ArrayList* lista){
    eLlamada* llamada;

    int auxDni;
    char nombre[40];
    int dni;
    int cantLlamados=0;
    int llamadosMax=0;
    if (lista != NULL)
    {
        for (int i=0 ; i<(lista->len(lista)); i++)
        {
            llamada = lista->get(lista, i);
            auxDni=getDni(llamada);
            cantLlamados=buscarDni(lista,auxDni);
            if(cantLlamados>llamadosMax){
                strcpy(nombre,getNombre(llamada));
                dni=auxDni;
                llamadosMax=cantLlamados;
            }
        }
    }
    printf("Persona con mas llamados:\n Nombre: %s\n Dni: %d\n",nombre,dni);
}

int buscarDni(ArrayList* lista, int dni){
    eLlamada* llamada;
    int contador=0;
    if (lista != NULL)
    {
        for (int i=0 ; i<(lista->len(lista)); i++)
        {
            llamada = lista->get(lista, i);
            if(dni==getDni(llamada)){
                contador++;
            }
        }
    }
    return contador;
 }

int crearArchivo(ArrayList* lista,ArrayList* listaFiltrada){
    int retorno=-1;
    FILE* f;
    int tam;
    eLlamada* llamada;

    if( lista != NULL && listaFiltrada!= NULL){
       f = fopen("clientes.csv", "w");

        if(f != NULL)
        {
            retorno = 0;

            filtrar(lista,listaFiltrada);
            tam = listaFiltrada->len(listaFiltrada);
            for(int i=0 ; i<tam ; i++)
            {
                if(i==0){
                    fprintf(f,"DNI,NOMBRE,EMAIL\n");
                }
                llamada = listaFiltrada->get(listaFiltrada, i);
                fprintf(f,"%d,", getDni(llamada));
                fprintf(f,"%s,", getNombre(llamada));
                fprintf(f,"%s\n", getEmail(llamada));
            }
        }
        fclose(f);
    }
    return retorno;
}

void filtrar(ArrayList* lista,ArrayList* listaFiltrada){
    eLlamada* llamada;
    int flag=1;

    if( lista != NULL && listaFiltrada!= NULL){
        llamada = newLlamada();
        for (int i=0 ; i<(lista->len(lista)); i++)
        {
            llamada = lista->get(lista, i);
            if(flag==0){
                if(filtrarDni(getDni(llamada),listaFiltrada)){
                    listaFiltrada->add(listaFiltrada,llamada);
                }
            }else if(flag==1){
                listaFiltrada->add(listaFiltrada,llamada);
                flag=0;
                }
        }
    }
}

int filtrarDni(int dni,ArrayList* listaFiltrada){
    int retorno=1;
    int tam;
    eLlamada* llamada;
    llamada = newLlamada();

    tam=listaFiltrada->len(listaFiltrada);
    for (int i=0 ; i<tam; i++){
        llamada = listaFiltrada->get(listaFiltrada,i);
        if(dni==getDni(llamada)){
            retorno=0;
            break;
        }
    }
    return retorno;
}
