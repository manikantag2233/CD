#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 32
#define MAX_CONST_LEN 32

void skipWhitespaceAndComments(FILE *fp) {
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch)) continue;
        if (ch == '/') {
            char nextChar = fgetc(fp);
            if (nextChar == '/') { // single line comment
                while ((ch = fgetc(fp)) != '\n' && ch != EOF);
            } else if (nextChar == '*') { // multi-line comment
                while ((ch = fgetc(fp)) != EOF) {
                    if (ch == '*' && (nextChar = fgetc(fp)) == '/') break;
                }
            } else {
                ungetc(nextChar, fp);
                ungetc(ch, fp);
                break;
            }
        } else {
            ungetc(ch, fp);
            break;
        }
    }
}

void identifyToken(char *token) {
    if (isdigit(token[0])) {
        printf("Constant: %s\n", token);
    } else if (isalpha(token[0]) || token[0] == '_') {
        printf("Identifier: %s\n", token);
    } else {
        printf("Operator: %s\n", token);
    }
}

void lexicalAnalyzer(FILE *fp) {
    char ch, token[MAX_ID_LEN];
    int index = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch) || ch == '/' || ispunct(ch)) {
            if (index > 0) {
                token[index] = '\0';
                identifyToken(token);
                index = 0;
            }
            if (ch == '/' || ispunct(ch)) {
                ungetc(ch, fp);
                skipWhitespaceAndComments(fp);
            }
        } else {
            if (index < MAX_ID_LEN - 1) {
                token[index++] = ch;
            }
        }
    }

    if (index > 0) {
        token[index] = '\0';
        identifyToken(token);
    }
}

int main() {
    FILE *fp = fopen("input.c", "r");
    if (!fp) {
        printf("Failed to open file.\n");
        return 1;
    }

    lexicalAnalyzer(fp);

    fclose(fp);
    return 0;
}

