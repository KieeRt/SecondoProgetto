#ifndef GRAPH__H_INCLUDED
#define GRAPH__H_INCLUDED
#include "list.h"

struct TGraph {
    List *adjList;
    int numeroAeroporti;
};

struct TEdge{
    int src, dest;
    int peso, prezzo;
};


typedef struct TGraph* Graph;

Graph createGraph(int numeroAeroporto);
void addEdge(Graph graph, Aeroporto s, Aeroporto d);
void printGraphX(Graph graph);
/*
Graph initGraph();
void printGraph(Graph G);*/



#endif // GRAPH__H_INCLUDED
