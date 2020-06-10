#include "prenotazioni.h"


Prenotazione addPrenotazione(Prenotazione ListaPrenotazioni, int* percorso_scelto, List aeroporti, Graph graph){
    Prenotazione tmp = (Prenotazione)malloc(sizeof(struct TPrenotazione));
    int i = 0;
   // List tmp = NULL;
    while(percorso_scelto[i] != -1){
        tmp->aeroporto[i] = findAeroportoIndex(percorso_scelto[i], aeroporti);
        //tmp = findList(percorso_scelto[i+1], graph->adjList[percorso_scelto[i]]);
        i++;
    }
    tmp->codice = 1;
    tmp->prezzo =  CostoVolo(graph, percorso_scelto);
    tmp->tempo = TempoVolo(graph, percorso_scelto);

    ListaPrenotazioni = inserPrenotezione(ListaPrenotazioni, tmp);

    return ListaPrenotazioni;
}



Prenotazione inserPrenotezione(Prenotazione ListaPrenotazioni, Prenotazione nuovaPrenotazione){
    if( ListaPrenotazioni == NULL){
        nuovaPrenotazione->next = NULL;
    }
    else{
        nuovaPrenotazione->next = ListaPrenotazioni;
    }
    return nuovaPrenotazione;
}


void stampaPrenotazione(Prenotazione ListaPrenotazioni){

    while(ListaPrenotazioni->next){
        printf(" - Codice:%d\n", ListaPrenotazioni->codice);
        printTimeVolo(ListaPrenotazioni->tempo);
        printf(" - Costo:%d", ListaPrenotazioni->prezzo);

        ListaPrenotazioni = ListaPrenotazioni->next;
    }

}

void stampaPrenotazioneR(Prenotazione ListaPrenotazioni){

    if(ListaPrenotazioni){
        printf(" - Codice:%d\n", ListaPrenotazioni->codice);
        printTimeVolo(ListaPrenotazioni->tempo);
        printf(" - Costo:%d", ListaPrenotazioni->prezzo);

        stampaPrenotazioneR(ListaPrenotazioni->next);
    }

}
