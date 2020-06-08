#include <stdio.h>
#include <stdlib.h>
#include "Utente.h"
#include "list.h"
#include "graph.h"
#include "file.h"

int* findScali(int *prev,int part, int *tmp,int pos);

int main()
{
    List aeroportiList = initNodeListFromFile();
    Graph graph = createGraph(numeroAeroporto(aeroportiList));
    createEdgeFromFile(graph, aeroportiList);
//    List tmp = copyList(graph->adjList[0]);

  //  MergeSort(&tmp, 1);

    //printAereoporto(tmp);

   // welcome(graph,aeroportiList);


    int dist [20];

    int prev[20];
    shortestPathPrice( graph, &dist, &prev,  0,  aeroportiList);

    for(int j =0; j<20;j++)
        printf("%d %d prev%d\n",j,dist[j],prev[j]);

    printOrder(dist,20,aeroportiList,prev,0);

    return 0;
}

void printOrder (int *array, int n, List list, int * prev,int src){
    int min;
    int i =0;
    Aeroporto a1 ;
    Aeroporto a2 ;
    a2= findAeroportoIndex(src,list);



    while(true){
        if (array[i] != 9999 && array[i] != 0){
            min = findMin(array,n);
            if(array[min] != 9999    ){
                a1= findAeroportoIndex(min,list);
                printf("%s (%s) ->",a2.nomeCitta ,a2.nomeAeroporto);
                 if(a1.index != src)
                    printf("\t\t%s (%s) Costo volo:%d",a1.nomeCitta,a1.nomeAeroporto,array[min]);

                    int * tmp = (int*)calloc(sizeof(int),20);
                    tmp=findScali(prev, min, tmp,0);

                    int j=0;

                    while(tmp[j]!=0){
                        a1= findAeroportoIndex(tmp[j],list);
                        printf(" ->%s  ",a1.nomeAeroporto);
                        j++;
                    }
                    if(j == 0 && a1.index != src )
                        printf(" ->Non presenti");


                    free(tmp);
                    array[min]=9999;
                    printf("\n\n");

            }else{
                break;
            }
        }
        i++;
    }

    printf("\n\n");


}

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





