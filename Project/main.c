#include <stdio.h>
#include <stdlib.h>
#include "Utente.h"
#include "list.h"
#include "graph.h"
#include "file.h"



List checkPrice2(int *array, int n, List list, int max);
List headNode(List lista);
List insertListNoAeroporto(List lista, List nodo);
void bubbleSort(int *array, int n);
List checkPrice(int * array,int n, List list, int max);

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

    printOrder(dist,20,aeroportiList,prev);


    return 0;
}

void printOrder (int *array, int n, List list, int * prev){
    int min;
    int i =0;
    Aeroporto a1 ;

    while(true){
        if (array[i] != 9999 && array[i]!=0){
            min = findMin(array,n);
            if(array[min] != 9999){
                a1= findAeroportoIndex(min,list);
                printf("%s %d\n",a1.nomeAeroporto,array[min]);
                array[min]=9999;
            }else{
                break;
            }
        }
        i++;
    }

    printf("\n\n");
    int index=-1;
    i=0;
    while(i!=20){
        if( prev[i]!=-1 ){
            index = findScali(prev,i);
            printf("%d %d\n",i,index);
        }
        i++;
    }

}

int findScali(int *prev,int part){
    int i =0;
    int index;
    // A partire da un indice trovo i predecessori e looppo finche non trovo 0
    while()


    return prev[part];
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





