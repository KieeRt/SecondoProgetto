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

    strcpy(aeroporto.nomeAeroporto, doSceltaStringZero("-Nome Aeroporto(IATA)(0 per uscire)\nInput -> ",0, 3, 256));
        if(!strcmp(aeroporto.nomeAeroporto, "0")){
            aeroporto.index = -1;
            return aeroporto;
        }

    upperCase(aeroporto.nomeAeroporto);
    strcpy(aeroporto.nomeCitta, doSceltaStringZero("-Nome Citta(0 per uscire)\nInput -> ", 0, 2, 256));
        if(!strcmp(aeroporto.nomeCitta, "0")){
            aeroporto.index = -1;
            return aeroporto;
        }
    upperCase(aeroporto.nomeCitta);
    aeroporto.costoVita = doSceltaIntZero("-Costo vita(0 per uscire)\nInput->",500000);
        if(aeroporto.costoVita == 0){
            aeroporto.index = -1;
            return aeroporto;
        }
    aeroporto.popolarita = doSceltaIntZero("-Popolarita\nInput->",5000);
    aeroporto.index = 0;

    return aeroporto;
}
