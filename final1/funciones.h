#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "string.h"
//id,nombre,email,dni,ID_producto,observaciones
typedef struct
{
    int id;
    char producto[40];
    char direccion[40];
    char localidad[40];
    char recibe[40];
}eEntrega;

eEntrega* newEntrega();

//INICIO Gueters y seters
int setId(eEntrega*, int);
int getId(eEntrega*);

int setProducto(eEntrega*, char*);
char* getProducto(eEntrega*);

int setDireccion(eEntrega*, char*);
char* getDireccion(eEntrega*);

int setLocalidad(eEntrega*, char*);
char* getLocalidad(eEntrega*);

int setRecibe(eEntrega*, char*);
char* getRecibe(eEntrega*);

//MENU
int menu();
int subMenu();

//PARSER
int parser(ArrayList*, char*);

//punto 1
int cargarArchivo(ArrayList*);
//Punto2
void imprimirEntregas(ArrayList*);
void imprimirEntrega(eEntrega*);
/*//punto3
void imprimirEstadisticas(ArrayList*);
void mostrarProductoMasConsultado(ArrayList*);
void mostrarPersonaConMasLlamados(ArrayList*);
int buscarProducto(ArrayList*,char*);
int buscarDni(ArrayList*,int);
//punto4
int crearArchivo(ArrayList*,ArrayList*);
void filtrar(ArrayList*,ArrayList*);
int filtrarDni(int,ArrayList*);*/
