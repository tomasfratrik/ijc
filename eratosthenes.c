#include "bitset.h"
#include<math.h>

void Eratosthenes(bitset_t bitset_arr){
    
    unsigned long zero = 0;
    unsigned long one = 1;
    bitset_setbit(bitset_arr,zero, 1);
    bitset_setbit(bitset_arr,one , 1);

    unsigned long size = bitset_size(bitset_arr);
    unsigned long condition = sqrt(size);



    for(unsigned long i = 2; i <= condition;i++){
        if(bitset_getbit(bitset_arr,i) == 0){
            for(unsigned long n = 2; n*i < size;n++){
                bitset_setbit(bitset_arr,n*i,1);
            }
        }
    }


}