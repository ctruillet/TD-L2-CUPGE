#include <stdio.h>

int main() {
    int a = 42;  
    int *ptr = &a;  

    printf("Adresse de a : %p\n", (void*)&a);
    printf("Valeur de a via ptr : %d\n", *ptr);

    *ptr = 99; // Modification via le pointeur

    printf("Nouvelle valeur de a : %d\n", a);
    
    return 0;
}

