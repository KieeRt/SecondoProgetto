#ifndef GRAPH__H_INCLUDED
#define GRAPH__H_INCLUDED
#include "list.h"
#include <stdbool.h>
#include "queue.h"
struct TGraph {
    List *adjList;
    int numeroAeroporti;
};


typedef struct TGraph* Graph;

Graph createGraph(int numeroAeroporto);

bool addEdge(Graph graph, Aeroporto s, Aeroporto d, int prezzo, int tempo);

void printGraph(Graph graph);

void printAereoportoCollegamenti(Graph graph, List aeroporti);

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

bool removeNode(Graph graph, int node_to_remove);

List checkListRemoval(List L, int node_to_remove);

List deleteEdge(Graph graph, int src, int dest);

bool isDeletedEdge(Graph graph, int src, int dest);

void shortestPathPrice(Graph g, int *dist, int *prev, int start, List list);

void shortestPathTime(Graph g, int *dist, int *prev, int start, List list);




#endif // GRAPH__H_INCLUDED
