#ifndef INTARR_H_INCLUDED
#define INTARR_H_INCLUDED

struct IntArray
{
    int* data;
    int* size;
};

IntArray CreateArray(int size); // Создаёт массив длинны size и возвращает его

void DeleteArray(IntArray array); // Удаляет переданный массив (освобождает память)

/*В переменную result возвращается значение элемента с index массива array
И возвращает false при выходе за границу массива*/

bool Return (IntArray array, int index, int& result);

/*Элементу с index присваивается значение value
Возвращает false при выходе за границу массива*/

bool Assignment (IntArray array, int index, int value);

#endif // INTARR_H_INCLUDED
