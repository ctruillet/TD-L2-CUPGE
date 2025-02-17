#include <stdio.h>

int main() {
    int tab[] = {10, 20, 30, 40, 50};
    int *p = tab; // tab est déjà un pointeur vers le premier élément

    for (int i = 0; i < 5; i++) {
        printf("tab[%d] = %d (via pointeur)\n", i, *(p + i));
    }

    return 0;
}

