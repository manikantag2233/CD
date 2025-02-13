#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SYMBOLS 100
#define MAX_SYMBOL_LEN 32

typedef struct {
    char name[MAX_SYMBOL_LEN];
    int value;
} Symbol;

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

int lookupSymbol(const char *name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void insertSymbol(const char *name, int value) {
    int index = lookupSymbol(name);
    if (index == -1) {
        if (symbolCount < MAX_SYMBOLS) {
            strncpy(symbolTable[symbolCount].name, name, MAX_SYMBOL_LEN);
            symbolTable[symbolCount].value = value;
            symbolCount++;
        } else {
            printf("Symbol table is full.\n");
        }
    } else {
        symbolTable[index].value = value;
    }
}

void displaySymbolTable() {
    printf("Symbol Table:\n");
    printf("Name\tValue\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("%s\t%d\n", symbolTable[i].name, symbolTable[i].value);
    }
}

int main() {
    insertSymbol("x", 10);
    insertSymbol("y", 20);
    insertSymbol("z", 30);

    displaySymbolTable();

    printf("Lookup 'y': %d\n", lookupSymbol("y"));
    printf("Lookup 'a': %d\n", lookupSymbol("a"));

    insertSymbol("y", 25); // Update the value of 'y'

    displaySymbolTable();

    return 0;
}

