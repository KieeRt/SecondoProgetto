#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "list.h"
#include "graph.h"
#include <stdbool.h>

void createEdgeFromFile(Graph graph, List head);

List initNodeListFromFile();

bool updateFileArchi(Graph graph, List aeroporti);


void updateFileAeroporti(List aeroporti);

#endif // FILE_H_INCLUDED
