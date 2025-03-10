#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure d'un nœud de la table de hachage
struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
};

// Fonction de hachage
unsigned int hash(char *key) {
    unsigned int hash_value = 0;
    while (*key) {
        hash_value = (*key++ + 31 * hash_value) % SIZE;
    }
    return hash_value;
}

// Fonction pour insérer une clé-valeur dans la table de hachage
void insertValue(HashTable table, char *key, int value) {
    unsigned int hash_value = hash(key);
    HashNode new_node = (HashNode)malloc(sizeof(struct HashNode));
    new_node->key = (char *)malloc(strlen(key) + 1);
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = table[hash_value];
    table[hash_value] = new_node;
}

// Fonction pour rechercher une clé dans la table de hachage
int searchValue(HashTable table, char *key) {
    unsigned int hash_value = hash(key);
    HashNode node = table[hash_value];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1; // Valeur de retour pour indiquer que la clé n'a pas été trouvée
}

// Fonction pour supprimer une clé de la table de hachage
void deleteValue(HashTable table, char *key) {
    unsigned int hash_value = hash(key);
    HashNode node = table[hash_value];
    HashNode prev = NULL;

    while (node != NULL && strcmp(node->key, key) != 0) {
        prev = node;
        node = node->next;
    }

    if (node == NULL) {
        // Clé non trouvée
        return;
    }

    if (prev == NULL) {
        // Le nœud à supprimer est le premier de la liste
        table[hash_value] = node->next;
    } else {
        // Le nœud à supprimer est au milieu ou à la fin de la liste
        prev->next = node->next;
    }

    free(node->key);
    free(node);
}

// Fonction pour libérer la mémoire allouée pour la table de hachage
void free_hashtable(HashTable table) {
    for (int i = 0; i < SIZE; i++) {
        HashNode node = table[i];
        while (node != NULL) {
            HashNode temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
}
