#include "stdafx.h"
#include<iostream>
using namespace System;
using namespace std;
#include <stdio.h>

union { //определение локального объедин€ющего типа
int ss;
struct {
unsigned a0:1; //каждый бит получает название
unsigned a1:1;
unsigned a2:1;
unsigned a3:1;
unsigned a4:1;
unsigned a5:1;
unsigned a6:1;
unsigned a7:1;
unsigned a8:1;
unsigned a9:1;
unsigned a10:1;
unsigned a11:1;
unsigned a12:1;
unsigned a13:1;
unsigned a14:1;
unsigned a15:1;
} byte; // назв перем
} cod;
//определение локальный переменной-объединени€
struct r // название структуры // тип данных
{float x;
float y;};
int main(){
r r1[10];
r1[0].x=10;
cout<<sizeof(int)<<endl;
cod.ss=20; //занесение в объединение значени€ аргумента функции
cout << "nomera bitov: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0\n";
cout <<"znachenie: ";
cout << " " << cod.byte.a15 << " " << cod.byte.a14 ;
cout << " " << cod.byte.a13 << " " << cod.byte.a12 ;
cout << " " << cod.byte.a11 << " " << cod.byte.a10 ;
cout << " " << cod.byte.a9 << " " << cod.byte.a8 ;
cout << " " << cod.byte.a7 << " " << cod.byte.a6 ;
cout << " " << cod.byte.a5 << " " << cod.byte.a4 ;
cout << " " << cod.byte.a3 << " " << cod.byte.a2 ;
cout << " " << cod.byte.a1 << " " << cod.byte.a0 ;
cout <<endl;
cod.ss=-20; //занесение в объединение значени€ аргумента функции
cout << "nomera bitov: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0\n";
cout <<"znachenie: ";
cout << " " << cod.byte.a15 << " " << cod.byte.a14 ;
cout << " " << cod.byte.a13 << " " << cod.byte.a12 ;
cout << " " << cod.byte.a11 << " " << cod.byte.a10 ;
cout << " " << cod.byte.a9 << " " << cod.byte.a8 ;
cout << " " << cod.byte.a7 << " " << cod.byte.a6 ;
cout << " " << cod.byte.a5 << " " << cod.byte.a4 ;
cout << " " << cod.byte.a3 << " " << cod.byte.a2 ;
cout << " " << cod.byte.a1 << " " << cod.byte.a0 ;
cout <<endl;
}
