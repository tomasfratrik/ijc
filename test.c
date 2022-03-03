#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define GET_BIT(num,index) (num >> index) & 1

int main(){
    int velkost = 5; // 101
    int bit = GET_BIT(5,1);
    // int debil = (velkost & ;
    // printf("debil = %d\n",debil);
    if(GET_BIT(velkost,2)){
        printf("1\n");
        printf("cislo: %d\n",velkost);
    }
    else{
        printf("0\n");
        printf("cislo: %d\n",velkost);
    }
    printf("%ld\n",sizeof(unsigned long)*CHAR_BIT);
    printf("%d\n",(635/64));


}