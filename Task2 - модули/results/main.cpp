//main.cpp
#include <iostream>
#include "IntArr.h"
#include <cstdlib>
using namespace std;
int main()
{
	srand(time(0));
    IntArray a;
	//int length;
    cout<<"введтите длину массива "<<endl;
    cin>>a.length;
    a.data=new int[a.length];
   
    cout<<"массив: "<<endl;
    creature(a);///заполняю
    print(a);///вывожу
   cout<<"сортируем: "<<endl;
   sort(a);///сортирую пузырьком
   print(a);
   int y;
   cout<<"хотите записать элемент по индексу-жмиите 0,получить значения элемента по индексу-жмиите 1 "<<endl;
   cin>>y;
   if (y==0)
   {
     insert(a);///запись элемента
   }
   else if (y==1)
   {
   	receiving(a);///получение элемента
   }
   cout<<"массив: "<<endl;
   print(a);



    return 0;
}