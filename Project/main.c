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



    welcome(graph, aeroportiList, ListaPrenotazioni);
  /*
int *prev = (int*)malloc(sizeof(int)* 20);
int *dist = (int*)malloc(sizeof(int)* 20);

    shortestPathPrice(graph, &dist, &prev, 0, aeroportiList);
    for(int i = 0; i < 20; i++){
        printf("%d ", dist[i]);
    }
    return 0;*/
}

