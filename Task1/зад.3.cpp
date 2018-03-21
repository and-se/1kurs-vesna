#include <iostream>

using namespace std;

void my_func(int a)
{
    a=10;
    int *ptr=&a;
    cout << "a vnutri funcii= " << a << endl;
    cout << "adres " << ptr << endl;
}
int my_func1(int a)
{
    a=10;
    int *ptr=&a;
    cout << "a vnutri funcii= " << a << endl;
    cout << "adres " << ptr << endl;
    return a;
}
double sinn(double x)
{
double y = Math::Sin(x*0.01);
return y;
}
int main()
{
   int a1=0;
   int *ptr1=&a1;
   a1=my_func(a1);
   cout << "a posle vyzova funcii= " << a1 << endl;
   cout << "adres " << ptr1 << endl;
   cout << "vtoroy vyzov funcii" << endl;
   //my_func(a1);
   double r = sinn(10);
   cout<< r << endl;
}
