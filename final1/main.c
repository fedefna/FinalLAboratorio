#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Funciones.h"

int main()
{
    ArrayList* listaEntregas;
    listaEntregas=al_newArrayList();

    ArrayList* listaLocalidades;
    listaLocalidades=al_newArrayList();

    ArrayList* listaNuevoReparto;
    listaNuevoReparto=al_newArrayList();

    int flag=0;

    if(listaEntregas != NULL){
        char seguir='s';

        while (seguir == 's')
        {
            system("cls");
            switch(menu())
            {
            case 1:
                if(cargarArchivo(listaEntregas)==0){
                    printf("Archivo cargado con exito!\n");
                    flag=1;
                }
                system("Pause");
                break;
            case 2:
                if(flag==1){
                    imprimirEntregas(listaEntregas);
                }else{
                    printf("Primero debe cargar el archivo.\n");
                }
                system("Pause");
                break;
            case 3:
                if(flag==1){
                    imprimirLocalidades(listaEntregas,listaLocalidades);
                }else{
                    printf("Primero debe cargar el archivo.\n");
                }
                system("Pause");
                break;
            case 4:
                if(flag==1){
                    generarArchivo(listaEntregas,listaNuevoReparto);
                }else{
                    printf("Primero debe cargar el archivo.\n");
                }
                system("Pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error. La opcion ingresada no es valida. Intente nuevamente.\n\n");
                system("Pause");
                break;
            }
        }
    }

    return 0;
}
