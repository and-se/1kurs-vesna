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
    char* str = readLongString(input);
    printf("Dict is read\n");
    char* key;
    char* value;
    int m = 0;

    while ((strlen(str) > 1) && (!feof(input))) {
        int keyLength = 0;
        int numOfKeys = 1;
        printf("%d\n", m++);

        while (*(str+keyLength) != ' ') {

            if (*(str + keyLength) == ',') {
                ++numOfKeys;
                ++keyLength;
            }

            ++keyLength;
        }

        key = (char*)(malloc(sizeof(char)*(keyLength + 1)));
        value = (char*)(malloc(sizeof(char)*(strlen(str) - keyLength)));

        strncpy(key, str, keyLength);
        strncpy(value, str+keyLength+1, strlen(str)-keyLength-1);

        Item items[numOfKeys];

        if (numOfKeys > 1) {
            int StartPos = 0;
            int EndPos = 0;

            for (int i = 0; i < numOfKeys; ++i) {

                while ((*(key + EndPos) != ',') && (EndPos != (int)strlen(key))) {
                    ++EndPos;
                }

                items[i].key = (char*)(malloc(sizeof(char)*(EndPos - StartPos + 1)));
                items[i].value = (char*)(malloc(sizeof(char) * strlen(value) + 1));
                strncpy(items[i].key, key + StartPos, EndPos - StartPos);
                strcpy(items[i].value, value);

                EndPos += 2;
                StartPos = EndPos;
            }
        } else {
            items[0].key = (char*)(malloc(sizeof(char) * strlen(key) + 1));
            items[0].value = (char*)(malloc(sizeof(char) * strlen(value) + 1));

            strcpy(items[0].key, key);
            strcpy(items[0].value, value);
        }

        //free(key);
        //free(value);

        for (int i = 0; i < numOfKeys; ++i) {

            if (((int)searchItem(result, items[i].key, 0)) == -1) {
                addItem(result, items[i]);
            }

            //free(items[i].key);
            //free(items[i].value);
        }

        //free(str);
        str = readLongString(input);
    }

    printf("Dict is read\n");
    return result;
}
