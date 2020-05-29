#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Utente.h"
User initUtente(){
    User utente;
    utente.nome = (char*)malloc(sizeof(char)*10);
    utente.cognome = (char*)malloc(sizeof(char)*10);
    utente.codiceFiscale = (char*)malloc(sizeof(char)*10);
    utente.password = (char*)malloc(sizeof(char)*10);
    return utente;
}
User registazioneUtente(){
   User utente = initUtente();
    char buff [20];
    char buff1 [20];
    int count = 0;


    printf("Compila i seguenti campi:\n");

    strcpy(utente.nome, doSceltaString("Nome:", 0, 2, 20));


    strcpy(utente.cognome, doSceltaString("Cognome:", 0, 2, 20));

    do{
        if(count > 0)
            printf("C.F gia' e' registrato nel sistema\n");
        count++;
        strcpy(utente.codiceFiscale, doSceltaString("Codice Fiscale (16 caratteri):", 16, 0, 0));
    }while(checkIfExist(utente.codiceFiscale, "Utenti.txt"));


    strcpy(utente.password, doCompare());



    utente.punti = 0;
    registraFileUtente(utente);
    stampaUtente(utente);

}

bool registrazioneSulFile(User utente){
FILE *source;

    source = fopen("Utenti.txt", "w");
    if(source == NULL){
        printf("Errore apertura file Utenti.txt\n");
    }
    else{
        while(!feof(source)){
          //  fscanf()
        }
    }

}

void stampaUtente(User utente){
    printf("Nome:%s\n", utente.nome);
    printf("Cognome:%s\n", utente.cognome);
    printf("Codice Fiscale:%s\n", utente.codiceFiscale);
    printf("Password:%s\n", utente.password);
    printf("Punti:%d\n", utente.punti);
}

void registraFileUtente(User utente){

    FILE * fp;
    fp = fopen("Utenti.txt", "a");

    char tmp[20];
    fflush(stdin);



   if(!fp){
        printf("Errore nell'apertura del file");
        return -1;
    }

    fprintf(fp,"%s\n" ,   concatenation("@Nome ", utente.nome));
    fprintf(fp,"%s\n" ,  concatenation("@Cognome ", utente.cognome));
    fprintf(fp,"%s\n" ,   concatenation("@CodiceFiscale ", utente.codiceFiscale));
    fprintf(fp,"%s\n" ,   concatenation("@Password ", utente.password));
    sprintf(tmp, "%d", utente.punti);
    fprintf(fp, "%s\n", concatenation("@Punti ", tmp));



}







