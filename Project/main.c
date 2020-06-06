#include <stdio.h>
#include <stdlib.h>
#include "Utente.h"
#include "list.h"
#include "graph.h"
#include "file.h"






int main()
{
    List aeroportiList = initNodeListFromFile();
    Graph graph = createGraph(numeroAeroporto(aeroportiList));
    createEdgeFromFile(graph, aeroportiList);
//    List tmp = copyList(graph->adjList[0]);

  //  MergeSort(&tmp, 1);

    //printAereoporto(tmp);

//  welcome(graph,aeroportiList);
    int dist [20];
    int prev[20];
    shortestPathPrice( graph, &dist, &prev,  0,  aeroportiList);

for(int i=0;i<20;i++){
        printf("index %d -> %d\n",i,prev[i]);
    }
    return 0;
}







