#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "list.h"

Graph initGraph(){
    int i;
    Graph G = (Graph)malloc(sizeof(struct TGraph));
    List list = initNodeListFromFile();
    int node_number = numeroAeroporto(list);

    G->adj = (List*)malloc(node_number*sizeof(List));
    G->numeroAeroporti=node_number;

    for(i=0;i<node_number;i++){
        G->adj[i]=list;
        list->next;
    }
    printAereoporto(list);

    return G;
}



void printGraph(Graph  graph){
    int i;
    List e;
    if(graph != NULL){
        for (i=0;i<graph->numeroAeroporti;i++){

            printf("nodi adiacenti al nodo %d->",i);
            e=graph->adj[i];
            while(e!=NULL){
                printf("%s",e->aeroporto.nomeAeroporto);
                e=e->next;
            }
            printf("\n\n");
        }

    }

}
