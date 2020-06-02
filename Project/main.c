#include <stdio.h>
#include <stdlib.h>
#include "Utente.h"
#include "list.h"
#include "graph.h"
#include "file.h"

void menu();

int main()
{
Aeroporto a1, a2, a3;
strcpy(a1.nomeCitta, "Napoli");
strcpy(a1.nomeAeroporto, "Ae.Napoli");
a1.popolarita = 5;
a1.costoVita = 1000;
a1.index = 0;


strcpy(a2.nomeCitta, "Milano");
strcpy(a2.nomeAeroporto, "Ae.Milano");
a2.popolarita = 5;
a2.costoVita = 1000;
a2.index = 1;


strcpy(a3.nomeCitta, "Roma");
strcpy(a3.nomeAeroporto, "Ae.Roma");
a3.popolarita = 5;
a3.costoVita = 1000;
a3.index = 2;





    List tmp = initNodeListFromFile();

    Graph graph = createGraph(numeroAeroporto(tmp));
  /*  addEdge(graph, a3, a2, 0, 1);
    addEdge(graph, a1, a3, 0, 2);
    addEdge(graph, a1, a3, 0, 3);
        addEdge(graph, a1, a3, 0, 3);
    //addEdge(graph, a3, a1, 0, 4);
    //addEdge(graph, a3, a2, 0, 5);*/
    createEdgeFromFile(graph, tmp);

   // printAereoporto(tmp);

    printGraphX(graph);
    updateFileArchi(graph);
    printf("\n\n");



   // bool find = isPozzo(graph,a3);
   // printf("%d", find);

    return 0;
}







