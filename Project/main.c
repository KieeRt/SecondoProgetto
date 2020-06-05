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

    MergeSort(&aeroportiList);

    printAereoporto(aeroportiList);

  // welcome(graph,aeroportiList);



    return 0;
}







