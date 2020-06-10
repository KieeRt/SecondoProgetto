#ifndef PRENOTAZIONI_H_INCLUDED
#define PRENOTAZIONI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Aeroporto.h"
#include "list.h"
#include "graph.h"

struct TPrenotazione{
    int codicePrenotazione;
    int codiceVolo;
    Aeroporto aeroporto[10];
    int tempo;
    int prezzo;
    struct TPrenotazione* next;
};

typedef struct TPrenotazione* Prenotazione;

Prenotazione addPrenotazione(Prenotazione ListaPrenotazioni, int* percorso_scelto, List aeroporti, Graph graph);

void stampaPrenotazione(Prenotazione ListaPrenotazioni);
Prenotazione inserPrenotezione(Prenotazione ListaPrenotazioni, Prenotazione nuovaPrenotazione);


#endif // PRENOTAZIONI_H_INCLUDED
