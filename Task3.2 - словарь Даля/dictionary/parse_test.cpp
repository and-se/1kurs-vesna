#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

int main() {
    setlocale(0, "");
    FILE* in = fopen("SampleOEM866.txt", "r");
    printf("File open\n");

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
        char* value = (char*)(calloc(strlen(str) - valueBegin + 1, sizeof(char)));
        strcpy(value, str+valueBegin);
        printf("%s\n", value);
        free(value);
        char* keys[numOfKeys];

        if (numOfKeys > 1) {
            int startPos = 0, endPos = 0;

            for (int j = 0; j < numOfKeys; ++j) {

                while((*(str + endPos) != ',') && (*(str+endPos) < keyEnds)) {
                    ++endPos;
                }

                keys[j] = (char*)(calloc(endPos - startPos - 1, sizeof(char)));
                strncpy(keys[j], str+startPos, endPos - startPos);
                endPos+=2;
                startPos = endPos;
                printf("%s\n", keys[j]);
                free(keys[j]);
            }

        } else {
            keys[0] = (char*)(calloc(keyEnds+1, sizeof(char)));
            strncpy(keys[0], str, keyEnds);
            printf("%s\n", keys[0]);
            free(keys[0]);
        }

        free(str);
    }

}
