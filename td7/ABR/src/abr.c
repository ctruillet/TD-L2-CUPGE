#include "abr.h"
#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud de l'ABR
struct ABRNode {
    int data;
    struct ABRNode *left;
    struct ABRNode *right;
};

// Fonction pour créer un nouvel ABR
ABR create_abr() {
    return NULL;
}

// Fonction pour insérer une valeur dans l'ABR
void insert_abr(ABR *tree, int value) {
    if (*tree == NULL) {
        *tree = (ABR)malloc(sizeof(struct ABRNode));
        (*tree)->data = value;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    } else {
        if (value < (*tree)->data) {
            insert_abr(&((*tree)->left), value); // Insère dans le sous-arbre gauche
        } else {
            insert_abr(&((*tree)->right), value); // Insère dans le sous-arbre droit
        }
    }
}

// Fonction pour afficher les éléments de l'ABR
void print_abr(ABR tree) {
    if (tree != NULL) {
        print_abr(tree->left); // Affiche le sous-arbre gauche
        printf("%d ", tree->data); // Affiche la valeur du nœud actuel
        print_abr(tree->right); // Affiche le sous-arbre droit
    }
}

// Fonction pour libérer la mémoire allouée pour l'ABR
void free_abr(ABR tree) {
    if (tree != NULL) {
        free_abr(tree->left); // Libère le sous-arbre gauche
        free_abr(tree->right); // Libère le sous-arbre droit
        free(tree); // Libère le nœud actuel
    }
}
