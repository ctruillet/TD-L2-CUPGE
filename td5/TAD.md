# Types Abstraits de Données

## Pile
**Sorte** : Pile   
**Utilise** : ENTIER x BOOL

**Opérateurs** :
- **creerPile** : -> Pile
  *Crée une pile vide.*
- **empiler** : ENTIER x Pile -> Pile
  *Ajoute un élément au sommet de la pile.*
- **depiler** : Pile -> ENTIER x Pile
  *Retire et retourne l'élément au sommet de la pile.*
- **estVide** : Pile -> BOOL
  *Vérifie si la pile est vide.*

**Préconditions** :
- *depiler(p)* définie ssi ¬*estVide(p)*

**Axiomes** :
- estVide(creerPile()) = true
- estVide(empiler(p, e)) = false
- depiler(empiler(p, e)) = e
- empiler(p, depiler(p)) = p

---

## File
**Sorte** : File   
**Utilise** : ENTIER x BOOL

**Opérateurs** :
- **creerFile** : -> File
  *Crée une file vide.*
- **enfiler** : ENTIER x File -> File
  *Ajoute un élément à la fin de la file.*
- **defiler** : File -> ENTIER x File
  *Retire et retourne l'élément à l'avant de la file.*
- **estVide** : File -> BOOL
  *Vérifie si la file est vide.*

**Préconditions** :
- *defiler(f)* définie ssi ¬*estVide(f)*

**Axiomes** :
- estVide(creerFile()) = true
- estVide(enfiler(f, e)) = false
- defiler(enfiler(creerFile(), e)) = e
- defiler(enfiler(f, e)) = defiler(enfiler(defiler(f), e))
