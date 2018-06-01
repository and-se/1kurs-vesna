#include <iostream>
#include <cmath>

using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");
int *v = new int;                 // динамически выделяем целочисленную переменную.
*v = 5;                           // помещаем в переменную числовое значение.
int *a = v;                       // 'a' теперь указывает на ту же самую выделенную память, что и 'v'.

cout << " Первый блок ";
cout << " " << endl;
cout << " " << *v << endl;
cout << " " << *a << endl;
cout << " " << endl;

delete v;                        // возвращение памяти, выделенную под переменную.
v = 0;
cout << " Второй блок ";
cout << " " << endl;
cout << " " << *a << endl;

return 0;
}

