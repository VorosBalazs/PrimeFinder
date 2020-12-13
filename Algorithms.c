#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

const double base=2.9200509773161347;
int rd;
int i=0;
int min=0;
int max=0;
int swap=0;
double calc;
int j;
int k;
int l;

int* pfbase() {
    int* Primes = (int)malloc(sizeof(int));
    if(i==0){
        rd=(int)floor(base);
        calc=base;
        if(min<calc){
            Primes[i]=calc;
            i++;
            realloc(Primes, sizeof(int)*(i+1));
        }
    }
    while(calc<max){
        int rd=(int)floor(calc);
        calc=rd*(calc-rd+1);
        if(min<calc){
            Primes[i]=calc;
            i++;
            realloc(Primes, sizeof(int)*(i+1));
        }
    }
    return Primes;
}

void checkMinMax() {
    if (min>max) {
        swap=min;
        min=max;
        max=swap;
    }
    if (min==max) {
        printf ("Min and max can't be the same number!");
        exit(0);
    }
}

void takeMinMax() {
    printf("Please input the integer values you want to check between, separated by an enter:\n");
    scanf("%i%i",&min,&max);
}

void printPrimesBase() {
    int* p = pfbase();
    printf("Primes in the given range:\n");
    for(j=0;j+1<i;j++) {
        printf("%i\n", p[j]);
    }
    free(p);
}

void SievePrimes(){
    if(min<2){
        min=2;
    }

    bool Sieve[max+1];
    for(k=2; k*k<max;k++){
        if(Sieve[k]==false){
            for(l=k*k;l<=max;l+=k){
                Sieve[l]=true;
            }
        }
    }
    printf("Primes in the given range:\n");
    for(k=2;k<=max;k++){
        if(k>=min && Sieve[k]==false){
            printf("%i\n",k);
        }
    }
}

