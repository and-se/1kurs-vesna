#include <cstdio>
#include "dictionary.h"
#include "tree.h"
#include <cstring>
#include <iostream>
#include <cstdlib>

node* searchQ (node* p, char* query, node* result);
void postorder (node* p);

int main () {
    setlocale(0, "");
    FILE* in = fopen("SampleOEM866.txt", "r");
    node* tree = create(nullptr, nullptr);

    for (int i = 0; i < 100; ++i) {
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
                tree = insert(tree, keys[j], value);
                endPos+=2;
                startPos = endPos;
            }

        } else {
            keys[0] = new char[keyEnds+1];
            strncpy(keys[0], str, keyEnds);
            //Key founded
            tree = insert(tree, keys[0], value);
        }

        free(str);
    }

    char query[100];
    char oldQuery[100];

    //scanf("%s", query);
    node* res = create(nullptr, nullptr);
    res = searchQ (tree, "ÀÁÀ", res);
    postorder(res);
}

node* searchQ (node* p, char* query, node* result){

    if (p->left != nullptr) {
        result = searchQ(p -> left, query, result);
    }

    if (strncmp(query, p -> key, strlen(query)) == 0) {
        result = insert(result, p -> key, p -> value);
    }

    if (p -> right != nullptr) {
        result = searchQ(p -> right, query, result);
    }

    return result;
}

void postorder (node* p) {
    if (p -> left != nullptr) {
        postorder(p -> left);
    }

    printf("%s\n", p -> key);

    if (p -> right != nullptr) {
        postorder(p -> right);
    }
}
