#include "array.h"


int* findScali(int *prev,int part, int *tmp,int pos){


    if(prev[part]!= -1 ){
        tmp[pos]=prev[part];
        part = prev[part];
        pos++;
        tmp= findScali(prev,part,tmp,pos);


    }else{

        return tmp;
    }

}



int findMin (int* array , int n){
    int i=0;
    int min = 0;
    for ( i= 0;i <n ; i++){
        if(array[min]> array[i]){
            min = i;
        }
    }
    return min;
}





void printPath(int* array, int n){
    for(int i = 0; i < n ; i++){

            printf("%d ", array[i]);
    }
    printf("Fine array\n");
}

void copyArray(int** a, int* b, int n){
    int i = 0;
    for(i=0;i<n;i++){
            (*a)[i] = b[i];
    }

}

int CostoVolo(Graph graph, int* percorso){
    int i = 0;
    int sum = 0;

    while(percorso[i+1] != -1){
        List tmp = graph->adjList[percorso[i]];
        while(tmp){
            if(tmp->aeroporto.index == percorso[i+1]){
               sum += tmp->prezzo;
            }
            tmp = tmp->next;
        }
        i++;
    }
    return sum;

}

int TempoVolo(Graph graph, int* percorso){
    int i = 0;
    int sum = 0;

    while(percorso[i+1] != -1){
        List tmp = graph->adjList[percorso[i]];
        while(tmp){
            if(tmp->aeroporto.index == percorso[i+1]){
               sum += tmp->tempo;
            }
            tmp = tmp->next;
        }
        i++;
    }
    return sum;

}



