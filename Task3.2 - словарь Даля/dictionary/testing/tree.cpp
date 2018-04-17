#include <cstring>
#include "tree.h"
#include <cstdio>

unsigned char height (node* p);
int bfactor (node* p);
void fixheight (node* p);
node* rotateleft (node* q);
node* rotateright (node* p);
node* balance (node* p);
node* findmin (node* p);
node* removemin (node* p);node*
searchQ (node* p, char* query);

node* create (char* k, char* val) {
    node* result = new node;
    result -> key = k;
    result -> value = val;
    result -> left = result -> right = nullptr;
    result -> height = 0;
    result -> parent = nullptr;

    return result;
}

unsigned char height (node* p) {
    if (p != nullptr) {
        return p -> height;
    } else {
        return 0;
    }
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

node* insert (node* p, char* key, char* value) {

    if (p == nullptr) {
        node* result = create(key, value);
        //result -> parent = nullptr;
        return result;
    }

    if (strcmp(key, p -> key) < 0) {
        p -> left = insert(p -> left, key, value);
        //p -> left -> parent = p;
    } else {
        p -> right = insert(p -> right, key, value);
        //p -> right -> parent = p;
    }

    return balance(p);
}

node* findmin (node* p) {
    if (p -> left != nullptr) {
        return findmin(p -> left);
    } else {
        return p;
    }
}

node* removemin(node* p) {

    if (p -> left == nullptr) {
        return p -> right;
    }

    p -> left = removemin(p -> left);
    return balance(p);
}

node* remove (node* p, char* key) {
    if (p != nullptr) {
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
        if (r != nullptr) {
            return q;
        }
        node* min = findmin(r);
        min -> right = removemin(r);
        min -> left = q;
        return balance(min);
    }

    return balance(p);
}

node* next (Iter* iterator) {

    if (iterator -> lastResult == nullptr) {
        iterator -> lastResult = searchQ(iterator -> tree, iterator -> query);
        return iterator -> lastResult;
    } else if (iterator -> lastResult -> right != nullptr) {
        node* current = iterator -> lastResult -> right;

        if(strncmp(iterator -> query, current -> key, strlen(iterator -> query)) == 0) {

            while (current -> left != nullptr) {
                current = current -> left;
            }

            iterator -> lastResult = current;
            return iterator -> lastResult;
        } else {
            return nullptr;
        }

    } else {
        node* current = iterator -> lastResult -> parent;
        node* previous = iterator -> lastResult;

        while ((current -> left != previous) && (current != nullptr)) {
            current = current -> parent;
            previous = previous -> parent;
        }

        if (current != nullptr) {
            iterator -> lastResult = current;
            return iterator -> lastResult;
        } else {
            return nullptr;
        }
    }

}

node* searchQ (node* p, char* query) {
    node* min = nullptr;
    node* current = p;

    while (true) {
        if (strncmp(query, current -> key, strlen(query)) == 0) {

            if ((min == nullptr) || (strcmp(current -> key, min -> key) < 0)) {
                min = current;
            }

        }

        if ((current->left != nullptr) && (strncmp(current -> key, query, strlen(query)) >= 0)) {
            current = current -> left;
        } else if ((current -> right != nullptr) && (strncmp(current -> key, query, strlen(query)) < 0)) {
            current = current -> right;
        } else {
            break;
        }
    }

    return min;
}

void setParent (node* p) {
    if (p -> left != nullptr) {
        setParent(p -> left);
    }

    if (p -> left != nullptr) {
        p -> left -> parent = p;
    }

    if (p -> right != nullptr) {
        p -> right -> parent = p;
    }

    if (p -> right != nullptr) {
        setParent(p -> right);
    }
}
