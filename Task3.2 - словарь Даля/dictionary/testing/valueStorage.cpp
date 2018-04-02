#include "valueStorage.h"

void grow (Storage* str) {
    char** newStore = new char*[(str -> size)*2];

    for (unsigned int i = 0; i < str -> length; ++i) {
        *(newStore + i) = *((str->store) + i);
    }

    str -> store = newStore;
    (str -> size) *= 2;
}

void add (Storage* str, char* key) {

    if (str -> length == str -> size) {
        grow(str);
    }

    *((str -> store) + str -> length) = key;
    str->length++;
}
