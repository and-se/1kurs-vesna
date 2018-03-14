#ifndef IntArray_h
#define IntArray_h

struct IntArray {
    int* data;
    int* size;
};

/*Создаёт массив размера size и возвращает его в качестве результата*/
IntArray create (int size);

/*В переменную result возвращается значение элемента с индексом index массива array
Возвращает false при выходе за границу массива*/
bool getItem (IntArray array, int index, int& result);

/*Элементу с индексом index массива array присваивается значение value
Возвращает false при выходе за границу массива*/
bool setItem (IntArray array, int index, int value);

/*Удаляет массив array*/
void remove (IntArray array);

#endif
