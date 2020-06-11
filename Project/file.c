#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void createEdgeFromFile(Graph graph, List head){
    FILE * file_aeroporti;
    file_aeroporti = fopen("archi.txt", "r");

    char buff[100];
    Aeroporto src, dest;
    double prezzo;
    int tempo;

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
            prezzo = atof(buff);
        }
         if(strstr(read_line,"@tempo")){
            strcpy(buff,strremove(read_line,"@tempo "));
            tempo = atoi(buff);
            addEdge(graph, src, dest, prezzo, tempo);
        }

    }
    fclose(file_aeroporti);

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
    fclose(file_aeroporti);
    return head;

}

bool updateFileArchi(Graph graph, List aeroporti){

    FILE *file_archi;
    file_archi = fopen("archi.txt", "w");
    fflush(stdin);
    Aeroporto support;


   if(!file_archi){
        printf("Errore nell'apertura del file");
        return -1;
    }
    int v;
    for(v = 0; v < graph->numeroAeroporti; v++){

    List tmp = graph->adjList[v];

        if(tmp != NULL){
                support = findAeroportoIndex(v, aeroporti);
                if(support.index != -1)
                    printf("Aeroporto trovato:%s\n", support.nomeAeroporto);
                else{
                    printf("Error aeroporto non trovato\n");
                    exit(0);
                }

            while(tmp){
                fprintf(file_archi, "%s\n", concatenation("@partenza ", support.nomeAeroporto));
                fprintf(file_archi, "%s\n", concatenation("@destinazione ", tmp->aeroporto.nomeAeroporto));

                fprintf(file_archi, "%s ", "@prezzo");
                fprintf(file_archi, "%.2lf\n", tmp->prezzo);
                fprintf(file_archi, "%s ", "@tempo");
                fprintf(file_archi, "%d\n", tmp->tempo);

                tmp = tmp->next;
            }
            aeroporti = aeroporti->next;
        }
    }
}



void updateFileAeroporti(List aeroporti){
    FILE *file_aeroporti;
    file_aeroporti = fopen("Aeroporti.txt", "w");
    fflush(stdin);
    char tmp[256];


   if(!file_aeroporti){
        printf("Errore nell'apertura del file");
        return -1;
    }

    while(aeroporti){
        fprintf(file_aeroporti, "%s\n", concatenation("@nomeAeroporto ", aeroporti->aeroporto.nomeAeroporto));
        fprintf(file_aeroporti, "%s\n", concatenation("@nomeCitta ", aeroporti->aeroporto.nomeCitta));
        fprintf(file_aeroporti, "%s", "@popolarita ");
        fprintf(file_aeroporti, "%d\n",aeroporti->aeroporto.popolarita );
        fprintf(file_aeroporti,"%s", "@costoVita ");
        fprintf(file_aeroporti, "%d\n",aeroporti->aeroporto.costoVita );
        fprintf(file_aeroporti, "%s", "@index ");
        fprintf(file_aeroporti, "%d\n",aeroporti->aeroporto.index );
        aeroporti =  aeroporti->next;
    }

}
