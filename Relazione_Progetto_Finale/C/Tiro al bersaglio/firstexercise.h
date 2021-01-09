#include "stdlib.h"
#include "time.h"
#include <stdio.h>
//DEFINE PER LA MAPPATURA DEL TABELLONE
#define rosso 6
#define arancione 1
#define verde 3

#ifndef PROGETTO_FINALE_ESAME_FIRSTEXERCISE_H
#define PROGETTO_FINALE_ESAME_FIRSTEXERCISE_H

//CREAZIONE DELLA STRUTTURA DI UN GIOCATORE, CARATTERIZZATO DA UN NOME, DAL TIRO EFFETTUATO E DAI PUNTI TOTALI TOTALIZZATI.
struct giocatori{
    char *nome;
    int tiro;
    int punti;
};

typedef struct giocatori Giocatori;

//IL TABELLONE E' STATO CREATO COME UNA VARIABILE GLOBALE
int tabellone[7][5];

//PROTOTIPI DELLE FUNZIONI
void tiro(int *);
void mappatura_tabellone(int [7][5]);
void conteggio_tiri(Giocatori [], int *, int *);


#endif //PROGETTO_FINALE_ESAME_FIRSTEXERCISE_H
