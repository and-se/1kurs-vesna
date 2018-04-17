#include <fstream>;
#include <cstdio>
#include "dictionary.h"
#include "tree.h"
#include "list.h"
#include <cstring>
#include <iostream>
#include <Windows.h>

void postorder (ListNode* p);
//void print_Tree(node * p, int level, FILE* fout);
void setParent (node* p);

int main () {
    setlocale(0, "");
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    FILE* in = fopen("SampleOEM866.txt", "r");
    node* tree = nullptr;

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
                tree = tree::insert(tree, keys[j], value);
                endPos+=2;
                startPos = endPos;
            }

        } else {
            keys[0] = new char[keyEnds+1];
            strncpy(keys[0], str, keyEnds);
            //Key founded
            tree = tree::insert(tree, keys[0], value);
        }

        free(str);
    }

    fclose(in);
    setParent(tree);

    Iter* iterator = new Iter (tree, "ÀÁÀ");

    node* res = tree::next(iterator);

    while (res != nullptr) {
        printf("%s\n", res -> key);
        res = tree::next(iterator);
    }

    /*char* query = new char[100];
    char oldQuery[100];
    FILE* logOut = fopen("queries.log", "w");
    query = fgets(query, 101, stdin);
    fwrite(query, 1, strlen(query), logOut);
    fclose(logOut);
    FILE* logIn = fopen("queries.log", "r");
    query = fgets(query, 101, logIn);
    printf("%s\n", query);*/
    //printf("%s\n", searchQ(tree, "À") -> key);
}

/*void print_Tree (node * p, int level, FILE* fout)
{
    if(p != nullptr)
    {
        print_Tree(p->left,level + 1, fout);

        for (int i = 0; i < level; i++){
            fwrite(" ", 1, 2, fout);
        }

        fwrite(p -> key, 1, strlen(p -> key), fout);
        fwrite("\n", 1, 1, fout);
        print_Tree(p->right,level + 1, fout);
    }
}*/

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
