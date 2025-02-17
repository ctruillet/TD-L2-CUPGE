#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud de la liste chaînée
typedef struct Node {
    int elt;
    struct Node * next;
} Node;

// Définition de la structure de la file
typedef struct {
    Node * premier;
    Node * dernier;
} File;

// Fonction pour initialiser la file
File* initFile() {
    File* f = (File*)malloc(sizeof(File));
    f->premier = f->dernier = NULL;
    return f;
}

// Fonction pour ajouter un élément à la file
void enfiler(File* f, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur : impossible d'allouer de la mémoire\n");
        return;
    }
    newNode->elt = value;
    newNode->next = NULL;
    if (f->dernier == NULL) {
        f->premier = f->dernier = newNode;
    } else {
        f->dernier->next = newNode;
        f->dernier = newNode;
    }
}

// Fonction pour retirer un élément de la file
int defiler(File* f) {
    if (f->premier == NULL) {
        printf("Erreur : la file est vide\n");
        exit(1);
    }
    Node* n = f->premier;
    int value = n->elt;
    f->premier = f->premier->next;
    if (f->premier == NULL) {
        f->dernier = NULL;
    }
    free(n);
    return value;
}

// Fonction pour vérifier si la file est vide
int fileEstVide(File* f) {
    return f->premier == NULL;
}

// Fonction pour afficher les éléments de la file
void afficheFile(File* f) {
    if (fileEstVide(f)) {
        printf("La file est vide\n");
        return;
    }
    Node* n = f->premier;
    while (n != NULL) {
        printf("%d ", n->elt);
        n = n->next;
    }
    printf("\n");
}

// Fonction principale pour tester le programme
int main() {
    File * f = initFile();

    enfiler(f, 10);
    enfiler(f, 20);
    enfiler(f, 30);

    printf("Éléments de la file : ");
    afficheFile(f);

    printf("Élément retiré : %d\n", defiler(f));
    printf("Élément retiré : %d\n", defiler(f));

    printf("Éléments de la file après retrait : ");
    afficheFile(f);

    return 0;
}
