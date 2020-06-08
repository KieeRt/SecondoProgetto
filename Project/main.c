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

    welcome(graph,aeroportiList);




    return 0;
}

