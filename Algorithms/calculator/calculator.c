#include <stdio.h>
#include <stdlib.h>


struct operation {
    char operation;
    int priority;
    struct value *value_right;
    struct value *value_left;
};


struct value {
    int value;
    struct operation *operation_right;
    struct operation *operation_left;
};


void resolve_operations(struct operation *operations[], int sizeOfArray) {
    for (int i = 0; i < sizeOfArray; i++) {
        struct value *newValue = malloc(sizeof(struct value));
        newValue->operation_left = operations[i]->value_left->operation_left;
        if (operations[i]->value_left->operation_left != NULL) {
            operations[i]->value_left->operation_left->value_right = newValue;
        }
        newValue->operation_right = operations[i]->value_right->operation_right;
        if (operations[i]->value_right->operation_right != NULL) {
            operations[i]->value_right->operation_right->value_left = newValue;
        }

        int value1 = operations[i]->value_left->value;
        int value2 = operations[i]->value_right->value;

        if (operations[i]->operation == '+') {
            newValue->value = value1 + value2;

        } else if (operations[i]->operation == '-') {
            newValue->value = value1 - value2;

        } else if (operations[i]->operation == '*') {
            newValue->value = value1 * value2;

        } else if (operations[i]->operation == '/') {
            newValue->value = value1 / value2;
        }

        free(operations[i]->value_left);
        free(operations[i]->value_right);
        free(operations[i]);
    }
}


/* Test */
int main(int argc, char *argv[]) {
    struct value *value1 = malloc(sizeof(struct value));
    struct operation *operation1 = malloc(sizeof(struct operation));
    struct value *value2 = malloc(sizeof(struct value));
    struct operation *operation2 = malloc(sizeof(struct operation));
    struct value *value3 = malloc(sizeof(struct value));
    struct operation *operation3 = malloc(sizeof(struct operation));
    struct value *value4 = malloc(sizeof(struct value));
    struct operation result;
    struct operation *operations[] = {operation1, operation2, operation3};

    /* 5 + 2 - 13 + 20 */

    value1->value = 5;
    value1->operation_right = operation1;

    value2->value = 2;
    value2->operation_left = operation1;
    value2->operation_right = operation2;

    value3->value = 13;
    value3->operation_left = operation2;
    value3->operation_right = operation3;

    value4->value = 20;
    value4->operation_left = operation3;
    value4->operation_right = NULL;

    operation1->operation = '+';
    operation1->value_left = value1;
    operation1->value_right = value2;

    operation2->operation = '-';
    operation2->value_left = value2;
    operation2->value_right = value3;
    
    operation3->operation = '+';
    operation3->value_left = value3;
    operation3->value_right = value4;

    result.value_right = value1;

    value1->operation_left = &result;

    resolve_operations(operations, 3);

    printf("The result of \"5 + 2 - 13 + 20\" is: %d\n", result.value_right->value);

    free(result.value_right);

    return 0;
}