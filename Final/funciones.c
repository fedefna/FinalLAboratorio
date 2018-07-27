#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

eProducto* newProducto(){
    eProducto* retorno;

    retorno= (eProducto*) malloc(sizeof(eProducto));

    if(retorno!=NULL){
        retorno->id=-1;
        strcpy(retorno->nombre," ");
        strcpy(retorno->direccion," ");
        strcpy(retorno->localidad," ");
        strcpy(retorno->recibe," ");
    }
    return retorno;
}
//GUETERS Y SETERS
int setId(eProducto* pProducto, int id){
    int retorno=-1;
    if(pProducto!=NULL){
        pProducto->id=id;
        retorno=0;
    }
    return retorno;
}

int getId(eProducto* pProducto){
    int retorno=-1;
    if(pProducto!=NULL){
        retorno=pProducto->id;
    }
    return retorno;
}

int setNombre(eProducto* pProducto, char* nombre){
    int retorno=-1;
    if(pProducto!=NULL){
        strcpy(pProducto->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

char* getNombre(eProducto* pProducto){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pProducto!=NULL && retorno!=NULL){
        strcpy(retorno,pProducto->nombre);
    }
    return retorno;
}
int setDireccion(eProducto* pProducto, char* direccion){
    int retorno=-1;
    if(pProducto!=NULL){
        strcpy(pProducto->direccion,direccion);
        retorno=0;
    }
    return retorno;
}

char* getDireccion(eProducto* pProducto){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pProducto!=NULL && retorno!=NULL){
        strcpy(retorno,pProducto->direccion);
    }
    return retorno;
}
int setLocalidad(eProducto* pProducto, char* localidad){
    int retorno=-1;
    if(pProducto!=NULL){
        strcpy(pProducto->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

char* getLocalidad(eProducto* pProducto){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pProducto!=NULL && retorno!=NULL){
        strcpy(retorno,pProducto->localidad);
    }
    return retorno;
}
int setRecibe(eProducto* pProducto, char* recibe){
    int retorno=-1;
    if(pProducto!=NULL){
        strcpy(pProducto->recibe,recibe);
        retorno=0;
    }
    return retorno;
}

char* getRecibe(eProducto* pProducto){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pProducto!=NULL && retorno!=NULL){
        strcpy(retorno,pProducto->recibe);
    }
    return retorno;
}

//MENU
int menu(void)
{
    int opcion;

    system ("cls");
    printf("--- SELECCIONE OPCION DESEADA ---\n\n");
    printf("1- Cargar Archivo\n");
    printf("2- Imprimir entregas.\n");
    printf("3- Imprimir localidades.\n");
    printf("4- Generar archivo de reparto.\n");
    printf("5- Salir.\n");
    printf("\n");

    scanf("%d",&opcion);
    return opcion;
}


//PARSER
int parser(ArrayList* lista,char* path){
    int status = -1;
    int flag=0;
    FILE* f;
    int cant = 0;
    char bufferId[4];
    char bufferNombre[20];
    char bufferDireccion[40];
    char bufferLocalidad[40];
    char bufferRecibe[40];
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
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferDireccion, bufferLocalidad, bufferRecibe);
            auxProducto = newProducto();
            if (cant != 5)
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
            if(flag==1){
                setId(auxProducto,atoi(bufferId));
                setNombre(auxProducto, bufferNombre);
                setDireccion(auxProducto,bufferDireccion);
                setLocalidad(auxProducto,bufferLocalidad);
                setRecibe(auxProducto,bufferRecibe);

                lista->add(lista, auxProducto);
            }else if(flag==0){
                flag=1;
            }
    }
    fclose(f);
    return status;
}
}

int cargarArchivo(ArrayList* lista){
    int resultado=-1;
    char path[20];
    printf("Ingresar el nombre del archivo:\n");
    fflush(stdin);
    scanf("%s",path);

    if(parser(lista,path)==0){
        resultado=0;
    }

    return resultado;
}

void imprimirEntregas(ArrayList* lista){
    eProducto* producto;

    if (lista != NULL)
    {
        printf("ID            PRODUCTO            DIRECCION          LOCALIDAD      RECIBE\n\n");
        for (int i=0 ; i<(lista->len(lista)); i++)
        {
            producto = lista->get(lista, i);
            mostrarProducto(producto);
        }
    }
}

void mostrarProducto(eProducto* producto){
    printf("%2d  %18s  %24s  %10s  %10s\n", getId(producto),getNombre(producto),getDireccion(producto),getLocalidad(producto),getRecibe(producto));
}


//PUNTO 3
char* newLocalidad(){
    char* retorno;

    retorno= (char*) malloc(sizeof(char)*40);
    if(retorno!=NULL){
        strcpy(retorno," ");
    }
    return retorno;
}

void imprimirLocalidades(ArrayList* lista){
    printf("Entro");
    system("pause");

    ArrayList* listaLocalidades;
    listaLocalidades=al_newArrayList();
    char* auxLocalidad;
    eProducto* producto;
    char* localidad;
    printf("2");
    system("pause");
    if (listaLocalidades!=NULL){
        auxLocalidad=newLocalidad();
        if(auxLocalidad!=NULL){

            for (int i=0 ; i<(lista->len(lista)); i++){
                producto = lista->get(lista, i);
                if(i==0){
                    strcpy(auxLocalidad,getLocalidad(producto));
                    listaLocalidades->add(listaLocalidades, auxLocalidad);
                }else{
                    for(int j=0 ; j<(listaLocalidades->len(listaLocalidades)); j++){

                        localidad  = listaLocalidades->get(listaLocalidades,j);
                        if(strcmpi(localidad,getLocalidad(producto))==0){
                            auxLocalidad=newLocalidad();
                            strcpy(auxLocalidad,getLocalidad(producto));
                            listaLocalidades->add(listaLocalidades, auxLocalidad);

                        }
                    }
                }
            }
        }
    }
    printf("LOCALIDADES\n\n");
        for (int k=0 ; k<(listaLocalidades->len(listaLocalidades)); k++)
        {
            localidad = listaLocalidades->get(listaLocalidades, k);
            printf("%s", localidad);
        }
}




