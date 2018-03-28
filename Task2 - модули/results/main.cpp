//main.cpp
#include <iostream>
#include "IntArr.h"
#include <cstdlib>
using namespace std;//заполнить массив
int main()
{
    IntArray a;
	//int length;
    cout<<"введтите длину массива "<<endl;
    cin>>a.length;
    a.data=new int[a.length];
   

    creature(a);
    print(a);


    return 0;
}