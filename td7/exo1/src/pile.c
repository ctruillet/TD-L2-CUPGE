#include <stdio.h>
#include "pile.h"
#include "node.h"


// Définition de la structure Pile pour représenter la pile
struct Pile {
    Node top;  // Pointeur vers le sommet de la pile
};

// Fonction pour initialiser une pile
Pile initPile() {
    Pile p = (Pile)malloc(sizeof(struct Pile));  // Allocation dynamique de mémoire pour la pile
    p->top = NULL;  // Initialisation du sommet de la pile à NULL (pile vide)
    return p;
}

// Fonction pour vérifier si la pile est vide
int PileEstVide(Pile p) {
    return p->top == NULL;  // Retourne 1 si la pile est vide, 0 sinon
}

// Fonction pour empiler un élément dans la pile
void empiler(Pile p, int x) {
    Node n = createNode(x);  // Création d'un nouveau nœud avec la valeur x
    setNextNode(n, p->top);  // Le nouveau nœud pointe vers l'ancien sommet de la pile
    p->top = n;  // Le nouveau nœud devient le sommet de la pile
}

// Fonction pour dépiler un élément de la pile
int depiler(Pile p) {
    if (PileEstVide(p)) {
        printf("Erreur : la pile est vide\n");
        exit(1);  // Termine le programme si la pile est vide
    }
    Node n = p->top;  // Récupération du sommet de la pile
    int x = getNodeElement(n);  // Récupération de la valeur de l'élément
    p->top = getNextNode(n);  // Le sommet de la pile pointe vers le nœud suivant
    free(n);  // Libération de la mémoire du nœud dépilé
    return x;  // Retourne la valeur de l'élément dépilé
}

// Fonction pour afficher les éléments de la pile
void afficher_pile(Pile p) {
    Node n = p->top;  // Récupération du sommet de la pile
    while (n != NULL) {
        printf("%d ", getNodeElement(n));  // Affiche chaque élément de la pile
        n = getNextNode(n);  // Passe au nœud suivant
    }
    printf("\n");
}

