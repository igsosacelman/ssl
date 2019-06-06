#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void* lut = [f1,f2];

void main (void){

    lut[0]();
    
}

void f1(){
    printf("f1\n");

}

void f2(){
    printf("f2\n");

}