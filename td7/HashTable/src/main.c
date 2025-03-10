#include <stdio.h>
#include "hashTable.h"

int main() {
    HashTable table = {NULL};
    insertValue(table, "one", 1);
    insertValue(table, "two", 2);
    insertValue(table, "three", 3);

    printf("Value for 'two': %d\n", searchValue(table, "two"));
    printf("Value for 'four': %d\n", searchValue(table, "four")); // Devrait afficher -1 car la clé n'existe pas

    deleteValue(table, "two");
    printf("Value for 'two' after deletion: %d\n", searchValue(table, "two")); // Devrait afficher -1 car la clé a été supprimée

    free_hashtable(table);

    return 0;
}
