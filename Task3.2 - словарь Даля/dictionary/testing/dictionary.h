#ifndef dictionary
#define dictionary

struct node {
    char* key;
    char* value;
    unsigned char height; // char is less than int
    node* left;
    node* right;
    node* parent;
};

struct Iter {
    node* tree;
    char query[100];
    node* lastResult;
};

node* next (Iter* iterator);
void loadDict(FILE* in);
Iter* newIter(char* query);

#endif
