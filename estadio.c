#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estadio.h"


struct EstadioE{
    char nombre[30];
    char ciudad[30];
    int capacidad;

};


EstadioP cargarEstadio(char n[], char ciu[], int capa){
    EstadioP e = malloc(sizeof(struct EstadioE));
    strcpy(e->nombre,n);
    strcpy(e->ciudad, ciu);
    e->capacidad=capa;


    return e;
};
EstadioP cargarEstadioVacio(){
    EstadioP e = malloc(sizeof(struct EstadioE));
    strcpy(e->nombre,"VACIO");
    strcpy(e->ciudad,"VACIO");
    e->capacidad=-1;

    return e;
};
void mostrarEstadio(EstadioP e){
    printf("\n--ESTADIO--\n");
    printf("NOMBRE: %s",e->nombre);
    printf("\nCIUDAD: %s",e->ciudad);
    printf("\nCAPACIDAD: %d",e->capacidad);

};

void guardarEstadio(EstadioP e){

    FILE * archivo;
    archivo=fopen("estadio.txt","a");
    if(e->capacidad!=-1){
        fprintf(archivo,"\n%s;%s;%d",e->nombre, e->ciudad, e->capacidad);
    }


    fclose(archivo);

};


int getCapacidad(EstadioP e){
    return e->capacidad;
};
char* getCiudad(EstadioP e){
    return e->ciudad;
};


