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
    int scelta, scelta2, scelta3;
    List tmp = NULL;
    Aeroporto srcAeroporto;
    Aeroporto destAeroporto;
 //   int prev[20], dist[20],
    int *prev = (int*)malloc(sizeof(int)* 20);
    int *dist = (int*)malloc(sizeof(int)* 20);
    int **matrix;
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
        printf("4 - Visualizza meta piu' gettonata\n"); // A partire dal aeroporto di partenza
        printf("5 - Check-in volo\n");
        printf("6 - Logout\n");


        scelta=doSceltaInt("Input -> ", 6);

        switch(scelta){


        case 1:
           system("cls");
           if(ListaPrenotazioni){
                stampaPrenotazione(ListaPrenotazioni);
           }
           else{
                printf("Non ci sono ancora prenotazioni attive\n");
           }



            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin

        break;
        case 2:
            system("cls");
            printf("Lista tratte disponibili:\n");
            printAereoportoCollegamenti(graph, aeroporti);
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
                if(matrix[0][0] != -1){
                        scelta2 = doSceltaIntZeroError("Scegliere la tratta(0 per uscire) \nInput -> ", count, "Input non valido\n");
                    if(scelta2 !=  0){
                        if (utente.punti > 0 ){
                            printf("Lei ha a disposizione %d punti \n", utente.punti);
                            fflush(stdin);
                            scelta3 = doSceltaIntZeroError("Vorrebbe usarli per il viaggio?(0 per uscire) \n 1-No\n 2-Si\nInput-> ", 2, "Input non valido\n");
                            if(scelta3 != 0){
                                if(scelta3 == 1){
                                    ListaPrenotazioni = addPrenotazione(ListaPrenotazioni, matrix[--scelta2], aeroporti, graph,&utente.punti,false);
                                }
                                else{
                                    ListaPrenotazioni = addPrenotazione(ListaPrenotazioni, matrix[--scelta2], aeroporti, graph,&utente.punti,true);
                                }
                            }
                        }
                        else{
                            ListaPrenotazioni = addPrenotazione(ListaPrenotazioni, matrix[--scelta2], aeroporti, graph,&utente.punti,false);
                        }
                        printf("Prenotazione avvenuta con successo.\n");
                       // stampaPrenotazione(ListaPrenotazioni);

                    }
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
            scelta2 = -2;
         do{
                strcpy(srcAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di partenza(0 se si vuole uscire)\nInput -> ", "Input non valido\n",0, 1, 3));
                    if(!strcmp(srcAeroporto.nomeAeroporto,"0")){
                        scelta2 = -1;
                        break;
                    }

                        upperCase(srcAeroporto.nomeAeroporto);
                        srcAeroporto = findAeroporto(aeroporti,srcAeroporto.nomeAeroporto);

                }while(srcAeroporto.index == -1);

                if(scelta2 != -1){
                    shortestPathPrice(graph,&dist,&prev,srcAeroporto.index,aeroporti);
                    printOrder(dist,graph->numeroAeroporti,aeroporti,prev,srcAeroporto.index);
                }


                fflush(stdin);
                printf("\nPremi invio per tornare al menu precedente\n");
                while(getchar()!='\n'); // option TWO to clean stdin

            break;
        case 4:
            printf("Lista aeroporti disponibili:\n");
            printAereoporto(aeroporti);
            scelta2 = -2;
            do{
                strcpy(srcAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di partenza(0 se si vuole uscire)\nInput -> ", "Input non valido\n",0, 1, 3));
                    if(!strcmp(srcAeroporto.nomeAeroporto,"0")){
                        scelta2 = -1;
                         break;
                    }

                        upperCase(srcAeroporto.nomeAeroporto);
                        srcAeroporto = findAeroporto(aeroporti,srcAeroporto.nomeAeroporto);

            }while(srcAeroporto.index == -1);

            if(scelta2 != -1){
                tmp = copyList(graph->adjList[srcAeroporto.index]);
                MergeSort(&tmp, 1);
                printf("\nLista di mete piu' gettonate a partire dal aeroporto di %s\n\n", srcAeroporto.nomeCitta);
                printAereoportoPrice(tmp);
            }

            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin

            //TODO prenotazione!!!

            break;
        case 5:
            scelta2 = -2;
            system("cls");
           stampaPrenotazione(ListaPrenotazioni);
        //   int numeroPrenotazioni = numberPrenotazioni(ListaPrenotazioni);
            if(ListaPrenotazioni){
             do{
                   scelta2 = doSceltaIntZero("-Inserire il Codice Prenotazione \nInput -> ", 100);
                    if(scelta2 == 0){
                        break;
                    }

                }while(!confermaVolo(&ListaPrenotazioni, scelta2));
            }
            else{
                printf("-Utente non ha nessun volo prenotato\n");
            }
            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin
            break;
        case 6:
            system("cls");
            writePrenotezioniFile(utente.codiceFiscale,  ListaPrenotazioni);
            updateUserOnFile(utente);
            updateFileAeroporti(aeroporti);

            fflush(stdin);
            printf("Grazie per aver usato il nostro servizio, arrividerci (Premi invsio per uscire)\n");
            while(getchar()!='\n'); // option TWO to clean stdin
        break;

        default:
            printf("\n\n\tScelta non valida\n");
        }

    }while(scelta!=6);


}

void homeAdmin(User utente,Graph graph, List aeroporti){
 int scelta, scelta2 = 0;
    Aeroporto srcAeroporto;
    Aeroporto destAeroporto;
    double  prezzo = 0;
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
            if(srcAeroporto.index == -1)
                break;

            printf("Aeroporto e' stato inserito con successo\n\n");
            srcAeroporto.index = graph->numeroAeroporti;
            graph=addAeroporto(aeroporti,graph,srcAeroporto);

            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin




        break;
        case 2:
            scelta2 = -2;
            printf("Lista aeroporti disponibili:\n");
            printAereoporto(aeroporti);

            do{
                strcpy(srcAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di partenza(0 se si vuole uscire)\nInput -> ", "Input non valido\n", 0, 1, 3));
                if(!strcmp(srcAeroporto.nomeAeroporto,"0")){
                    scelta2 = -1;
                    break;
                }

                upperCase(srcAeroporto.nomeAeroporto);
                srcAeroporto = findAeroporto(aeroporti,srcAeroporto.nomeAeroporto);


                strcpy(destAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di arrivo(0 se si vuole uscire)\nInput -> ", "Input non valido\n", 0, 1, 3));
               if(!strcmp(destAeroporto.nomeAeroporto,"0")){
                    scelta2 = -1;
                    break;
                }
                upperCase(destAeroporto.nomeAeroporto);
                destAeroporto = findAeroporto(aeroporti,destAeroporto.nomeAeroporto);
                if(!strcmp(destAeroporto.nomeAeroporto,"0")){
                    scelta2 = -1;
                    break;
                }

                prezzo = doSceltaDoubleZero("-Inserire prezzo volo\nInput -> ",50000);
                if(prezzo == 0.0)
                    break;

                tempo = doSceltaIntZero("-Inserire durata volo(minuti)\nInput -> ",1500);
                if(tempo == 0){
                    scelta2 = -1;
                    break;
                }

            }while(!addEdge(graph,srcAeroporto,destAeroporto,prezzo,tempo));

            if(scelta2 != -1){
                printf("La tratta e' stata aggiunta con successo\n");
            }
            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin

        break;

        case 3:
            scelta2=-2;
            printf("Lista aeroporti disponibili:\n");
            printAereoporto(aeroporti);

            do{

                strcpy(srcAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATa dell'aeroporto da rimuovere(0 se si vuole uscire)\nInput -> ", "Input non valido\n",0, 1, 3));
                if(!strcmp(srcAeroporto.nomeAeroporto,"0")){
                    scelta2 =-1;
                    break;
                }
                upperCase(srcAeroporto.nomeAeroporto);
                srcAeroporto = findAeroporto(aeroporti,srcAeroporto.nomeAeroporto);

            }while(!removeNode(graph, srcAeroporto.index));

            if(scelta2!=-1){
                aeroporti= removeNodeList(aeroporti,srcAeroporto.index);
                aeroporti= updateNodeListIndexR(aeroporti,0);
                updatePrenotazioniFile(srcAeroporto.index,srcAeroporto.index,aeroporti);
            }

            fflush(stdin);
            printf("\nPremi invio per tornare al menu precedente\n");
            while(getchar()!='\n'); // option TWO to clean stdin

            break;
        case 4:
            printf("-Collegamenti disponibili\n");
            printAereoportoCollegamenti(graph, aeroporti);


             do{
                strcpy(srcAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di partenza(0 se si vuole uscire)\nInput -> ", "Input non valido\n", 0, 1, 3));
                if(!strcmp(srcAeroporto.nomeAeroporto,"0")){
                scelta2 = -1;
                    break;
                }
                upperCase(srcAeroporto.nomeAeroporto);
                srcAeroporto = findAeroporto(aeroporti,srcAeroporto.nomeAeroporto);


                strcpy(destAeroporto.nomeAeroporto, doSceltaStringError("-Inserire codice IATA dell'aeroporto di arrivo(0 se si vuole uscire)\nInput -> ", "Input non valido\n", 0, 1, 3));

                if(!strcmp(destAeroporto.nomeAeroporto,"0")){
                scelta2 = -1;
                    break;
                }
                upperCase(destAeroporto.nomeAeroporto);
                destAeroporto = findAeroporto(aeroporti,destAeroporto.nomeAeroporto);

                if(!strcmp(destAeroporto.nomeAeroporto,"0")){
                scelta2 = -1;
                    break;
                }

            }while(!isDeletedEdge(graph, srcAeroporto.index, destAeroporto.index));
            if(scelta2 != -1){

                updatePrenotazioniFile(srcAeroporto.index, destAeroporto.index, aeroporti);

            }

            //Controllo se e' stata effettuata la cancellazione, se si recupero indici srcAeroporto.index e destAeroporto.index
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

            //printGraph(graph);
            updateFileAeroporti(aeroporti);
            updateFileArchi(graph,aeroporti);
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




