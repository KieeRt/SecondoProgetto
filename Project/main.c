#include <stdio.h>
#include <stdlib.h>
#include "Utente.h"
#include "list.h"
#include "graph.h"
#include "file.h"
#include "prenotazioni.h"

int* findScali(int *prev,int part, int *tmp,int pos);
int main()
{
    Prenotazione ListaPrenotazioni = (Prenotazione)malloc(sizeof(struct TPrenotazione));
    ListaPrenotazioni = NULL;
    List aeroportiList = initNodeListFromFile();
    Graph graph = createGraph(numeroAeroporto(aeroportiList));
    createEdgeFromFile(graph, aeroportiList);
//    List tmp = copyList(graph->adjList[0]);

  //  MergeSort(&tmp, 1);

    //printAereoporto(tmp);
    printf("%d", ListaPrenotazioni->next);
  //  welcome(graph,aeroportiList);

  // printAllPaths(0,13, graph,aeroportiList);



    return 0;
}




