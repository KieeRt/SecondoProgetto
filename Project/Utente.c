#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Utente.h"

User registazioneUtente(){
    User utente;
    utente.nome = (char*)malloc(sizeof(char)*10);
    utente.cognome = (char*)malloc(sizeof(char)*10);
    utente.codiceFiscale = (char*)malloc(sizeof(char)*10);
    utente.password = (char*)malloc(sizeof(char)*10);
    char buff[20];



    printf("Comprila seguenti campi:\n");
    printf("Nome:");
    if(check("DKDLJSDJFL", 2));
    scanf("%s", buff);
    if(strlen(buff) < 2){
        printf("Errore di lunghezza, inserire almeno due caratteri");
    }

    scanf("%s", utente.nome);
    printf("Cognome:");
    scanf("%s", utente.cognome);
    printf("C.F:");
    scanf("%s", utente.cognome);

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
