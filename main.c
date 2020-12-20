#include <stdio.h>
#include <stdlib.h>
#include "Algorithms.h"
//Please set arguments before running the program
//The three arguments should be the lower and upper limit of the check, and which method to use
//Method 1 uses the base number, method 2 is the sieve, method 3 is a normal prime finder algorithm
//Method 1 is only accurate up to 43, as it needs a really precise Base number for it to work
//Please don't use method 3 for large numbers, calculating all the primes up to one million took this method 2 minutes

int main(int argc,char *argv[]){
    checkArguments(argc);
    checkMinMax(argv);
    ChooseMethod(argv);
    return 0;
}
