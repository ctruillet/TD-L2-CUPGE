Évaluation d'Expressions Postfixées

# Évaluation d'Expressions Postfixées

## Présentation

Dans cet exercice, nous allons écrire un programme en C qui utilise une pile pour évaluer des expressions en notation postfixée (RPN). La notation postfixée est une notation où chaque opérateur suit ses opérandes. Par exemple, l'expression infixée `(3 + 4) * 2` est écrite en RPN comme `3 4 + 2 *`.

## Instructions

1. **Définir les structures de données :**
   - Créez une structure `Node` pour représenter un nœud de la liste chaînée.
   - Créez une structure `Pile` pour représenter la pile.

2. **Initialiser la pile :**
   - Écrivez une fonction `initPile` pour initialiser la pile.

3. **Ajouter un élément à la pile :**
   - Écrivez une fonction `empiler` pour ajouter un élément au sommet de la pile.

4. **Retirer un élément de la pile :**
   - Écrivez une fonction `depiler` pour retirer l'élément du sommet de la pile et le retourner.

5. **Vérifier si la pile est vide :**
   - Écrivez une fonction `estVide` pour vérifier si la pile est vide.

6. **Évaluer une expression RPN :**
   - Écrivez une fonction `evaluate_rpn` qui utilise la pile pour évaluer une expression en notation postfixée.

7. **Tester le programme :**
   - Écrivez une fonction `main` pour tester la fonction `evaluate_rpn` avec différentes expressions RPN.

## Algorithme en Pseudo-Code
```{r, tidy=FALSE, eval=FALSE, highlight=FALSE }
Fonction evaluate_rpn(expression):
    Initialiser une pile vide
    Pour chaque caractère dans l'expression:
        Si le caractère est un espace:
            Continuer
        Si le caractère est un chiffre:
            Lire le nombre entier et l'empiler
        Sinon:
            Dépiler les deux opérandes
            Calculer le résultat en fonction de l'opérateur
            Empiler le résultat
    Retourner le sommet de la pile
```


## Références

- [Pile (informatique) - Wikipédia](https://fr.wikipedia.org/wiki/Pile_(informatique))
- [Notation polonaise inverse - Wikipédia](https://fr.wikipedia.org/wiki/Notation_polonaise_inverse)
