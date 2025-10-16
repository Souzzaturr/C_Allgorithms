//Praticando uso do comando break, em C

#include <stdio.h>

int main (void) {
    
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);

        if (i == 5) {
            break;
        }
    }

    return 0;
}