struct IntArray{
    int *data;
    int size;
};

int createArr(IntArray array);///заполн€ю массив
void write(IntArray array);///вывожу на экран
int sort(IntArray array);///сортироывка массива
int getItem(IntArray array);///получение элемента
int editItem(IntArray array);///изменение элемента
void remove (IntArray array);
IntArray newArray (IntArray array);
