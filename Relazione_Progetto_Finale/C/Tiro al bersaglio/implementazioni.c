
#include "firstexercise.h"
//FUNZIONE CHE GENERA CASUALMENTE UNA POSIZIONE ALL'INTERNO DEL TABELLONE ED ASSEGNA UN PUNTO IN BASE AL COLORE CORRISPONDENTE AL PUNTEGGIO
void  tiro(int *pt_tiro) {
    int i,j;                                    //PRENDE IN INPUT UN PUNTATORE
    i = rand()%7;                               //RANDOMIZZA UN PRIMO INDICE
    j = rand()%5;                               //RANDOMIZZA IL SECONDO INDICE
    *pt_tiro = tabellone[i][j];                 //ASSEGNA AL PUNTATORE IL VALORE DEL TABELLONE IN QUEL PUNTO
}

//A QUESTO PUNTO VIENE MAPPATO IL TABELLONE, VENGONO ASSEGNATI I COLORI ALLE CELLE DELLA MATRICE
void mappatura_tabellone(int tab[7][5]) {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 5; ++j) {
            tabellone[i][j] = arancione;
        }
    }
//ESCLUSIONE VERDE
    for (int i = 2; i < 5; ++i) {
        for (int j = 1; j < 4; ++j) {
            tabellone[i][j] = verde;
        }
    }
//ESCLUSIONE ROSSO
    tabellone[3][2] = rosso;
}

//FUNCTION CHE EFFETTUA IL CORPO PRINCIPALE DEL GIOCO, PERMETTE DI ESEGUIRE UN TIRO PER OGNI GIOCATORE E TIENE CONTO DI QUANTI TIRI E DEL PUNTEGGIO PIU' ALTO AL MOMENTO DEL TIRO, IN MODO DA POTERSI
//FERMARE AL RAGGIUNGIMENTO DI CENTO TIRI O DI UN PUNTEGGIO PARI A CENTO DA PARTE DI UN GIOCATORE, I TIRI VENGONO EFFETTUATI RICHIAMANDO LA FUNCTION TIRO ALL'INTERNO DI UN CICLO FOR E DOPODICHE' VIENE
//EFFETTUATA LA VERIFICA DEL TIRO PIU' ALTO FATTO, PIU' L'ASSEGNAZIONE IN UN ALTRO FOR ANCORA A CHI HA EFFETTUATO QUEL TIRO.
//TENER CONTO DI CHI E' IL VINCITORE PER OGNI TIRO EFFETTUATO E' FONDAMENTALE PER DECRETARE IL PUNTEGGIO FINALE.
//INPUT: ARRAY DI TIPO GIOCATORI, DUE VARIABILI DI INPUT.
//OUTPUT: ASSEGNAZIONE DI VALORI AI PARAMETRI DI INPUT. (VOID)
void conteggio_tiri(Giocatori players[], int *max_globale, int *max) {
    int tiri_tot = 0;
    //AFFINCHE' IL GIOCATORE IN TESTA ALLA CLASSIFICA NON TOTALIZZA 100 PUNTI OPPURE VENGONO EFFETTUATI 100 VOLTE I TIRI DEI GIOCATORI
    while (players[*max_globale].punti <= 100 && tiri_tot < 100) {

        //CHIAMATA DELLA FUNZIONE TIRO PER OGNI GIOCATORE
        //printf("\nTURNO: %d\n", tiri_tot+1);
        for (int i = 0; i < 5; ++i) {                   //ASSEGNA COME PARAMETRO LA VARIABILE TIRO DELLA STRUCT LA FUNZIONE TIRO E QUINDI ASSEGNERA' UN VALORE DEL TABELLONE A CASO
            tiro(&players[i].tiro);
           // printf("Giocatore %d : %d\n", i+1,players[i].tiro);
        }


        //VERIFICA DEL TIRO PIU' ALTO EFFETTUATO TRA I CINQUE GIOCATORI
        for (int i = 0; i < 5; ++i) {
            if (players[i].tiro > players[*max].tiro)
                *max = i;
        }

        //ASSEGNAZIONE DEI PUNTI A CHI EFFETTUA IL TIRO PIU' ALTO
        for (int i = 0; i < 5; ++i) {
            if (players[*max].tiro == players[i].tiro) {
                players[i].punti+=players[i].tiro;
            }
        }

        //QUESTO CICLO FOR CI PERMETTE DI TENERE NOTA DEL GIOCATORE PIU' ALTO IN CLASSIFICA AD OGNI TIRO EFFETTUATO, IN MODO DA POTER VEDERE IL VINCITORE "TEMPORANEO"
        for (int i = 0; i < 5; ++i) {
          //  printf("Punti giocatore %d : %d\n", i+1, players[i].punti);
            if (players[i].punti > players[*max_globale].punti)
                *max_globale = i;
        }

        tiri_tot++;
    }

}
