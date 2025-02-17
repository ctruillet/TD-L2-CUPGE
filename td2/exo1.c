#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

#define SIGMA 10
#define RHO 28
#define BETA 8/3



int main(int arg, char * argv[]){
    float x[100];
    float y[100];
    float z[100];

    float dt = 0.0001;

    x[0] = 0.0;
    y[0] = 1.0;
    z[0] = 3.0;

    FILE *fichier = NULL;
    fichier = fopen("position.dat", "w+");
    fclose(fichier);
    fichier = fopen("position.dat", "a");
        
    for(int i = 1; i < SIZE; i++){
        x[i] = x[i-1] + dt * (SIGMA*(y[i-1] - x[i-1]));
        y[i] = y[i-1] + dt * ((RHO - z[i-1])*x[i-1] - y[i-1]);
        z[i] = z[i-1] + dt * (x[i-1]*y[i-1] - BETA*z[i-1]);

    }
    
    float t = 0;
    for(int i = 0; i < SIZE; i++){

        printf("%f %f %f\n", x[i], y[i], z[i]);
        fprintf(fichier, "%f %f %f %f\n", t, x[i], y[i], z[i]);
        t = t + dt;
    }
    return 0;
}