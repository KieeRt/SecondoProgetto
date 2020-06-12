#ifndef PRENOTAZIONI_H_INCLUDED
#define PRENOTAZIONI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Aeroporto.h"
#include "list.h"
#include "graph.h"
#include <time.h>


struct TPrenotazione{
    int codicePrenotazione;
    int codiceVolo;
    Aeroporto aeroporto[10];
    int tempo;
    int prezzo;
    struct TPrenotazione* next;
};

typedef struct TPrenotazione* Prenotazione;

Prenotazione addPrenotazione(Prenotazione ListaPrenotazioni, int *percorso_scelto, List aeroporti, Graph graph,int* punti, bool usePoint);

void stampaPrenotazione(Prenotazione ListaPrenotazioni);
void writePrenotezioniFile(char* codice_fiscale, Prenotazione ListaPrenotazioni);


//Se utente non e' presente nel file con la lista di prenotazioni lo mette in coda al file stesso
void addNewUserFilePrenotazioni(char* codice_fiscale, Prenotazione ListaPrenotazioni);
Prenotazione inserPrenotezione(Prenotazione ListaPrenotazioni, Prenotazione nuovaPrenotazione);

//Controlla se degli utenti hanno dei voli prenotati verso target
List canRemove(List L, int target);

Prenotazione readPrenotazioni(char *codice_ficale, List listaAeroporti);

int maxCodicePrenotazioneUtente(Prenotazione ListaPrenotazioni);

//Restituisce true se nella Prenotazione esiste un arco da s a d
bool isEdgeOnPrenotazione(Prenotazione ListaPrenotazioni, int s, int d);
// Elimina le prenotazioni da P  in modo ricorsivo che contengono un percorso DIRETTO tra src e dest
Prenotazione deletePrenotazioniSrcDst(Prenotazione P, int src,  int dest);
// Per ogni utente controlla !!STA SUL MAIN
void updatePrenotazioniFile(int src, int dest, List listaAeroporti);
// Cancella dal file Prenotazioni.txt utente con le sue prenotazioni
void cancellaUtenteFilePrenotazioni(char* codice_fiscale);
//Aggiorna campo CodicePrenotazione nel caso viene rimossa una prenotazione
Prenotazione updateCodicePrenotazioneR(Prenotazione P, int numero);
#endif // PRENOTAZIONI_H_INCLUDED
