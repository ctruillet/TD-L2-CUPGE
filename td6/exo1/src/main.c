#include "file.h"
#include "pile.h"

// Fonction principale pour tester le programme
int main() {
    File f = initFile();

    enfiler(f, 10);
    enfiler(f, 20);
    enfiler(f, 30);

    printf("Éléments de la file : ");
    afficheFile(f);

    printf("Élément retiré : %d\n", defiler(f));
    printf("Élément retiré : %d\n", defiler(f));

    printf("Éléments de la file après retrait : ");
    afficheFile(f);

    return 0;
}
