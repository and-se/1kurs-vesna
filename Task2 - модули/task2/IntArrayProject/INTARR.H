#ifndef INTARR_H_INCLUDED
#define INTARR_H_INCLUDED

struct IntArray{
    int *data;
    int size;
};

///Создает массив
IntArray CreateArray(int size);

///Элементу с индексом index массива array присваивается значение value
///Возвращает false при выходе за границу массива
bool setItem(IntArray array, int index, int value);

///В переменную result возвращается значение элемента с индексом index массива array
///Возвращает false при выходе за границу массива
bool getItem (IntArray array, int index, int& result);


///Выводит массив на экран
void write (IntArray array);

///Сортировка
void sort (IntArray array);

///Удаление массива
void remove (IntArray array);

///Cоздание нового массива
IntArray newArray (IntArray array);

///Изменяет значение по индексу
void put (IntArray array, int index, int value);

#endif // INTARR_H_INCLUDED
