#include <iostream>
#include "IntArr.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(0,"");
    IntArray array;
    cout<<"Введите длину массива: ";
    cin>>array.size;
    cout<<endl;
    array.data=new int[array.size];
    cout<<"Ваш массив: ";
    createArr(array);
    write(array);
    cout<<endl;
    cout<<"Сортировка: ";
    sort(array);
    write(array);
    cout<<endl;
    cout<<"Получение значения по индексу\n";
    getItem(array);
    cout<<"Изменение значения по индексу\n";
    editItem(array);
    write(array);
    cout<<endl;
    remove(array);
    int n;
    cout<<"Создать новый массив?\nда-1 нет-0\n";
    cin>>n;
    if(n==1){
    array=newArray(array);
    }
    return 0;
}
