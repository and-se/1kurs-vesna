#include <cstring>
#include <cstdio>
#include "dictionary.h"

char* readLongString(FILE *input);
void setParent (node* p);
node* create (char* k, char* value);
node* insert (node* p, char* key, char* value);
node* remove (node* p, char* key);
unsigned char height (node* p);
int bfactor (node* p);
void fixheight (node* p);
node* rotateleft (node* q);
node* rotateright (node* p);
node* balance (node* p);
node* findmin (node* p);
node* removemin (node* p);node*
searchQ (node* p, char* query);

node* dict = nullptr;


char* readLongString(FILE* input) {
    const int readBuffer = 100;
    int stringSize = readBuffer;
    char* string = new char[stringSize];
    int position = 0;

    while (true) {
        fgets(string + position, stringSize - position, input);
        char end = *(string + strlen(string) - 1);

        if ((end!= '\n') && (!feof(input))) {
            position = stringSize - 1;
            stringSize += readBuffer;
            char* newString = new char[stringSize];
            strcpy(newString, string);
            delete[] string;
            string = newString;
        } else {
            break;
        }

    }

    return string;
}

void loadDict(FILE* in) {
    node* result = nullptr;

    while (!feof(in)) {
        char* str = readLongString(in);
        int valueBegin = 0;
        int numOfKeys = 1;

        while (((*(str+valueBegin) <'à') || (*(str+valueBegin) > 'ÿ')) && (*(str + valueBegin) != '\n')) {

            if (*(str+valueBegin) == ',') {
                ++numOfKeys;
            }

            ++valueBegin;
        }

        int keyEnds = valueBegin - 1;
        char* value = new char[strlen(str) - valueBegin + 1];
        strcpy(value, str+valueBegin);
        //Value founded
        char* keys[numOfKeys];

        if (numOfKeys > 1) {
            int startPos = 0, endPos = 0;

            for (int j = 0; j < numOfKeys; ++j) {

                while((*(str + endPos) != ',') && (*(str+endPos) < keyEnds)) {
                    ++endPos;
                }

                keys[j] = new char[endPos - startPos - 1];
                strncpy(keys[j], str+startPos, endPos - startPos);
                //Key j founded
                result = insert(result, keys[j], value);
                endPos+=2;
                startPos = endPos;
            }

        } else {
            keys[0] = new char[keyEnds+1];
            strncpy(keys[0], str, keyEnds);
            //Key founded
            result = insert(result, keys[0], value);
        }

        delete[] str;
    }

    setParent(result);
    dict = result;
}

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
    } else if (iterator -> lastResult -> right != nullptr) { //Has right
        node* current = searchQ(iterator -> lastResult -> right, iterator -> query);

        if (current != nullptr) {
            iterator -> lastResult = current;
            return iterator -> lastResult;
        } else {
            return nullptr;
        }

    } else {  //No right
        node* current = iterator -> lastResult -> parent;
        node* previous = iterator -> lastResult;

        while ((current != nullptr) && ((current -> left != previous) || (strncmp(current -> key, iterator -> query, strlen(iterator -> query)) != 0))) {
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

Iter* newIter (char* query) {
    Iter* result = new Iter;
    result -> tree = dict;
    result -> lastResult = nullptr;
    strcpy(result -> query, query);

    return result;
}
