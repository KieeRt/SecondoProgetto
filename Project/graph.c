#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "list.h"
#include <assert.h>


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
    if(a1.index ==-1 && a2.index == -1){ // controlla nodo cappio
        printf("Aeroporti non esisteni\n");
        return false;
    }
    else if(a1.index == a2.index){ // controlla nodo cappio
        printf("Non puoi collegare un aeroporto con se stesso\n");
        return false;
    }
    //Controllo che i vertici facciano parte del grafo
    if(a1.index >= graph->numeroAeroporti || a2.index >= graph->numeroAeroporti){
        printf("Non e' possibile aggiungere questa tratta (Out of range)\n");
        return false;
    }
    //Controllo che i vertici facciano parte del grafo
    if(a1.index < 0 || a2.index < 0){
        printf("Uno degli aeroporti non � stato trovato\n");
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



void printGraph(Graph graph){
    int v;
    for(v = 0; v < graph->numeroAeroporti; v++){
      List tmp = graph->adjList[v];
      printf("\n Vertice: %d\n",  v);
        while(tmp){
            printf("%s(%d) -> ", tmp->aeroporto.nomeAeroporto, tmp->tempo);
            tmp = tmp->next;
        }
    }
}
void printAereoportoCollegamenti(Graph graph, List aeroporti){
Aeroporto partenza: Napoli


    Collegamento 1:
    Roma (FCO)
    prezzo
        tempo

Collegamento 2:

    int v;
    for(v = 0; v < graph->numeroAeroporti; v++){
      List tmp = graph->adjList[v];

      printf("\n Aeroporto partenza:%s\n",  aeroporti->aeroporto.nomeAeroporto);
      aeroporti = aeroporti->next;
        while(tmp){
            printf("\tCollegamento %d:\n%s(%s)\n", v, tmp->aeroporto.nomeCitta, tm tmp->tempo);
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




Graph  g_insert(Graph G) {
     List *e;
     if (G==NULL)
     return createGraph(20);
      e = realloc(G->adjList,(G->numeroAeroporti+1) *sizeof(List));
      if ((e == NULL))
          printf("ERRORE: impossibile reallocarememoria \n");
          else {
          G->adjList=e;
          G->adjList[G->numeroAeroporti]=NULL;
          G->numeroAeroporti= G->numeroAeroporti+1;
          }
            return(G);
}


Graph addAeroporto(List aeroporti, Graph g, Aeroporto aeroporto){

      if (findAeroporto(aeroporti, aeroporto.nomeAeroporto).index == -1){
            aeroporti = insertList(aeroporti, aeroporto);
           g =  g_insert(g);

      } else {
          printf("Aeroporto  gia presente %s\n", aeroporto);
      }
      return g;


}

List deleteEdge(Graph graph, int src, int dest){

    assert(graph != NULL);
    assert(src < graph->numeroAeroporti);
    assert(dest < graph->numeroAeroporti);

    if (src != dest) {
        graph->adjList[src] = removeNodeList(graph->adjList[src], dest);
    }
    return graph->adjList[src];
}




bool removeNode(Graph graph, int node_to_remove){
    int i;
    int x = 0;
    bool find = false;

    if(node_to_remove <= graph->numeroAeroporti-1 && node_to_remove >= 0){
        find = true;

        for(i = 0; i < graph->numeroAeroporti; i++){
            if(i == node_to_remove){
                graph->adjList[i] = freeList(graph->adjList[i]);
            }
            else{

                  graph->adjList[x]  = checkListRemoval(graph->adjList[i] , node_to_remove);
                x++;
            }
        }
        graph->numeroAeroporti -=1;
        printf("-Aeroporto e' stato eliminato\n");
    }
    else{
        printf("-Aeroporto non e' presente nella lista\n");
    }

    return find;
}

List checkListRemoval(List L, int node_to_remove) {

    if (L != NULL) {
        L->next = checkListRemoval(L->next, node_to_remove);
        if (L->aeroporto.index == node_to_remove) {
            List tmp = L->next;
            free(L);
            L = NULL;
            return tmp;
        }

    }
    return L;
}
