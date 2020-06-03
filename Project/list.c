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

    List tmp = head;
    while(tmp->next ){

        tmp = tmp->next;

    }

    tmp->next = newNode;

    newNode->aeroporto=aeroporto;
    newNode->next = NULL;
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
        printf("-Index %d\n\n", list->aeroporto.index);

        printAereoporto(list->next);
    }


}

Aeroporto findAeroporto(List lista, char* nomeCode){
Aeroporto fake = initAeroporto();
    if(lista){
        if(!strcmp(nomeCode, lista->aeroporto.nomeAeroporto)){
            return lista->aeroporto;
        }
       fake = findAeroporto(lista->next, nomeCode);
    }
    return fake;
}

Aeroporto findAeroportoIndex(int v, List aeroporti){
Aeroporto fake = initAeroporto();
    if(aeroporti){
        if(aeroporti->aeroporto.index == v){
            return aeroporti->aeroporto;
        }
       fake = findAeroportoIndex(v, aeroporti->next);
    }
    return fake;
}







void freeList(List L) {
    if (L != NULL) {
        freeList(L->next);
        free(L);
    }
}









