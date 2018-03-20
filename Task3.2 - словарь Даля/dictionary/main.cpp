#include <cstdio>
#include "dictionary.h"
#include "dictWorking.h"
#include <cstring>
#include <iostream>

int main() {
    setlocale(0, "");
    FILE* in;
    Map result;
    char query[100];
    Iterator iter;
    in = fopen("SampleOEM866.txt", "r");
    printf("File open\n");
    Map map = loadDict(in);
    sortByKey(map);
    scanf("%s", query);
    create(result,1);

    while (strcmp(query, "quit") != 0) {

        if (strcmp(query, "+") != 0) {

            if (result.length == 0) {
                remove(result);
            }

            //Problem is here
            //Can't get any item from result;
            result = searchByQuery(map, query, true);
            iter = getIterator(result);
            printf("Results prepared\n");
        }

        for (int i = 0; i < 10; ++i) {
            Item item = next(&iter);
            printf("Next item got\n");

            if (item.key == NULL) {
                printf("END\n");
                break;
            }

            printf("Next item not last\n");

            if (result.length == 1) {
                printf("Almost print key and value\n");
                printf("%s : %s\n", item.key, item.value);
            } else {
                printf("Almost print key\n");
                printf("%s\n", item.key);
            }
        }

        scanf("%s", query);
    }

    return 0;
}
