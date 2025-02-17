#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure Node pour représenter un élément de la pile
typedef struct Node {
    char elt;  // Élément stocké dans le nœud
    struct Node * next;  // Pointeur vers le nœud suivant
} Node;

// Définition de la structure Pile pour représenter la pile
typedef struct Pile {
    Node * top;  // Pointeur vers le sommet de la pile
} Pile;

// Fonction pour initialiser une pile
Pile * initPile() {
    Pile * p = (Pile *)malloc(sizeof(Pile));  // Allocation dynamique de mémoire pour la pile
    p->top = NULL;  // Initialisation du sommet de la pile à NULL (pile vide)
    return p;
}

// Fonction pour vérifier si la pile est vide
int estVide(Pile * p) {
    return p->top == NULL;  // Retourne 1 si la pile est vide, 0 sinon
}

// Fonction pour empiler un élément dans la pile
void empiler(Pile * p, int x) {
    Node * n = malloc(sizeof(Node));  // Allocation dynamique de mémoire pour un nouveau nœud
    n->elt = x;  // Affectation de la valeur à l'élément du nœud
    n->next = p->top;  // Le nouveau nœud pointe vers l'ancien sommet de la pile
    p->top = n;  // Le nouveau nœud devient le sommet de la pile
}

// Fonction pour dépiler un élément de la pile
int depiler(Pile * p) {
    if (estVide(p)) {
        printf("Erreur : la pile est vide\n");
        exit(1);  // Termine le programme si la pile est vide
    }
    Node * n = p->top;  // Récupération du sommet de la pile
    int x = n->elt;  // Récupération de la valeur de l'élément
    p->top = n->next;  // Le sommet de la pile pointe vers le nœud suivant
    free(n);  // Libération de la mémoire du nœud dépilé
    return x;  // Retourne la valeur de l'élément dépilé
}

// Fonction pour afficher les éléments de la pile
void afficher_pile(Pile * p) {
    Node * n = p->top;  // Récupération du sommet de la pile
    while (n != NULL) {
        printf("%d ", n->elt);  // Affiche chaque élément de la pile
        n = n->next;  // Passe au nœud suivant
    }
    printf("\n");
}

// Fonction pour vérifier si une séquence de parenthèses est équilibrée
int is_balanced(char* str) {
    Pile * p = initPile();  // Initialisation de la pile

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            empiler(p, str[i]);  // Empiler les parenthèses ouvrantes
        } else if (str[i] == ')') {
            if (estVide(p)) {
                return 0;  // Parenthèse fermante sans parenthèse ouvrante correspondante
            }
            depiler(p);  // Dépiler les parenthèses fermantes
        }
    }

    return estVide(p);  // Si la pile est vide, la séquence est équilibrée
}

int main() {
    Pile * p = initPile();  // Initialisation de la pile

    empiler(p, 1);  // Empiler l'élément '1'
    afficher_pile(p);  // Afficher la pile

    empiler(p, 2);  // Empiler l'élément '2'
    afficher_pile(p);  // Afficher la pile

    empiler(p, 3);  // Empiler l'élément '3'
    afficher_pile(p);  // Afficher la pile

    depiler(p);  // Dépiler l'élément au sommet
    afficher_pile(p);  // Afficher la pile

    // Tableau de séquences à vérifier
    char* sequences[] = {
        "()",
        "(()",
        "(())",
        "((()))",
        "(()()()())",
        "(()()(())))",
        "3 x (10 + 5)",
        "sin((3*pi+4)/(2*pi)"
    };

    // Vérification de chaque séquence
    for (int i = 0; i < sizeof(sequences) / sizeof(sequences[0]); i++) {
        if (is_balanced(sequences[i])) {
            printf("La séquence \"%s\" est équilibrée.\n", sequences[i]);
        } else {
            printf("La séquence \"%s\" n'est pas équilibrée.\n", sequences[i]);
        }
    }

    return 0;
}
