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

#endif // LIST_H_INCLUDED
