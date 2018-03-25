#include <cstdio>
#include "dictionary.h"
#include <cstring>
#include <iostream>

int main() {
    setlocale(0, "");
    FILE* in;
    in = fopen("SampleOEM866.txt", "r");
    printf("File open\n");
    Map map = loadDict(in);
    char query[100];
    scanf("%s", query);
    Iterator iter;

    for (int i = 0; i < map.length; ++i) {
            printf("%s : %s\n", getItemI(map, i).key, getItemI(map, i).value);
    }

    while (strcmp(query, "quit") != 0) {

        if (strcmp(query, "+") != 0) {
            iter = getIterator(map, query);
            printf("Results prepared, first item at index %d\n", iter.position);
        }

        for (int i = 0; i < 10; ++i) {
            //Problem is here
            Item item = next(iter);
            printf("Next item got\n");

            if (item.key == NULL) {

                if (i == 1) {
                    printf("%s\n", getItemI(map, iter.position-1).value);
                }

                printf("END\n");
                break;
            }

            printf("Next item not last\n");
            printf("%s/n", item.key);
        }

        scanf("%s", query);
    }

    return 0;
}
