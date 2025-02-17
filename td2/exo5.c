#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum TypeContrat{
    CDI, CDD, STAGE
};

typedef union Contrat{
    float salaire;  // Pour CDI
    int duree;      // Pour CDD
    char * maitre;  // Pour STAGE 
};

typedef struct Employe{
    char * nom;
    enum TypeContrat type;
    union Contrat details;
} ;

int main() {
    struct Employe ** employes = (struct Employe**) malloc(10 * sizeof(struct Employe*));

    struct Employe * e1 = (struct Employe*) malloc(sizeof(struct Employe));
    e1->nom = (char*) malloc(16 * sizeof(char));
    strcpy(e1->nom, "Alice Dupont");
    e1->type = CDI;
    e1->details.salaire = 2500.0;
    employes[0] = e1;

    struct Employe * e2 = (struct Employe*) malloc(sizeof(struct Employe));
    e2->nom = (char*) malloc(16 * sizeof(char));
    strcpy(e2->nom, "Bob Martin");
    e2->type = CDD;
    e2->details.duree = 6;
    employes[1] = e2;

    struct Employe * e3 = (struct Employe*) malloc(sizeof(struct Employe));
    e3->nom = (char*) malloc(16 * sizeof(char));
    strcpy(e3->nom, "Charlie Smith");
    e3->type = STAGE;
    e3->details.maitre = (char*) malloc(16 * sizeof(char));
    strcpy(e3->details.maitre, "Alice Dupont");
    employes[2] = e3;

    for (int i = 0; i < 3; i++) {
        struct Employe * e = employes[i];
        printf("Nom : %s\n", e->nom);
        if (e->type == CDI) {
            printf("\tContrat : CDI\n\tSalaire : %.2f €/mois\n", e->details.salaire);
        } else if (e->type == CDD) {
            printf("\tContrat : CDD\n\tDurée : %d mois\n", e->details.duree);
        } else if (e->type == STAGE) {
            printf("\tContrat : Stage\n\tMaître de stage : %s\n", e->details.maitre);
        }
        printf("\n");
    }

    return 0;
}
