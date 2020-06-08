#ifndef AEROPORTO_H_INCLUDED
#define AEROPORTO_H_INCLUDED

struct TAeroporto{
    char nomeAeroporto[30];
    char nomeCitta [30];
    int popolarita;
    int costoVita;
    int index;
};
typedef struct TAeroporto Aeroporto;

Aeroporto initAeroporto();

Aeroporto insertAeroporto();

//void printAereoportoArray(int *array , List list ,int dim);

#endif // AEROPORTO_H_INCLUDED
