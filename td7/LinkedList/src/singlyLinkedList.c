#include "singlyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure d'un nœud de la liste simplement chaînée
struct SinglyLinkedListNode {
    int data;           // La valeur stockée dans le nœud
    struct SinglyLinkedListNode *next; // Pointeur vers le nœud suivant
};

// Définition de la structure de la liste simplement chaînée
struct SinglyLinkedList {
    struct SinglyLinkedListNode *head; // Pointeur vers le premier nœud de la liste
};

// Fonction pour créer une nouvelle liste simplement chaînée
struct SinglyLinkedList *create_singly_linked_list() {
    struct SinglyLinkedList *list = (struct SinglyLinkedList *)malloc(sizeof(struct SinglyLinkedList));
    list->head = NULL; // Initialise la tête de la liste à NULL
    return list; // Retourne la liste nouvellement créée
}

// Fonction pour ajouter un nœud à la fin de la liste simplement chaînée
void append_singly_linked_list(struct SinglyLinkedList *list, int value) {
    struct SinglyLinkedListNode *new_node = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    new_node->data = value; // Assigne la valeur au nouveau nœud
    new_node->next = NULL; // Le nouveau nœud est le dernier, donc next est NULL

    if (list->head == NULL) {
        // Si la liste est vide, le nouveau nœud devient la tête de la liste
        list->head = new_node;
    } else {
        // Sinon, parcourt la liste jusqu'au dernier nœud et ajoute le nouveau nœud
        struct SinglyLinkedListNode *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Fonction pour afficher les éléments de la liste simplement chaînée
void print_singly_linked_list(struct SinglyLinkedList *list) {
    struct SinglyLinkedListNode *current = list->head;
    while (current != NULL) {
        if (current->next == NULL) {
            printf("%d", current->data); // Si c'est le dernier nœud, affiche sans flèche
        } else {
            printf("%d -> ", current->data); // Affiche la valeur avec une flèche
        }
        current = current->next; // Passe au nœud suivant
    }
    printf("\n"); // Saute une ligne à la fin de l'affichage
}

// Fonction pour convertir la liste simplement chaînée en une chaîne de caractères
char *to_string_singly_linked_list(struct SinglyLinkedList *list) {
    char *str = (char *)malloc(1);
    str[0] = '\0'; // Initialise la chaîne vide

    struct SinglyLinkedListNode *current = list->head;
    while (current != NULL) {
        char *data_str = (char *)malloc(12); // Alloue de la mémoire pour la valeur du nœud
        if (current->next == NULL) {
            sprintf(data_str, "%d", current->data); // Si c'est le dernier nœud, sans flèche
        } else {
            sprintf(data_str, "%d -> ", current->data); // Ajoute la valeur avec une flèche
        }
        str = (char *)realloc(str, strlen(str) + strlen(data_str) + 1); // Réalloue la mémoire pour la chaîne
        strcat(str, data_str); // Concatène la valeur à la chaîne
        free(data_str); // Libère la mémoire temporaire
        current = current->next; // Passe au nœud suivant
    }

    return str; // Retourne la chaîne complète
}

// Fonction pour libérer la mémoire allouée pour la liste simplement chaînée
void free_singly_linked_list(struct SinglyLinkedList *list) {
    struct SinglyLinkedListNode *current = list->head;
    while (current != NULL) {
        struct SinglyLinkedListNode *next = current->next; // Sauvegarde le pointeur vers le nœud suivant
        free(current); // Libère le nœud actuel
        current = next; // Passe au nœud suivant
    }
    free(list); // Libère la structure de la liste
}
