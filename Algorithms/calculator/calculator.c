#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct operation {
    char operation;
    int withParenteses;
    int priority;
    struct value *value_right;
    struct value *value_left;
};


struct value {
    double value;
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
    struct value *calculation;
};


void add_value(struct value *value, struct calculation_structure *calculation_structure);
void add_operation(struct operation *operation, struct calculation_structure *calculation_structure);
void add_calculation(char *character, int priority, int withParenteses, struct calculation_structure *calculation_structure);
void resolve(struct calculation_structure *calcStruct);
void resolve_operations(struct operations_list *list);
int is_operation(char character);
int is_value_char(char character);
int is_parenteses(char character);
char * operationToStr(char operation);
struct calculation_structure * reader(char *string);
void clear(struct calculation_structure **calcStructPtr);


/* Main function */
int main(int argc, char *argv[]) {
    struct calculation_structure *calculation_structure;

    if (argc == 1) {
        printf("Argument calculation is needed!\n");

        return 1;
    }

    if (argc > 2) {
        printf("Many arguments inserted, only one is necessary!\n");

        return 1;
    }

    // Resolution
    calculation_structure = reader(argv[1]);
    
    if (calculation_structure == NULL) {
        
        return 1;
    }
    
    resolve(calculation_structure);

    printf("%f\n", calculation_structure->calculation->value);
    
    clear(&calculation_structure);

    return 0;
}


void add_value(struct value *value, struct calculation_structure *calculation_structure) {
    struct value_node *node = malloc(sizeof(struct value_node));
    node->value = value;
    node->prox = NULL;
    
    if (calculation_structure->values_list == NULL) {
        calculation_structure->values_list = malloc(sizeof(struct values_list));
        calculation_structure->values_list->first_node = node;
        calculation_structure->values_list->last_node = node;
        node->prev = NULL;

        return;
    }

    calculation_structure->values_list->last_node->prox = node;
    node->prev = calculation_structure->values_list->last_node;
    calculation_structure->values_list->last_node = node;
}


void add_operation(struct operation *operation, struct calculation_structure *calculation_structure) {
    struct operation_node *node = malloc(sizeof(struct operation_node));
    node->operation = operation;
    node->prev = NULL;
    node->prox = NULL;

    struct operations_list *temp = calculation_structure->operations_list_first;

    if (temp == NULL) {
        struct operations_list *list_node = malloc(sizeof(struct operations_list));
        list_node->first_node = node;
        list_node->last_node = node;
        list_node->prox = NULL;
        list_node->prev = NULL;
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


void add_calculation(char *str, int priority, int withParenteses, struct calculation_structure *calculation_structure) {
    struct value *value;
    struct operation *operation;
    struct operation *temp1 = NULL;
    struct value *temp2 = NULL;

    if (strlen(str) == 1 && (*str == '+' || *str == '-' || *str == '*' || *str == '/')) {
        operation = malloc(sizeof(struct operation));
        operation->operation = *str;
        operation->priority = priority;
        operation->withParenteses = withParenteses;
        operation->value_left = NULL;
        operation->value_right = NULL;

        temp2 = calculation_structure->calculation;
        
        while (temp2->operation_right != NULL) {
            temp1 = temp2->operation_right;
            temp2 = temp1->value_right;
        }

        temp2->operation_right = operation;
        operation->value_left = temp2;

        add_operation(operation, calculation_structure);

        return;
    }

    value = malloc(sizeof(struct value));
    value->value = atof(str);
    value->operation_right = NULL;
    value->operation_left = NULL;

    if (calculation_structure->calculation == NULL) {
        calculation_structure->calculation = value;

    } else {
        temp1 = calculation_structure->calculation->operation_right;

        while (temp1->value_right != NULL) {
            temp2 = temp1->value_right;
            temp1 = temp2->operation_right;
        }

        temp1->value_right = value;
        value->operation_left = temp1;
    }

    add_value(value, calculation_structure);
}


void resolve(struct calculation_structure *calcStruct) {
    struct operations_list *list = calcStruct->operations_list_first;

    while (list != NULL) {
        resolve_operations(list);

        list = list->prox;
    }
}


void resolve_operations(struct operations_list *list) {
    struct operation_node *node = list->first_node;
    struct operation_node *temp;
    struct value *newValue;
    int isFirstOperationOfCalculation;
    int isLastOperationOfCalculation;

    while (node != NULL) {
        isFirstOperationOfCalculation = 0;
        isLastOperationOfCalculation = 0;

        if (node->operation->value_left->operation_left != NULL && node->operation->value_right->operation_right != NULL) {
            newValue = malloc(sizeof(struct value));

        } else {
            if (node->operation->value_left->operation_left == NULL) {
                newValue = node->operation->value_left;
                isFirstOperationOfCalculation = 1;

            }
            
            if (node->operation->value_right->operation_right == NULL) {
                if (!isFirstOperationOfCalculation) {
                    newValue = node->operation->value_right;
                }

                isLastOperationOfCalculation = 1;

            }
        }

        newValue->operation_left = node->operation->value_left->operation_left;
        if (!isFirstOperationOfCalculation) {
            node->operation->value_left->operation_left->value_right = newValue;
        }

        newValue->operation_right = node->operation->value_right->operation_right;
        if (!isLastOperationOfCalculation) {
            node->operation->value_right->operation_right->value_left = newValue;
        }

        double value1 = node->operation->value_left->value;
        double value2 = node->operation->value_right->value;

        if (node->operation->operation == '+') {
            newValue->value = value1 + value2;

        } else if (node->operation->operation == '-') {
            newValue->value = value1 - value2;

        } else if (node->operation->operation == '*') {
            newValue->value = value1 * value2;

        } else if (node->operation->operation == '/') {
            if (value2 == 0) {
                printf("Error, division for zero!\n");
                newValue->value = 0;
                // break;
            }

            newValue->value = value1 / value2;
        }

        temp = node;
        node = node->prox;

        if (!isFirstOperationOfCalculation) {
            free(temp->operation->value_left);
        }

        if (isFirstOperationOfCalculation || !isLastOperationOfCalculation) {
            free(temp->operation->value_right);
        }

        free(temp->operation);
    }
}


struct calculation_structure * reader(char *calculation) {
    struct calculation_structure *calcStruct;
    char *valueBuffer;
    int priority;
    int openedParentesesCount = 0;
    int parenteses = 0;
    int calculationSize = strlen(calculation);

    if (is_operation(*calculation) || is_operation(*(calculation + calculationSize - 1))) {
        printf("Operation with invalid value on the %s-hand side, in the calculation %s!\n", is_operation(*calculation) ? "left" : "right", is_operation(*calculation) ? "start" : "end");

        return NULL;
    }

    for (int i = 0; i < calculationSize; i++) {
        if (*(calculation + i) < 40 || *(calculation + i) == 44 || *(calculation + i) > 57) {
            printf("Insert only numbers, point \".\", parenteses \"(\" \")\", and operation characters (\"+\", \"-\", \"*\", \"/\")!\n");
            printf("Invalid character inserted: \"%c\"\n", *(calculation + i));

            return NULL;
        }

        if (i > 0 && i < calculationSize && is_operation(*(calculation + i)) && (is_operation(*(calculation + i - 1)) || is_operation(*(calculation + i + 1)))) {
            printf("Sequence with more than one operation \"%c\" in a row is not allowed!\n", *(calculation + i));

            return NULL;
        }

        if (i > 0 && i < calculationSize && *(calculation + i) == '.' && (*(calculation + i - 1) == '.' || *(calculation + i + 1) == '.')) {
            printf("Sequence with more than one point \".\" in a row is not allowed!\n");

            return NULL;
        }

        if (is_parenteses(*(calculation + i))) {
            if (*(calculation + i) == '(' && (i == 0 && i < calculationSize - 1 && !is_value_char(*(calculation + i + 1)) && !is_parenteses(*(calculation + i + 1)) || i > 0 && i < calculationSize - 1 && (!is_operation(*(calculation + i - 1)) && !is_parenteses(*(calculation + i - 1)) || !is_value_char(*(calculation + i + 1)) && !is_parenteses(*(calculation + i + 1))) || i == calculationSize - 1)) {
                printf("Invalid calculation with open parenteses!\n");

                return NULL;

            } else if (*(calculation + i) == ')' && (i == calculationSize - 1 && i > 0 && !is_value_char(*(calculation + i - 1)) && !is_parenteses(*(calculation + i - 1)) || i > 0 && i < calculationSize - 1 && (!is_value_char(*(calculation + i - 1)) && !is_parenteses(*(calculation + i - 1)) || !is_operation(*(calculation + i + 1)) && !is_parenteses(*(calculation + i + 1))) || i == 0)) {
                printf("Invalid calculation with close parenteses!\n");

                return NULL;
            }
                
            *(calculation + i) == '(' ? openedParentesesCount++ : openedParentesesCount--;

            if (openedParentesesCount < 0) {
                printf("Parenteses closed without other opening parenteses before it!\n");

                return NULL;
            }
        }
    }

    if (openedParentesesCount != 0) {
        printf("Parenteses not opened or closed correctly!\n");

        return NULL;
    }

    calcStruct = malloc(sizeof(struct calculation_structure));
    calcStruct->calculation = NULL;
    calcStruct->operations_list_first = NULL;
    calcStruct->values_list = NULL;

    for (int i = 0; i < calculationSize; i++) {
        if (is_operation(*(calculation + i))) {

            if (*(calculation + i) == '+' || *(calculation + i) == '-') {
                priority = 0;

            } else if (*(calculation + i) == '*' || *(calculation + i) == '/') {
                priority = 1;
            }

            add_calculation(operationToStr(*(calculation + i)), priority, parenteses, calcStruct);

            continue;
        }

        if (*(calculation + i) == '(') {
            parenteses++;

            continue;

        } else if (*(calculation + i) == ')') {
            parenteses--;

            continue;
        }

        if (is_value_char(*(calculation + i))) {
            if (i == 0 || i > 0  && !is_value_char(*(calculation + i - 1))) {
                valueBuffer = malloc(2);
                *(valueBuffer) = *(calculation + i);
                *(valueBuffer + 1) = '\0';

                if (i == calculationSize - 1 || !is_value_char(*(calculation + i + 1))) {
                    add_calculation(valueBuffer, 0, 0, calcStruct);

                    free(valueBuffer);
                }

            } else if (i == calculationSize - 1 || !is_value_char(*(calculation + i + 1))) {
                valueBuffer = (char *) realloc(valueBuffer, strlen(valueBuffer) + 2);
                *(valueBuffer + strlen(valueBuffer) + 1) = '\0';
                *(valueBuffer + strlen(valueBuffer)) = *(calculation + i);

                add_calculation(valueBuffer, 0, 0, calcStruct);

                free(valueBuffer);

            } else {
                valueBuffer = (char *) realloc(valueBuffer, strlen(valueBuffer) + 2);
                *(valueBuffer + strlen(valueBuffer) + 1) = '\0';
                *(valueBuffer + strlen(valueBuffer)) = *(calculation + i);
            }
        }
    }

    return calcStruct;
}


void clear(struct calculation_structure **calcStructPtr) {
    if (*calcStructPtr == NULL) return;

    struct operations_list *op_list_temp;
    struct operation_node *op_nd_temp;
    struct value_node *vlr_nd_temp;

    vlr_nd_temp = (*calcStructPtr)->values_list->first_node;

    while ((*calcStructPtr)->values_list->first_node != NULL) {
        (*calcStructPtr)->values_list->first_node = vlr_nd_temp->prox;
        free(vlr_nd_temp);
        vlr_nd_temp = (*calcStructPtr)->values_list->first_node;
    }

    op_list_temp = (*calcStructPtr)->operations_list_first;

    while ((*calcStructPtr)->operations_list_first != NULL) {
        (*calcStructPtr)->operations_list_first = op_list_temp->prox;

        op_nd_temp = op_list_temp->first_node;

        while (op_list_temp->first_node != NULL) {
            op_list_temp->first_node = op_nd_temp->prox;
            free(op_nd_temp);
            op_nd_temp = op_list_temp->first_node;
        }

        free(op_list_temp);
        op_list_temp = (*calcStructPtr)->operations_list_first;
    }

    if ((*calcStructPtr)->calculation != NULL) {
        free((*calcStructPtr)->calculation);
    }

    free(*calcStructPtr);
}


int is_operation(char character) {
    if (character == '+' || character == '-' || character == '*' || character == '/') return 1;
    return 0;
}


int is_value_char(char character) {
    if (character >= 48 && character <= 57 || character == '.') return 1;
    return 0;
}


int is_parenteses(char character) {
    if (character == '(' || character == ')') return 1;
    return 0;
}


char * operationToStr(char operation) {
    char *string = malloc(2);
    *string = operation;
    *(string + 1) = '\0';

    return string;
}