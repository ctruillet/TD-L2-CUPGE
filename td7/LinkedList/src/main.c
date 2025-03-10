#include <stdio.h>
#include "singlyLinkedList.h"
#include "doublyLinkedList.h"

int main() {
    // Utilisation de la liste chaînée simple
    SinglyLinkedList sll = create_singly_linked_list(); // Crée une nouvelle liste chaînée simple
    append_singly_linked_list(sll, 10); // Ajoute l'élément 10 à la liste
    append_singly_linked_list(sll, 20); // Ajoute l'élément 20 à la liste
    append_singly_linked_list(sll, 30); // Ajoute l'élément 30 à la liste

    printf("Singly Linked List : %s \n", to_string_singly_linked_list(sll)); // Affiche la liste sous forme de chaîne de caractères
    print_singly_linked_list(sll); // Affiche la liste de manière formatée
    

    // Utilisation de la liste chaînée double
    DoublyLinkedList dll = create_doubly_linked_list(); // Crée une nouvelle liste chaînée double
    append_doubly_linked_list(dll, 100); // Ajoute l'élément 100 à la liste
    append_doubly_linked_list(dll, 200); // Ajoute l'élément 200 à la liste
    append_doubly_linked_list(dll, 300); // Ajoute l'élément 300 à la liste

    printf("Doubly Linked List : %s \n", to_string_doubly_linked_list(dll)); // Affiche la liste sous forme de chaîne de caractères
    print_doubly_linked_list(dll); // Affiche la liste de manière formatée

    // Libération de la mémoire
    free_singly_linked_list(sll); // Libère la mémoire allouée pour la liste chaînée simple
    free_doubly_linked_list(dll); // Libère la mémoire allouée pour la liste chaînée double

    return 0; // Indique que le programme s'est exécuté avec succès
}
