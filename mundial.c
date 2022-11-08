#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mundial.h"
#include "estadio.h"
#define TAM 8

struct MundialE{
    int anio;
    char pais[20];
    char mascota[20];
    EstadioP estadios[TAM];
};



MundialP crearMundial(int n, char p[], char mas[]){
    MundialP m = malloc(sizeof(struct MundialE));

    m->anio=n;
    strcpy(m->pais, p);
    strcpy(m->mascota,mas);

    for(int i=0; i<TAM; i++){
        m->estadios[i]=cargarEstadioVacio();
    }


    return m;
};
void mostrarMundial(MundialP m){
    printf("\n---MUNDIAL---\n");
    printf("ANIO: %d",m->anio);
    printf("\nPAIS: %s",m->pais);
    printf("\nMASCOTA: %s",m->mascota);

    for(int i=0; i<TAM; i++){
        mostrarEstadio(m->estadios[i]);
    }

};

int buscarEstadioVacio(MundialP m){
    int pos=-1;

    for(int i=0; i<TAM; i++){
        if(getCapacidad(m->estadios[i])==-1){
            pos=i;
            i=TAM+1;
        }
    }


    return pos;
};

void agregarEstadio(MundialP m, char n[], char ciu[], int capa){
    int posVacia=-1;
    posVacia=buscarEstadioVacio(m);

    for(int i=0; i<TAM; i++){
        if(posVacia!=-1){
            m->estadios[posVacia]=cargarEstadio(n,ciu,capa);
        }
    }

};
void buscarEstadioPorCiuYCapa(MundialP m, char ciudadABuscar[], int capacidadABuscar){
    int pos=-1;
    for(int i=0; i<TAM; i++){
        if((strcmp(getCiudad(m->estadios[i]),ciudadABuscar)==0)&& (getCapacidad(m->estadios[i]),capacidadABuscar)){
            pos=i;
            i=TAM+1;
        }
    }
    if(pos!=-1){
        printf("\n\nEl estadio se encontro en la posicion: %d",pos);
        mostrarEstadio(m->estadios[pos]);
    }

};

void guardarMundial(MundialP m){

    FILE * archivo;
    archivo = fopen("mundial.txt","w");
    fprintf(archivo,"%d;%s;%s",m->anio, m->pais, m->mascota);
    for(int i=0; i<TAM; i++){
        guardarEstadio(m->estadios[i]);
    }

};
