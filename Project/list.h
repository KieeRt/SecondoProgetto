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

List insertList(List head, Aeroporto aereoporto);
void printAereoporto(List list);
int numeroAeroporto(List list);

#endif // LIST_H_INCLUDED
