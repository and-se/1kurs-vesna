#include <cstdio>
#include "dictionary.h"
#include "dictWorking.h"
#include <cstring>
#include <iostream>

int main() {
    setlocale(0, "");
    FILE* in;
    in = fopen("SampleOEM866.txt", "r");
    printf("File open\n");
    Map map = loadDict(in);
    sortByKey(map);

    /*for (int i = 0; i < (int)map.length; ++i) {
        //printf("%s : %s\n", getItemI(map, i).key, getItemI(map, i).value);
    }*/

    char query[100];
    scanf("%s", query);
    Map result;
    create(result,10);
    Iterator iter;

    while (strcmp(query, "quit") != 0) {

        if (strcmp(query, "+") != 0) {

            if (result.length == 0) {
                remove(result);
            }

            result = searchByQuery(map, query, true);
            iter = getIterator(result);
        }

        for (int i = 0; i < 10; ++i) {
            Item item = next(iter);
            if (item.key == NULL) {
                printf("END\n");
                break;
            }

            if (result.length == 1) {
                printf("%s : %s\n", item.key, item.value);
            } else {
                printf("%s\n", item.key);
            }
        }

        scanf("%s", query);
    }

    return 0;
}
