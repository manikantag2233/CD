#include <stdio.h>

void countWhitespaceAndNewlines(FILE *fp) {
    char ch;
    int whitespaceCount = 0;
    int newlineCount = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\t') {
            whitespaceCount++;
        } else if (ch == '\n') {
            newlineCount++;
        }
    }

    printf("Number of whitespace characters: %d\n", whitespaceCount);
    printf("Number of newline characters: %d\n", newlineCount);
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        printf("Failed to open file.\n");
        return 1;
    }

    countWhitespaceAndNewlines(fp);

    fclose(fp);
    return 0;
}

