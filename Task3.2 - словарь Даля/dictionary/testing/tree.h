#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

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
    char* query;
    node* lastResult;
    Iter (node* t, char* q) {tree = t; query = q; lastResult = nullptr;}
};

node* create (char* k, char* value);
node* insert (node* p, char* key, char* value);
node* remove (node* p, char* key);
node* next (Iter* iterator);
void setParent (node* p);

#endif // TREE_H_INCLUDED
