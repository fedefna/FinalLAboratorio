#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "string.h"

typedef struct
{
    int id;
    char nombre[20];
    char direccion[40];
    char localidad[40];
    char recibe[40];
}eProducto;

eProducto* newProducto();

//INICIO Gueters y seters
int setId(eProducto*, int);
int getId(eProducto*);

int setNombre(eProducto*, char*);
char* getNombre(eProducto*);

int setDireccion(eProducto*, char*);
char* getDireccion(eProducto*);

int setLocalidad(eProducto*, char*);
char* getLocalidad(eProducto*);

int setRecibe(eProducto*, char*);
char* getRecibe(eProducto*);

//MENU
int menu();
int subMenu();

//PARSER
int parser(ArrayList*, char*);

//punto1
int cargarArchivo(ArrayList*);
//PUNTO 2
void imprimirEntregas(ArrayList*);
void mostrarProducto(eProducto*);
//PUNTO 3
char* newLocalidad();
void imprimirLocalidades(ArrayList*);
