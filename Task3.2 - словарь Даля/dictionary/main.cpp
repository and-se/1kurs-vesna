#include <cstdio>
#include "dictionary.h"
#include "dictWorking.h"
#include <cstring>

int mainn() {
    FILE* in;
    //in = stdin;
    in = fopen("SampleOEM866.txt", "r");
    printf("File open\n");
    //Map map = loadDict(in);

    for (int i = 0; i < 100/*(int)map.length*/; ++i) {
        //printf("%s\n", readLongString(in));
        //printf("%s : %s\n", getItemI(map, i).key, getItemI(map, i).value);
    }
    /*sortByKey(map);
    char query[100];
    scanf("%s", query);
    Map result;
    Iterator iter;

    while (strcmp(query, "quit") != 0) {

        if (strcmp(query, "+") != 0) {
            remove(result);
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
    }*/

    return 0;
}
