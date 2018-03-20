#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "dictionary.h"

void grow (Map& map);

void create (Map& map, unsigned int size) {
    map.size = size;
    map.length = 0;
    map.data = (Item*)(malloc(sizeof(Item) * size));
}

void remove (Map& map) {

    for (unsigned int i = 0; i < map.length; ++i) {
        free( (*(map.data + i)).key );
        free( (*(map.data + i)). value );
    }

    free(map.data);
    map.length = 0;
}

void grow (Map& map) {
    Map temp;
    create(temp, map.size);

    for (unsigned int i = 0; i < map.length; ++i) {
        Item item;

        item.key = (char*)(malloc(sizeof(char) * strlen(getItemI(map, i).key) + 1));
        item.value = (char*)(malloc(sizeof(char) * strlen(getItemI(map, i).value) + 1));

        strcpy(item.key, getItemI(map, i).key);
        strcpy(item.value, getItemI(map, i).value);

        addItem(temp, item);

        free(item.key);
        free(item.value);
    }

    remove(map);
    create(map, temp.size * 2);

    for (unsigned int i = 0; i < temp.length; ++i) {
        Item item = getItemI(temp, i);

        item.key = (char*)(malloc(sizeof(char) * strlen(getItemI(temp, i).key) + 1));
        item.value = (char*)(malloc(sizeof(char) * strlen(getItemI(temp, i).value) + 1));

        strcpy(item.key, getItemI(temp, i).key);
        strcpy(item.value, getItemI(temp, i).value);

        addItem(map, item);

        free(item.key);
        free(item.value);
    }

}

void addItem (Map& map, Item item) {

    if (map.size == map.length) {
        grow(map);
    }

    (*(map.data + map.length)).key = (char*)(malloc(sizeof(char) * strlen(item.key)+1));
    (*(map.data + map.length)).value = (char*)(malloc(sizeof(char) * strlen(item.value)+1));

    strcpy((*(map.data + map.length)).key, item.key);
    strcpy((*(map.data + map.length)).value, item.value);

    map.length++;
}

int removeItemI (Map& map, unsigned int index) {

    if (index > map.length - 1) {
        return -1;
    }

    for(unsigned int i = index; i < map.length - 1; ++i) {
        Item item = getItemI(map, i + 1);

        free( (*(map.data + i)).key );
        free( (*(map.data + i)).value );

        setItemI(map, item, i);
    }

    free( (*(map.data + map.length-1)).key );
    free( (*(map.data + map.length-1)).value );

    map.length--;

    return 0;
}

Item getItemI (Map map, unsigned int index) {
    Item result;

    if (index > map.length - 1) {
        result.key = NULL;
        result.value = NULL;

        return result;
    }

    /* Если необходимо возвращать копию, использовать этот код. Существующий закомментировать
    result.key = (char*)(malloc(sizeof(char) * strlen( (*(map.data + index)).key )+1));
    result.value = (char*)(malloc(sizeof(char) * strlen( (*(map.data + index)).value )+1));

    strcpy(result.key, (*(map.data + index)).key);
    strcpy(result.value, (*(map.data + index)).value);
    */

    result.key = (*(map.data + index)).key;
    result.value = (*(map.data + index)).value;

    return result;
}

int setItemI (Map& map, Item item, unsigned int index) {

    if (index > map.length - 1) {
        return -1;
    }

    free( (*(map.data + index)).key );
    free( (*(map.data + index)).value );

    (*(map.data + index)).key = (char*)(malloc(sizeof(char) * strlen(item.key)+1));
    (*(map.data + index)).value = (char*)(malloc(sizeof(char) * strlen(item.value)+1));

    strcpy((*(map.data + index)).key, item.key);
    strcpy((*(map.data + index)).value, item.value);

    return 0;
}

unsigned int searchItem (Map map, char* key, unsigned int startPosition) {
    unsigned int result = -1;

    if(startPosition > map.length - 1) {
        return result;
    }

    for (unsigned int i = startPosition; i < map.length; ++i) {
        Item item = getItemI(map, i);

        if(strcmp(key, item.key) == 0) {
            result = i;
            break;
        }

    }

    return result;
}

Item getItemK (Map map, char* key, unsigned int startPosition) {
    Item result;

    if(startPosition > map.length - 1) {
        result.key = NULL;
        result.value = NULL;

        return result;
    }

    result = getItemI(map, searchItem(map, key, startPosition));

    return result;
}

int setItemK (Map& map, char* key, Item item, unsigned int startPosition) {

    if(startPosition > map.length - 1) {
        return -1;
    }

    setItemI(map, item, searchItem(map, key, startPosition));

    return 0;
}

int removeItemK (Map& map, char* key, unsigned int startPosition) {

    if (startPosition > map.length - 1) {
        return -1;
    }

    removeItemI(map, searchItem(map, key, startPosition));

    return 0;
}

Map searchByQuery (Map map, char* query, bool isSorted) {
    Map result;
    create(result, 1);

    if (!isSorted) {
        sortByKey(map);
    }

    char shortKey[strlen(query)+1];
    unsigned int first = 0, last= map.length, mid;

    if (map.length == 0) {
        return result;
    } else {
        strncpy(shortKey, getItemI(map, 0).key, strlen(query));

        if (strcmp(shortKey, query) > 0){
            return result;
        } else {
            strncpy(shortKey, getItemI(map, map.length-1).key, strlen(query));

            if (strcmp(shortKey, query) < 0) {
                return result;
            }

        }

    }

    while (first < last) {
        mid = first + (last - first)/2;
        strncpy(shortKey, getItemI(map, mid).key, strlen(query));

        if (strcmp(shortKey, query) >= 0) {
            last = mid;
        } else {
            first = mid + 1;
        }
    }

    strncpy(shortKey, getItemI(map, last).key, strlen(query));
    unsigned int i = last;

    while (strcmp(shortKey, query) == 0) {
        Item item;
        item.key = (char*)(malloc(strlen(getItemI(map, i).key) + 1));
        item.value = (char*)(malloc(strlen(getItemI(map, i).value) + 1));
        addItem(result, item);
        ++i;
        free(item.key);
        free(item.value);
        strncpy(shortKey, getItemI(map, i).key, strlen(query));
    }

    return result;
}

void sortByKey (Map& map) {

    for (unsigned int i = 0; i < map.length; ++i) {

        for (unsigned int j = 0; j < map.length-1-i; ++j) {

            if (strcmp(getItemI(map, j).key, getItemI(map, j+1).key) > 0) {
                Item temp = getItemI(map, j);
                setItemI(map, getItemI(map, j+1), j);
                setItemI(map, temp, j+1);
            }

        }

    }

}

Iterator getIterator (Map map) {
    Iterator result;
    result.map = map;
    result.position = 0;

    return result;
}

Item next (Iterator* iter) {
    return getItemI((*iter).map, (*iter).position++);
}
