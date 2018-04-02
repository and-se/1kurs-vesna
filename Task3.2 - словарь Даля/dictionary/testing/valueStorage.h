#ifndef VALUESTORAGE_H_INCLUDED
#define VALUESTORAGE_H_INCLUDED

struct Storage {
    char** store;
    unsigned int length;
    unsigned int size;
    Storage (unsigned int s) { store = new char*[s]; size = s; length = 0; }
};

void grow (Storage* str);
void add (Storage* str, char* key);

#endif // VALUESTORAGE_H_INCLUDED
