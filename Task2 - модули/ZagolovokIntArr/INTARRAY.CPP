// Подключаем заголовочный файл с объявлениями
#include "IntArrHeader.h"
// Стандартный модуль ввода-вывода нужен нам для демонстрации реализации, потом следует его отсюда удалить
#include <iostream>
// Модуль для работы с функцией free;
#include <cstdlib>
using namespace std;

IntArray CreateArray(int size)
{
    cout << "Create array with length = " << size << endl;

    // Вернём какой-нибудь ненастоящий результат
    IntArray array;

    array.data = 0;
    *array.size = size;

    return array;
}


void DeleteArray(IntArray array)
{
    cout << "Delete your array" << endl;
    free(array.data); //удаление памяти созданной для переменных из структуры
    free(array.size);
}


bool Get (IntArray array, int index, int& result)
{
    if ((*array.size <= index) || (index < 0))
    {
        return false;       /* если количество индексов будет больше чем длина массива и количество индекса будет меньше нуля,
                             то возвращать false*/ }
    result = *(array.data + index); /* результат равен количеству элементов и их индексов, возвращает true,
                                      т.е. массив не вышел за границцы  */
    return true;
}


bool Set (IntArray array, int index, int value)
{
    if ((*array.size <= index) || (index < 0))
    {
        return false;  }

    value = *(array.data + index);
    return true;
}
