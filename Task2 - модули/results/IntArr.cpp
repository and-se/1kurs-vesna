//IntArr.cpp
#include <iostream>
#include "IntArr.h"
#include <cstdlib>
using namespace std;
 int creature(IntArray b)
{
     int l=a.length;
    for (int i = 0; i <l; ++i)
    {
         srand(time(0));
    
         a[i].data=rand() % (9)+ 1;
    }
    return 0;
}
void print(IntArray b)
{
   int l=a.length;
    for (int i = 0; i <l; ++i)
    {
         srand(time(0));
    
         cout<<a[i].data<<endl;  

    }
}
