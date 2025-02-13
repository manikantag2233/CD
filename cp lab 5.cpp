#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 32

int isValidIdentifier(const char *identifier) {
    // Check if the first character is a letter or underscore
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return 0;
    }

    // Check the rest of the characters
    for (int i = 1; i < strlen(identifier); i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return 0;
        }
    }

    return 1;
}

void checkIdentifier(const char *identifier) {
    if (isValidIdentifier(identifier)) {
        printf("Valid identifier: %s\n", identifier);
    } else {
        printf("Invalid identifier: %s\n", identifier);
    }
}

int main() {
    char input[MAX_ID_LEN];
    printf("Enter an identifier: ");
    scanf("%s", input);

    checkIdentifier(input);

    return 0;
}


