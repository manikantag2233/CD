#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024

int isSingleLineComment(const char *line) {
    return line[0] == '/' && line[1] == '/';
}

int isMultiLineComment(const char *line) {
    if (strstr(line, "/*") != NULL) {
        return 1;
    }
    return 0;
}

void analyzeLine(const char *line) {
    if (isSingleLineComment(line)) {
        printf("Single-line comment: %s\n", line);
    } else if (isMultiLineComment(line)) {
        printf("Start of multi-line comment: %s\n", line);
        // handle multi-line comments here (simplified for this example)
    } else {
        printf("Not a comment: %s\n", line);
    }
}

int main() {
    FILE *fp = fopen("input.c", "r");
    if (!fp) {
        printf("Failed to open file.\n");
        return 1;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';
        analyzeLine(line);
    }

    fclose(fp);
    return 0;
}

