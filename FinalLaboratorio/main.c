#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Funciones.h"

int main()
{
    ArrayList* lista0;
    lista0=al_newArrayList();

    ArrayList* lista1;
    lista1=al_newArrayList();

    int archivo;
    int flag=0;

    if(lista0 != NULL && lista1!=NULL){
        char seguir='s';

        while (seguir == 's')
        {
            system("cls");
            switch(menu())
            {
            case 1:
                parser(lista0,PATH0);
                parser(lista1,PATH1);
                printf("Depositos cargados!\n\n");
                flag=1;
                system("Pause");
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
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
