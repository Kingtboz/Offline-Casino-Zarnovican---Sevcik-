#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void guessTheNumber(int* balance) {
    int bet = 10; // Vklad pro tuto hru

    // Kontrola zůstatku
    if (*balance < bet) {
        printf("Nedostatecny zustatek pro hru.\n");
        return;
    }

    *balance -= bet; // Odčítání vkladu

    printf("Hra 'Do kolko?' - Vsadili jste %d kreditu.\n", bet);
    printf("Pocitac si vybral cislo od 1 do 15. Zkuste uhodnout, ktere to je: ");

    int playersGuess;
    scanf("%d", &playersGuess);

    // Kontrola, zda je hádané číslo v platném rozsahu
    if (playersGuess < 1 || playersGuess > 15) {
        printf("Neplatny vstup, cislo musi byt od 1 do 15.\n");
        *balance += bet; // Vrácení vkladu zpět kvůli neplatnému vstupu
        return;
    }

    int computerNumber = rand() % 15 + 1; // Náhodné číslo od 1 do 15

    printf("Pocitac si vybral cislo %d.\n", computerNumber);

    if (playersGuess == computerNumber) {
        int win = bet * 3;
        *balance += win;
        printf("Uhodli jste! Vyhravate %d kreditu. Vas zustatek je nyni %d.\n", win, *balance);
    }
    else {
        printf("Nevyhravate. Vas zustatek je nyni %d kreditu.\n", *balance);
    }
            char znovuHra;
    printf("Chces hrat znovu? (yes/no)\n");
    scanf(" %c", &znovuHra);

    if (znovuHra == 'y' || znovuHra == 'Y') {
        guessTheNumber(balance);
    }
}
