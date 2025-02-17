# Vérification de l'Équilibre des Parenthèses

## Présentation

Dans cet exercice, nous allons écrire un programme en C qui utilise une pile pour vérifier si une séquence de parenthèses `()`, crochets `[]` et accolades `{}` est bien équilibrée. Une séquence est équilibrée si chaque parenthèse, crochet et accolade ouvrante a une correspondante fermante dans le bon ordre.

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

6. **Vérifier l'équilibre des parenthèses :**
   - Écrivez une fonction `is_balanced` qui utilise la pile pour vérifier si une séquence de parenthèses est bien équilibrée.

7. **Tester le programme :**
   - Écrivez une fonction `main` pour tester la fonction `is_balanced` avec différentes séquences.



## Algorithme en Pseudo-Code
```{r, tidy=FALSE, eval=FALSE, highlight=FALSE }
Fonction is_balanced(sequence):
    Initialiser une pile vide
    Pour chaque caractère dans la séquence:
        Si le caractère est '(' ou '[' ou '{':
            Empiler le caractère
        Sinon si le caractère est ')' ou ']' ou '}':
            Si la pile est vide:
            Retourner Faux

        Dépiler le sommet de la pile dans top

        Si (caractère est ')' et top n'est pas '(') ou
            (caractère est ']' et top n'est pas '[') ou
            (caractère est '}' et top n'est pas '{'):

            Retourner Faux
    Retourner Vrai si la pile est vide, sinon Faux
```


## Références

- [Pile (informatique) - Wikipédia](https://fr.wikipedia.org/wiki/Pile_(informatique))
- [Algorithme de vérification de l'équilibre des parenthèses](https://en.wikipedia.org/wiki/Balanced_parentheses)