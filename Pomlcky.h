#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dashRace(int* balance) {
    int bet = 5; // Vklad pro tuto hru

    // Kontrola zůstatku
    if (*balance < bet) {
        printf("Nedostatecny zustatek pro hru.\n");
        return;
    }

    *balance -= bet; // Odčítání vkladu

    printf("Hra 'Zavod Pomlcek' - Vsadili jste %d kreditu.\n", bet);
    printf("Vyberte pomlcku (1, 2 nebo 3): ");
    int playersChoice;
    scanf("%d", &playersChoice);

    if (playersChoice < 1 || playersChoice > 3) {
        printf("Neplatny vyber. Vyberte 1, 2 nebo 3.\n");
        *balance += bet; // Vrácení vkladu
        return;
    }

    int positions[3] = { 0, 0, 0 }; // Pozice pomlček
    int winner = 0;
    while (winner == 0) {
        system("cls");  // Čistí konzolu v systému Windows

        for (int i = 0; i < 3; i++) {
            positions[i] += rand() % 3; // Posun každé pomlčky o 0, 1 nebo 2
            if (positions[i] >= 10) {
                winner = i + 1;
                break;
            }
        }

        // Výpis pozic
        for (int i = 0; i < 3; i++) {
            printf("%d: ", i + 1);
            for (int j = 0; j < positions[i]; j++) {
                printf("-");
            }
            printf("\n");
        }
    }

    printf("Pomlcka %d vyhrava!\n", winner);

    if (playersChoice == winner) {
        int win = bet * 5;
        *balance += win;
        printf("Vyhravate! Vas zustatek je nyni %d kreditu.\n", *balance);
    }
    else {
        printf("Nevyhravate. Vas zustatek je nyni %d kreditu.\n", *balance);
    }
}
