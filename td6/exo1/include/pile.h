#ifndef PILE_H
#define PILE_H

// Définition de la structure Pile pour représenter la pile
typedef struct Pile * Pile;

// Fonction pour initialiser une pile
Pile initPile();

// Fonction pour vérifier si la pile est vide
int PileEstVide(Pile p);

// Fonction pour empiler un élément dans la pile
void empiler(Pile p, int x);

// Fonction pour dépiler un élément de la pile
int depiler(Pile p);

// Fonction pour afficher les éléments de la pile
void afficher_pile(Pile p);

#endif // PILE_H