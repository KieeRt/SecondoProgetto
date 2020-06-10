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



int** printAllPaths(int s, int d,Graph graph,List list){
    int *visited= (int*) calloc(sizeof(int),graph->numeroAeroporti);
    int i, j, sumCosto = 0, sumTempo =0, count = 1;
    Aeroporto aeroporto;
    //Array per immagazinare i percorsi
    int *path = (int*) calloc(sizeof(int),graph->numeroAeroporti);
    int path_index = 0;

    int** matrix = (int**)malloc(20*sizeof(int*));
    for(int i = 0; i < 20; i++){
        matrix[i] = (int*)malloc(10*sizeof(int));
    }
    for(i = 0; i < 20; i++){
    for(j = 0; j < 10; j++){
            matrix[i][j] = -1;
        }
    }


    printAllPathsUntil(s,d,visited,path,&path_index,graph,list,matrix);

    if(matrix[0][0] == -1){
        printf("La tratta non e'disponibile\n");
    }



   for(i = 0; i < 20; i++){
        for(j = 0; j < 10; j++){
            if(matrix[i][j] != -1){
                    if(matrix[i][j] == s){
                        sumCosto = CostoVolo(graph, matrix[i]);
                        sumTempo = TempoVolo(graph, matrix[i]);
                        aeroporto = findAeroportoIndex(matrix[i][j], list);
                        printf("%d - %s(%s):%d euro ",count, aeroporto.nomeAeroporto,aeroporto.nomeCitta, sumCosto);
                        printTimeVolo(sumTempo);
                        count++;
                    }else {
                        if(j==1){
                            aeroporto = findAeroportoIndex(matrix[i][j], list);
                            printf("\t%s(%s)->",aeroporto.nomeAeroporto,aeroporto.nomeCitta);
                    } else {
                        aeroporto = findAeroportoIndex(matrix[i][j], list);
                        printf("%s(%s)->",aeroporto.nomeAeroporto,aeroporto.nomeCitta);
                    }
            }
        }

    }
     if(matrix[i][0] != -1)
            printf("\n\n");
   }

   return matrix;
}

void printAllPathsUntil(int u, int d,int * visited,int *path,int *path_index,Graph graph,List list,int** matrix){
    Aeroporto a1;
    visited[u]=1;
    path[*path_index]= u;
    (*path_index)++;

    if( u == d){
        int i = 0;
        while(matrix[i][0] != -1){
           i++;
            }
           copyArray(&matrix[i], path, *path_index);

    }else{
        List pCrawl = graph->adjList[u];
        while(pCrawl){

            if(!visited[pCrawl->aeroporto.index])
                printAllPathsUntil(pCrawl->aeroporto.index,d,visited,path,path_index,graph,list,matrix);
            pCrawl= pCrawl->next;
        }

    }
    (*path_index)--;
    visited[u]=0;

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



