#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void createEdgeFromFile(Graph graph, List head){
    FILE * file_aeroporti;
    file_aeroporti = fopen("archi.txt", "r");

    char buff[100];
    Aeroporto src, dest;
    int prezzo, tempo;

    char read_line[150];

    if(!file_aeroporti){
        printf("Errore nell'apertura del file archi.txt\n");
        return -1;
    }



    while(fgets(read_line,150,file_aeroporti)!=NULL){
        //Controllo il contenuto di ogni riga e rimuovo un determinato prefisso
        if(strstr(read_line,"@partenza")){
            strcpy(buff,strremove(read_line,"@partenza "));
            src = findAeroporto(head, buff);
            if(src.index == -1){
                printf("Aeroporto non esiste");
                return;
            }
        }

        if(strstr(read_line,"@destinazione")){
            strcpy(buff,strremove(read_line,"@destinazione "));
            dest = findAeroporto(head, buff);
            if(dest.index == -1){
                printf("Aeroporto non esiste");
                return;
            }

        }
         if(strstr(read_line,"@prezzo")){
            strcpy(buff,strremove(read_line,"@prezzo "));
            prezzo = atoi(buff);
        }
         if(strstr(read_line,"@tempo")){
            strcpy(buff,strremove(read_line,"@tempo "));
            tempo = atoi(buff);
            addEdge(graph, src, dest, prezzo, tempo);
        }

    }

}


List initNodeListFromFile(){
      FILE * file_aeroporti;
    file_aeroporti = fopen("Aeroporti.txt", "r");

    List head = NULL;
    Aeroporto aeroporto;

    char read_line[150];

    if(!file_aeroporti){
        printf("Errore nell'apertura del file\n");
        return -1;
    }



    while(fgets(read_line,150,file_aeroporti)!=NULL){
        //Controllo il contenuto di ogni riga e rimuovo un determinato prefisso
        if(strstr(read_line,"@nomeAeroporto"))
            strcpy(aeroporto.nomeAeroporto,strremove(read_line,"@nomeAeroporto "));


        if(strstr(read_line,"@nomeCitta"))
            strcpy(aeroporto.nomeCitta,strremove(read_line,"@nomeCitta "));

        if(strstr(read_line,"@popolarita"))
            aeroporto.popolarita=atoi(strremove(read_line,"@popolarita"));

        if(strstr(read_line,"@costoVita")){
            aeroporto.costoVita=atoi(strremove(read_line,"@costoVita"));

        }
        if(strstr(read_line,"@index")){
            aeroporto.index = atoi(strremove(read_line, "@index"));
             head=insertList(head,aeroporto);
        }
    }
    return head;

}


//!!! Funzione da implementare !!!
bool updateCampoFile(char* nomeCampo, int nuovoValore){
    FILE *source, *target;
    char buff[100];
    int local_value;


    source = fopen("archi.txt", "r");
     if (source == NULL){
        printf("Apertura del file log.txt in lettura e' fallita");
        return;
    }
    else{
       target = fopen("archiTMP.txt", "w+");

       if(target == NULL){
            printf("Apertura del file new_log.txt in scrittura e' fallita");
            return;
       }
       else{
            while(!feof(source)){
                fscanf(source, "%s %d", &buff, &local_value);
                if(!strcmp(buff, nomeCampo)){
                    fprintf(target, "%s %d\n", buff, nuovoValore);
                }
                 else if(!strcmp(buff, "END_OF_FILE")){ // \n dopo l'ultimo elemento causa la rilettura dell'ultimo campo nel nuovo file e di conseguenza la riscrittura del ultimo elemento nel utilizzo successivo
                    fprintf(target, "%s %d", buff, local_value);
                }
                else{
                    fprintf(target, "%s %d\n", buff, local_value);
                }

            }
            fclose(target);
       }
       fclose(source);
    }


    if(remove("log.txt") == 0){

    }
    else{
        printf("Impossibile eliminare il file\n");
    }

    if(rename("log1.txt", "log.txt") == 0){

    }
    else{
        printf("Impossibile rinominare il nome del file\n");
    }

}

bool updateFileArchi(Graph graph){
    FILE *file_archi;
    file_archi = fopen("archi2.txt", "w");
    int i;
    char tmp[16];
    fflush(stdin);



   if(!file_archi){
        printf("Errore nell'apertura del file");
        return -1;
    }



    for(i = 0; i< graph->numeroAeroporti; i++){
        List pCrawl = graph->adjList[i];
       // strcpy(tmp, pCrawl->aeroporto.nomeAeroporto);
        //printf("Tmp:%s\nNome aeroporto:%s\n", tmp, pCrawl->aeroporto.nomeAeroporto);
        //pCrawl = pCrawl->next;
        while(pCrawl){
           // fprintf(file_archi,"%s\n" ,   concatenation("@partenza ", tmp));
           fprintf(file_archi," %s ", "ciao");
           // fprintf(file_archi,"%s\n" ,   concatenation("@partenza ", pCrawl->aeroporto.nomeAeroporto));
            pCrawl = pCrawl->next;
         //   fprintf(file_archi, "%d", 250);
            printf("DEBUG\n");
        }


    }
}
