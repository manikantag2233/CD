#include <stdio.h>
#include <string.h>

void eliminateLeftFactoring(char *nonTerminal, char *alpha, char *beta1, char *beta2) {
    char newNonTerminal[2];
    newNonTerminal[0] = nonTerminal[0];
    newNonTerminal[1] = '\'';

    printf("%s -> %s%s\n", nonTerminal, alpha, newNonTerminal);
    printf("%s -> %s | %s\n", newNonTerminal, beta1, beta2);
}

int main() {
    char nonTerminal[10], alpha[10], beta1[10], beta2[10];

    printf("Enter the non-terminal (A): ");
    scanf("%s", nonTerminal);

    printf("Enter the common prefix (a): ");
    scanf("%s", alpha);

    printf("Enter the first suffix (ß1): ");
    scanf("%s", beta1);

    printf("Enter the second suffix (ß2): ");
    scanf("%s", beta2);

    eliminateLeftFactoring(nonTerminal, alpha, beta1, beta2);

    return 0;
}

