#include <stdio.h>
#include "abr.h"

int main() {
    ABR tree = create_abr();
    insert_abr(&tree, 50);
    insert_abr(&tree, 30);
    insert_abr(&tree, 20);
    insert_abr(&tree, 40);
    insert_abr(&tree, 70);
    insert_abr(&tree, 60);
    insert_abr(&tree, 80);

    printf("Arbre Binaire de Recherche (ABR):\n");
    print_abr(tree);

    // Libération de la mémoire
    free_abr(tree);

    return 0;
}
