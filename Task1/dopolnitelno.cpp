#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

typedef union { //создание обьединени€ с двум€ переменными: знаковое целочисленное, беззнаковое целочисленное
    int znakovoe;
    unsigned int bezznakovoe;
    struct { //создание структуры с беззнаковыми одноэлементными переменными
        unsigned char a;
        unsigned char b;
        unsigned char c;
        unsigned char d;
    } bytes;//название структуры
} union1;//объект обьединени€


int main()
{
    union1 test; //создание переменной
    test.bezznakovoe = 4*1000*1000*1000;
    cout << "test.bezznakovoe = " << test.bezznakovoe << endl;
    cout << "test.znakovoe = " << test.znakovoe << endl;
    cout << "test.bezznakovoe = " << test.bezznakovoe << endl;

    cout.unsetf(ios::dec);//вывод величин в 10ричной системе счислени€
    cout.setf(ios::hex);//вывод величин в 16ричной системе счислени€
    cout << (unsigned int) test.bytes.d << " " << (unsigned int) test.bytes.c << " " << (unsigned int) test.bytes.b << " " << (unsigned int) test.bytes.a << endl;
 //вывод кодировани€ переменной int
}
/* мы создали объединение с беззнаковым целочисленным
и знаковым целочисленным, чтобы проверить как одно число интерпретруетс€ со знаком и без, и показали его код к шестнадцатиричной системе счислени€*/
