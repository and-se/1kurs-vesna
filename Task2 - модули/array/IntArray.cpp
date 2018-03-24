#include "IntArray_h.h"
#include <cstdlib>

IntArray create (int size) {
    IntArray array;
    array.data = (int*)(malloc(sizeof(int)*size));
    array.size = size;

    return array;
}

bool getItem (IntArray array, int index, int& result) {
    if ((index >= array.size) || (index < 0)) {
        return false;
    }

    result = *(array.data + index);
    return true;
}

bool setItem (IntArray array, int index, int value) {
    if ((index >= array.size) || (index < 0)) {
        return false;
    }

    *(array.data + index) = value;
    return true;
}

void remove (IntArray array) {
    array.size = 0;
    free(array.data);
}
