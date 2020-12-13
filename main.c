#include <stdio.h>
#include <stdlib.h>
#include "Algorithms.h"

int main(void){
    int num;
    printf("Please choose an option:\n");
    printf("1: Use the sieve algorithm\n");
    printf("2: Use the Base number\n");
    printf("Your choice:\n");
    scanf("%i",&num);
    switch(num){
        case 1:
            takeMinMax();
            checkMinMax();
            SievePrimes();
            break;

        case 2:
            printf("WARNING! This method is only precise for primes under 44!\n");
            takeMinMax();
            checkMinMax();
            printPrimesBase();
            break;

        default:
            printf("Please choose a valid option!");
    }
    return 0;
}
