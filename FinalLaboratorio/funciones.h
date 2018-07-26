#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "string.h"

typedef struct
{
    int id;
    char nombre[40];
    char direccion[40];
    int horas;
    int sueldo;
}eEmpleado;

eEmpleado* newEmpleado();

//INICIO Gueters y seters
int setId(eEmpleado*, int);
int getId(eEmpleado*);
int setNombre(eEmpleado*, char*);
char* getNombre(eEmpleado*);

//MENU
int menu();
int subMenu();

//PARSER
int parser(ArrayList*, char*);
