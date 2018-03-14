// 24.01.18 Разбор особенностей языка. Домашнее задание
#include<iostream>

void setValue (int v, int value);
int* getPointer (int value);
void ShowBin (int a);

int main (int argc, char *argv[]) {
    std::cout << "Task 1" << std::endl;
    int k = 9;
    int* pk = &k;
    std::cout << "Adress of variable: " << std::endl;
    std::cout << pk << std::endl; // Вывод адреса переменной
    setValue(k,10); // Передача переменной в качестве аргумента

    std::cout << "Task2" << std::endl;
    std::cout << "Value of adress in memory after first fuction call:" << std::endl;
    int* p_getPointer = getPointer(0);
    std::cout << *p_getPointer << std::endl; // Вывод значения по сохранённому адресу
    std::cout << "Value of the same adress after second function call:" << std::endl;
    getPointer(10); // Вызов функции с другим аргументом
    std::cout << *p_getPointer << std::endl << std::endl; // Повторный вывод значения по тому же аресу

    std::cout << "Additional task 2" << std::endl;
    std::cout << "Size of Int type " << sizeof(int) << " byte" << std::endl;
    int positiveNum = 1023;
    int negativeNum = -1023;
    std::cout << "Num 1023 in memory:" << std::endl;
    ShowBin(positiveNum);
    std::cout << "Num -1023 in memory:" << std::endl;
    ShowBin(negativeNum);
    unsigned char* positiveNum_toChar_pointer = (unsigned char*)(&positiveNum);
    std::cout << "First 8 bit of num 1023 in memory: " << (int)(*positiveNum_toChar_pointer) << std::endl;
    // Отрицательные числа в дополненном коде, это значит, что знак кодируется первым битом

    return 0;
}


void setValue (int v, int value) {
    int* pv = &v;
    std::cout << "Adress of argument in memory:" << std::endl;
    std::cout << pv << std::endl << std::endl; // Вывод адреса аргумента
    v = value;
}

int* getPointer (int value) {
    int a = value;
    int* pa = &a;

    return pa; // Возвращение адреса локальной переменой в качестве результата
}

void ShowBin (int a) {

    for (int i = 0; i < 32; i++) {

        //Проверяем старший бит
        if (a & 2147483648) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }

        //Сдвигаем влево на 1 бит
        a = a << 1;
    }

    std::cout << std::endl;
}
