#include "node.h"

struct Node {
    int elt;
    struct Node * next;
};

Node createNode(int elt){
    Node n = (Node)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Erreur : impossible d'allouer de la mémoire\n");
        exit(1);
    }
    n->elt = elt;
    n->next = NULL;
    return n;
}

Node getNextNode(Node n) {
    return n->next;
}

int getNodeElement(Node n){
    return n->elt;
}

void setNextNode(Node n, Node next){
    n->next = next;
}

void setNodeElement(Node n, int elt){
    n->elt = elt;
}