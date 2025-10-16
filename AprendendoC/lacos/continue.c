//Praticando uso do comando continue, em C

#include <stdio.h>

int main (void) {

    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            continue;
        }

        printf("%d ", i);
    }

    return 0;
}