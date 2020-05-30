#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

List initNodeList(Aeroporto aeroporto){

}

List initNodeListFromFile(){
    FILE *fp;
    fp = fopen("Aeroporti.txt", "r");

    List lista = NULL;
    Aeroporto aeroporto = initAeroporto();
    char read_line[150];

    if(!fp){
        printf("Errore nell'apertura del file Aeroporti.txt\n");
        return -1;
    }

    while(fgets(read_line,150,fp)!=NULL){
        //Controllo il contenuto di ogni riga e rimuovo un determinato prefisso
        if(strstr(read_line,"@nomeAeroporto")){
            strcpy(aeroporto.nomeAeroporto,strremove(read_line,"@nomeAeroporto "));
            printf("%s\n",aeroporto.nomeAeroporto);
        }
        if(strstr(read_line,"@nomeCitta")){
            strcpy(aeroporto.nomeCitta,strremove(read_line,"@nomeCitta "));
            printf("%s\n",aeroporto.nomeCitta);
        }
        if(strstr(read_line,"@popolarita")){
           aeroporto.popolarita = atoi(strremove(read_line,"@popolarita "));
            printf("%d\n",aeroporto.popolarita);
        }
        if(strstr(read_line,"@costoVita")){
            aeroporto.costoVita = atoi(strremove(read_line,"@costoVita "));
            printf("%d\n",aeroporto.costoVita);
            lista = insertList(lista, aeroporto);

        }

    }

    return lista;
}


List insertList(List head, Aeroporto aeroporto) {

    //Creo il nodo se la lista � vuota
    if(head==NULL){
        head = (List) malloc (sizeof(struct TList));
        if(head==NULL){
            printf("Errore, probabilmetne la memoria non e' sufficente");
            return head;
        }
        head->aeroporto=aeroporto;
        head->next=NULL;
        return head;

    }

    //Se la lista non � vuota creo un nuovo nodo e decido dove metterlo
    List newNode =  (List) malloc (sizeof(struct TList));
    if(newNode==NULL){
            printf("Errore, probabilmetne la memoria non e' sufficente");
            return newNode;
    }
    newNode->aeroporto=aeroporto;

    newNode->next=head;
    return newNode;

}

int numeroAeroporto(List list){
    int n=1;
    if(list->next!=NULL)
        n+=numeroAeroporto(list->next);
    return n;
}

void printAereoporto(List list) {

    if (list != NULL) {
      //Necessario per una formattazione migliore del test
        printf("-nome ->%s\n",list->aeroporto.nomeAeroporto);
        printf("-citta ->%s\n",list->aeroporto.nomeCitta);
        printf("-popolarita ->%d\n",list->aeroporto.popolarita);
        printf("-costo ->%d\n\n\n",list->aeroporto.costoVita);

        printAereoporto(list->next);
    }
}


