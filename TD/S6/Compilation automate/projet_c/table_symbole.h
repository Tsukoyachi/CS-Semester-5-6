struct Symbol {
    char name[20];
    int type;
    int value;
};

struct Symbol* findSymbol(struct Symbol symbolTable[], const char* name);

int insertSymbol(struct Symbol symbolTable[], const char* name, int value, int type);

int hashFunction(const char* name);