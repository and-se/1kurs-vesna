#include "IntArr1.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <cstring>

using namespace std;

IntArray CreateArray(int size){
    IntArray array;
    array.data=(int*)(malloc(sizeof(int)*size));
    array.size=size;
    return array;
}

bool setItem(IntArray array, int index, int value) {
    if ((index >= array.size) || (index < 0)) {
        return false;
    }
    *(array.data + index) = value;
    return true;
}

bool getItem (IntArray array, int index, int& result) {
    if ((index >= array.size) || (index < 0)) {
        return false;
    }
    result = *(array.data + index);
    return true;
}

void write (IntArray array) {
    int result;
    for (int i = 0; i < array.size; ++i)
    {
        if (getItem(array, i, result)) {
            cout << result << " ";
        } else {
            cout << "Вы вышли за границу массива";
            break;
        }
    }
    cout<<endl;
}

void sort (IntArray array) {
    int result1, result2;
        for (int i = 0; i < array.size; ++i)
        {

            for (int j = 0; j < array.size - 1 - i; ++j)
            {

                if ((getItem(array,j,result1)) && (getItem(array, j+1, result2))) {

                    if (result1 > result2) {
                        setItem(array, j, result2);
                        setItem(array, j+1, result1);
                    }

                } else {
                    std::cout << "Error: out of bounds";
                }

            }

        }
        }

void remove (IntArray array){
    array.size = 0;
    free(array.data);
}

IntArray newArray (IntArray array) {
    remove(array);
    int size;
    cout << "Введите длину массива"<<endl;
    cin >> size;
    IntArray result = CreateArray(size);
    for (int i = 0; i < size; ++i) {
        setItem(result, i, rand() % 201 - 100);
    }

    return result;
    }

void put (IntArray array, int index, int value) {
    if(!setItem(array, index, value)) {
        std::cout << "ОШИБКА" << std::endl;
    }
}
