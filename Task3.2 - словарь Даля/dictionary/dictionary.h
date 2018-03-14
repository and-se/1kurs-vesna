#ifndef dictionary
#define dictionary

struct Item {
    char* key;
    char* value;
};

/** Переменная size обозначает объём занимаемой памяти
Переменная length обозначает количество заполненных ячеек*/
struct Map {
    Item* data;
    unsigned int size; //ТОЛЬКО ДЛЯ ВНУТРЕННЕГО ИСПОЛЬЗОВАНИЯ!!!!
    unsigned int length;
};

struct Iterator {
    Map* map;
    unsigned int position;
};

/** Инициальзирует структуру типа map c map.size = size и map.length = 0*/
void create (Map& map, unsigned int size);

/** Удаляет структуру map, очищая зарезервированную память и устанавливая map.lenght = 0*/
void remove (Map& map);

/** Добавляет копию элемента item в конец map, выделяя для него память*/
void addItem (Map& map, Item item);

/** Удаляет элемент из map, расположенный по индексу index
Для этого очищает занимаемую им память и сдвигает все элементы влево
Возвращает -1 если index за пределами map и 0 при успешном завершении*/
int removeItemI (Map& map, unsigned int index);

/** Возвращает элемент из map, расположенный по индексу index
Или элемент со значениями NULL если index за пределами map
ВНИМАНИЕ! Не испоьзуите эту функцию для приствоения значений так getItemI(...).key = ...;
Для присвоения значений используйте setItemI или setItemK*/
Item getItemI (Map map, unsigned int index);

/** Устанавливает значение элемента из map и индексом index в item
При этом внутри map оказывается копия item (с выделением памяти)
Возвращает -1 если index >= map.length и 0 если успешно завершится*/
int setItemI (Map& map, Item item, unsigned int index);

/** Ищет первый элемент в map со значением ключа key и индесом >= startPosition
Возвращает -1 если элемент не найден или если startPosition >= map.length и индес элемента при успешном завершении*/
unsigned int searchItem (Map map, char* key, unsigned int startPosition);

/** Возвращает первый элемент из map со значением ключа key и индексом >= startPosition
ВНИМАНИЕ! Не испоьзуите эту функцию для приствоения значений так getItemK(...).key = ...;
Для присвоения значений используйте setItemI или setItemK
Либо элемент со значениями NULL если startPosition за пределами map или если элемент не найден*/
Item getItemK (Map map, char* key, unsigned int startPosition);

/** Устанавливает первый элемент из map со значением ключа key и индексом >= startPosition в значение item
При этом в map создаётся копия item (с выделением памяти)
Возвращает -1 если startPosition >= map.length и 0 при успешном завершении*/
int setItemK (Map& map, char* key, Item item, unsigned int startPosition);

/** Удаляет первый элемент из map с ключом key и индексом >= startPosition
Для этого очищает занимаемую им память и смещает последующие элементы влево
Возвращает -1 если startPosition >= map.length и 0 при успешном завершении*/
int removeItemK (Map& map, char* key, unsigned int startPosition);

/**Возвращает Map из элеменов чьи ключи начинаются с query
Использует алгоритм бинарного поиска, поэтому предварительно сорирует массив.
Если массив уже отсортирован можно передать значение isSorted = true*/
Map searchByQuery (Map map, char* query, bool isSorted);

/**Сортирует map по возрастанию ключа методом пузырька*/
void sortByKey (Map& map);

/**Возвращает Iterator по map*/
Iterator getIterator (Map map);

/** Возвращает следующий элемент из Map на который ссылается iter*/
Item next (Iterator iter);

#endif
