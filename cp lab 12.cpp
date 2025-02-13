#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the structure for three-address code representation
typedef struct {
    char op[3];
    char arg1[10];
    char arg2[10];
    char result[10];
} TAC;

void generateTAC(char *expression, TAC *tac) {
    char temp[10];
    int count = 1;
    int i = 0, j = 0, k = 0;
    char op;

    while (expression[i] != '\0') {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            op = expression[i];
            tac[j].op[0] = op;
            tac[j].op[1] = '\0';
            strncpy(tac[j].arg1, temp, k);
            tac[j].arg1[k] = '\0';
            k = 0;
            i++;

            while (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/' && expression[i] != '\0') {
                temp[k++] = expression[i++];
            }
            temp[k] = '\0';
            strncpy(tac[j].arg2, temp, k);
            tac[j].arg2[k] = '\0';

            sprintf(tac[j].result, "t%d", count++);
            j++;
            k = 0;
        } else {
            temp[k++] = expression[i++];
        }
    }
}

int main() {
    char expression[100];
    TAC tac[10];

    // Read the input expression from the user
    printf("Enter the arithmetic expression: ");
    scanf("%s", expression);

    // Generate three-address code
    generateTAC(expression, tac);

    // Print the generated three-address code
    printf("Three-address code:\n");
    for (int i = 0; i < 10 && tac[i].op[0] != '\0'; i++) {
        printf("%s = %s %s %s\n", tac[i].result, tac[i].arg1, tac[i].op, tac[i].arg2);
    }

    return 0;
}

