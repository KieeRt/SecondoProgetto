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


void removeNode(Graph G, int node_to_remove) {
    if (G != NULL) {
        int i = 0;
        int x = 0;
        List *tmp = G->adjList;
        printf("NUMERO AEROPORTI:%d\n", G->numeroAeroporti);
        //Viene decrementato il numero di aeroporti
        G->adjList = (List *)calloc(G->numeroAeroporti -=1, sizeof(List));
        printf("Debug\n");
        for (i = 0; i < G->numeroAeroporti; i++) {
        printf("NUMERO AEROPORTI:%d\n", G->numeroAeroporti);
                printf("Debug2\n");
            if (i != node_to_remove) {
                printf("Debug3\n");
                printf("x:%d\n i:%d\n node_rm:%d\n", x, i, node_to_remove);
                G->adjList[i] = checkListRemoval(G->adjList[i], node_to_remove);
                //printf("x : %d %d\n", x, i);
                x++;
            } else
             {
                 printf("Debug4\n");
				//freeList(G->adj[x]);
               tmp[i] = freeList(tmp[i]);
                x++;
            }
        }
        printf("Debug5\n");

        //free(tmp);
    printf("Debug6\n");
    }
}

void removeNode2(Graph graph, int node_to_remove){
    int i;
    for(i = 0; i < graph->numeroAeroporti; i++){
        if(i == node_to_remove){
            graph->adjList[i] = freeList(graph->adjList[i]);
        }
        else{

              graph->adjList[i]  = checkListRemoval(graph->adjList[i] , node_to_remove);
        }
    }
    graph->numeroAeroporti -=1;
}

List checkListRemoval(List L, int node_to_remove) {

    if (L != NULL) {
        L->next = checkListRemoval(L->next, node_to_remove);
        if (L->aeroporto.index == node_to_remove) {
            List tmp = L->next;
            free(L);
            L = NULL;
            return tmp;
        }/*else if (L->aeroporto.index > node_to_remove) {
            L->aeroporto.index -= 1;
        }*/
    }
    return L;
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
