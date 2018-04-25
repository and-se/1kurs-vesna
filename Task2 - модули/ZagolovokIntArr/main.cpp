#include<iostream>
#include<cstdlib>
#include<ctime>
#include <cstring>

// Подключаем модуль работы с массивами
#include "IntArrHeader.h"


using namespace std;

void sort(IntArray array)//сортировка массива
{
    int result1;
    int result2;
    for (int i = 0; i < *array.size; ++i) //цикл выполняется пока не переберёт все элементы массива
        {

            for (int j = 0; j < *array.size - 1 - i; ++j) // начиная с первого элемента
            {

                if ((Return(array,j,result1)) && (Return(array, j+1, result2))) {
                        /*если значение J элемента равно значению result1
                        и значение следующего элемента равно result 2, то*/
                    if (result1 > result2)
                        /*если значение первого больше чем значение второго, то
                        присваиваем элементу J значение result2*/
                        {
                        Assignment(array, j, result2);
                        Assignment(array, j+1, result1);
                        }
                    }
                else { // в другом случае выход за границу
                    cout << "Going abroad";
                }

            }

        }

}
void mistake(IntArray array){
for ( int i=0; i > array.size; ++i){
        cout << "Error: you went beyond the array";
}


int main()
{
    int size;//Вызываем функцию для создания массива размером, которую ввёл пользователь
    cout << "Enter the length of the array = ";
    cin >> size;
    IntArray array = CreateArray(size);//создание массива размера size

    srand(time(NULL));
    char answer[100];

    for ( int i=0; i < size; ++i){//вывод массива на экран
        Assignment(array, i, (rand() % 201 - 100);//элементу с индексом i присваивается значение случайного числа
    }
    cout << "array sorting";
    void sort();
    for ( int i=0; i < size; ++i){//вывод массива на экран
        Assignment(array, i, *array.data);
    void mistake();

    DeleteArray(array);
    return 0;
}
}


