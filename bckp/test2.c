
#include<stdio.h>
#include<stdlib.h>

void repoint(int **t){
    int xd = 141;
    int *p = &xd;

    *t = p;
    printf("*t->%d\n",**t);
    *p = 99;
    printf("*t->%d\n",**t);
}
int main(){
    int j = 10;
    int *t = &j;
    repoint(&t);
    printf("*t->%d\n",*t);
}