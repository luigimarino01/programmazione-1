#include <stdio.h>
#include "string.h"
#include "time.h"
#include "stdlib.h"
#ifndef SECONDO_ESERCIZIO_PROGETTO_FINALE_SECONDEXERCISE_H
#define SECONDO_ESERCIZIO_PROGETTO_FINALE_SECONDEXERCISE_H

//CREAZIONE DELLE STRUCT.
struct giocatore{
    char nome;
    char cognome;
    int numero_maglia;
    int peso;
};

struct squadra {
    int n_squadra;
    struct giocatore giocatori[11];
    int vittorie;
    int peso;
};
typedef struct giocatore Giocatore;
typedef struct squadra Squadre;

//PROTOTIPI DELLE FUNCTION
void crea_squadre(Squadre []);
void calcola_pesi(int [],Squadre []);
void ordinamento_per_inserimento(Squadre [], int );
int appartiene(Giocatore [], int );
void scontri(Squadre [], int, Squadre []);
int somma_pesi_ricDI(int [], int ,int );



#endif //SECONDO_ESERCIZIO_PROGETTO_FINALE_SECONDEXERCISE_H
