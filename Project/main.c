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
a1.index = 20;


strcpy(a2.nomeCitta, "Milano");
strcpy(a2.nomeAeroporto, "Ae.Milano");
a2.popolarita = 5;
a2.costoVita = 1000;
a2.index = 25;


strcpy(a3.nomeCitta, "Roma");
strcpy(a3.nomeAeroporto, "Ae.Roma");
a3.popolarita = 5;
a3.costoVita = 1000;
a3.index = 19;





    List tmp = initNodeListFromFile();
    Graph graph = createGraph(numeroAeroporto(tmp));
    createEdgeFromFile(graph, tmp);




    graph->adjList[0] = deleteEdge(graph,0,1);

 graph->adjList[1] = deleteEdge(graph,1,0);
 // int z =   updateFileArchi(graph, tmp);


//    printGraph(graph);
   // printAereoporto(tmp);


   printGraphX(graph);

  //  removeNode(graph, 1);
 //   printf("PROVA\n");
 //   printGraphX(graph);
    //removeNode(graph, 2);
   // printGraphX(graph);



  //  createEdgeFromFile(graph, tmp);

   // printAereoporto(tmp);

    //printGraphX(graph);
    //printAereoporto(tmp);
 //  updateFileArchi(graph, tmp);
   //int n =0;
   //printAereoporto(tmp);
    //updateFileAeroporti(tmp);
    //printf("\n\n");



   // bool find = isPozzo(graph,a3);
   // printf("%d", find);

    return 0;
}







