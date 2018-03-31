//IntArr.cpp
///jfhwlfvwhvjlhfl
#include <iostream>
#include "IntArr.h"
#include <cstdlib>
using namespace std;
 int creature(IntArray b)///заполняю массив
{
     
    for (int i = 0; i <b.length; ++i)
    {
         
    
         *(b.data+i)=rand() % (9)+ 1;
    }
    return 0;
}
void print(IntArray b)///вывожу на экран
{
    for (int i = 0; i <b.length; ++i)
    {
         //srand(time(0));
    
         cout<<*(b.data+i)<<endl;  

    }
}
///
int sort(IntArray b)///сортирую пузырьком
{
    

  for (int i=b.length-1; i>=0; i--)
  {
    for (int j=0; j<i; j++)
    {
      if (*(b.data+j)>*(b.data+j+1))
      {
        int tmp = *(b.data+j);
        *(b.data+j) = *(b.data+j+1);
        *(b.data+j+1) = tmp;
      }
    }
  }
}
int receiving(IntArray b)///получение элемента
{
    int n;
    cout<<"Введите номер элемента"<<endl;
    cin>>n;
    if(n<=b.length&&n>=0)
    {  
        cout<<"элемент"<<n<<"-"<<*(b.data+n-1)<<endl;
    }
    else
    {  
        cout<<"элемента с таким номером нет"<<endl;

    }


}
int insert(IntArray b)///запись элемента
{
     int n;
    cout<<"Введите номер элемента"<<endl;
    cin>>n;
     
    if(n<=b.length&&n>=0)
    { 
        int e;
       cout<<"Введите элемент"<<endl;
       cin>>e;
     
        *(b.data+n-1)=e;
    }
    else
    {  
        cout<<"элемента с таким номером нет"<<endl;

    }

}



