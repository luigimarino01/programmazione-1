#include "secondexercise.h"

//LA FUNCTION RICORSIVA CON APPROCCIO DIVIDA ET IMPERA PER LA SOMMA DI ELEMENTI ALL'INTERNO DI UN ARRAY, IN QUESTO CASO FA RIFERIMENTO ALL'ARRAY PESI_SQUADRA E VIENE RICHIAMATA ALL'INTERNO DELLA FUNCTION CALCOLA PESI
//INPUT : ARRAY, INDICE INIZIALE, INDICE FINALE.
//OUTPUT: LA SOMMA TOTALE DEGLI ELEMENTI DELL'ARRAY.
int somma_pesi_ricDI(int a[], int primo, int  ultimo) {
    int mediano;
    if (primo==ultimo)
        return a[primo];
    else {
        mediano = (primo + ultimo)/2;
        return
        somma_pesi_ricDI(a, primo, mediano) + somma_pesi_ricDI(a, mediano +1,ultimo);
    }
}

//FUNCTION  PERMETTE LA CREAZIONE DELLE SQUADRE IN MODO TOTALMENTE CASUALE, ASSEGNANDO UNA LETTERA PER IL NOME, UNA PER IL COGNOME, UN PESO DA 60 A 95 E UN NUMERO DI MAGLIA PER 11 GIOCATORI, OGNI VOLTA VERRA' RIPETUTA
//PER 8 SQUADRE IN TOTALE, ALL'INTERNO APPUNTO DI DUE CICLI FOR.
//E' COMPRESA L'INIZIALIZZAZIONE DELL'INTERO VITTORIE E L'ASSEGNAZIONE DI UN NUMERO DELLA SQUADRA IN DIPENDENZA DELL'INDICE I.
//VIENE ANCHE RICHIAMATA LA FUNCTION APPARTIENE ALL'INTERNO DI UN WHILE PER PERMETTERE L'ASSEGNAZIONE DI UN NUMERO CHE NON SIA GIA STATO ASSEGNATO AD UN GIOCATORE DELLA STESSA SQUADRA.
//INPUT: ARRAY DI TIPO SQUADRA.
//OUTPUT: LA FUNCTION E' UNA VOID CHE MODIFICA I VALORI DEL PARAMETRO DI INPUT.
void crea_squadre(Squadre teams[]) {
    for (int i = 0; i < 8; ++i) {
        teams[i].n_squadra = i + 1;
        teams[i].vittorie = 0;
        for (int j = 0; j < 11; ++j) {
            teams[i].giocatori[j].nome = 'A' + (rand() % 26);
            teams[i].giocatori[j].cognome = 'A' + (rand() % 26);
            teams[i].giocatori[j].peso = 60 + rand()%(96-60);
            teams[i].giocatori[j].numero_maglia = 100;
            int k = 0;
            while (k<1) {
                int tmp = rand()%11;
                if (!appartiene(teams[i].giocatori,tmp)) {
                    k++;
                    teams[i].giocatori[j].numero_maglia = tmp;
                }
            }
            }
        }
    }

//LA FUNCTION UTILIZZA DUE CICLI FOR, UNO PER SCORRERE LE SQUADRE, UNO PER I GIOCATORI.
//UTILIZZA UN ARRAY CHIAMATO PESI SQUADRA DI SIZE 11 PER PERMETTERE DI INSERIRE I PESI DEI SINGOLI GIOCATORI PER OGNI SQUADRA, SUCCESSIVAMENTE TRAMITE LA CHIAMATA ALLA FUNCTION
//SOMMA PESI RICDI, VERRA' SOMMATO ALL'INTERNO DI TEAMS.PESO (OVVERO DELLA VARIABILE CHE CONTIENE IL PESO TOTALE DI UNA SQUADRA) QUELL'ARRAY.
//INPUT: ARRAY DI TIPO SQUADRA, ARRAY DI TIPO INTERI.
//OUTPUT: LA FUNCTION E' UNA VOID CHE MODIFICA I VALORI DEL PARAMETRO DI INPUT DI TIPO SQUADRA.
void calcola_pesi(int pesi_squadra[], Squadre teams[]) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 11; ++j) {
            pesi_squadra[j] = teams[i].giocatori[j].peso;
        }
        teams[i].peso = somma_pesi_ricDI(pesi_squadra, 0, 10);
    }
}

//L'ALGORITMO DI ORDINAMENTO PER INSERIMENTO PER IL TIPO SQUADRA.
//INPUT: ARRAY DI TIPO SQUADRA, ARRAY DI TIPO INTERO.
//OUTPUT: LA FUNCTION E' UNA VOID CHE MODIFICA I VALORI DEL PARAMETRO DI INPUT DI TIPO SQUADRA.
void ordinamento_per_inserimento(Squadre a[], int n){

    int i,j;
    Squadre el_da_ins;

    for (i=1;i<n;i++)
    {
        j = i-1;
        el_da_ins = a[i];

        while (j>=0 && el_da_ins.vittorie>a[j].vittorie)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = el_da_ins;
    }
}

//FUNCTION CHE DETERMINA L'APPARTENENZA DI UN VALORE ALL'INTERNO DI UN ARRAY.
//INPUT: ARRAY DI TIPO GIOCATORE, VARIABILE DI TIPO INT.
//OUTPUT: 0 o 1 IN BASE ALL'APPARTENENZA O ALLA NON APPARTENENZA.
int appartiene(Giocatore arr[], int chiave) {
    for (int i = 0; i < 11; ++i) {
        if (chiave==arr[i].numero_maglia)
            return 1;
    }
    return 0;
}


//FUNZIONE PRINCIPALE CHE PERMETTE LO SVOLGIMENTO DEL TORNEO, PRENDENDO IN INPUT ANCHE UN INDICE, RIESCE A CALCOLARE SOLO PER LE SQUADRE CHE VENGONO IMMESSE IL LORO PESO MOLTIPLICATO
//PER UN NUMERO CASUALE NELL'INTERVALLO (0..1) E CONFRONTARLO CON LA SQUADRA AVVERSARIA, PER POI COPIARE SOLAMENTE I VINCITORI ALL'INTERNO DI UN ARRAY CONTENENTE GLI INDICI DELLE SQUADRE VINCENTI.
//PER OGNI SCONTRO PRENDERA' COME INPUT UN ARRAY SEMPRE PIU' PICCOLO COSI' DA POTER DETERMINARE SEMPRE IL VINCITORE DI OGNI SCONTRO, FINO AL FINALISTA.
//INPUT: UN ARRAY DI TIPO SQUADRE, CHE CAMBIERA' OGNI VOLTA, UNA VARIABILE DI TIPO INTERO CHE FA DA INDICE E UN ARRAY DI TIPO SQUADRA CHE CAMBIERA' OGNI VOLTA.
//OUTPUT: LA FUNCTION E' UNA VOID CHE MODIFICA I VALORI DEL PARAMETRO DI INPUT COPIA DI TIPO SQUADRA.
void scontri(Squadre pesi[],int ind, Squadre copia[]) {
    int peso1 = 0, peso2 = 0, cont = 0;

    for (int i = 0; i < ind; i+=2) {
        peso1 = pesi[i].peso*(rand()/(double)RAND_MAX);
        peso2 = pesi[i+1].peso*(rand()/(double)RAND_MAX);
        if (peso1>peso2)
            copia[cont] = pesi[i];
         else
            copia[cont] = pesi[i+1];
        cont++;
    }
}








