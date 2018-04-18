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
