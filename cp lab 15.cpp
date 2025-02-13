#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold intermediate code
typedef struct {
    char op[3];
    char arg1[10];
    char arg2[10];
    char result[10];
} IntermediateCode;

// Function to generate intermediate code
void generateIntermediateCode(char* expr, IntermediateCode* code, int* codeIndex) {
    char temp[10];
    int count = 1;
    int i = 0, j = 0, k = 0;
    char op;

    while (expr[i] != '\0') {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            op = expr[i];
            code[*codeIndex].op[0] = op;
            code[*codeIndex].op[1] = '\0';
            strncpy(code[*codeIndex].arg1, temp, k);
            code[*codeIndex].arg1[k] = '\0';
            k = 0;
            i++;

            while (expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/' && expr[i] != '\0') {
                temp[k++] = expr[i++];
            }
            temp[k] = '\0';
            strncpy(code[*codeIndex].arg2, temp, k);
            code[*codeIndex].arg2[k] = '\0';

            sprintf(code[*codeIndex].result, "t%d", count++);
            (*codeIndex)++;
            k = 0;
        } else {
            temp[k++] = expr[i++];
        }
    }
}

// Function to generate assembly-like code
void generateAssemblyCode(IntermediateCode* code, int codeIndex) {
    printf("Assembly-like code:\n");
    for (int i = 0; i < codeIndex; i++) {
        printf("%s = %s %s %s\n", code[i].result, code[i].arg1, code[i].op, code[i].arg2);
    }
}

int main() {
    char expr[100];
    IntermediateCode code[10];
    int codeIndex = 0;

    // Read the input expression from the user
    printf("Enter the arithmetic expression: ");
    scanf("%s", expr);

    // Generate intermediate code
    generateIntermediateCode(expr, code, &codeIndex);

    // Generate assembly-like code
    generateAssemblyCode(code, codeIndex);

    return 0;
}

