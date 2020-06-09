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
    int i;
    int j;
    Aeroporto aeroporto;
    //Array per immagazinare i percorsi
    int *path = (int*) calloc(sizeof(int),graph->numeroAeroporti);
    int path_index = 0;

    int** matrix = (int**)malloc(20*sizeof(int*));
    for(int i = 0; i < 20; i++){
        matrix[i] = (int*)malloc(5*sizeof(int));
    }
    for(i = 0; i < 20; i++){
    for(j = 0; j < 5; j++){
            matrix[i][j] = -1;
        }
    }


    printAllPathsUntil(s,d,visited,path,&path_index,graph,list,matrix);
   for(i = 0; i < 20; i++){
        for(j = 0; j < 5; j++){
            if(matrix[i][j] != -1){
                    if(matrix[i][j] == s){
                        aeroporto = findAeroportoIndex(matrix[i][j], list);
                        printf("%s(%s):\n",aeroporto.nomeAeroporto,aeroporto.nomeCitta);
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
     if(matrix[i][--j] != -1)
            printf("\n");
   }
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




