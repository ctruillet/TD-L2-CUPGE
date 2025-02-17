#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud de la liste chaînée
typedef struct Node {
    int elt;
    struct Node* next;
} Node;

// Définition de la structure de la file
typedef struct {
    Node* premier;
    Node* dernier;
} File;

// Définition de la structure de la pile
typedef struct {
    Node* top;
} Pile;

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

// Fonction pour initialiser la pile
Pile * initPile() {
    Pile* p = (Pile*)malloc(sizeof(Pile));
    p->top = NULL;
    return p;
}

// Fonction pour ajouter un élément à la pile
void empiler(Pile* p, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur : impossible d'allouer de la mémoire\n");
        return;
    }
    newNode->elt = value;
    newNode->next = p->top;
    p->top = newNode;
}

// Fonction pour retirer un élément de la pile
int depiler(Pile* p) {
    if (p->top == NULL) {
        printf("Erreur : la pile est vide\n");
        exit(1);
    }
    Node * n = p->top;
    int value = n->elt;
    p->top = p->top->next;
    free(n);
    return value;
}

// Fonction pour vérifier si la pile est vide
int pileEstVide(Pile* p) {
    return p->top == NULL;
}

// Fonction pour inverser la file
void inverseFile(File* f) {
    Pile * p = initPile();
    initPile(&p);

    while (!fileEstVide(f)) {
        int value = defiler(f);
        empiler(p, value);
    }

    while (!pileEstVide(p)) {
        int value = depiler(p);
        enfiler(f, value);
    }
}

// Fonction principale pour tester le programme
int main() {
    File* f = initFile();

    enfiler(f, 10);
    enfiler(f, 20);
    enfiler(f, 30);

    printf("Éléments de la file avant inversion : ");
    afficheFile(f);

    inverseFile(f);

    printf("Éléments de la file après inversion : ");
    afficheFile(f);

    return 0;
}
