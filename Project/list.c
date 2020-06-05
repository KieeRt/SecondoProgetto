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







List freeList(List L) {
    if (L != NULL) {
        freeList(L->next);
        free(L);
        L = NULL;
    }
    return L;
}



List removeNodeList(List L, int target){
    if (L != NULL) {
        if (L->aeroporto.index == target) {
            List tmp = L->next;
            free(L);
            L = NULL;
            return tmp;
        }
        L->next = removeNodeList(L->next, target);
    }
    return L;

}
List updateNodeListIndex(List L, int numeroAeroporti){
    int i;
    List tmp = L;
    for(i = 0; i < numeroAeroporti; i++){
        L->aeroporto.index = i;
        L = L->next;
    }
    return tmp;
}
List updateNodeListIndexR(List L, int numero){
    List tmp = L;
    if(L != NULL){
        L->next = updateNodeListIndexR(L->next, numero+1);
        L->aeroporto.index = numero;
    }
    return L;
}





void MergeSort(List* headRef){
    List head = *headRef;
    List a;
    List b;

    if((head == NULL) || (head->next == NULL)){
        return;
    }
    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMergePopular(a,b);

}

List SortedMergePopular(List a, List b){
    List result = NULL;

    if(a == NULL)
        return (b);
    else if(b == NULL)
        return (a);

    if(a->aeroporto.popolarita <= b->aeroporto.popolarita){
        result = a;
        result->next = SortedMergePopular(a->next, b);
    }
    else{
        result = b;
        result->next = SortedMergePopular(a, b->next);
    }
    return result;
}

void FrontBackSplit(List source, List* frontRef, List* backRef){
    List fast;
    List slow;
    slow = source;
    fast = source->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}



