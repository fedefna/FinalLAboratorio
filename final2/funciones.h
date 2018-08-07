#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "string.h"
//id,nombre,email,dni,ID_producto,observaciones
typedef struct
{
    int id;
    char nombre[40];
    char email[40];
    int dni;
    char idProducto[40];
    char observaciones[300];
}eLlamada;

eLlamada* newLlamada();

//INICIO Gueters y seters
int setId(eLlamada*, int);
int getId(eLlamada*);

int setNombre(eLlamada*, char*);
char* getNombre(eLlamada*);

int setEmail(eLlamada*, char*);
char* getEmail(eLlamada*);

int setDni(eLlamada*, int);
int getDni(eLlamada*);

int setIdProducto(eLlamada*, char*);
char* getIdProducto(eLlamada*);

int setObservaciones(eLlamada*, char*);
char* getObservaciones(eLlamada*);

//MENU
int menu();
int subMenu();

//PARSER
int parser(ArrayList*, char*);

//punto 1
int cargarArchivo(ArrayList*);
//Punto2
void imprimirLlamadas(ArrayList*);
void imprimirLlamada(eLlamada*);
//punto3
void imprimirEstadisticas(ArrayList*);
void mostrarProductoMasConsultado(ArrayList*);
void mostrarPersonaConMasLlamados(ArrayList*);
int buscarProducto(ArrayList*,char*);
int buscarDni(ArrayList*,int);
//punto4
int crearArchivo(ArrayList*,ArrayList*);
void filtrar(ArrayList*,ArrayList*);
