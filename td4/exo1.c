#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud* suivant;
} Noeud;

Noeud* ajouterEnDebut(Noeud* tete, int valeur) {
    Noeud* nouveau = (Noeud*) malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return tete;
    }
    nouveau->valeur = valeur;
    nouveau->suivant = tete;
    return nouveau;
}

void afficherListe(Noeud* tete) {
    Noeud* courant = tete;
    while (courant != NULL) {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

int main() {
    Noeud* liste = NULL;
    liste = ajouterEnDebut(liste, 10);
    liste = ajouterEnDebut(liste, 20);
    liste = ajouterEnDebut(liste, 30);

    printf("Liste chaînée : ");
    afficherListe(liste);

    return 0;
}
