#ifndef GRAPH__H_INCLUDED
#define GRAPH__H_INCLUDED
#include "list.h"

struct TGraph {
    List *adj;
    int numeroAeroporti;
};


typedef struct TGraph* Graph;

Graph initGraph();
void printGraph(Graph G);



#endif // GRAPH__H_INCLUDED
