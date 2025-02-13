#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void eliminateLeftRecursion(char *nonTerminal, char *alpha, char *beta) {
    char newNonTerminal[2];
    newNonTerminal[0] = nonTerminal[0];
    newNonTerminal[1] = '\'';

    printf("%s -> %s%s\n", nonTerminal, beta, newNonTerminal);
    printf("%s -> %s%s | e\n", newNonTerminal, alpha, newNonTerminal);
}

int main() {
    char nonTerminal[10], alpha[10], beta[10];

    printf("Enter the non-terminal (A): ");
    scanf("%s", nonTerminal);
    
    printf("Enter the production in the form A -> Aa | ß\n");
    printf("Enter a: ");
    scanf("%s", alpha);
    printf("Enter ß: ");
    scanf("%s", beta);

    eliminateLeftRecursion(nonTerminal, alpha, beta);

    return 0;
}

