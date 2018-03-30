#include <cstdio>
#include "dictionary.h"
#include <cstring>
#include <iostream>
#include <cstdlib>

int parse(char* str, char** keys, char* value);

int main()
{
    setlocale(0, "");
    FILE* in = fopen("SampleOEM866.txt", "r");
    char** keys;
    char* value;
    char* str = readLongString(in);
    int num = parse(str, keys, value);

    for (int i = 0; i < num; ++i) {
        printf("%s : %s\n", *(keys + i), value);
        free(*(keys + i));
    }

    free(str);
    free(keys);
    free(value);
}

int parse(char* str, char** keys, char* value) {
    int valueBegin = 0;
    int numOfKeys = 1;

    while (((*(str+valueBegin) <'à') || (*(str+valueBegin) > 'ÿ')) && (*(str + valueBegin) != '\n')) {

        if (*(str+valueBegin) == ',') {
            ++numOfKeys;
        }

        ++valueBegin;
    }

    int keyEnds = valueBegin - 1;
    value = (char*)(calloc(strlen(str) - valueBegin + 1, sizeof(char)));
    strcpy(value, str+valueBegin);
    keys = (char**)(calloc(numOfKeys, sizeof(char*)));

    if (numOfKeys > 1) {
        int startPos = 0, endPos = 0;

        for (int j = 0; j < numOfKeys; ++j) {

            while((*(str + endPos) != ',') && (*(str+endPos) < keyEnds)) {
                ++endPos;
            }

            *(keys + j) = (char*)(calloc(endPos - startPos - 1, sizeof(char)));
            strncpy(*(keys + j), str+startPos, endPos - startPos);
            endPos+=2;
            startPos = endPos;
        }

    } else {
        *keys = (char*)(calloc(keyEnds+1, sizeof(char)));
        strncpy(*keys, str, keyEnds);
    }

    return numOfKeys;

}
