#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int main(int arg, char * argv[]){
    int x;
    int * tab;
    tab = (int*)malloc(SIZE*sizeof(int));

    for (int i = 0; i < SIZE; i++){
        x = (int)scanf("%d", &x);

        tab[i] = x;
    }

    for(int i=0; i<SIZE; i++){
        printf("%d ", tab[i]);
    }

    free(tab);
    
    return 0;
}