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
//Ritorna l'aeroporto ricercato o uno fake se questo non esiste
Aeroporto findAeroporto(List lista, char* nomeCode);


/*
Graph initGraph();
void printGraph(Graph G);*/



#endif // GRAPH__H_INCLUDED
