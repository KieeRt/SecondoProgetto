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
    char buff[20];

    printf("Comprila seguenti campi:\n");

    strcpy(utente.nome, doSceltaString("Nome:", 0, 2, 20));
   // utente.nome = buff;

    strcpy(utente.cognome, doSceltaString("Cognome:", 0, 2, 20));
   // utente.cognome = buff;


    strcpy(utente.codiceFiscale, doSceltaString("Codice Fiscale (16 caratteri):", 16, 0, 0));
    //utente.codiceFiscale = buff;

    stampaUtente(utente);

}

bool registrazioneSulFile(User utente){
FILE *source;

    source = fopen("Utenti.txt", "w");
    if(source == NULL){
        printf("Errore appertura file Utenti.txt\n");
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




