#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node * Node;

Node createNode(int elt);

Node getNextNode(Node n);

int getNodeElement(Node n);

void setNextNode(Node n, Node next);

void setNodeElement(Node n, int elt);

#endif // Node_H
