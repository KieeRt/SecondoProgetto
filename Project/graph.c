#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "list.h"


Graph createGraph(int numeroAeroporti){
    Graph graph = (Graph)malloc(sizeof(struct TGraph));
    graph->numeroAeroporti = numeroAeroporti;

    graph->adjList = malloc(numeroAeroporti * sizeof(struct TList*));

    int i;

    for(i = 0;i<numeroAeroporti; i++){
       graph->adjList[i] = NULL;
    }

    return graph;
}

bool addEdge(Graph graph, Aeroporto s, Aeroporto d, int prezzo, int tempo){
    bool result = false;
  // Add edge from s to d
    if(checkEdge(graph,s,d)){
        List newNode = createNode(d);
        newNode->next =  graph->adjList[s.index];
        newNode->prezzo = prezzo;
        newNode->tempo = tempo;
        graph->adjList[s.index] = newNode;
        result = true;

    }
    return result;

}
bool checkEdge(Graph graph ,Aeroporto a1, Aeroporto a2){
    bool find = true;
    int i;
    if(a1.index == a2.index){ // controlla nodo cappio
        printf("Non puoi collegare un aeroporto con se stesso\n");
        return false;
    }
    //Controllo che i vertici facciano parte del grafo
    if(a1.index >= graph->numeroAeroporti || a2.index >= graph->numeroAeroporti){
        printf("Non e' possibile aggiungere questa tratta (Out of range)\n");
        return false;
    }

    //Controllo se esiste gia l'arco
    List pCrawl = graph->adjList[a1.index];
    while(pCrawl){
        if(pCrawl->aeroporto.index == a2.index){
            printf("Collegamento gia presente\n");
            find = false;
            break;
        }
        pCrawl= pCrawl->next;
    }
    return find;
}



void printGraphX(Graph graph){
   // List aeroporto = initFromFile();

    int v;
    for(v = 0; v < graph->numeroAeroporti; v++){

        List tmp = graph->adjList[v];
        printf("\n Vertice: %d\n",  v);
      //  aeroporto = aeroporto->next;
        while(tmp){
            printf("%s(%d) -> ", tmp->aeroporto.nomeAeroporto, tmp->tempo);
            tmp = tmp->next;
        }
    }
}



int* findoutDegree(Graph graph){
    int v;
    int* degree;
    degree = (int*)calloc(sizeof(int) , (graph->numeroAeroporti));

    if(graph==NULL)
        printf("Inserire un grafo valido\n");
    else


    for (v = 0; v < graph->numeroAeroporti; ++v){
        List pCrawl = graph->adjList[v];

        while (pCrawl){
            degree[v]++;
            pCrawl = pCrawl->next;
        }
    }
    return degree;
}

int* findDegree(Graph graph){
    int v;
    int* degree;
    degree = (int*)calloc(sizeof(int) , (graph->numeroAeroporti));


    if(graph==NULL)
        printf("Inserire un grafo valido\n");
    else
    for (v = 0; v < graph->numeroAeroporti; ++v){
        List pCrawl = graph->adjList[v];

        while (pCrawl){
            degree[pCrawl->aeroporto.index]++;
            pCrawl = pCrawl->next;
        }
    }
    return degree;
}

bool isPozzo(Graph  graph,Aeroporto a1){
    int* gu = findoutDegree(graph);
    int * ge = findDegree(graph);
    bool find = false;

    if(ge[a1.index]== graph->numeroAeroporti-1 && gu[a1.index]== 0)
        find = true;

    return find;
}


/*
Graph initGraph(){
    int i;
    Graph G = (Graph)malloc(sizeof(struct TGraph));
    List list = initNodeListFromFile();
    int node_number = numeroAeroporto(list);

    G->adj = (List*)malloc(node_number*sizeof(List));
    G->numeroAeroporti=node_number;

    for(i=0;i<node_number;i++){
        G->adj[i]=list;
        list = list->next;

    }


    return G;
}



void printGraph(Graph  graph){
    int i;
    List e;
    List a = initNodeListFromFile();
    if(graph != NULL){
        for (i=0;i<graph->numeroAeroporti;i++){



            printf("nodi adiacenti al nodo %s->",a->aeroporto.nomeCitta);
            a= a->next;
            e=graph->adj[i];
            while(e!=NULL){
                printf("%s ",e->aeroporto.nomeAeroporto);
                e=e->next;
            }
            printf("\n\n");
        }



    }



}


*/
