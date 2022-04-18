#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 10


struct list;
struct array;
struct pair;

typedef struct array{
    int size;
    struct list *arr_ptr[NUM];
} array_t;

typedef struct list {
    int value;
    struct list *next;
    struct pair *pair;

}list_t;

typedef struct pair {
    int x;
    int y;
}pair_t;



void print_elems(array_t *table){
    printf("\n");
    printf("/************ HASH TABLE ************/\n");
    for(int i = 0; i < table->size;i++){
        
        if(table->arr_ptr[i] == NULL){
            printf("%d \t ---\n",i);
        }
        else{
            list_t *curr = table->arr_ptr[i];
            printf("%d \t ",i);
            while(curr != NULL){
                printf("(%d, %d) -> ",curr->pair->x, curr->pair->y);
                curr = curr->next;
            }
            printf("\n");
            // printf("%d \t %s[%d]\n",i,table->arr_ptr[i]->pair->key,table->arr_ptr[i]->pair->value);

        }
    }
    printf("/************************************/\n");
}

int main(){
    array_t *a;
    a = malloc(sizeof(array_t) + sizeof(list_t)*NUM);
    for(int i = 0; i < NUM ; i++){
        a->arr_ptr[i] = NULL;
    }
    a->size = NUM;

    a->arr_ptr[0] = malloc(sizeof(list_t));
    a->arr_ptr[0]->pair = malloc(sizeof(pair_t));

    a->arr_ptr[0]->pair->x = 33;
    printf("%d\n",a->arr_ptr[0]->pair->x);


        // pair_t *pair = curr->pair;
        // // pair = curr->pair;
        // curr->pair->x = 45;
        // curr->pair->y = 42;
        // curr->next = NULL;

        // list_t *curr = a->arr_ptr[0]->next;


    for(int i = 0; i<5;i++){
        list_t *curr = a->arr_ptr[0];
        while(curr != NULL){
            curr = curr->next;
        }
        list_t *alloc = malloc(sizeof(list_t));
        alloc->pair = malloc(sizeof(pair_t));
        alloc->pair->x = i;
        alloc->pair->y = i;
        alloc->next = NULL;
        while(curr != NULL){
            curr = curr->next;
            if(curr == NULL){
                curr = alloc;
                break;
            }
        }
        // memcpy(curr,alloc,sizeof(list_t) + sizeof(pair_t));
        // list_t *list_ptr = a->arr_ptr[0];
        curr = alloc;
        //  = alloc;
    }

        


        // if(a->arr_ptr[0]->next == NULL){

        //     printf("Je tam NULL");
        //     // printf("%d\n",a->arr_ptr[0]->next->pair->x);
        // }
        // else {
        //     printf("HURAAA");
        // }

    // while(a->arr_ptr[0] != NULL){
    //     // printf(">>%d<<\n",curr->pair->x);
    //     a->arr_ptr[0] = a->arr_ptr[0]->next;
    // }
    // a->arr_ptr[0]->next = malloc(sizeof(list_t));
    // a->arr_ptr[0]->next->pair =  malloc(sizeof(pair_t));
    

    // a->arr_ptr[0]->next = curr;
    // a->arr_ptr[0]->next = malloc(sizeof(list_t));
    // a->arr_ptr[0]->next->pair = malloc(sizeof(pair_t));
    // a->arr_ptr[0]->next->pair->x = 90;

    print_elems(a);


    // list_t *next = a.arr_ptr[0]->next;
    // a->arr_ptr[0]->next = malloc(sizeof(list_t));
    // a->arr_ptr[0]->next->value = 33;
    // printf("%d\n",  a->arr_ptr[0]->next->value);


}