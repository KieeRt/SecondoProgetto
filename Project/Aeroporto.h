#ifndef AEROPORTO_H_INCLUDED
#define AEROPORTO_H_INCLUDED

struct TAeroporto{
    char* nomeAeroporto;
    char* nomeCitta;
    int popolarita;
    int costoVita;
};
typedef struct TAeroporto Aeroporto;

Aeroporto initAeroporto();
#endif // AEROPORTO_H_INCLUDED
