#ifndef ABR_H
#define ABR_H

// Déclaration du type pointeur vers un nœud de l'ABR
typedef struct ABRNode *ABR;

// Fonctions déclarées
ABR create_abr();
void insert_abr(ABR *tree, int value);
void print_abr(ABR tree);
void free_abr(ABR tree);

#endif // ABR_H
