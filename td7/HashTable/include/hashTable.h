#ifndef HASHTABLE_H
#define HASHTABLE_H

#define SIZE 10

// Déclaration du type pointeur vers un nœud de la table de hachage
typedef struct HashNode *HashNode;

// Déclaration du type table de hachage
typedef HashNode HashTable[SIZE];

// Fonctions déclarées
unsigned int hash(char *key);
void insertValue(HashTable table, char *key, int value);
int searchValue(HashTable table, char *key);
void deleteValue(HashTable table, char *key);
void free_hashtable(HashTable table);

#endif // HASHTABLE_H
