#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

List createNode(Aeroporto aeroporto){
    List newNode = (List) malloc (sizeof(struct TList));
    newNode->aeroporto = aeroporto;
    newNode->next = NULL;
    return newNode;
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



List insertList(List head, Aeroporto aeroporto) {

    //Creo il nodo se la lista è vuota
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
            printf("Errore, probabilmente la memoria non e' sufficente");
            return newNode;
    }
    newNode->aeroporto=aeroporto;

    //Controllo se il nodo dovrebbe essere posto prima della testa

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



        printf("-Nome aeroporto %s\n", list->aeroporto.nomeAeroporto);
        printf("-Nome citta %s\n", list->aeroporto.nomeCitta);
        printf("-Popolarita  %d\n", list->aeroporto.popolarita);
        printf("-Costo della vita %d\n\n", list->aeroporto.costoVita);

        printAereoporto(list->next);
    }


}


