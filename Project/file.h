#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "list.h"
#include "graph.h"
#include <stdbool.h>

void createEdgeFromFile(Graph graph, List head);
List initNodeListFromFile();
bool updateFileArchi(Graph graph);
//!!! Funzione da implementare !!!
bool updateCampoFile(char* nomeCampo, int nuovoValore);


#endif // FILE_H_INCLUDED
