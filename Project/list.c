#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <list.h>


List initNodeList(){
    FILE *fp;
    fp = fopen("listaLibri.txt", "r");

    Biblioteca head = NULL;
    Aeroporto aeroporto;
    char read_line[150];

    if(!file_libri){
        printf("Errore nell'apertura del file\n");
        return -1;
    }



    while(fgets(read_line,150,file_libri)!=NULL){
        //Controllo il contenuto di ogni riga e rimuovo un determinato prefisso
        if(strstr(read_line,"@Titolo"))
            strcpy(libro.titolo,strremove(read_line,"@Titolo "));

        if(strstr(read_line,"@Autore"))
            strcpy(libro.autore,strremove(read_line,"@Autore "));

        if(strstr(read_line,"@Disponibili ")){
            libro.copieDisponibili=atoi(strremove(read_line,"@Disponibili"));


            head=inserisciLibro(head,libro);
        }
    }
    return head;
}
