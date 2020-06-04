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

    strcpy(utente.nome, doSceltaString("Nome\nInput -> ", 2,0 , 20));


    strcpy(utente.cognome, doSceltaString("Cognome\nInput -> ", 2, 0, 20));

    do{
        if(count > 0)
            printf("C.F gia' e' registrato nel sistema\n");
        count++;
        strcpy(utente.codiceFiscale, doSceltaString("Codice Fiscale (16 caratteri)\nInput -> ", 16, 0, 0));
    }while(checkIfExist(utente.codiceFiscale, "Utenti.txt"));


    strcpy(utente.password, doCompare());



    utente.punti = 0;
    registraFileUtente(utente);


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
    fprintf(fp,"%s\n" ,   concatenation("@CodiceFiscale ", utente.codiceFiscale));
    fprintf(fp,"%s\n" ,   concatenation("@Nome ", utente.nome));
    fprintf(fp,"%s\n" ,  concatenation("@Cognome ", utente.cognome));
    fprintf(fp,"%s\n" ,   concatenation("@Password ", utente.password));
    sprintf(tmp, "%d", utente.punti);
    fprintf(fp, "%s\n", concatenation("@Punti ", tmp));



}


User login(){
    User utente = initUtente();
    int check=0;
    char tmpCF[50];
    char tmpPassword[50];
    do{
        if(check){
            system("cls");
            printf("\nCoppia Codice Fiscale/Password non presente , riprova\n");

        }

        printf("Inserire codice fiscale: ");
        scanf("%s",tmpCF);

        printf("Inserire Password: ");
        scanf("%s",tmpPassword);


        check++;

    }while(!checkIfExist(tmpCF,"Utenti.txt")||!checkPassword(tmpCF,tmpPassword));

    utente = getUtente(tmpCF);


    return utente;
}

User getUtente(char* codiceFiscale){
        User utente=initUtente();
        char buff[400];
        char punti[20];
        FILE *fp = fopen("Utenti.txt", "r");
        if(fp == NULL){
            printf("Impossibile aprire il file" );
        }else {

        while(fgets(buff,400,fp)!=NULL){
        //Controllo il contenuto di ogni riga e rimuovo un determinato prefisso
            if(strstr(buff,"@CodiceFiscale"))
                strcpy(utente.codiceFiscale,strremove(buff,"@CodiceFiscale "));

            if (!strcmp(utente.codiceFiscale,codiceFiscale)){
                if(strstr(buff,"@Nome"))
                    strcpy(utente.nome,strremove(buff,"@Nome "));
                if(strstr(buff,"@Cognome"))
                    strcpy(utente.cognome,strremove(buff,"@Cognome "));
                if(strstr(buff,"@Password"))
                    strcpy(utente.password,strremove(buff,"@Password "));
                if(strstr(buff,"@Punti")){
                    strcpy(punti,strremove(buff,"@Punti "));
                    utente.punti=atoi(punti);
                }

            }

        }

        return utente;
    }
}

bool checkPassword(char* codiceFiscale, char* password){
        bool find= false;
        char buff[200];
        char *tmpCF;
        tmpCF = (char*)malloc(sizeof(char)*16);
        char *tmpPassword;
        tmpPassword = (char*)malloc(sizeof(char)*16);

        FILE *fp = fopen("Utenti.txt", "r");
        if(fp == NULL){
            printf("Impossibile aprire il file" );
        }else {

        while(fgets(buff,200,fp)!=NULL){
        //Controllo il contenuto di ogni riga e rimuovo un determinato prefisso
            if(strstr(buff,"@CodiceFiscale"))
                strcpy(tmpCF,strremove(buff,"@CodiceFiscale "));
                if (!strcmp(tmpCF,codiceFiscale))
                    strcpy(tmpPassword,strremove(buff,"@Password "));
                    if(!strcmp(tmpPassword,password))
                        find = true;
        }

        return find;
    }
}



