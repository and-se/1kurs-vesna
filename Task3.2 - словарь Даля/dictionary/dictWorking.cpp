#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "dictionary.h"

char* readLongString(FILE *input) {
    const int readBuffer = 100;
    int stringSize = readBuffer;
    char* string = (char*)(malloc(sizeof(char)*stringSize));
    int position = 0;

    while (true) {
        fgets(string + position, stringSize - position, input);
        char end = *(string + strlen(string) - 1);

        if((end != '\n') && (!feof(input))) {
            char temp[stringSize];
            strcpy(temp, string);
            position = stringSize - 1;
            stringSize += readBuffer;
            free(string);
            string = (char*)(malloc(sizeof(char)*stringSize));
            strcpy(string, temp);
        } else {
            break;
        }

    }

    // Remove '/n' symbol
    *(string + strlen(string) - 1) = '\0';

    return string;
}

Map loadDict (FILE *input/*, Map& map*/) {
    Map result;
    create(result, 10);

    while (!feof(input)) {
        char* str = readLongString(input);
        int valueBegin = 0;
        int numOfKeys = 1;

        while (((*(str+valueBegin) <'à') || (*(str+valueBegin) > 'ÿ')) && (*(str + valueBegin) != '\n')) {

            if (*(str+valueBegin) == ',') {
                ++numOfKeys;
            }

            ++valueBegin;
        }

        int keyEnds = valueBegin - 1;

        if (numOfKeys > 1) {
            int startPos = 0, endPos = 0;

            for (int j = 0; j < numOfKeys; ++j) {

                while((*(str + endPos) != ',') && (*(str+endPos) < keyEnds)) {
                    ++endPos;
                }

                Item item;
                item.key = (char*)(calloc(endPos - startPos - 1, sizeof(char)));
                strncpy(item.key, str+startPos, endPos - startPos);
                item.value = (char*)(calloc(strlen(str) - valueBegin + 1, sizeof(char)));
                strcpy(item.value, str+valueBegin);
                addItem(result, item);

                endPos+=2;
                startPos = endPos;
                free(item.key);
                free(item.value);
            }

        } else {
            Item item;
            item.key = (char*)(calloc(keyEnds+1, sizeof(char)));
            strncpy(item.key, str, keyEnds);
            item.value = (char*)(calloc(strlen(str) - valueBegin + 1, sizeof(char)));
            strcpy(item.value, str+valueBegin);
            addItem(result, item);

            free(item.key);
            free(item.value);
        }

        free(str);
    }

    printf("Dict is read\n");
    return result;
}
