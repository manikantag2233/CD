#include <stdio.h>
#include <ctype.h>
#include <string.h>

void validateAndRecognizeOperators(const char *input) {
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        char ch = input[i];

        // Skip whitespace
        if (isspace(ch)) {
            continue;
        }

        // Recognize arithmetic operators
        switch (ch) {
            case '+':
                printf("Operator: +\n");
                break;
            case '-':
                printf("Operator: -\n");
                break;
            case '*':
                printf("Operator: *\n");
                break;
            case '/':
                printf("Operator: /\n");
                break;
            default:
                // Print as identifier or constant for simplicity
                if (isdigit(ch) || isalpha(ch)) {
                    printf("Identifier or Constant: %c\n", ch);
                } else {
                    printf("Invalid Character: %c\n", ch);
                }
                break;
        }
    }
}

int main() {
    char input[256];
    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    validateAndRecognizeOperators(input);

    return 0;
}

