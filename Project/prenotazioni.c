#include "prenotazioni.h"

Prenotazione addPrenotazione(Prenotazione ListaPrenotazioni, int *percorso_scelto, List aeroporti, Graph graph)
{

    Prenotazione tmp = (Prenotazione)malloc(sizeof(struct TPrenotazione));
    int i = 0;
    while (percorso_scelto[i] != -1)
    {
        tmp->aeroporto[i] = findAeroportoIndex(percorso_scelto[i], aeroporti);
        i++;
    }
    tmp->aeroporto[i].index = -1;
    tmp->codiceVolo = 1; //Da gestine
    tmp->prezzo = CostoVolo(graph, percorso_scelto);
    tmp->tempo = TempoVolo(graph, percorso_scelto);

    ListaPrenotazioni = inserPrenotezione(ListaPrenotazioni, tmp);

    return ListaPrenotazioni;
}

Prenotazione inserPrenotezione(Prenotazione ListaPrenotazioni, Prenotazione nuovaPrenotazione)
{
    if (ListaPrenotazioni == NULL)
    {
        nuovaPrenotazione->next = NULL;
    }
    else
    {
        nuovaPrenotazione->next = ListaPrenotazioni;
    }
    return nuovaPrenotazione;
}

void stampaPrenotazione(Prenotazione ListaPrenotazioni)
{
    int i = 0;
    if (ListaPrenotazioni)
    {
        printf(" - Codice:%d\n - ", ListaPrenotazioni->codiceVolo);
        printTimeVolo(ListaPrenotazioni->tempo);
        printf(" - Costo:%d\n", ListaPrenotazioni->prezzo);
        while (ListaPrenotazioni->aeroporto[i].index != -1)
        {
            printf("%s(%s) -> ", ListaPrenotazioni->aeroporto[i].nomeCitta, ListaPrenotazioni->aeroporto[i].nomeAeroporto);
            i++;
        }
        printf("\n\n");

        stampaPrenotazione(ListaPrenotazioni->next);
    }
}

void readPrenotazioni(char *codice_ficale)
{
    FILE *file_prenotazioni;
    file_prenotazioni = fopen("Prenotazioni.txt", "r");

    int i;
    char buff[100];
    char read_line[150];
    char tmpCf[20];
    strcpy(tmpCf,codice_ficale);
    char * pch;
    Prenotazione head = NULL;
    Prenotazione tmp ;

    if (!file_prenotazioni)
    {
        printf("Errore nell'apertura del file Prenotazioni.txt\n");
        return -1;
    }
    //aggiungere campi di tempo e prezzo
    while (fgets(read_line, 150, file_prenotazioni) != NULL  ){
        tmp=(Prenotazione)malloc(sizeof(struct TPrenotazione));
        if(strstr(read_line,"@CodiceFiscale"))
            strcpy(tmpCf,strremove(read_line,"@CodiceFiscale "));
        if(!strcmp(tmpCf,codice_ficale)){
            if(strstr(read_line,"@CodicePrenotazione"))
                tmp->codicePrenotazione= atoi(strremove(read_line, "@CodicePrenotazione "));
            i=0;
            if(strstr(read_line,"@Aeroporti")){
                strremove(read_line,"@Aeroporti ");
                pch = strtok (read_line," ");
                while (pch != NULL){
                    strcpy(tmp->aeroporto[i].nomeAeroporto,pch);
                    pch = strtok (NULL, " ");
                    i++;
                }
                head= inserPrenotezione(head, tmp);
            }



        }

    }

}
