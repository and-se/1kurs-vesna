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

/**The function load dictionary from stream in*/
void loadDict(FILE* in);
/**The function return search iterator with search query == query*/
Iter* newIter(char* query);
/**The function return the next item from dictionary, that suitable on query*/
node* next (Iter* iterator);

#endif
