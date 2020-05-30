#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "Aeroporto.h"
struct TList {
    Aeroporto aeroporto;
    struct TList* next;
};

typedef struct TList* List;

List initNodeList(Aeroporto aeroporto);
List initNodeListFromFile();
List insertList(List head, Aeroporto aereoporto);
void printAereoporto(List list);
int numeroAeroporto(List list);
#endif // LIST_H_INCLUDED
