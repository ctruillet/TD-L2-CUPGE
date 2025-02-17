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

// Fonction pour vérifier si la file est vide
int estVide(File* f) {
    return f->premier == NULL;
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
    if (estVide(f)) {
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

// Fonction pour afficher les éléments de la file
void afficheFile(File* f) {
    if (estVide(f)) {
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

// Fonction pour fusionner deux files triées
File * fusionFile(File * f1, File * f2) {
    File * f = initFile();

    while (!estVide(f1) && !estVide(f2)) {
        if (f1->premier->elt <= f2->premier->elt) {
            enfiler(f, defiler(f1));
        } else {
            enfiler(f, defiler(f2));
        }
    }

    while (!estVide(f1)) {
        enfiler(f, defiler(f1));
    }

    while (!estVide(f2)) {
        enfiler(f, defiler(f2));
    }

    return f;
}

// Fonction principale pour tester le programme
int main() {
    File * f1 = initFile();
    File * f2 = initFile();

    enfiler(f1, 10);
    enfiler(f1, 20);
    enfiler(f1, 30);

    enfiler(f2, 15);
    enfiler(f2, 25);
    enfiler(f2, 35);

    printf("Éléments de la file 1 : ");
    afficheFile(f1);

    printf("Éléments de la file 2 : ");
    afficheFile(f2);

    File * f = fusionFile(f1, f2);

    printf("Éléments de la file fusionnée : ");
    afficheFile(f);

    return 0;
}
