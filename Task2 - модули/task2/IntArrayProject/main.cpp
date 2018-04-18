#include "IntArr.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <cstring>

using namespace std;

int main()
{
    setlocale(0,"");
    int size;
    cout<<"Введите длину массива: ";
    cin>>size;
    cout<<endl;
    IntArray array=CreateArray(size);
    for (int i=0;i<size;++i) {
        setItem(array,i,rand()%10+1);
    }
    cout<<"Ваш массив: ";
    write(array);
    sort(array);
    cout<<"Сортировка: ";
    write(array);

    cout<<"Получение значения по индексу:\n";
    cout<<"Введите индекс: ";
    int index=1;
    int result=0;
    cin>>index;
    getItem(array,index,result);
    cout<<"Значение: "<<result<<endl;
    cout<<"Поменять значение какого-нибудь элемента?\nда-1 нет-0\n";
    int n1;
    cin>>n1;
    if(n1==1){
    cout << "Введите индекс" <<endl;
            int index;
            cin>>index;
            cout<<"Введите новое значение"<<endl;
            int value;
            cin>>value;
            put(array, index, value);
            cout<<"Ваш массив: ";
            write(array);
    }
    remove(array);
    int n;
    cout<<"Создать новый массив?\nда-1 нет-0\n";
    cin>>n;
    if(n==1){
    array=newArray(array);
    }
 return 0;
}
