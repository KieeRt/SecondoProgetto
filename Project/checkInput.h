#ifndef CHECKINPUT_H_INCLUDED
#define CHECKINPUT_H_INCLUDED
#include <stdbool.h>

//Controlla se la stringa ha una dimensione esatta
//
bool controllaLunghezza(char* stringa, int dimensione_esatta, int dimensione_min, int dimensione_max);

bool doSceltaInt(char* messaggio, int valore_max);

//Chiede in input una stringa e stampa il messaggio finche la stringa non soddisfa le dimensioni indicate, mettere 0 nel campo nel caso in cui un paramentro deve essere ignorato.
//Ritorna l'indirizzo della stringa che contiene l'input
int doSceltaString(char* messaggio, int dimensione_esatta, int dimensione_min, int dimensione_max);

char* doCompare();
char* strremove(char *str, const char *sub);
bool checkIfExist(char *st1, FILE *file);
#endif // CHECKINPUT_H_INCLUDED
