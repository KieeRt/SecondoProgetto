#include <stdio.h>
#include <stdlib.h>
#include "Utente.h"
#include "list.h"
#include "graph.h"


void menu();

int main()
{

    List lista= initNodeListFromFile();
    //
    printAereoporto(lista);
   // printAereoporto(lista->next);
   // Graph graph = initGraph();
   // printGraph(graph);
    //welcome();
    return 0;
}



