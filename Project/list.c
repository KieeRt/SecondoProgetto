#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

List initNodeList(Aeroporto aeroporto){

}

List initNodeListFromFile(){
    FILE *fp;
    fp = fopen("listaLibri.txt", "r");

    List lista = NULL;
    Aeroporto aeroporto = initAeroporto();
    char read_line[150];

    if(!fp){
        printf("Errore nell'apertura del file Aeroporti.txt\n");
        return -1;
    }

    while(fgets(read_line,150,fp)!=NULL){
        //Controllo il contenuto di ogni riga e rimuovo un determinato prefisso
        if(strstr(read_line,"@nomeAeroporto"))
            strcpy(aeroporto.nomeAeroporto,strremove(read_line,"@nomeAeroporto "));

        if(strstr(read_line,"@nomeCitta"))
            strcpy(aeroporto.nomeCitta,strremove(read_line,"@nomeCitta "));

        if(strstr(read_line,"@popolarita"))
           aeroporto.popolarita = atoi(strremove(read_line,"@popolarita "));
        if(strstr(read_line,"@costoVita")){
            aeroporto.costoVita = atoi(strremove(read_line,"@costoVita "));
            lista = insertList(lista, aeroporto);
        }

    }
    return lista;
}
List insertList(){

}
