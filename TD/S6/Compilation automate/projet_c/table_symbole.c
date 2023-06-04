#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 10

struct Symbol {
    char name[20];
    int type;
    int value;
};

struct Symbol* findSymbol(struct Symbol symbolTable[], const char* name) {
    int index = hashFunction(name); // Get the hash index
    int originalIndex = index;

    while (strcmp(symbolTable[index].name, name) != 0) {
        index = (index + 1) % MAX_SYMBOLS; // Linear probing
        if (index == originalIndex || symbolTable[index].name[0] == '\0') {
            return NULL; // Symbol not found
        }
    }

    return &symbolTable[index]; // Found the symbol
}

int insertSymbol(struct Symbol symbolTable[], const char* name, int value, int type) {
    int index = hashFunction(name); // Get the hash index
    int originalIndex = index;

    while (symbolTable[index].name[0] != '\0') {
        index = (index + 1) % MAX_SYMBOLS; // Linear probing
        if (index == originalIndex) {
            return 0; // Symbol table is full
        }
    }

    strcpy(symbolTable[index].name, name);
    symbolTable[index].value = value;
    symbolTable[index].type = type;
    return 1; // Insertion successful
}

int hashFunction(const char* name) {
    // A simple hash function using the ASCII values of characters
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }
    return sum % MAX_SYMBOLS;
}