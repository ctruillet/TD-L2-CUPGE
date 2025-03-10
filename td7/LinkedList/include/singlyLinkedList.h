#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

// Déclaration des types pour les nœuds et la liste simplement chaînée
typedef struct SinglyLinkedListNode * SinglyLinkedListNode;
typedef struct SinglyLinkedList * SinglyLinkedList;

// Fonction pour créer une nouvelle liste simplement chaînée
SinglyLinkedList create_singly_linked_list();

// Fonction pour ajouter un nœud à la fin de la liste simplement chaînée
void append_singly_linked_list(SinglyLinkedList list, int value);

// Fonction pour afficher les éléments de la liste simplement chaînée
void print_singly_linked_list(SinglyLinkedList list);

// Fonction pour convertir la liste simplement chaînée en une chaîne de caractères
char * to_string_singly_linked_list(SinglyLinkedList list);

// Fonction pour libérer la mémoire allouée pour la liste simplement chaînée
void free_singly_linked_list(SinglyLinkedList list);

#endif // SINGLY_LINKED_LIST_H
