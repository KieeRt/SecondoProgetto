#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "interfaccia.h"


void welcome(Graph graph, List aeroporti){
    User utente=initUtente();
    int scelta=-1;




    do{

    printf("\n");
    printf("1 - Login\n");
    printf("2 - Registrati\n");
    printf("3 - Esci\n");

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
        printf("5 - Stampare tutti gli aeroporti\n");
        printf("6 - Stampare tutti gli aeroporti con destinazioni possibili\n");
        printf("7 - Logout\n");

        scelta=doSceltaIntError("Input -> ", 7,"Scelta non valida,riprova\n");

        switch(scelta){


        case 1:
            system("cls");

            srcAeroporto = insertAeroporto();
            srcAeroporto.index = graph->numeroAeroporti;
            graph=addAeroporto(aeroporti,graph,srcAeroporto);

            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin




        break;
        case 2:
            printf("Lista aeroporti disponibili:\n");
            printAereoporto(aeroporti);

            do{
                strcpy(srcAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di partenza(0 se si vuole uscire)\nInput -> ", "Input non valido\n", 0, 1, 3));
                if(!strcmp(srcAeroporto.nomeAeroporto,"0"))
                    break;
                upperCase(srcAeroporto.nomeAeroporto);
                srcAeroporto = findAeroporto(aeroporti,srcAeroporto.nomeAeroporto);


                strcpy(destAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di arrivo(0 se si vuole uscire)\nInput -> ", "Input non valido\n", 0, 1, 3));
               if(!strcmp(destAeroporto.nomeAeroporto,"0"))
                    break;
                upperCase(destAeroporto.nomeAeroporto);
                destAeroporto = findAeroporto(aeroporti,destAeroporto.nomeAeroporto);
                if(!strcmp(destAeroporto.nomeAeroporto,"0"))
                    break;

                prezzo = doSceltaIntZero("-Inserire prezzo volo\nInput -> ",50000);
                if(prezzo == 0)
                    break;

                tempo = doSceltaIntZero("-Inserire durata volo\nInput -> ",1500);
                if(tempo == 0)
                    break;

            }while(!addEdge(graph,srcAeroporto,destAeroporto,prezzo,tempo));

            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin

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

            }while(!removeNode(graph, srcAeroporto.index));

            aeroporti = removeNodeList(aeroporti, srcAeroporto.index);
            aeroporti = updateNodeListIndexR(aeroporti, 0);


            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin

            break;
        case 4:
            printf("-Collegamenti disponibili\n");
            printAereoportoCollegamenti(graph, aeroporti);

             do{
                strcpy(srcAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di partenza(0 se si vuole uscire)\nInput -> ", "Input non valido\n", 0, 1, 3));
                if(!strcmp(srcAeroporto.nomeAeroporto,"0"))
                    break;
                upperCase(srcAeroporto.nomeAeroporto);
                srcAeroporto = findAeroporto(aeroporti,srcAeroporto.nomeAeroporto);


                strcpy(destAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di arrivo(0 se si vuole uscire)\nInput -> ", "Input non valido\n", 0, 1, 3));

                if(!strcmp(destAeroporto.nomeAeroporto,"0"))
                    break;
                upperCase(destAeroporto.nomeAeroporto);
                destAeroporto = findAeroporto(aeroporti,destAeroporto.nomeAeroporto);

                if(!strcmp(destAeroporto.nomeAeroporto,"0"))
                    break;

            }while(!isDeletedEdge(graph, srcAeroporto.index, destAeroporto.index));


            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin
            break;
        case 5:
            printAereoporto(aeroporti);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin
        break;
        case 6:
            printAereoportoCollegamenti(graph, aeroporti);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin
        break;
        case 7:
            system("cls");
            break;
        default:
            printf("\n\n\tScelta non valida\n");
        }
    }while(scelta!=7);

}
