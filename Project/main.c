#include <stdio.h>
#include <stdlib.h>
#include "Utente.h"
#include "list.h"
#include "graph.h"
#include "file.h"

int* findScali(int *prev,int part, int *tmp,int pos);

int main()
{
    List aeroportiList = initNodeListFromFile();
    Graph graph = createGraph(numeroAeroporto(aeroportiList));
    createEdgeFromFile(graph, aeroportiList);
//    List tmp = copyList(graph->adjList[0]);

  //  MergeSort(&tmp, 1);

    //printAereoporto(tmp);

   // welcome(graph,aeroportiList);
   printAllPaths(0,13, graph,aeroportiList);



    return 0;
}

//dfs modificata
void printAllPaths(int s, int d,Graph graph,List list){
    int *visited= (int*) calloc(sizeof(int),graph->numeroAeroporti);

    //Array per immagazinare i percorsi
    int *path = (int*) calloc(sizeof(int),graph->numeroAeroporti);
    int path_index = 0;

    printAllPathsUntil(s,d,visited,path,&path_index,graph,list);
}

void  printAllPathsUntil(int u, int d,int * visited,int *path,int *path_index,Graph graph,List list){
    Aeroporto a1;
    visited[u]=1;
    path[*path_index]= u;
    (*path_index)++;

    if( u == d){
        int i;


        for (i=0; i< *path_index;i++){
            a1=findAeroportoIndex(path[i],list);
            printf("->%s(%s)\n",a1.nomeAeroporto,a1.nomeCitta);
    }
    }else{
        List pCrawl = graph->adjList[u];
        while(pCrawl){

            if(!visited[pCrawl->aeroporto.index])
                printAllPathsUntil(pCrawl->aeroporto.index,d,visited,path,path_index,graph,list);
            pCrawl= pCrawl->next;
        }

    }
    (*path_index)--;
    visited[u]=0;

}



