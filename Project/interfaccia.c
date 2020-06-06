#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Utente.h"


void welcome(){
    User utente=initUtente();
    int scelta=-1;

    printf("\n");
    printf("1 - Login\n");
    printf("2 - Registrati\n");
    printf("3 - Esci\n");



   scelta=doSceltaInt("Input -> ",3);
    switch(scelta){

<<<<<<< Updated upstream

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
=======
            if(!strcmp(utente.codiceFiscale, "admin"))
                homeAdmin(utente,graph,aeroporti);
            else
                home(utente,graph, aeroporti);
            break;
        case 2:
            system("cls");
            utente = registazioneUtente();
            printf("Account creato con successo.\nBenvenuto!");
>>>>>>> Stashed changes

    break;
    case 3:
        exit(0);
    break;
    default:
        printf("\n\n\tScelta non valida\n");
    }
}

<<<<<<< Updated upstream
void home(User utente){
=======
void home(User utente,Graph graph, List aeroporti){
    List tmp = NULL;
     Aeroporto srcAeroporto;
     Aeroporto destAeroporto;
>>>>>>> Stashed changes
    int scelta;
    system("cls");
    printf("\n");
    printf("Bentornato %s %s. Finora hai accumulato %d punti",utente.cognome,utente.nome,utente.punti);
    printf("\n\n");
    printf("1 - Visaulizza prenotazioni attive\n");
    printf("2 - Effettua nuova prenotazione\n");
    printf("3 - Visualizza meta piu' economica\n");
    printf("4 - Visualliza meta piu' gettonata\n");
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
         printf("Lista aeroporti disponibili:\n");
            printAereoporto(aeroporti);
     do{
            strcpy(srcAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di partenza(0 se si vuole uscire)\nInput -> ", "Input non valido\n",0, 1, 3));
                if(!strcmp(srcAeroporto.nomeAeroporto,"0"))
                    break;
                    upperCase(srcAeroporto.nomeAeroporto);
                    srcAeroporto = findAeroporto(aeroporti,srcAeroporto.nomeAeroporto);

            }while(srcAeroporto.index == -1);
            tmp = copyList(graph->adjList[srcAeroporto.index]);
            MergeSort(&tmp, 0);
            printAereoportoPrice(tmp);
            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin
            //TODO prenotazione!!!

        break;
    case 4:
         printf("Lista aeroporti disponibili:\n");
            printAereoporto(aeroporti);
     do{
            strcpy(srcAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di partenza(0 se si vuole uscire)\nInput -> ", "Input non valido\n",0, 1, 3));
                if(!strcmp(srcAeroporto.nomeAeroporto,"0"))
                    break;
                    upperCase(srcAeroporto.nomeAeroporto);
                    srcAeroporto = findAeroporto(aeroporti,srcAeroporto.nomeAeroporto);

            }while(srcAeroporto.index == -1);
            tmp = copyList(graph->adjList[srcAeroporto.index]);
            printAereoporto(graph->adjList[srcAeroporto.index]);
            MergeSort(&tmp, 1);
            printAereoportoPrice(tmp);
            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin
            //TODO prenotazione!!!

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
    int destinazione, sorgente, prezzo, tempo;

    system("cls");
    printf("\n");
    printf("Bentornato %s %s.",utente.cognome,utente.nome);
    printf("\n\n");
    printf("1 - Aggiungere un nuovo aeroporto\n");
    printf("2 - Aggiungere una tratta\n");
    printf("3 - Rimuovere aeroporto\n");
    printf("4 - Rimuovere la tratta\n");
    printf("5 - Logout\n");


    scelta=doSceltaInt("Input -> ", 5);

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
