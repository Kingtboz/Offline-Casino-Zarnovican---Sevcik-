#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void slotMachine(int* balance) {
    int bet = 15; // Vklad pro tuto hru

    // Kontrola zůstatku
    if (*balance < bet) {
        printf("Nedostatecny zustatek pro hru.\n");
        return;
    }

    *balance -= bet; // Odčítání vkladu

    printf("Hra 'Automaty' - Vsadili jste %d kreditu.\n", bet);

    int num1 = rand() % 10; // První náhodné číslo od 0 do 9
    int num2 = rand() % 10; // Druhé náhodné číslo od 0 do 9
    int num3 = rand() % 10; // Třetí náhodné číslo od 0 do 9

    printf("Výsledek automatu: %d %d %d\n", num1, num2, num3);

    if (num1 == num2 && num2 == num3) {
        int win = bet * 100;
        *balance += win;
        printf("Vsechna tri cisla se shoduji! Vyhravate %d kreditu. Vas zustatek je nyni %d.\n", win, *balance);
    }
    else {
        printf("Cisla se neshoduji. Vas zustatek je nyni %d kreditu.\n", *balance);
    }
}