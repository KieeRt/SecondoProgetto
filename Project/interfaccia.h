#ifndef INTERFACCIA_H_INCLUDED
#define INTERFACCIA_H_INCLUDED
#include "Utente.h"
#include "graph.h"
#include "list.h"

void welcome(Graph graph, List aeroporti);
void home(User utente,Graph graph, List aeroporti);
void homeAdmin(User utente,Graph graph, List aeroporti);

#endif // INTERFACCIA_H_INCLUDED
