#include <stdio.h>
#include <string.h>

// Define a structure to hold expressions
typedef struct {
    char expr[50];
    char temp[10];
} Expression;

// Check if the expression is already in the list of expressions
int findExpression(Expression expressions[], int n, char *expr) {
    for (int i = 0; i < n; i++) {
        if (strcmp(expressions[i].expr, expr) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of statements: ");
    scanf("%d", &n);

    Expression expressions[n];
    char statement[50];
    int exprCount = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter statement %d: ", i + 1);
        scanf("%s", statement);

        // Parse the statement
        char lhs[10], op1[10], op2[10], op;
        sscanf(statement, "%[^=]=%[^%c]%[^%c]", lhs, op1, &op, op2);

        char expr[50];
        sprintf(expr, "%s %c %s", op1, op, op2);

        // Check if the expression is already in the list of expressions
        int pos = findExpression(expressions, exprCount, expr);

        if (pos == -1) {
            // Add the new expression to the list
            strcpy(expressions[exprCount].expr, expr);
            sprintf(expressions[exprCount].temp, "t%d", exprCount + 1);
            exprCount++;
        } else {
            // Use the existing temporary variable
            strcpy(lhs, expressions[pos].temp);
        }

        printf("%s = %s\n", lhs, expr);
    }

    return 0;
}

