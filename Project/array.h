#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include "graph.h"
#include "list.h"



int* findScali(int *prev,int part, int *tmp,int pos);
//Restituisce il minimo di un array
int findMin (int* array , int n);;

void copyArray(int** a, int* b, int n);
void printPath(int* array, int n);


#endif // ARRAY_H_INCLUDED
