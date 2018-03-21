#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void* inner_func(int);
void outer_func();

//void outer_static();
//void inner_static();

int main()
{
    outer_func();
    //outer_static();
}

void* inner_func(int a) {
    cout << "inner_func: a = " << a << endl;//вывели полученное данные
    a += 1;//показываем, что переменная передалась и мы поменяли её значения
//    if (a < 7) inner_func(a); //показываем, что переменные создаются в памяти каждый раз при вызове (даже если рекурсия, т. е. вызываем сами себя)
    cout << "inner_func: int the end a = " << a << endl;//выводим конечный результат
    cout << "*" << &a << " = " << a << endl;//выводим данные, которые находятся по указателю
    return &a;
}

void outer_func() {
    int a;//ввели переменную а
    int *inner_a;
    a = 5;
    cout << "outer_func: a = " << a << endl; //вывели первоначальное значение переменной
    inner_a = (int *) inner_func(a);//отдали переменную во внутреннюю функцию
    cout << "outer_func: in the end a = " << a << endl;//вывели то, что нам вернула функция inner
    cout << "*" << inner_a << " = " << *inner_a << endl;//вывели то, что находится по указателю переменной inner
}


//static int static_a;

//void outer_static()
//{
  //  static_a = 10;
    //cout << "*" << &static_a << " = " << static_a << endl;
    //inner_static();
    //cout << "*" << &static_a << " = " << static_a << endl;
//}

//void inner_static()
//{
  //  static_a += 1;
    //cout << "*" << &static_a << " = " << static_a << endl;
//}

