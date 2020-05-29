#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./lib/inputReader.h"

bool controllaLunghezza(char* stringa, int dimensione_esatta, int dimensione_min, int dimensione_max){
int dimensione_stringa = strlen(stringa);
    if(dimensione_esatta != 0){
        if( dimensione_stringa == dimensione_esatta)
            return true;
        else
            return false;
    }
    else if(dimensione_min != 0){
        if(dimensione_stringa >= dimensione_min){
            if(dimensione_stringa <= dimensione_max)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else{
        printf("Errore controllo parametri funzione controllaLunghezza");
        return false;
    }
}

bool doSceltaInt(char* messaggio, int valore_max){
int input_locale;

    do{
    printf("%s", messaggio);
    }while(!getPositive(&input_locale) || input_locale == 0 || input_locale > valore_max);

    return input_locale;

}
int doSceltaString(char* messaggio, int dimensione_esatta, int dimensione_min, int dimensione_max){
char buff[20];
int* pt = &buff;

    do{
        printf("%s", messaggio);
        scanf("%s", buff);
    }while(!controllaLunghezza(buff, dimensione_esatta, dimensione_min, dimensione_max));
   return pt;
}


char* doCompare () {
  char* buff;
  char* buff1;
  buff = (char*)malloc(sizeof(char)*20);
  buff1 = (char*)malloc(sizeof(char)*20);

    int* pt = &buff;

    do{
        printf("Inserisci Password: ");
        scanf("%s", buff);
        printf("Conferma Password: ");
        scanf("%s", buff1);
    }while ( strcmp(buff, buff1) && controllaLunghezza(buff,0, 4, 16));

   return buff;



}

