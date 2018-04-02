#include <cstring>
#include "tree.h"
#include <cstdio>

unsigned char height (node* p) {
    return p?p->height:0;
}

int bfactor (node* p) {
    return height(p->right) - height(p->left);
}

void fixheight (node* p) {
    unsigned char h1 = height(p->left);
    unsigned char h2 = height(p->right);
    p->height = (h1>h2?h1:h2) + 1;
}

node* rotateleft (node* q) {
    node* p = q -> right;
    q -> right = p -> left;
    p -> left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

node* rotateright (node* p) {
    node* q = p -> left;
    p -> left = q -> right;
    q -> right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

node* balance (node* p) {
    fixheight(p);

    if (bfactor(p) > 1) {

        if (bfactor(p -> right) < 0) {
            p -> right = rotateright(p->right);
        }

        return rotateleft(p);
    }

    if (bfactor(p) < -1) {

        if (bfactor(p ->left) > 0) {
            p->left = rotateleft(p -> left);
        }

        return rotateright(p);
    }

    return p;
}

node* insert (node* p, char* key, unsigned int pos) {

    if (!p) {
        return new node(key, pos);
    }

    if (strcmp(key, p -> key) < 0) {
        p -> left = insert(p -> left, key, pos);
    } else {
        p -> right = insert(p -> right, key, pos);
    }

    return balance(p);
}

node* findmin (node* p) {
    return p->left?findmin(p->left):p;
}

node* removemin(node* p) {

    if (p -> left == 0) {
        return p -> right;
    }

    p -> left = removemin(p -> left);
    return balance(p);
}

node* remove (node* p, char* key) {
    if (!p) {
        return 0;
    }

    if (strcmp(key, p -> key) < 0) {
        p -> left = remove(p -> left, key);
    } else if (strcmp(key, p -> key) > 0) {
        p -> right = remove(p -> right, key);
    } else {
        node* q = p -> left;
        node* r = p -> right;
        delete p;
        if (!r) return q;
        node* min = findmin(r);
        min -> right = removemin(r);
        min -> left = q;
        return balance(min);
    }

    return balance(p);
}
