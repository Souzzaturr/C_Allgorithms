//Aprendendo sobre Variáveis em C
//Aprendendo sobre tipos de variáveis em C

#include <stdio.h>

int main(void) {
    const char MACHINE_NAME[10] = "COMPUTER";
    const char USER_NAME[6] = "User";
    int age = 0;
    float weight = 0;

    printf("The Machine's name is: %s\n", MACHINE_NAME);
    printf("The user name is: %s\n\n", USER_NAME);

    printf("What is your age, %s?\n", USER_NAME);
    scanf("%d", &age);

    printf("What is your weight, %s?\n", USER_NAME);
    scanf("%f", &weight);

    printf("The age of %s is: %d years old.\n", USER_NAME, age);
    printf("The weight of %s is: %.fKG.\n", USER_NAME, weight);
    printf("And your machine is the %s!!\n", MACHINE_NAME);

    return 0;
}