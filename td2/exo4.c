#include <stdio.h>
#include <string.h>

typedef struct {
    char nom[50];
    int age;
} Personne;

int main() {
    Personne p1;
    Personne *ptr = &p1;

    char * nom = "Alice Dupont";
    strcpy(ptr->nom, nom);
    ptr->age = 25;

    printf("Nom : %s\n", ptr->nom);
    printf("Âge : %d\n", ptr->age);

    return 0;
}

