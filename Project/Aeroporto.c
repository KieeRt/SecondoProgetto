#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Aeroporto.h"

Aeroporto initAeroporto(){
    Aeroporto aeroporto;
//    aeroporto.nomeAeroporto = (char*)malloc(sizeof(char)*20);
//    aeroporto.nomeCitta = (char*)malloc(sizeof(char)*20);
    aeroporto.popolarita = 0;
    aeroporto.costoVita = 0;

    return aeroporto;
}
