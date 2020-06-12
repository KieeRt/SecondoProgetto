#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Aeroporto.h"

Aeroporto initAeroporto(){
    Aeroporto aeroporto;
    aeroporto.popolarita = 0;
    aeroporto.costoVita = 0;
    aeroporto.index = -1;
    return aeroporto;
}



Aeroporto insertAeroporto(){
    Aeroporto aeroporto;

    strcpy(aeroporto.nomeAeroporto, doSceltaString("-Nome Aeroporto\nInput -> ",0, 2, 256));
    upperCase(aeroporto.nomeAeroporto);
    strcpy(aeroporto.nomeCitta, doSceltaString("-Nome Citta\nInput -> ", 0, 2, 256));
    upperCase(aeroporto.nomeCitta);
    aeroporto.costoVita = doSceltaInt("-Costo vita\nInput->",500000);
    aeroporto.popolarita = doSceltaIntZero("-Popolarita\nInput->",5000);
    aeroporto.index = -1;

    return aeroporto;
}
