// Ёти вещи нам пока не нужны
#ifndef INTARR_H_INCLUDED
#define INTARR_H_INCLUDED

/// “ип данных массива
struct IntArray
{
    int* data;
    int* size;
};

/// —оздаЄт массив длинны size и возвращает его
IntArray CreateArray(int size);

/// ”дал€ет переданный массив (освобождает пам€ть)
void DeleteArray(IntArray array);

/*¬ переменную result возвращаетс€ значение элемента с индексом index массива array
¬озвращает false при выходе за границу массива*/
bool Return (IntArray array, int index, int& result);

/*Ёлементу с индексом index array присваиваетс€ значение value
¬озвращает false при выходе за границу массива*/
bool Assignment (IntArray array, int index, int value);


#endif // INTARR_H_INCLUDED

