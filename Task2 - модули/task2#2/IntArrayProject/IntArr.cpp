#include <iostream>
#include "IntArr.h"
#include <cstdlib>
using namespace std;


///заполн€ю массив
 int createArr(IntArray array){

     for (int i = 0; i <array.size; ++i)
    {
         *(array.data+i)=rand() % (9)+ 1;
    }
    return 0;
}

///вывожу на экран
void write(IntArray array){

    for (int i = 0; i <array.size; ++i)
    {
         cout<<*(array.data+i)<<" ";

    }
}


///сортирую массив
int sort(IntArray array){

  for (int i=array.size-1; i>=0; i--)
  {
    for (int j=0; j<i; j++)
    {
      if (*(array.data+j)>*(array.data+j+1))
      {
        int tmp = *(array.data+j);
        *(array.data+j) = *(array.data+j+1);
        *(array.data+j+1) = tmp;
      }
    }
  }
}


///получение элемента
int getItem(IntArray array){
    int index;
    cout<<"¬ведите индекс элемента"<<endl;
    cin>>index;
    if(index<=array.size && index>=0)
    {
        cout<<"элемент: "<<*(array.data+index)<<endl;
    }
    else
    {
        cout<<"Ёлемента с таким индексом нет"<<endl;

    }


}


///изменение элемента
int editItem(IntArray array){
     int index;
    cout<<"¬ведите индекс элемента: ";
    cin>>index;

    if(index<=array.size && index>=0)
    {
        int value;
       cout<<"¬ведите значение"<<endl;
       cin>>value;

        *(array.data+index)=value;
    }
    else
    {
        cout<<"элемента с таким индексом нет"<<endl;

    }

}
///удал€ем массив
void remove (IntArray array){
    array.size = 0;
    free(array.data);
}

IntArray newArray (IntArray array) {
    cout<<"¬ведите длину массива: ";
    cin>>array.size;
    cout<<endl;
    array.data=new int[array.size];
    cout<<"¬аш массив: ";
    createArr(array);
    write(array);
    cout<<endl;
    }

