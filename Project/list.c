#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"



List initNodeListFromFile(){
      FILE * file_libri;
    file_libri = fopen("Aeroporti.txt", "r");

    List head = NULL;
    Aeroporto aeroporto;

    char read_line[150];

    if(!file_libri){
        printf("Errore nell'apertura del file\n");
        return -1;
    }



    while(fgets(read_line,150,file_libri)!=NULL){
        //Controllo il contenuto di ogni riga e rimuovo un determinato prefisso
        if(strstr(read_line,"@nomeAeroporto"))
            strcpy(aeroporto.nomeAeroporto,strremove(read_line,"@nomeAeroporto "));


        if(strstr(read_line,"@nomeCitta"))
            strcpy(aeroporto.nomeCitta,strremove(read_line,"@nomeCitta "));

        if(strstr(read_line,"@popolarita"))
            aeroporto.popolarita=atoi(strremove(read_line,"@popolarita"));

        if(strstr(read_line,"@costoVita")){
            aeroporto.costoVita=atoi(strremove(read_line,"@costoVita"));
            head=insertList(head,aeroporto);
        }
    }
    return head;

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
    List newNode = (List) malloc (sizeof(struct TList));

    if(newNode==NULL){
            printf("Errore, probabilmetne la memoria non e' sufficente");
            return newNode;
    }
    newNode->aeroporto=aeroporto;

    //Controllo se il nodo dovrebbe essere posto prima della testa
    if(strcmp(head->aeroporto.nomeAeroporto,aeroporto.nomeAeroporto)>0){
        newNode->next=head;
        return newNode;

    }

    List temp , prev;
    temp = head->next;
    prev=head;
    while(temp != NULL && strcmp(temp->aeroporto.nomeAeroporto,aeroporto.nomeAeroporto)>0) {
        prev = temp;
        temp = temp->next;
    }
    newNode->next = temp;
    prev->next = newNode;

    return head;
}


int numeroAeroporto(List list){
    int n=1;
    if(list->next!=NULL)
        n+=numeroAeroporto(list->next);
    return n;
}

void printAereoporto(List list) {


    if (list != NULL) {



        printf("-Nome aeroporto %s\n", list->aeroporto.nomeAeroporto);
        printf("-Nome citta %s\n", list->aeroporto.nomeCitta);
        printf("-Popolarita  %d\n", list->aeroporto.popolarita);
        printf("-Costo della vita %d\n\n", list->aeroporto.costoVita);

        printAereoporto(list->next);
    }


}


