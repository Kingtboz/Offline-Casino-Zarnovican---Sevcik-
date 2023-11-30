#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DoKolko.h"
#include "SaveLoad.h"
#include "Pomlcky.h"
#include "Automatos.h"


//Funkcie hier a ukladania ci loadovania zostatku
void slotMachine(int* balance);
void dashRace(int* balance);
void guessTheNumber(int* balance);
void saveBalance(int balance);
int loadBalance();

int main() {
    srand((unsigned int)time(NULL));

    int balance = loadBalance();
    if (balance == 0) {
        balance = 100;  // Startovnz kredit je 100
    }

    do {
        printf("VITEJTE V KASINU!\n");
        printf("\nVas aktualni zustatek je: %d kreditu.\n \n", balance);
        printf("HLAVNI NABIDKA:\n");
        printf("1. Automaty\n");
        printf("2. Zavod Pomlcek\n");
        printf("3. Do kolko?\n");
        printf("\n4. Ulozit zustatek a ukoncit hru\n");

        int choice;
        printf("\nZadejte cislo hry: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            slotMachine(&balance);
            break;
        case 2:
            dashRace(&balance);
            break;
        case 3:
            guessTheNumber(&balance);
            break;
        case 4:
            saveBalance(balance);
            printf("Vas zustatek byl ulozen. Nashledanou.\n");
            return 0;
        default:
            printf("Neplatna volba. Zkuste to znovu.\n");
        }
    } while (balance > 0);

    printf("Vycerpali jste svuj zustatek. Konec hry.\n");
    return 0;
}



