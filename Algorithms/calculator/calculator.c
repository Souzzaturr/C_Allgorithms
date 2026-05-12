#include <stdio.h>
#include <stdlib.h>


struct operation {
    char operation;
    int withParenteses;
    int priority;
    struct value *value_right;
    struct value *value_left;
};


struct value {
    int value;
    struct operation *operation_right;
    struct operation *operation_left;
};


struct value_node {
    struct value *value;
    struct value_node *prev;
    struct value_node *prox;
};


struct values_list {
    struct value_node *first_node;
    struct value_node *last_node;
};


struct operation_node {
    struct operation *operation;
    struct operation_node *prox;
    struct operation_node *prev;
};


struct operations_list {
    struct operation_node *first_node;
    struct operation_node *last_node;
    struct operations_list *prox;
    struct operations_list *prev;
    int withParenteses;
    int priority;
};


struct calculation_structure {
    struct operations_list *operations_list_first;
    struct values_list *values_list;
};


void add_value(struct value *value, struct calculation_structure *calculation_structure) {
    struct value_node *node = malloc(sizeof(struct value_node));
    node->value = value;
    node->prox = NULL;
    
    calculation_structure->values_list->last_node->prox = node;
    node->prev = calculation_structure->values_list->last_node;
    calculation_structure->values_list->last_node = node;
}


void add_operation(struct operation *operation, struct calculation_structure *calculation_structure) {
    struct operation_node *node = malloc(sizeof(struct operation_node));
    node->operation = operation;
    node->prox = NULL;

    struct operations_list *temp = calculation_structure->operations_list_first;

    if (temp == NULL) {
        struct operations_list *list_node = malloc(sizeof(struct operations_list));
        list_node->first_node = node;
        list_node->last_node = node;
        list_node->prox = NULL;
        list_node->withParenteses = node->operation->withParenteses;
        list_node->priority = node->operation->priority;

        calculation_structure->operations_list_first = list_node;

        return;
    }

    struct operations_list *prev = temp;

    while (temp != NULL) {
        if (node->operation->withParenteses == temp->withParenteses && node->operation->priority == temp->priority) {
            node->prev = temp->last_node;
            temp->last_node->prox = node;
            temp->last_node = node;

            return;
        }

        if (node->operation->withParenteses > temp->withParenteses || node->operation->withParenteses == temp->withParenteses && node->operation->priority > temp->priority) {
            struct operations_list *list = malloc(sizeof(struct operations_list));
            list->first_node = node;
            list->last_node = node;
            list->prev = (temp != prev) ? prev : NULL;
            list->prox = temp;
            list->withParenteses = node->operation->withParenteses;
            list->priority = node->operation->priority;

            temp->prev = list;

            if (temp != prev) {
                prev->prox = list;

            } else {
                calculation_structure->operations_list_first = list;
            }

            return;
        }

        if (prev != temp) {
            prev = temp;
        }

        temp = temp->prox;
    }

    struct operations_list *list = malloc(sizeof(struct operations_list));
    list->first_node = node;
    list->last_node = node;
    list->withParenteses = node->operation->withParenteses;
    list->priority = node->operation->priority;
    list->prox = NULL;
    list->prev = prev;
    prev->prox = list;
}


void resolve_operations(struct operations_list *list) {
    struct operation_node *node = list->first_node;
    struct operation_node *temp;

    while (node != NULL) {
        struct value *newValue = malloc(sizeof(struct value));
        newValue->operation_left = node->operation->value_left->operation_left;
        if (node->operation->value_left->operation_left != NULL) {
            node->operation->value_left->operation_left->value_right = newValue;
        }
        newValue->operation_right = node->operation->value_right->operation_right;
        if (node->operation->value_right->operation_right != NULL) {
            node->operation->value_right->operation_right->value_left = newValue;
        }

        int value1 = node->operation->value_left->value;
        int value2 = node->operation->value_right->value;

        if (node->operation->operation == '+') {
            newValue->value = value1 + value2;

        } else if (node->operation->operation == '-') {
            newValue->value = value1 - value2;

        } else if (node->operation->operation == '*') {
            newValue->value = value1 * value2;

        } else if (node->operation->operation == '/') {
            newValue->value = value1 / value2;
        }

        temp = node;
        node = node->prox;

        free(temp->operation->value_left);
        free(temp->operation->value_right);
        free(temp->operation);
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

    resolve_operations(operations);

    printf("The result of \"5 + 2 - 13 + 20\" is: %d\n", result.value_right->value);

    free(result.value_right);

    return 0;
}