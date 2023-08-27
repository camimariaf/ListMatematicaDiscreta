/*
Escrever um programa para listar números primos sequencialmente. Você deve
otimizar o programa para que ele liste o maior número possível de primos em 60
segundos.*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void primo(int num, int contador) {
    if (num % contador == 0 || num < 2) {

        return;
    }
    if (contador <= sqrt(num)){
        printf("%d\n", num);
        return;
    }
    contador += 1;
    return primo(num, contador);
}

void loop(time_t end_time,int num) {
    if (time(NULL) >= end_time)
    {
        return;
    }
    primo(num,2);
    num++;
    return loop(end_time,num);
}
int main(){
    time_t start_time = time(NULL);
    time_t end_time = start_time + 60;
    int num = 1;
    loop(end_time,num);
    return 0;
}