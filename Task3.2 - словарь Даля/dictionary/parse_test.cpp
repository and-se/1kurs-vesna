#include <stdio.h>
#include "dictionary.h"
#include "dictWorking.h"
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* in = fopen("SampleUTF8.txt", "r");
    printf("File open\n");

    for (int i = 0; i < 4; ++i) {
        char* str = readLongString(in);
        printf("%s\n", str);
        int valueBegin = 0;
        int numOfKeys = 1;

        while (((*(str+valueBegin) <'a') || (*(str+valueBegin) > 'z')) && (*(str + valueBegin) != '\n')) {
            printf("%s\n", str+valueBegin);

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
        int startPos = 0, endPos = 0;

        for (int j = 0; j < numOfKeys; ++j) {

            while((*(str + endPos) != ',') && (*(str+endPos) != keyEnds)) {
                ++endPos;
            }

            keys[j] = (char*)(calloc(endPos - startPos - 1, sizeof(char)));
            strncpy(keys[j], str+startPos, endPos - startPos);
            startPos = endPos;
            printf("%s\n", keys[j]);
            free(keys[j]);
        }

        free(str);
    }

}
