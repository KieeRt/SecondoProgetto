#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "interfaccia.h"


void welcome(Graph graph, List aeroporti, Prenotazione ListaPrenotazioni){
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

            else{
                ListaPrenotazioni = readPrenotazioni(utente.codiceFiscale, aeroporti);
                home(utente,graph, aeroporti, ListaPrenotazioni);
            }

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

void home(User utente,Graph graph, List aeroporti, Prenotazione ListaPrenotazioni){
    int scelta, scelta2;
    List tmp = NULL;
    Aeroporto srcAeroporto;
    Aeroporto destAeroporto;
    int prev[20], dist[20], **matrix;
    int error=0;
    int i;
    int count = 0;



    do{
        system("cls");
        printf("\n");
        printf("Bentornato %s %s. Finora hai accumulato %d punti",utente.cognome,utente.nome,utente.punti);
        printf("\n\n");
        printf("1 - Visualizza prenotazioni attive\n");
        printf("2 - Effettua una nuova prenotazione\n");
        printf("3 - Visualizza meta piu' economica\n");
        printf("4 - Visualizza meta piu' gettonata\n");
        printf("5 - Cronologia ordini\n");
        printf("6 - Logout\n");


        scelta=doSceltaInt("Input -> ", 6);

        switch(scelta){


        case 1:
           system("cls");
           stampaPrenotazione(ListaPrenotazioni);
           writePrenotezioniFile(utente.codiceFiscale, ListaPrenotazioni);

            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin

        break;
        case 2:
            system("cls");
                        printf("Lista aeroporti disponibili:\n");
            printAereoporto(aeroporti);
            do{
                if(error>0){
                    printf("Uno degli aeroporti inseriti non e' stato trovato, riprova\n");
                }
                error++;
                strcpy(srcAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di partenza(0 se si vuole uscire)\nInput -> ", "Input non valido\n",0, 1, 3));
                if(!strcmp(srcAeroporto.nomeAeroporto,"0")){
                    error=-1;
                    break;
                }
                upperCase(srcAeroporto.nomeAeroporto);
                srcAeroporto = findAeroporto(aeroporti,srcAeroporto.nomeAeroporto);
                strcpy(destAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di arrivo(0 se si vuole uscire)\nInput -> ", "Input non valido\n",0, 1, 3));

                if(!strcmp(destAeroporto.nomeAeroporto,"0")){
                    error=-1;
                    break;
                }
                upperCase(destAeroporto.nomeAeroporto);
                destAeroporto = findAeroporto(aeroporti,destAeroporto.nomeAeroporto);

            }while(srcAeroporto.index == -1 || destAeroporto.index == -1);

            if(error != -1){
                matrix = printAllPaths(srcAeroporto.index,destAeroporto.index, graph,aeroporti);

                for(i = 0; i < 20; i++){
                    if(matrix[i][0] != -1)
                        count++;
                    else
                        break;
                }
                    if(matrix[0][0] != -1)
                        scelta2 = doSceltaIntZeroError("Scegliere la tratta(0 per uscire) \nInput -> ", count, "Input non valido\n");
                if(scelta2 !=  0){
                    ListaPrenotazioni = addPrenotazione(ListaPrenotazioni, matrix[--scelta2], aeroporti, graph,&utente.punti,true);
                    stampaPrenotazione(ListaPrenotazioni);
                }
            }

            error=0;

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

                }while(srcAeroporto.index == -1);

                shortestPathPrice(graph,&dist,&prev,srcAeroporto.index,aeroporti);

                printOrder(dist,graph->numeroAeroporti,aeroporti,prev,srcAeroporto.index);

                fflush(stdin);
                printf("\nPremi invio per tornare al menu precedente\n");
                while(getchar()!='\n'); // option TWO to clean stdin

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
            writePrenotezioniFile(utente.codiceFiscale,  ListaPrenotazioni);
            welcome(graph, aeroporti, ListaPrenotazioni);
             fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin
        break;

        default:
            printf("\n\n\tScelta non valida\n");
        }

    }while(scelta!=6);


}

void homeAdmin(User utente,Graph graph, List aeroporti){
 int scelta;
    Aeroporto srcAeroporto;
    Aeroporto destAeroporto;
    double  prezzo;
    int tempo;
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

                prezzo = doSceltaDoubleZero("-Inserire prezzo volo\nInput -> ",50000);
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


void printOrder (int *array, int n, List list, int * prev,int src){
    int min;
    int i =0;
    Aeroporto a1 ;

    a1= findAeroportoIndex(src,list);
    printf("%s (%s): ",a1.nomeCitta ,a1.nomeAeroporto);


    while(true){
        if (array[i] != 9999 && array[i] != 0){
            min = findMin(array,n);

            if(array[min] != 9999    ){
                a1= findAeroportoIndex(min,list);

                 if(a1.index != src)
                    printf("\t%s (%s) Costo volo:%d \t",a1.nomeCitta,a1.nomeAeroporto,array[min]);

                    int * tmp = (int*)calloc(sizeof(int),20);
                    tmp=findScali(prev, min, tmp,0);

                    int j=0;
                     if(a1.index != src)
                          printf("SCALI: ");
                    while(tmp[j]!=0){
                        a1= findAeroportoIndex(tmp[j],list);

                        printf("%s->", a1.nomeAeroporto);
                        j++;
                    }
                    if(j == 0 && a1.index != src )
                        printf("Non presenti");


                    free(tmp);
                    array[min]=9999;
                    printf("\n\n");

            }else{
                break;
            }
        }
        i++;
    }

    printf("\n\n");
}




