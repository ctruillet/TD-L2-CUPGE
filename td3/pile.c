#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 100

// Définition de la structure Pile
typedef struct Pile {
    char tab[TAILLE_MAX];  // Tableau pour stocker les éléments de la pile
    int indice_sommet;     // Indice du sommet de la pile
} Pile;

// Fonction pour initialiser une pile
Pile * initPile() {
    Pile * p = (Pile *)malloc(sizeof(Pile));  // Allocation dynamique de mémoire pour la pile
    p->indice_sommet = -1;  // Initialisation de l'indice du sommet à -1 (pile vide)
    return p;
}

// Fonction pour vérifier si la pile est vide
int estVide(Pile * p) {
    return p->indice_sommet == -1;  // Retourne 1 si la pile est vide, 0 sinon
}

// Fonction pour vérifier si la pile est pleine
int estPleine(Pile * p) {
    return p->indice_sommet == TAILLE_MAX - 1;  // Retourne 1 si la pile est pleine, 0 sinon
}

// Fonction pour empiler un caractère dans la pile
void empiler(Pile * p, char c) {
    if (estPleine(p)) {
        printf("Erreur : la pile est pleine\n");
        exit(1);  // Termine le programme si la pile est pleine
    }
    p->tab[++p->indice_sommet] = c;  // Ajoute le caractère au sommet de la pile
}

// Fonction pour dépiler un caractère de la pile
char depiler(Pile * p) {
    if (estVide(p)) {
        printf("Erreur : la pile est vide\n");
        exit(1);  // Termine le programme si la pile est vide
    }
    return p->tab[p->indice_sommet--];  // Retourne le caractère au sommet de la pile et décrémente l'indice
}

// Fonction pour afficher les éléments de la pile
void afficher_pile(Pile * p) {
    for (int i = 0; i <= p->indice_sommet; i++) {
        printf("%d ", p->tab[i]);  // Affiche chaque élément de la pile
    }
    printf("\n");
}

// Fonction pour inverser une chaîne de caractères en utilisant une pile
void inverserChaine(char * str) {
    Pile * pile = initPile();  // Initialisation de la pile

    // Empiler tous les caractères de la chaîne
    for (int i = 0; i < strlen(str); i++) {
        empiler(pile, str[i]);
    }

    // Dépiler les caractères pour obtenir la chaîne inversée
    for (int i = 0; i < strlen(str); i++) {
        str[i] = depiler(pile);
    }
}

int main() {
    Pile * p = initPile();  // Initialisation de la pile

    empiler(p, 1);  // Empiler le caractère '1'
    afficher_pile(p);  // Afficher la pile

    empiler(p, 2);  // Empiler le caractère '2'
    afficher_pile(p);  // Afficher la pile

    empiler(p, 3);  // Empiler le caractère '3'
    afficher_pile(p);  // Afficher la pile

    depiler(p);  // Dépiler le caractère au sommet
    afficher_pile(p);  // Afficher la pile

    char chaine[] = "hello World";  // Chaîne de caractères à inverser
    printf("Chaîne originale : %s\n", chaine);

    inverserChaine(chaine);  // Inverser la chaîne
    printf("Chaîne inversée : %s\n", chaine);

    return 0;
}
