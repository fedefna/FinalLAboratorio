#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "ArrayList.h"


eEntrega* newEntrega(){

    eEntrega* retorno;

    retorno= (eEntrega*) malloc(sizeof(eEntrega));

    if(retorno!=NULL){
        retorno->id=-1;
        strcpy(retorno->producto," ");
        strcpy(retorno->direccion," ");
        strcpy(retorno->localidad," ");
        strcpy(retorno->recibe," ");
    }
    return retorno;
}
//**************GUETERS Y SETERS*****************
//**********ID***********
int setId(eEntrega* pEntrega, int id){
    int retorno=-1;
    if(pEntrega!=NULL){
        pEntrega->id=id;
        retorno=0;
    }
    return retorno;
}

int getId(eEntrega* pEntrega){
    int retorno=-1;
    if(pEntrega!=NULL){
        retorno=pEntrega->id;
    }
    return retorno;
}
//**********PRODUCTO***********
int setProducto(eEntrega* pEntrega, char* producto){
    int retorno=-1;
    if(pEntrega!=NULL){
        strcpy(pEntrega->producto,producto);
        retorno=0;
    }
    return retorno;
}

char* getProducto(eEntrega* pEntrega){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pEntrega!=NULL && retorno!=NULL){
        strcpy(retorno,pEntrega->producto);
    }
    return retorno;
}
//**********DIRECCION***********
int setDireccion(eEntrega* pEntrega, char* direccion){
    int retorno=-1;
    if(pEntrega!=NULL){
        strcpy(pEntrega->direccion,direccion);
        retorno=0;
    }
    return retorno;
}

char* getDireccion(eEntrega* pEntrega){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pEntrega!=NULL && retorno!=NULL){
        strcpy(retorno,pEntrega->direccion);
    }
    return retorno;
}
//**********LOCALIDAD***********
int setLocalidad(eEntrega* pEntrega, char* localidad){
    int retorno=-1;
    if(pEntrega!=NULL){
        strcpy(pEntrega->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

char* getLocalidad(eEntrega* pEntrega){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pEntrega!=NULL && retorno!=NULL){
        strcpy(retorno,pEntrega->localidad);
    }
    return retorno;
}
//**********RECIBE***********
int setRecibe(eEntrega* pEntrega, char* recibe){
    int retorno=-1;
    if(pEntrega!=NULL){
        strcpy(pEntrega->recibe,recibe);
        retorno=0;
    }
    return retorno;
}

char* getRecibe(eEntrega* pEntrega){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*300);
    if(pEntrega!=NULL && retorno!=NULL){
        strcpy(retorno,pEntrega->recibe);
    }
    return retorno;
}
//****MENU******
int menu(void)
{
    int opcion;

    system ("cls");
    printf("--- SELECCIONE OPCION DESEADA ---\n\n");
    printf("1- Cargar archivo.\n");
    printf("2- Imprimir entregas.\n");
    printf("3- Imprimir localidades.\n");
    printf("4- Generar archivo de reparto.\n");
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
//id,producto,direccion,localidad,recibe
int parser(ArrayList* lista,char* path){
    int status = -1;
    FILE* f;
    int flag=1;
    int cant = 0;
    char bufferId[5];
    char bufferProducto[40];
    char bufferDireccion[40];
    char bufferLocalidad[40];
    char bufferRecibe[40];
    eEntrega* auxEntrega;

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
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferProducto, bufferDireccion, bufferLocalidad, bufferRecibe);
            auxEntrega= newEntrega();
            if (cant != 5)
            {
                if (feof(f))
                {
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
                //id,producto,direccion,localidad,recibe
                setId(auxEntrega, atoi(bufferId));
                setProducto(auxEntrega, bufferProducto);
                setDireccion(auxEntrega, bufferDireccion);
                setLocalidad(auxEntrega, bufferLocalidad);
                setRecibe(auxEntrega, bufferRecibe);

                lista->add(lista, auxEntrega);
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

void imprimirEntregas(ArrayList* lista){
    eEntrega* entrega;
    //id,producto,direccion,localidad,recibe
    if (lista != NULL)
    {
        printf("ID          PRODUCTO          DIRECCION          LOCALIDAD          RECIBE\n\n");
        for (int i=0 ; i<(lista->len(lista)); i++)
        {
            entrega = lista->get(lista, i);
            imprimirLlamada(entrega);
        }
    }
}

void imprimirLlamada(eEntrega* entrega){
    printf("%d  %10s  %10s  %10s  %10s\n", getId(entrega),getProducto(entrega),getDireccion(entrega),getLocalidad(entrega),getRecibe(entrega));
}

void imprimirLocalidades(ArrayList* listaEntregas,ArrayList* listaLocalidades){

}

void crearListaLocalidades(){
    int flag=0;
    eEntrega* aux;
    aux=newEntrega();

    if(listaEntregas!=NULL && listaLocalidades!=NULL){
        if(listaEntregas!=NULL && listaLocalidades!=NULL){
            for(int i=0; i<listaEntregas->len(listaEntregas),i++){
                aux=listaEntregas->get(listaEntregas,i);
                if(flag=1){
                    if(filtrarLocalidad(getLocalidad(aux),listaLocalidades)){
                        listaLocalidades->add(listaLocalidades,aux);
                    }
                }else if(flag==0){
                    listaLocalidades->add(listaLocalidades,aux);
                    flag=1;
                }
            }
        }
    }
}

int filtrarLocalidad(char* localidad,ArrayList* listaLocalidades){
    int retorno=1;
    eEntrega* aux;
    aux=newEntrega();

    if(localidad!=NULL && listaLocalidades!=NULL){
        for(int i=0, i<listaLocalidades->len(listaLocalidades),i++){
           aux=listaLocalidades->get(listaLocalidades,i);
           if(strcmp(localidad,getLocalidad(aux))==0){
                retorno=0;
                break;
           }
        }
    }
    return retorno;
}

/*void imprimirEstadisticas(ArrayList* lista){
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
*/
