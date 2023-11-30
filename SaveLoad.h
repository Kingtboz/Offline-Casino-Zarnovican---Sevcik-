#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void saveBalance(int balance) {
    FILE* file = fopen("balance.txt", "w");
    if (file == NULL) {
        printf("Nelze otevrit soubor pro ulozeni zustatku.\n");
        return;
    }
    fprintf(file, "%d", balance);
    fclose(file);
}

int loadBalance() {
    FILE* file = fopen("balance.txt", "r");
    if (file == NULL) {
        return 0;  // Ak subor neexistuje, dostaneme 0
    }
    int balance;
    fscanf(file, "%d", &balance);
    fclose(file);
    return balance;
}
