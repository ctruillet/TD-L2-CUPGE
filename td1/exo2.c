#include <stdio.h>
#include <stdlib.h>



int main(){

    int ** tab;
    int tab2[4][4] = {{1, 0, 0, 0},
                     {0, 1, 0, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 1}};

    tab = (int**)malloc(4*sizeof(int*));
    for(int i = 0; i < 4; i++){
        tab[i] = (int*)malloc(4*sizeof(int));
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i==j){
                tab[i][j] = 1;
            }else{
                tab[i][j] = 0;
            }
        }
    }



    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", tab2[i][j]);
        }
        printf("\n");
    }

    return 0;

}