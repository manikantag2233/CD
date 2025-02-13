#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char *input;
char lookahead;

void nextToken() {
    lookahead = *input++;
}

int E();
int EPrime();
int T();
int TPrime();
int F();

int E() {
    if (T()) {
        if (EPrime()) {
            return 1;
        }
    }
    return 0;
}

int EPrime() {
    if (lookahead == '+') {
        nextToken();
        if (T()) {
            if (EPrime()) {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

int T() {
    if (F()) {
        if (TPrime()) {
            return 1;
        }
    }
    return 0;
}

int TPrime() {
    if (lookahead == '*') {
        nextToken();
        if (F()) {
            if (TPrime()) {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

int F() {
    if (lookahead == '(') {
        nextToken();
        if (E()) {
            if (lookahead == ')') {
                nextToken();
                return 1;
            }
        }
        return 0;
    } else if (isalpha(lookahead)) {
        nextToken();
        return 1;
    }
    return 0;
}

int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", expression);

    input = expression;
    nextToken();

    if (E() && lookahead == '\0') {
        printf("The input string is a valid arithmetic expression.\n");
    } else {
        printf("The input string is NOT a valid arithmetic expression.\n");
    }

    return 0;
}

