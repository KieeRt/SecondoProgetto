#include <stdio.h>
#include <stdlib.h>
#include "Utente.h"
#include "list.h"
#include "graph.h"
#include "file.h"
#define GOD 0

int* findScali(int *prev,int part, int *tmp,int pos);
void printAllPaths(int s, int d,Graph graph,List list);
int*  printAllPathsUntil(int u, int d,int * visited,int *path,int *path_index,Graph graph,List list);
int main()
{
    List aeroportiList = initNodeListFromFile();
    Graph graph = createGraph(numeroAeroporto(aeroportiList));
    createEdgeFromFile(graph, aeroportiList);
//    List tmp = copyList(graph->adjList[0]);

  //  MergeSort(&tmp, 1);

    //printAereoporto(tmp);

    //welcome(graph,aeroportiList);

   printAllPaths(0,13, graph,aeroportiList);



    return 0;
}


//dfs modificata
void printAllPaths(int s, int d,Graph graph,List list){
    int *visited= (int*) calloc(sizeof(int),graph->numeroAeroporti);

    //Array per immagazinare i percorsi
    int *path = (int*) calloc(sizeof(int),graph->numeroAeroporti);
    int path_index = 0;


      int **matrix = (int**)malloc(sizeof(int*)*20);
       printf("Debug0\n");
    for(int i = 0; i < 20; i++){
        matrix[i] = (int*)malloc(sizeof(int)*20);
    }
    printf("Debug\n");
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            matrix[i][j] = -1;
        }
    }
 printf("Debug2\n");
    for(int i = 0; i < 20; i++ ){
        matrix[i] = printAllPathsUntil(s,d,visited,path,&path_index,graph,list);
    }
 printf("Debug3\n");
      for(int i = 0; i < 20; i++){
            printf("\n");
        for(int j = 0; j < 20; j++){
            printf("%d ", matrix[i][j]);
        }
    }
}

int*  printAllPathsUntil(int u, int d,int * visited,int *path,int *path_index,Graph graph,List list){
    Aeroporto a1;
    visited[u]=1;
    path[*path_index]= u;
    (*path_index)++;

    if( u == d){
        int i;

     // foo(path);
        for (i=0; i< *path_index;i++){
           // a1=findAeroportoIndex(path[i],list);
           // printf("->%s(%s)\n",a1.nomeAeroporto,a1.nomeCitta);

    }

    }else{
        List pCrawl = graph->adjList[u];
        while(pCrawl){

            if(!visited[pCrawl->aeroporto.index]){
               // printf()
              printAllPathsUntil(pCrawl->aeroporto.index,d,visited,path,path_index,graph,list);

            }

            pCrawl= pCrawl->next;
        }

    }
    (*path_index)--;
    visited[u]=0;

 return path;
}

void foo(int* array){
    for(int i = 0; i < 4 ; i++){

                printf("%d ", array[i]);


    }
    printf("Fine array\n");
}


