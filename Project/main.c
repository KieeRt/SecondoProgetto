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
    List tmp = copyList(graph->adjList[1]);

    MergeSort(&tmp, 0);

    printAereoporto(tmp);

  // welcome(graph,aeroportiList);



    return 0;
}







