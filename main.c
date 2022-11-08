#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mundial.h"


int main(){

    MundialP m1=crearMundial(2022, "ARGENTINA", "LEON");
    mostrarMundial(m1);

    agregarEstadio(m1,"MESSI","BARSA", 89000);
    agregarEstadio(m1,"RONALDO","MADRID",43200);
    agregarEstadio(m1,"ROMAN","LA BOCA",49000);
    agregarEstadio(m1,"ARABE","DOHA",45000);

    mostrarMundial(m1);

    buscarEstadioPorCiuYCapa(m1,"DOHA",45000);

    guardarMundial(m1);

    return 0;
}
