#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

// Déclaration des structures complète
typedef struct Node {
    int elt;
    struct Node * next;
} * Node;


#endif // Node_H
