#include <fstream>;
#include <cstdio>
#include "dictionary.h"
#include "tree.h"
#include <cstring>
#include <iostream>
#include <Windows.h>

int main () {
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE* fin = fopen("SampleOEM866.txt", "r");
    node* tree = loadDict(fin);
    fclose(fin);
    char query[100];
    scanf("%s", query);

    Iter* iterator = new Iter (tree, query);

    node* res = next(iterator);

    while (res != nullptr) {
        printf("%s\n", res -> key);
        res = next(iterator);
    }
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
