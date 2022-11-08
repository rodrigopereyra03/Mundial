#ifndef ESTADIO_H_INCLUDED
#define ESTADIO_H_INCLUDED

struct EstadioE;

typedef struct EstadioE * EstadioP;

EstadioP cargarEstadio(char n[], char ciu[], int capa);
EstadioP cargarEstadioVacio();
void mostrarEstadio(EstadioP e);

int getCapacidad(EstadioP e);
char* getCiudad(EstadioP e);

void guardarEstadio(EstadioP e);
#endif // ESTADIO_H_INCLUDED
