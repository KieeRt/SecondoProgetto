#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Utente.h"


void welcome(){
    User utente;
    int scelta=-1;

    printf("\n");
    printf("1.Login\n");
    printf("2.Registrati\n");
    printf("3.Esci\n");



   scelta=doSceltaInt("Selezionare un operazione ",3);
    switch(scelta){


    case 1:
       system("cls");
       utente = login();
       printf("Bentornato");

    break;
    case 2:
        system("cls");
        utente = registazioneUtente();
        printf("Account creato con successo.\nBenvenuto!");

    break;
    case 3:
        exit(0);
    break;
    default:
        printf("\n\n\tScelta non valida\n");
    }
}

void home(){
    int scelta
    printf("\n");
    printf("1.Visaulizza prenotazioni attive\n");
    printf("2.Registrati\n");
    printf("3.Esci\n");



   scelta=doSceltaInt("Selezionare un operazione ",3);
    switch(scelta){


    case 1:
       system("cls");
       utente = login();
       printf("Bentornato");

    break;
    case 2:
        system("cls");
        utente = registazioneUtente();
        printf("Account creato con successo.\nBenvenuto!");

    break;
    case 3:
        exit(0);
    break;
    default:
        printf("\n\n\tScelta non valida\n");
    }


}
