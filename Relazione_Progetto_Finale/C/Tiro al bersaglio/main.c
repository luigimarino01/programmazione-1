#include "firstexercise.h"
//ALL'INTERNO DI QUESTO ALGORITMO E' STATO UTILIZZATO UNO SWITCH PER POTER SCEGLIERE TRA LE OPZIONI PROPOSTE ALL'INIZIO DEL PROGRAMMA.
//COME INIZIARE IL GIOCO, VISUALIZZARE IL REGOLAMENTO O USCIRE DAL PROGRAMMA.
//AVVIANDO IL PROGRAMMA CI SARA' DIRETTAMENTE LA PROCLAMAZIONE DEL VINCITORE, ALL'INTERNO DELLA RELAZIONE CI SARANNO DELLE DIMOSTRAZIONI TRAMITE PRINTF DEI VARI PUNTEGGI E DEI TIRI EFFETTUATI
//E' STATA FATTA LA SCELTA DI COMMENTARE TUTTI I PRINTF DEI PUNTEGGI PER NON RIEMPIRE LA CONSOLE DI PRINT, BASTERA' RIMUOVERE I COMMENTI DALLE FUNCTION PER POTER VERIFICARE PASSO PASSO I PUNTEGGI.

int main() {
    srand(time(NULL));
    Giocatori players[5];
    players[0].nome = "Giocatore1";
    players[1].nome = "Giocatore2";
    players[2].nome = "Giocatore3";
    players[3].nome = "Giocatore4";
    players[4].nome = "Giocatore5";

    int max = 0, max_globale = 0, scelta = 10;

    while (scelta!=3) {
        printf("Benvenuto nel gioco delle freccette\n1)Inizia a giocare\n2)Regolamento\n3)Esci\n");
        scanf("%d",&scelta);
    switch (scelta) {
        case 1:
            //INIZIALIZZAZIONE DEI PUNTI TOTALI DEI GIOCATORI
            for (int i = 0; i < 5; ++i) {
                players[i].punti = 0;
            }

            //CHIAMATE ALLE FUNCTION
            mappatura_tabellone(tabellone);
            conteggio_tiri(players, &max_globale, &max);

            printf("\n IL VINCITORE E' %s CON UN PUNTEGGIO TOTALE DI %d!\n", players[max_globale].nome, players[max_globale].punti);
            system("pause");
            break;

        case 2:
            printf("REGOLAMENTO:\nOgni giocatore effettua il suo lancio e viene assegnato il punteggio al giocatore con il lancio piu' vicino al centro.\nSe il punteggio piu' alto si ripete, viene assegnato ai corrispettivi giocatori il punteggio massimo.\n");
            printf("Il primo giocatore che arriva a 100 punti e' il vincitore, altrimenti, al termine di 100 turni automaticamente\nverra' scelto un vincitore in base al punteggio.\n");
            system("pause");
            break;

        case 3:
            return 0;

        default:
            printf("Operazione non consentita.\n");
    }
    }
    }
    


