#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Funciones.h"

int main()
{
    ArrayList* listaLlamadas;
    listaLlamadas=al_newArrayList();

    ArrayList* listaClientes;
    listaClientes=al_newArrayList();

    int flag=0;

    if(listaLlamadas != NULL){
        char seguir='s';

        while (seguir == 's')
        {
            system("cls");
            switch(menu())
            {
            case 1:
                if(cargarArchivo(listaLlamadas)==0){
                    printf("Archivo cargado con exito!\n");
                    flag=1;
                }
                system("Pause");
                break;
            case 2:
                if(flag==1){
                    imprimirLlamadas(listaLlamadas);
                }else{
                    printf("Primero debe cargar el archivo.\n");
                }
                system("Pause");
                break;
            case 3:
                if(flag==1){
                    imprimirEstadisticas(listaLlamadas);
                }else{
                    printf("Primero debe cargar el archivo.\n");
                }
                system("Pause");
                break;
            case 4:
                if(flag==1){
                    if(crearArchivo(listaLlamadas,listaClientes)==0){
                        printf("Archivo creado con exito!\n");
                    }else{
                        printf("Error al crear el archivo.");
                    }
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
