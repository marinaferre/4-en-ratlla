// inicialitzacio de lo joc en si

#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct tauler {
    char taula[N+1][N+1]; // fico +1 per poder posar el /0 al final de tot
    int qui_juga;
    int qui_jugara;
    int columna;
    int fila;
} Tauler;

void imprimir(Tauler *t);
int inicialitzacio(Tauler *t);
void preguntem(Tauler *t, int torn_persona);
void apuntem(Tauler *t, int torn_persona);
void jugades(Tauler *t, int torn_persona);
int guanyar(char taula[N+1][N+1], char trobarX[], char trobarO[]);
