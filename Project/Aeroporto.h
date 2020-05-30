#ifndef AEROPORTO_H_INCLUDED
#define AEROPORTO_H_INCLUDED

struct TAeroporto{
    char nomeAeroporto[30];
    char nomeCitta [30];
    int popolarita;
    int costoVita;
};
typedef struct TAeroporto Aeroporto;

Aeroporto initAeroporto();
#endif // AEROPORTO_H_INCLUDED
