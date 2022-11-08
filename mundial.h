#ifndef MUNDIAL_H_INCLUDED
#define MUNDIAL_H_INCLUDED

struct MundialE;

typedef struct MundialE * MundialP;

MundialP crearMundial(int n, char p[], char mas[]);
void mostrarMundial(MundialP m);

void agregarEstadio(MundialP m, char n[], char ciu[], int capa);

void buscarEstadioPorCiuYCapa(MundialP m, char ciudadABuscar[], int capacidadABuscar);

void guardarMundial(MundialP m);
#endif // MUNDIAL_H_INCLUDED
