#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "interfaccia.h"


void welcome(Graph graph, List aeroporti){
    User utente=initUtente();
    int scelta=-1;

    printf("\n");
    printf("1 - Login\n");
    printf("2 - Registrati\n");
    printf("3 - Esci\n");


    do{
        scelta=doSceltaInt("Input -> ",3);

        switch(scelta){


        case 1:
            system("cls");
            utente = login();

            if(!strcmp(utente.codiceFiscale, "admin"))

                homeAdmin(utente,graph,aeroporti);

            else
                home(utente,graph, aeroporti);


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
    }while(scelta!=3);
}

void home(User utente,Graph graph, List aeroporti){
    int scelta;
    system("cls");
    printf("\n");
    printf("Bentornato %s %s. Finora hai accumulato %d punti",utente.cognome,utente.nome,utente.punti);
    printf("\n\n");
    printf("1 - Visaulizza prenotazioni attive\n");
    printf("2 - Effettua nuova prenotazione\n");
    printf("3 - Proponi meta piu' economica\n");
    printf("4 - Proponi meta piu' gettonata\n");
    printf("5 - Cronologia ordini\n");
    printf("6 - Logout\n");


    scelta=doSceltaInt("Input -> ", 6);

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
        welcome(graph, aeroporti);
    break;

    default:
        printf("\n\n\tScelta non valida\n");
    }


}

void homeAdmin(User utente,Graph graph, List aeroporti){
 int scelta;
    Aeroporto srcAeroporto;
    Aeroporto destAeroporto;
    int  prezzo, tempo;
    char buffer;


    do{
        system("cls");
        printf("\n");
        printf("Bentornato %s %s.",utente.cognome,utente.nome);
        printf("\n\n");
        printf("1 - Aggiungere un nuovo aeroporto\n");
        printf("2 - Aggiungere una tratta\n");
        printf("3 - Rimuovere aeroporto\n");
        printf("4 - Rimuovere la tratta\n");
        printf("5 - Logout\n");

        scelta=doSceltaIntError("Input -> ", 5,"Scelta non valida,riprova\n");

        switch(scelta){


        case 1:
            system("cls");

            srcAeroporto = insertAeroporto();
            srcAeroporto.index = graph->numeroAeroporti;
            graph=addAeroporto(aeroporti,graph,srcAeroporto);


        break;
        case 2:
            printf("Lista aeroporti disponibili:\n");
            printAereoporto(aeroporti);

            do{
                strcpy(srcAeroporto.nomeAeroporto, doSceltaString("-Inserire codice IATA dell'aeroporto di partenza\nInput -> ",3, 0, 0));
                upperCase(srcAeroporto.nomeAeroporto);
                srcAeroporto = findAeroporto(aeroporti,srcAeroporto.nomeAeroporto);

                strcpy(destAeroporto.nomeAeroporto, doSceltaString("-Inserire codice IATA dell'aeroporto di arrivo\nInput -> ",3, 0, 0));
                upperCase(destAeroporto.nomeAeroporto);
                destAeroporto = findAeroporto(aeroporti,destAeroporto.nomeAeroporto);

                prezzo= doSceltaInt("-Inserire prezzo volo\nInput -> ",50000);

                tempo= doSceltaInt("-Inserire durata volo\nInput -> ",1500);

            }while(!addEdge(graph,srcAeroporto,destAeroporto,prezzo,tempo));

            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin

        break;

        case 3:

            break;
        case 4:

            break;
        case 5:
            system("cls");

        break;

        default:
            printf("\n\n\tScelta non valida\n");
        }
    }while(scelta!=5);

}
