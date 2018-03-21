#include "stdafx.h"
#include <iostream>

using namespace std;
using namespace System;

void my_func(int a)
{
    a=10;
    cout << "a vnutri funcii= " << a << endl;
}

int main()
{
    int a1=0;
    my_func(a1);//вызов функции
    cout << "a posle vyzova funcii= " << a1 << endl;

}
