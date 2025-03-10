#include "doublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure d'un nœud de la liste doublement chaînée
struct DoublyLinkedListNode {
    int data;           // La valeur stockée dans le nœud
    struct DoublyLinkedListNode *next; // Pointeur vers le nœud suivant
    struct DoublyLinkedListNode *prev; // Pointeur vers le nœud précédent
};

// Définition de la structure de la liste doublement chaînée
struct DoublyLinkedList {
    struct DoublyLinkedListNode *head; // Pointeur vers le premier nœud de la liste
    struct DoublyLinkedListNode *tail; // Pointeur vers le dernier nœud de la liste
};

// Fonction pour créer une nouvelle liste doublement chaînée
struct DoublyLinkedList *create_doubly_linked_list() {
    struct DoublyLinkedList *list = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
    list->head = NULL; // Initialise la tête de la liste à NULL
    list->tail = NULL; // Initialise la queue de la liste à NULL
    return list; // Retourne la liste nouvellement créée
}

// Fonction pour ajouter un nœud à la fin de la liste doublement chaînée
void append_doubly_linked_list(struct DoublyLinkedList *list, int value) {
    struct DoublyLinkedListNode *new_node = (struct DoublyLinkedListNode *)malloc(sizeof(struct DoublyLinkedListNode));
    new_node->data = value; // Assigne la valeur au nouveau nœud
    new_node->next = NULL; // Le nouveau nœud est le dernier, donc next est NULL
    new_node->prev = list->tail; // Le précédent du nouveau nœud est l'ancien dernier nœud

    if (list->tail == NULL) {
        // Si la liste est vide, le nouveau nœud est à la fois la tête et la queue
        list->head = new_node;
        list->tail = new_node;
    } else {
        // Sinon, ajoute le nouveau nœud à la fin de la liste
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Fonction pour afficher les éléments de la liste doublement chaînée
void print_doubly_linked_list(struct DoublyLinkedList *list) {
    struct DoublyLinkedListNode *current = list->head;
    while (current != NULL) {
        if (current->next == NULL) {
            printf("%d", current->data); // Si c'est le dernier nœud, affiche sans flèche
        } else {
            printf("%d <-> ", current->data); // Affiche la valeur avec des flèches
        }
        current = current->next; // Passe au nœud suivant
    }
    printf("\n"); // Saute une ligne à la fin de l'affichage
}

// Fonction pour convertir la liste doublement chaînée en une chaîne de caractères
char *to_string_doubly_linked_list(struct DoublyLinkedList *list) {
    char *str = (char *)malloc(1);
    str[0] = '\0'; // Initialise la chaîne vide

    struct DoublyLinkedListNode *current = list->head;
    while (current != NULL) {
        char *data_str = (char *)malloc(12); // Alloue de la mémoire pour la valeur du nœud
        if (current->next == NULL) {
            sprintf(data_str, "%d", current->data); // Si c'est le dernier nœud, sans flèche
        } else {
            sprintf(data_str, "%d <-> ", current->data); // Ajoute la valeur avec des flèches
        }
        str = (char *)realloc(str, strlen(str) + strlen(data_str) + 1); // Réalloue la mémoire pour la chaîne
        strcat(str, data_str); // Concatène la valeur à la chaîne
        free(data_str); // Libère la mémoire temporaire
        current = current->next; // Passe au nœud suivant
    }

    return str; // Retourne la chaîne complète
}

// Fonction pour libérer la mémoire allouée pour la liste doublement chaînée
void free_doubly_linked_list(struct DoublyLinkedList *list) {
    struct DoublyLinkedListNode *current = list->head;
    while (current != NULL) {
        struct DoublyLinkedListNode *next = current->next; // Sauvegarde le pointeur vers le nœud suivant
        free(current); // Libère le nœud actuel
        current = next; // Passe au nœud suivant
    }
    free(list); // Libère la structure de la liste
}
