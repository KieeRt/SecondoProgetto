#include <stdio.h>
#include <stdlib.h>
#include "Utente.h"
#include "list.h"
#include "graph.h"


void menu();

int main()
{

    List lista= (List) malloc (sizeof(struct TList));
    Aeroporto a1=initAeroporto();
    Aeroporto a2=initAeroporto();

    a1.nomeAeroporto="Gastani";
    a2.nomeAeroporto="Frizzi";
    insertList(lista,a1);
    insertList(lista,a2);
    printAereoporto(lista);
   // Graph graph = initGraph();
   // printGraph(graph);
    //welcome();
    return 0;
}



