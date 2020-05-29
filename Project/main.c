#include <stdio.h>
#include <stdlib.h>
#include "Utente.h"

void menu();

int main()
{
    User x = registazioneUtente();
    //menu();
    return 0;
}

void menu(B){

    int scelta=-1;
    do{
        printf("\nSelezionare un operazione");
        printf("\n\t\t\t 1.Login");
        printf("\n\t\t\t 2.Registrati");
        printf("\n\t\t\t 0.Esci");


        printf("\n\n\n\t\t\t Enter choice => ");
        scanf("%d",&scelta);

        switch(scelta){

        case 0:
            exit(0);

        default:
            printf("Scelta non valida");

        }

    }while(scelta!=-1);
}
