#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

// Déclaration des types pour les nœuds et la liste doublement chaînée
typedef struct DoublyLinkedListNode * DoublyLinkedListNode;
typedef struct DoublyLinkedList * DoublyLinkedList;

// Fonction pour créer une nouvelle liste doublement chaînée
DoublyLinkedList create_doubly_linked_list();

// Fonction pour ajouter un nœud à la fin de la liste doublement chaînée
void append_doubly_linked_list(DoublyLinkedList list, int value);

// Fonction pour afficher les éléments de la liste doublement chaînée
void print_doubly_linked_list(DoublyLinkedList list);

// Fonction pour convertir la liste doublement chaînée en une chaîne de caractères
char * to_string_doubly_linked_list(DoublyLinkedList list);

// Fonction pour libérer la mémoire allouée pour la liste doublement chaînée
void free_doubly_linked_list(DoublyLinkedList list);

#endif // DOUBLY_LINKED_LIST_H
