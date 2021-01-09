#include "secondexercise.h"
//E' STATA FATTA LA SCELTA DI CREARE TRE ARRAY DI TIPO SQUADRA PER PERMETTERE ALLA FUNCTION SCONTRI DI ESSERE UTILIZZATA PIU' VOLTE CON DIVERSI PARAMETRI DI INPUT E DI OUTPUT
//L'ALGORITMO DI BASE CREA IN MODO TOTALMENTE RANDOMICO DELLE SQUADRE TRAMITE L'ASSEGNAZIONE DI 11 GIOCATORI DETERMINATI DA UN NOME, UN COGNOME, UN PESO E IL NUMERO DELLA MAGLIA, UNICO PER OGNUNO DI LORO ALL'INTERNO DELLA SQUADRA
//AVVIANDO IL PROGRAMMA SI AVRA' DIRETTAMENTE LA FINE DELL'ALGORITMO CON L'ESECUZIONE SENZA ALCUN PRINT, BASTERA' TOGLIERE I COMMENTI AI VARI PRINT ALL'INTERNO DEL MAIN PER POTER TENER TRACCIA DI TUTTI E CENTO I TORNEI CHE VERRANNO EFFETTUATI

int main() {
    srand(time(NULL));
    Squadre teams[8];
    int pesi_squadra[11] = {0};
    Squadre quarti[4];
    Squadre semifinale[2];
    Squadre finalista[1];


    //CHIAMATE ALLE FUNCTION
    crea_squadre(teams);
    calcola_pesi(pesi_squadra,teams);


// DA QUI INIZIA IL VERO E PROPRIO ALGORITMO ALL'INTERNO DI UN CICLO WHILE CHE PERMETTE DI CONTIUNUARE LE ITERAZIONI FINO AL RAGGIUNGIMENTO DI CENTO TORNEI EFFETTUATI
//VERRA' CHIAMATA LA FUNCTION SCONTRI 3 VOLTE PER 100 VOLTE, UNA VOLTA PER LE 8 SQUADRE IN TOTALE, LA SECONDA VOLTA PER LE 4 VINCITRICI E COSI' VIA FINO AL VINCITORE FINALE
    int giocate_tot = 0;
    while (giocate_tot<100){
        //printf("\nTORNEO N %d\n", giocate_tot+1);
        scontri(teams,8,quarti);
        //printf("\nQUARTI DI FINALE GIOCATI DA:\n");
        //for (int i = 0; i < 8; ++i) {
           // printf("%d\t", teams[i].n_squadra);
        //}
        //printf("\nSEMIFINALI GIOCATE DA :\n");
        scontri(quarti,4,semifinale);
        //for (int i = 0; i < 4; ++i) {
          //  printf("%d\t", quarti[i].n_squadra);
        //}
        //printf("\nFINALISTI:\n");
        scontri(semifinale,2,finalista);
        //for (int i = 0; i < 2; ++i) {
          //  printf("%d\t", semifinale[i].n_squadra);
        //}
        //printf("\nVINCITORE : %d\n", finalista[0].n_squadra);

        for (int i = 0; i < 8; ++i) {
            if (finalista[0].n_squadra==teams[i].n_squadra)
                teams[i].vittorie++;
        }
    giocate_tot++;
}

    //VIENE RICHIAMATO L'ORDINAMENTO CHE FA RIFERIMENTO AL TIPO INTERO VITTORIE ALL'INTERNO DELLA STRUCT SQUADRA
    ordinamento_per_inserimento(teams,8);




//PRINT FINALI PER LA VISUALIZAZZIONE DEL VINCITORE E DELLA FORMAZIONE DELLA SQUADRA VINCENTE.
    printf("CLASSIFICA TORNEO:\n");
    for (int i = 0; i < 8; ++i) {
        printf("%d) Squadra %d - Vittorie : %d - Peso : %d\n", i+1,teams[i].n_squadra, teams[i].vittorie, teams[i].peso);
    }
    printf("\nFORMAZIONE DELLA SQUADRA VINCENTE (SQUADRA %d) :\n", teams[0].n_squadra);

    for (int i = 0; i < 11; ++i) {
        printf("Nome: %c\t Cognome: %c\tNumero Maglia: %d\tPeso: %d\n", teams[0].giocatori[i].nome, teams[0].giocatori[i].cognome, teams[0].giocatori[i].numero_maglia, teams[0].giocatori[i].peso);

    }



    return 0;
}




