#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "Aeroporto.h"

struct TList{
    Aeroporto aeroporto;
    int prezzo;
    int tempo;
    struct TList* next;
};
typedef struct TList* List;


List createNode(Aeroporto aeroporto);


List initNodeList(Aeroporto aeroporto);
//Ritorna l'aeroporto ricercato o uno fake se questo non esiste
Aeroporto findAeroporto(List lista, char* nomeCode);
//Ritorna l'aeroporto ricercato o uno fake in base all'indice
Aeroporto findAeroportoIndex(int v, List aeroporti);

//Ritorna la città ricercato o un fake che avrà indice -1
Aeroporto findCitta(List lista, char* nomeCitta);

void printAereoportoPrice(List list);

//Rimuove un elemento dalla lista
List removeNodeList(List L, int target);
//Aggiorna il campo index della lista che contiene tutti gli aeroporti
List updateNodeListIndex(List L, int numeroAeroporti);
//Aggiorna il campo index della lista che contiene tutti gli aeroporti in modo ricorsivo
List updateNodeListIndexR(List L, int numeroAeroporti);
List insertList(List head, Aeroporto aereoporto);
void printAereoporto(List list);
int numeroAeroporto(List list);
List freeList(List L);

//Funzioni per il mergeSort
void MergeSort(List* headRef, int modalita);
void FrontBackSplit(List source, List* frontRef, List* backRef);
List SortedMergePopular(List a, List b);
List SortedMergePrice(List a, List b);

List copyList(List L);

#endif // LIST_H_INCLUDED
