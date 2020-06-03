#ifndef GRAPH__H_INCLUDED
#define GRAPH__H_INCLUDED
#include "list.h"
#include <stdbool.h>

struct TGraph {
    List *adjList;
    int numeroAeroporti;
};


typedef struct TGraph* Graph;

Graph createGraph(int numeroAeroporto);
bool addEdge(Graph graph, Aeroporto s, Aeroporto d, int prezzo, int tempo);
void printGraphX(Graph graph);
//Controlli sugli archi
bool checkEdge(Graph graph ,Aeroporto a1, Aeroporto a2);
//Grado entrante
int* findDegree(Graph graph);
//Grado uscente
int* findoutDegree(Graph graph);
//Controlla se il nodo associato all'aeroporto e' un nodo pozzo
bool isPozzo(Graph  graph,Aeroporto a1);

Graph addAeroporto(List aeroporti, Graph g, Aeroporto aeroporto);

Graph  g_insert(Graph G);
void removeNode(Graph G, int node_to_remove);
List checkListRemoval(List L, int node_to_remove);
/*
Graph initGraph();
void printGraph(Graph G);*/



#endif // GRAPH__H_INCLUDED
