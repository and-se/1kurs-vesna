#include <cstdio>
#include "dictionary.h"
#include "tree.h"
#include "valueStorage.h"
#include <cstring>
#include <iostream>
#include <cstdlib>

node* postorder (node* p, char* query);
void nul (node* p);

int main () {
    setlocale(0, "");
    FILE* in = fopen("SampleOEM866.txt", "r");
    Storage* store = new Storage(10);
    node* tree = create(nullptr, 0);

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
        add(store, value);
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
                //printf("String = %d, key = %s\n", i+1, keys[j]);
                tree = insert(tree, keys[j], i);
                endPos+=2;
                startPos = endPos;
            }

        } else {
            keys[0] = new char[keyEnds+1];
            strncpy(keys[0], str, keyEnds);
            //Key founded
            //printf("String = %d, key = %s\n", i+1, keys[0]);
            tree = insert(tree, keys[0], i);
        }

        free(str);
    }

    char query[100];
    char oldQuery[100];
    scanf("%s", query);

    while (strcmp(query, "quit") != 0) {

        if (strcmp(query, "next") == 0) {

            for (int i = 0; i < 10; ++i) {
                printf("%s\n", postorder(tree, oldQuery) -> key);
            }

        }else{
            strcpy(oldQuery, query);
            nul(tree);

            for (int i = 0; i < 10; ++i) {
                printf("%s\n", postorder(tree, oldQuery) -> key);
            }

        }

    }

}

node* postorder (node* p, char* query){

    if (p -> left != nullptr) {
        postorder(p -> left, query);
    }

    if((strncmp(p -> key, query, strlen(query)) == 0) && (!p -> isUsed)) {
        p -> isUsed = true;
        return p;
    }

    if (p -> right != nullptr) {
        postorder(p -> right, query);
    }

}

void nul (node* p) {

    if (p -> left != nullptr) {
        nul(p -> left);
    }

    p -> isUsed = false;

    if (p -> right != nullptr) {
        nul(p -> right);
    }

}
