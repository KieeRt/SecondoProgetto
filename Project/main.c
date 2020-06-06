#include <stdio.h>
#include <stdlib.h>
#include "Utente.h"
#include "list.h"
#include "graph.h"
#include "file.h"




List checkPrice(int * array,int n, List list, int max);

int main()
{
    List aeroportiList = initNodeListFromFile();
    Graph graph = createGraph(numeroAeroporto(aeroportiList));
    createEdgeFromFile(graph, aeroportiList);
//    List tmp = copyList(graph->adjList[0]);

  //  MergeSort(&tmp, 1);

    //printAereoporto(tmp);

   // welcome(graph,aeroportiList);
    int dist [20];
    int prev[20];
    shortestPathPrice( graph, &dist, &prev,  0,  aeroportiList);

    for(int i=0;i<graph->numeroAeroporti;i++)
            printf("%d %d\n",i,dist[i]);
    List tmp = checkPrice(dist,graph->numeroAeroporti,aeroportiList,9999);
    //MergeSort(&tmp,0);
    //printAereoportoPrice(tmp);
    return 0;
}

List checkPrice(int * array,int n, List list, int max){
    int i=0;
    Aeroporto aeroporto;
    List tmp = (List) malloc (sizeof(struct TList));
    tmp = NULL;
    for(i=0;i <n ;i++){
        List head = list;
        head->next=NULL;
    printf("Test\n");
        if(array[i]!=0 && array[i]!=max){
            aeroporto = findAeroportoIndex(i,list);
            tmp = insertList(head,aeroporto);

        }
        list=list->next;
    }

    return tmp;

}







