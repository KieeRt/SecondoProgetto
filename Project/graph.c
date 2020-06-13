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

bool addEdge(Graph graph, Aeroporto s, Aeroporto d, double prezzo, int tempo){
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
        printf("Uno degli aeroporti non è stato trovato\n");
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


    int v;

    for(v = 0; v < graph->numeroAeroporti; v++){
        int i = 0;
        List tmp = graph->adjList[v];

      printf("\n Aeroporto partenza:%s\n",  aeroporti->aeroporto.nomeAeroporto);
      aeroporti = aeroporti->next;
        while(tmp){
        i++;
            printf("\tCollegamento %d:\n", i);
            printf("\t%s(%s)\n",  tmp->aeroporto.nomeCitta, tmp->aeroporto.nomeAeroporto);
            printf("\tPrezzo: %.2lf\n",  tmp->prezzo);
            printf("\tTempo: ");
            printTimeVolo(tmp->tempo);
            printf("\n");

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

bool isDeletedEdge(Graph graph, int src, int dest){
    bool find = false;
    Aeroporto support;

    if(src != -1 && dest != -1){

        support = findAeroportoIndex(dest, graph->adjList[src]); //perche dalla lista di adiacenza

        if(support.index != -1){
            find = true;
            graph->adjList[src] = deleteEdge(graph, src, dest);
            printf("Collegamento cancellato\n");
        }
        else{
            printf("Collegamento non trovato\n");
        }


    }
    else{
        printf("Collegamento non trovato\n");
    }

    return find;

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


void shortestPathTime(Graph g, int *dist, int *prev, int start, List list) {
   int n = g->numeroAeroporti;
    int alt;
    //Initialize distance's array
    for(int u = 0; u<n; u++) {
        dist[u] = 9999;   //set as infinity
        prev[u] = -1;    //undefined previous
    }

    dist[start] = 0;   //distance of start is 0

    Queue queue = initQueue();

    //Add each vertex to queue
    int i =0;
    for (i =0 ; i< g->numeroAeroporti;i++){
        enqueue(queue, list->aeroporto.index);
        list = list->next;
    }


    while(!emptyQueue(queue)){
        //find min in queue
        int u = dequeue(queue);

        List pCrawl = g->adjList[u];

        while(pCrawl){

            alt = dist[u] + pCrawl->tempo;

            if(alt < dist[pCrawl->aeroporto.index]){

                dist[pCrawl->aeroporto.index] = alt;
                prev[pCrawl->aeroporto.index] = u;
            }
            pCrawl= pCrawl->next;
        }

    }
}



void shortestPathPrice(Graph g, int *dist, int *prev, int start, List list) {
   int n = g->numeroAeroporti;
    int alt;
    //Initialize distance's array
    for(int u = 0; u<n; u++) {
        dist[u] = 9999;   //set as infinity
        prev[u] = -1;    //undefined previous
    }

    dist[start] = 0;   //distance of start is 0

    Queue queue = initQueue();

    //Add each vertex to queue
    int i =0;
    for (i =0 ; i< g->numeroAeroporti;i++){
        enqueue(queue, list->aeroporto.index);
        list = list->next;
    }


    while(!emptyQueue(queue)){
        //find min in queue
        int u = dequeue(queue);

        List pCrawl = g->adjList[u];

        while(pCrawl){

            alt = dist[u] + pCrawl->prezzo;

            if(alt < dist[pCrawl->aeroporto.index]){

                dist[pCrawl->aeroporto.index] = alt;
                prev[pCrawl->aeroporto.index] = u;
            }
            pCrawl= pCrawl->next;
        }

    }
}


int** printAllPaths(int s, int d,Graph graph,List list){
    int *visited= (int*) calloc(sizeof(int),graph->numeroAeroporti);
    int i, j, sumCosto = 0, sumTempo =0, count = 1;
    Aeroporto aeroporto;
    //Array per immagazinare i percorsi
    int *path = (int*) calloc(sizeof(int),graph->numeroAeroporti);
    int path_index = 0;

    int** matrix = (int**)malloc(20*sizeof(int*));
    for(int i = 0; i < 20; i++){
        matrix[i] = (int*)malloc(10*sizeof(int));
    }
    for(i = 0; i < 20; i++){
    for(j = 0; j < 10; j++){
            matrix[i][j] = -1;
        }
    }


    printAllPathsUntil(s,d,visited,path,&path_index,graph,list,matrix);

    if(matrix[0][0] == -1){
        printf("La tratta non e'disponibile\n");
    }



   for(i = 0; i < 20; i++){
        for(j = 0; j < 10; j++){
            if(matrix[i][j] != -1){
                    if(matrix[i][j] == s){
                        sumCosto = CostoVolo(graph, matrix[i]);
                        sumTempo = TempoVolo(graph, matrix[i]);
                        aeroporto = findAeroportoIndex(matrix[i][j], list);
                        printf("%d - %s(%s):%d euro ",count, aeroporto.nomeAeroporto,aeroporto.nomeCitta, sumCosto);
                        printTimeVolo(sumTempo);
                        count++;
                    }else {
                        if(j==1){
                            aeroporto = findAeroportoIndex(matrix[i][j], list);
                            printf("\t%s(%s)->",aeroporto.nomeAeroporto,aeroporto.nomeCitta);
                    } else {
                        aeroporto = findAeroportoIndex(matrix[i][j], list);
                        printf("%s(%s)->",aeroporto.nomeAeroporto,aeroporto.nomeCitta);
                    }
            }
        }

    }
     if(matrix[i][0] != -1)
            printf("\n\n");
   }

   return matrix;
}

void printAllPathsUntil(int u, int d,int * visited,int *path,int *path_index,Graph graph,List list,int** matrix){
    Aeroporto a1;
    visited[u]=1;
    path[*path_index]= u;
    (*path_index)++;

    if( u == d){
        int i = 0;
        while(matrix[i][0] != -1){
           i++;
            }
           copyArray(&matrix[i], path, *path_index);

    }else{
        List pCrawl = graph->adjList[u];
        while(pCrawl){

            if(!visited[pCrawl->aeroporto.index])
                printAllPathsUntil(pCrawl->aeroporto.index,d,visited,path,path_index,graph,list,matrix);
            pCrawl= pCrawl->next;
        }

    }
    (*path_index)--;
    visited[u]=0;

}
