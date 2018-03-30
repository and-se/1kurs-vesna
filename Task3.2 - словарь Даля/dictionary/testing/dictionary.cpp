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

    if ((index > map.length - 1) || (index < 0)) {
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

unsigned int searchByQuery (Map map, char* query) {

    unsigned int first = 0, last = map.length, mid;

    if (map.length == 0) {
        return -1;
    } else if (strncmp(getItemI(map, 0).key, query, strlen(query)) > 0) {
        return -1;
    } else if (strncmp(getItemI(map, map.length -1).key, query, strlen(query)) < 0) {
        return -1;
    }

    while (first < last) {
        mid = first + (last - first)/2;

        if (strncmp(getItemI(map, mid).key, query, strlen(query)) >= 0) {
            last = mid;
        } else {
            first = mid + 1;
        }
    }

    return last;
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

Iterator getIterator (Map map, char* query) {
    Iterator result;
    result.query = query;
    result.map = map;
    result.position = searchByQuery(map, query);

    return result;
}

Item next (Iterator& iter) {
    Item item = getItemI(iter.map, iter.position);
    printf("Item get\n");
    /*char shortKey[strlen((*iter).query) + 1];
    printf("Memory allocated\n");
    strncpy(shortKey, item.key, strlen((*iter).query));
    printf("Short Key created\n");*/

    printf("Item key: %s\n", item.key);
    printf("Query: %s\n", iter.query);

    if (strncmp(item.key, iter.query, strlen(iter.query)) == 0) {
        printf("Keys compared\n");
        iter.position++;
        return item;
    }

    Item result;
    result.key = NULL;
    result.value = NULL;

    return result;
}

Map loadDict (FILE *input) {
    Map result;
    create(result, 10);

    while (!feof(input)) {
        char* str = readLongString(input);
        int valueBegin = 0;
        int numOfKeys = 1;

        while (((*(str+valueBegin) <'а') || (*(str+valueBegin) > 'я')) && (*(str + valueBegin) != '\n')) {

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

    //sortByKey(result);

    printf("Dict is read\n");
    return result;
}

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
    //*(string + strlen(string) - 1) = '\0';

    return string;
}
