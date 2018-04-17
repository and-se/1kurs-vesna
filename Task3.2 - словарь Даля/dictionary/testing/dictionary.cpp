#include <cstring>
#include <cstdio>
#include "dictionary.h"
#include "tree.h"

char* readLongString(FILE *input);

char* readLongString(FILE* input) {
    const int readBuffer = 100;
    int stringSize = readBuffer;
    char* string = new char[stringSize];
    int position = 0;

    while (true) {
        fgets(string + position, stringSize - position, input);
        char end = *(string + strlen(string) - 1);

        if ((end!= '\n') && (!feof(input))) {
            position = stringSize - 1;
            stringSize += readBuffer;
            char* newString = new char[stringSize];
            strcpy(newString, string);
            delete[] string;
            string = newString;
        } else {
            break;
        }

    }

    return string;
}

node* loadDict(FILE* in) {
    node* result = nullptr;

    while (!feof(in)) {
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
        char* value = new char[strlen(str) - valueBegin + 1];
        strcpy(value, str+valueBegin);
        //Value founded
        char* keys[numOfKeys];

        if (numOfKeys > 1) {
            int startPos = 0, endPos = 0;

            for (int j = 0; j < numOfKeys; ++j) {

                while((*(str + endPos) != ',') && (*(str+endPos) < keyEnds)) {
                    ++endPos;
                }

                keys[j] = new char[endPos - startPos - 1];
                strncpy(keys[j], str+startPos, endPos - startPos);
                //Key j founded
                result = insert(result, keys[j], value);
                endPos+=2;
                startPos = endPos;
            }

        } else {
            keys[0] = new char[keyEnds+1];
            strncpy(keys[0], str, keyEnds);
            //Key founded
            result = insert(result, keys[0], value);
        }

        delete[] str;
    }

    setParent(result);
    return result;
}
