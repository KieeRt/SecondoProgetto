#ifndef INTERFACCIA_H_INCLUDED
#define INTERFACCIA_H_INCLUDED
#include "Utente.h"
#include "graph.h"
#include "list.h"
#include "array.h"
#include "prenotazioni.h"

void welcome(Graph graph, List aeroporti, Prenotazione ListaPrenotazioni);
void home(User utente,Graph graph, List aeroporti, Prenotazione ListaPrenotazioni);
void homeAdmin(User utente,Graph graph, List aeroporti);

double doSceltaDoubleZero(char* messaggio, int valore_max);
#endif // INTERFACCIA_H_INCLUDED
