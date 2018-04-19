#include <fstream>;
#include <cstdio>
#include "dictionary.h"
#include <cstring>
#include <iostream>
#include <Windows.h>

int main () {
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE* fin = fopen("SampleOEM866.txt", "r");
    loadDict(fin);
    fclose(fin);
    Iter* iterator = nullptr;
    char query[100];
    scanf("%s", query);

    while (strcmp(query, "quit") != 0) {

        if (strcmp(query, "+") == 0) {

            if (iterator == nullptr) {
                printf("ERROR: No query\n");

            } else {
               node* res = next(iterator);

                for (int i = 0; i < 10; ++i) {

                    if (res == nullptr) {
                        printf("NULL\n");
                        break;
                    }

                    printf("%s\n", res -> key);
                    res = next(iterator);
                }

            }

        } else {

            if (iterator == nullptr) {
                iterator = newIter(query);
            } else {
                delete iterator;
                iterator = newIter(query);
            }

            node* res = next(iterator);
            char* firstValue = nullptr;

            if (res != nullptr) {
                firstValue = res -> value;
            }

            for (int i = 0; i < 10; ++i) {

                if (res == nullptr) {

                    if (i == 1) {
                        printf("%s", firstValue);
                    }

                    printf("NULL\n");
                    break;
                }

                printf("%s\n", res -> key);
                res = next(iterator);
            }

        }

        scanf("%s", query);
    }

}
