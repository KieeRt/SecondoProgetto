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

   readPrenotazioni("qawsedrftgyhujii", aeroportiList);
   // welcome(graph, aeroportiList, ListaPrenotazioni);



    return 0;
}




