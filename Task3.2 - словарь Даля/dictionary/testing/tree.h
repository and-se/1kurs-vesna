#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

struct node {
    char* key;
    char* value;
    unsigned char height; // char is less than int
    node* left;
    node* right;
};

node* create(char* k, char* value);
unsigned char height (node* p);
int bfactor (node* p);
void fixheight (node* p);
node* rotateleft (node* q);
node* rotateright (node* p);
node* balance (node* p);
node* insert (node* p, char* key, char* value);
node* findmin (node* p);
node* removemin(node* p);
node* remove (node* p, char* key);

#endif // TREE_H_INCLUDED
