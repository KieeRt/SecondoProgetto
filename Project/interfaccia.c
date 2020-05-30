#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Utente.h"


void welcome(){
    User utente=initUtente();
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

        if(!strcmp(utente.codiceFiscale, "admin"))
            homeAdmin(utente);
        else
            home(utente);


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

void home(User utente){
    int scelta;
    system("cls");
    printf("\n");
    printf("Bentornato %s %s. Finora hai accumulato %d punti",utente.cognome,utente.nome,utente.punti);
    printf("\n\n");
    printf("1.Visaulizza prenotazioni attive\n");
    printf("2.Effettua nuova prenotazione\n");
    printf("3.Proponi meta piu' economica\n");
    printf("4.Proponi meta piu' gettonata\n");
    printf("5.Cronologia ordini\n");
    printf("6.Logout\n");


    scelta=doSceltaInt("Selezionare un operazione ", 6);

    switch(scelta){


    case 1:
       system("cls");

    break;
    case 2:
        system("cls");

    break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:
        system("cls");
        welcome();
    break;

    default:
        printf("\n\n\tScelta non valida\n");
    }


}

void homeAdmin(User utente){
 int scelta;
    system("cls");
    printf("\n");
    printf("Bentornato %s %s. Finora hai accumulato %d punti",utente.cognome,utente.nome,utente.punti);
    printf("\n\n");
    printf("1.Aggiungere un nuovo aeroporto\n");
    printf("2.Aggiungere una tratta\n");
    printf("3.Rimuovere aeroporto\n");
    printf("4.Rimuovere la tratta\n");
    printf("5.Logout\n");


    scelta=doSceltaInt("Selezionare un operazione ", 5);

    switch(scelta){


    case 1:
       system("cls");

    break;
    case 2:
        system("cls");

    break;
    case 3:

        break;
    case 4:

        break;
    case 5:
        system("cls");
        welcome();
    break;

    default:
        printf("\n\n\tScelta non valida\n");
    }


}
