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
    tmp->aeroporto[i].index = -1;
    tmp->codice = 1;
    tmp->prezzo =  CostoVolo(graph, percorso_scelto);
    tmp->tempo = TempoVolo(graph, percorso_scelto);

    ListaPrenotazioni = inserPrenotezione(ListaPrenotazioni, tmp);

    return ListaPrenotazioni;
}



Prenotazione inserPrenotezione(Prenotazione ListaPrenotazioni, Prenotazione nuovaPrenotazione){
    if( ListaPrenotazioni == NULL){
            printf("CASO IF\n");
        nuovaPrenotazione->next = NULL;
    }
    else{
        printf("CASO ELSE\n");
        nuovaPrenotazione->next = ListaPrenotazioni;
    }
    return nuovaPrenotazione;
}



void stampaPrenotazione(Prenotazione ListaPrenotazioni){
int i = 0;
    if(ListaPrenotazioni){
        printf(" - Codice:%d\n", ListaPrenotazioni->codice);
        printTimeVolo(ListaPrenotazioni->tempo);
        printf(" - Costo:%d\n", ListaPrenotazioni->prezzo);
        while(ListaPrenotazioni->aeroporto[i].index != -1){
            printf("%s(%s) -> ", ListaPrenotazioni->aeroporto[i].nomeCitta, ListaPrenotazioni->aeroporto[i].nomeAeroporto);
        i++;
        }
        printf("\n\n");

        stampaPrenotazione(ListaPrenotazioni->next);
    }

}
