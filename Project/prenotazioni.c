#include "prenotazioni.h"



Prenotazione addPrenotazione(Prenotazione ListaPrenotazioni, int *percorso_scelto, List aeroporti, Graph graph,double* punti)
{
srand(time(0));
int a = 1+rand()%1000;
int b = 1+rand()%1000;
int numeroPrenotazioni = maxCodicePrenotazioneUtente(ListaPrenotazioni);

    Prenotazione tmp = (Prenotazione)malloc(sizeof(struct TPrenotazione));
    int i = 0;
    while (percorso_scelto[i] != -1)
    {
        tmp->aeroporto[i] = findAeroportoIndex(percorso_scelto[i], aeroporti);
        i++;
    }
    tmp->aeroporto[i].index = -1;
    tmp->codicePrenotazione = numeroPrenotazioni + 1;
    tmp->codiceVolo = a^b^ (int)tmp->aeroporto[0].nomeAeroporto; //Da gestine
    tmp->prezzo = CostoVolo(graph, percorso_scelto) ;
    tmp->tempo = TempoVolo(graph, percorso_scelto);

    ListaPrenotazioni = inserPrenotezione(ListaPrenotazioni, tmp);

    return ListaPrenotazioni;
}

Prenotazione inserPrenotezione(Prenotazione ListaPrenotazioni, Prenotazione nuovaPrenotazione)
{
    if (ListaPrenotazioni == NULL)
    {
        nuovaPrenotazione->next = NULL;
        return nuovaPrenotazione;
    }
    else{

        Prenotazione tmp = ListaPrenotazioni;

        while(tmp->next != NULL){
                tmp = tmp->next;
        }
        tmp->next = nuovaPrenotazione;
        nuovaPrenotazione->next = NULL;
        return ListaPrenotazioni;

    }

}


void stampaPrenotazione(Prenotazione ListaPrenotazioni)
{

    int i = 0;
    if (ListaPrenotazioni)
    {
        printf(" - Codice Prenotazione:%d\n ", ListaPrenotazioni->codicePrenotazione);
        printf(" - Codice Volo:%d\n - ", ListaPrenotazioni->codiceVolo);
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


Prenotazione readPrenotazioni(char *codice_ficale, List listaAeroporti)
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
    Prenotazione head1 = NULL;
    Prenotazione tmp ;
    Aeroporto support[20];

    int codicePrenotazione;
    int codiceVolo;
    int tempo;
    int prezzo;

    if (!file_prenotazioni)
    {
        printf("Errore nell'apertura del file Prenotazioni.txt\n");
        return -1;
    }
    while (fgets(read_line, 150, file_prenotazioni) != NULL  ){

        if(strstr(read_line,"@CodiceFiscale")){

            strcpy(tmpCf,strremove(read_line,"@CodiceFiscale "));
        }
        if(!strcmp(tmpCf,codice_ficale)){
            if(strstr(read_line,"@CodicePrenotazione"))
            {

              codicePrenotazione = atoi(strremove(read_line, "@CodicePrenotazione "));
            }

             if(strstr(read_line,"@CodiceVolo"))
            {

              codiceVolo =  atoi(strremove(read_line, "@CodiceVolo "));
            }


            i=0;
            if(strstr(read_line,"@Aeroporto")){

                strremove(read_line,"@Aeroporto ");
                pch = strtok (read_line," ");
                while (pch != NULL){
                    support[i] =  findAeroportoIndex(atoi(pch), listaAeroporti);
                    pch = strtok (NULL, " ");
                    i++;
                }
                 support[i].index = -1;
            }
              if(strstr(read_line,"@Tempo"))
            {
               tempo =  atoi(strremove(read_line, "@Tempo "));
            }
            if(strstr(read_line,"@Prezzo"))
            {
              prezzo =  atoi(strremove(read_line, "@Prezzo "));

                tmp=(Prenotazione)malloc(sizeof(struct TPrenotazione));

                tmp->codicePrenotazione = codicePrenotazione;
                tmp->codiceVolo = codiceVolo;
                tmp->prezzo = prezzo;
                tmp->tempo = tempo;
                for(i = 0; support[i].index != -1;i++){
                    tmp->aeroporto[i] = support[i];
                }
                tmp->aeroporto[i] = support[i];
                tmp->next = NULL;
                head = inserPrenotezione(head, tmp);

            }


        }

    }

    fclose(file_prenotazioni);

    return head;
}



void writePrenotezioniFile(char* codice_fiscale, Prenotazione ListaPrenotazioni){
    FILE *source, *target;
    char* buff1[400];
    char* buff2[400];
    int i = 0;
    char* last_CF[400];
    char tmp[20];

    source = fopen("Prenotazioni.txt", "r");

    if( source == NULL){
        printf("Impossibile aprire file Prenotazioni.txt\n");
        exit(0);
    }
    else{
        target = fopen("tmp.txt", "w+");
        if(target == NULL){
            printf("Impossibile creare nuovo file tmp.txt\n");
            exit(0);
        }
        else{
            while(fgets(buff1,400,source)!=NULL){
                if(strstr(buff1,"@CodiceFiscale")){ //Se il campo e' quello CodiceFiscale
                    strcpy(buff2,strremove(buff1,"@CodiceFiscale ")); //Viene rimosso il campo @CodiceFiscale dalla stringa buff1
                    concatenation(buff1,"@CodiceFiscale ");
                    strcpy(last_CF, buff2); // Salvo la variabile del attuale codice fiscale per i futuri controlli
                    if(!strcmp(buff2, codice_fiscale)){ //Se il valore del campo CodiceFiscale corrisponde al c.f passato
                    fprintf(target, "%s\n", concatenation("@CodiceFiscale ", codice_fiscale));
                        while(ListaPrenotazioni != NULL){

                            fprintf(target, "%s ", "@CodicePrenotazione ");
                            fprintf(target, "%d\n", ListaPrenotazioni->codicePrenotazione);

                            fprintf(target, "%s ", "@CodiceVolo ");
                            fprintf(target, "%d\n", ListaPrenotazioni->codiceVolo);


                           fprintf(target, "%s ", "@Aeroporto ");
                           for(int h = 0; ListaPrenotazioni->aeroporto[h].index != -1;h++){
                               fprintf(target, "%d ", ListaPrenotazioni->aeroporto[h].index);
                           }
                                fprintf(target, "\n");
                            fprintf(target, "%s ", "@Tempo ");
                            fprintf(target, "%d\n", ListaPrenotazioni->tempo);
                            fprintf(target, "%s ", "@Prezzo ");
                            fprintf(target, "%d\n\n", ListaPrenotazioni->prezzo);


                            ListaPrenotazioni = ListaPrenotazioni->next;
                        }

                    }
                    else{
                    	 fprintf(target, "%s\n", concatenation("@CodiceFiscale ", buff1)); // CASP ELSE Se il campo @CodiceFiscale e' diverso dal nostro codice_fiscale passato

                    }
                }
                else if (!strcmp(last_CF, codice_fiscale)){
                    // CASP ELSE IF Se il campo e' diverso dal @CodiceFiscale, faccio scorrere fgets
                   // printf("CASP ELSE IF Se il campo e' diverso dal @CodiceFiscale \n");
                }
                else{
                    fprintf(target, "%s", buff1); // CASP ELSE Se il campo e' diverso dal @CodiceFiscale

                }
            }

        }
        fclose(target);
    }
    fclose(source);

    if(remove("Prenotazioni.txt") == 0){

    }
    else{
        printf("Impossibile eliminare il file\n");
    }

    if(rename("tmp.txt", "Prenotazioni.txt") == 0){

    }
    else{
        printf("Impossibile rinominare il nome del file\n");
    }


}

int maxCodicePrenotazioneUtente(Prenotazione ListaPrenotazioni){
    Prenotazione tmp = ListaPrenotazioni;
    if(ListaPrenotazioni != NULL){
        while(tmp->next){
            tmp = tmp->next;
        }
        return tmp->codicePrenotazione;
    }
    else{
        return 0;
    }

}

