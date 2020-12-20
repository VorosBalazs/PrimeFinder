#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

const double base=2.9200509773161347;
int rd,i,j,k,swap,min,max;
double calc;

void pfbase() {
    int *Primes = (int)malloc(sizeof(int));
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
    printf("Primes in the given range:\n");
    for(j=0;j+1<i;j++) {
        printf("%i\n",Primes[j]);
    }
    free(Primes);

}

void checkMinMax(char *argv[]) {
    sscanf(argv[1],"%i",&min);
    sscanf(argv[2],"%i",&max);
    if(min==0 && argv[1]!='0') {
        printf("First argument is invalid, exiting\n");
        exit(1);
    }
    if(max==0 && argv[2]!='0') {
        printf("Second argument is invalid, exiting\n");
        exit(1);
    }
    if(min>max) {
        swap=max;
        max=min;
        min=swap;
    }
    if(min==max) {
        printf ("Min and max can't be the same number!");
        exit(1);
    }
}

void checkArguments(argc) {
    if(argc<4) {
        printf("Not enough arguments, please set all three!");
        exit(1);
    }
    if(argc>4) {
        printf("Too many arguments, please only set 3!");
        exit(1);
    }
}

void SievePrimes(){
    if(min<2){
        min=2;
    }

    bool Sieve[max+1];
    for(i=2; i*i<max;i++){
        if(Sieve[i]==false){
            for(j=i*i;j<=max;j+=i){
                Sieve[j]=true;
            }
        }
    }
    printf("Primes in the given range:\n");
    for(i=2;i<=max;i++){
        if(i>=min && Sieve[i]==false){
            printf("%i\n",i);
        }
    }
}

void ChooseMethod(char *argv[]) {
    int method;
    sscanf(argv[3],"%i",&method);
    if(method==0) {
        printf("Invalid method number, exiting\n");
        exit(1);
    }
    switch(method) {
        case 1:
            pfbase();
            break;
        case 2:
            SievePrimes();
            break;
        case 3:
            FindPrimes();
            break;
        default:
            printf("Invalid method number,exiting\n");
            exit(1);
    }
}

void FindPrimes() {
    if(min<2) {
        min=2;
    }
    bool Find[max+1];
    for(i=2;i<=max;i++) {
        j=2;
        while(i%j!=0 && j<i) {
            j++;
        }
        if(j==i) {
            Find[i]=true;
        }
        if(j!=i) {
            Find[i]=false;
        }
    }
    printf("Primes in the given range:\n");
    for(k=2;k<=max;k++) {
        if(k>=min && Find[k]==true) {
            printf("%i\n",k);
        }
    }
}

