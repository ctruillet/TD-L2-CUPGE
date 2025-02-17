 Conversion d'Expressions Infixées en Postfixées

## Présentation

Dans cet exercice, nous allons écrire un programme en C qui utilise une pile pour convertir une expression infixée en une expression postfixée. Par exemple, l'expression infixée `(3 + 4) * 2` sera convertie en `3 4 + 2 *`.

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

6. **Traiter la priorité des opérateurs :**
    - Écrivez une fonction `get_priority` pour obternir la priorité d'un opérateur
    - [Rappel : Ordre des opérations (PEMDAS)](https://fr.wikipedia.org/wiki/Ordre_des_op%C3%A9rations)

7. **Convertir une expression infixée en postfixée :**
   - Écrivez une fonction `infix_to_postfix` qui utilise la pile pour convertir une expression infixée en postfixée.

8. **Tester le programme :**
   - Écrivez une fonction `main` pour tester la fonction `infix_to_postfix` avec différentes expressions.

## Algorithme en Pseudo-Code
```{r, tidy=FALSE, eval=FALSE, highlight=FALSE }
Fonction infix_to_postfix(expression):
    Initialiser une pile vide
    Initialiser une chaîne de sortie vide
    
    Pour chaque caractère dans l'expression:
        Si le caractère est un chiffre:
            Ajouter le chiffre à la chaîne de sortie
        Si le caractère est '(':
            Empiler le caractère
        Si le caractère est ')':
            Tant que le sommet de la pile n'est pas '(':
                Dépiler le sommet de la pile et l'ajouter à la chaîne de sortie
                Dépiler '('
        Si le caractère est un opérateur:
        Tant que la pile n'est pas vide et le sommet de la pile a une priorité supérieure ou égale:
            Dépiler le sommet de la pile et l'ajouter à la chaîne de sortie
            Empiler le caractère

    Tant que la pile n'est pas vide:
        Dépiler le sommet de la pile et l'ajouter à la chaîne de sortie

    Retourner la chaîne de sortie
```

## Références

- [Pile (informatique) - Wikipédia](https://fr.wikipedia.org/wiki/Pile_(informatique))
- [Notation polonaise inverse - Wikipédia](https://fr.wikipedia.org/wiki/Notation_polonaise_inverse)
- [Algorithme de Shunting Yard](https://en.wikipedia.org/wiki/Shunting-yard_algorithm)