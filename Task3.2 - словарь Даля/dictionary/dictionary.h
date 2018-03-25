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
    Map map;
    unsigned int position;
    char* query;
};

/** Инициализирует структуру типа map c map.size = size и map.length = 0*/
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

/**Возвращает Map из элеменов чьи ключи начинаются с query
Использует алгоритм бинарного поиска, поэтому предварительно сорирует массив.
Если массив уже отсортирован можно передать значение isSorted = true*/
unsigned int searchByQuery (Map map, char* query, bool isSorted);

/**Сортирует map по возрастанию ключа методом пузырька*/
void sortByKey (Map& map);

/**Возвращает Iterator по map, который будет возвращать статьи удовлетворяющие запросу query*/
Iterator getIterator (Map map, char* query);

/** Возвращает следующий элемент из Map, на который ссылается iter, если он удовлетворяет запросу*/
Item next (Iterator& iter);

/**Загружает словарь из потока input, сортирует его и возвращает в качестве результата*/
Map loadDict (FILE *input);

/**Считывает длинную строку из input*/
char* readLongString(FILE *input);

#endif
