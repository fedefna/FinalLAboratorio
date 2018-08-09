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

void pedirLocalidades(char* localidad1,char* localidad2,char* localidad3)
{
    printf("*******GENERAR ARCHIVO DE REPARTO********\n\n");
    printf("Ingresar las 3 localidades para el archivo:\n");
    printf("Localidad 1:\n");
    fflush(stdin);
    gets(localidad1);
    printf("Localidad 2:\n");
    fflush(stdin);
    gets(localidad2);
    printf("Localidad 3:\n");
    fflush(stdin);
    gets(localidad3);
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
//PUNTO2
void imprimirEntregas(ArrayList* lista){
    eEntrega* entrega;
    //id,producto,direccion,localidad,recibe
    if (lista != NULL)
    {
        printf("ID          PRODUCTO          DIRECCION          LOCALIDAD          RECIBE\n\n");
        for (int i=0 ; i<(lista->len(lista)); i++)
        {
            entrega = lista->get(lista, i);
            imprimirEntrega(entrega);
        }
    }
}

void imprimirEntrega(eEntrega* entrega){
    printf("%d  %10s  %10s  %10s  %10s\n", getId(entrega),getProducto(entrega),getDireccion(entrega),getLocalidad(entrega),getRecibe(entrega));
}
//PUNTO3
void imprimirLocalidades(ArrayList* listaEntregas,ArrayList* listaLocalidades){
    crearListaLocalidades(listaEntregas,listaLocalidades);
    eEntrega* entrega;
    //id,producto,direccion,localidad,recibe
    if (listaEntregas != NULL  && listaLocalidades!=NULL)
    {
        printf("LOCALIDADES\n\n");
        for (int i=0 ; i<(listaLocalidades->len(listaLocalidades)); i++)
        {
            entrega = listaLocalidades->get(listaLocalidades, i);
            imprimirLocalidad(entrega);
        }
    }
}

void imprimirLocalidad(eEntrega* entrega){
    printf("%s\n",getLocalidad(entrega));
}

void crearListaLocalidades(ArrayList* listaEntregas,ArrayList* listaLocalidades){
    int flag=0;
    eEntrega* aux;
    aux=newEntrega();

    if(listaEntregas!=NULL && listaLocalidades!=NULL){
        for(int i=0; i<listaEntregas->len(listaEntregas);i++){
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

int filtrarLocalidad(char* localidad,ArrayList* listaLocalidades){
    int retorno=1;
    eEntrega* aux;
    aux=newEntrega();

    if(localidad!=NULL && listaLocalidades!=NULL){
        for(int i=0; i<listaLocalidades->len(listaLocalidades);i++){
           aux=listaLocalidades->get(listaLocalidades,i);
           if(strcmp(localidad,getLocalidad(aux))==0){
                retorno=0;
                break;
           }
        }
    }
    return retorno;
}
//PUNTO4
void generarArchivo(ArrayList* listaEntregas,ArrayList* listaNuevoReparto){
    char* localidad1;
    char* localidad2;
    char* localidad3;
    localidad1=(char*) malloc(sizeof(char)*40);
    localidad2=(char*) malloc(sizeof(char)*40);
    localidad3=(char*) malloc(sizeof(char)*40);
    if(localidad1!=NULL && localidad2!=NULL && localidad3!=NULL){
        pedirLocalidades(localidad1,localidad2,localidad3);
    }
    avisarIngreso(listaEntregas,listaNuevoReparto,localidad1);
    avisarIngreso(listaEntregas,listaNuevoReparto,localidad2);
    avisarIngreso(listaEntregas,listaNuevoReparto,localidad3);

    listaNuevoReparto->sort(listaNuevoReparto,comparar,1);

    if (crearNuevoArchivoReparto(listaNuevoReparto)==0){
        printf("Nuevo archivo de reparto creado con exito!\n");
    }else{
        printf("Error al crear archivo\n");
    }
}

void avisarIngreso(ArrayList* listaEntregas,ArrayList* listaNuevoReparto,char* localidad){
    if(filtrarListaReparto(listaEntregas,listaNuevoReparto,localidad)){
        printf("La localidad %s fue ingresada al nuevo reparto.\n",localidad);
    }else{
        printf("La localidad %s no existe en el archivo de reparto.\n",localidad);
    }
}

int filtrarListaReparto(ArrayList* listaEntregas,ArrayList* listaNuevoReparto,char* localidad){
    int retorno=0;
    eEntrega* aux;
    aux=newEntrega();

    if(listaEntregas!=NULL && listaNuevoReparto!=NULL && localidad!=NULL){
        for(int i=0; i<listaEntregas->len(listaEntregas);i++){
            aux=listaEntregas->get(listaEntregas,i);
            if(stricmp(localidad,getLocalidad(aux))==0){
                listaNuevoReparto->add(listaNuevoReparto,aux);
                retorno=1;
            }
        }
    }
    return retorno;
}

int comparar(void* entrega1, void* entrega2){
    int retorno = 0;

    if(strcmp(((eEntrega*)entrega1)->localidad, ((eEntrega*)entrega2)->localidad) < 0){
        retorno = 1;
    }
    if(strcmp(((eEntrega*)entrega1)->localidad, ((eEntrega*)entrega2)->localidad) > 0){
        retorno =  -1;
    }
}

int crearNuevoArchivoReparto(ArrayList* listaNuevoReparto){
    int retorno=-1;
    FILE* f;
    int tam;
    eEntrega* entrega;

    if( listaNuevoReparto != NULL){
       f = fopen("nuevoReparto.csv", "w");

        if(f != NULL)
        {
            retorno = 0;

            tam = listaNuevoReparto->len(listaNuevoReparto);
            for(int i=0 ; i<tam ; i++)
            {
                if(i==0){
                    fprintf(f,"ID,PRODUCTO,DIRECCION,LOCALIDAD,RECIBE\n");
                }
                entrega = listaNuevoReparto->get(listaNuevoReparto, i);
                fprintf(f,"%d,%s,%s,%s,%s\n", getId(entrega),getProducto(entrega),getDireccion(entrega),getLocalidad(entrega),getRecibe(entrega));
            }
        }
        fclose(f);
    }
    return retorno;
}
