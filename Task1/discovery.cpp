// 24.01.18 Разбор особенностей языка. Домашнее задание
#include<iostream>

void setValue (int v, int value);
int* getPointer (int value);
void ShowBin (int a);

int main (int argc, char *argv[]) {
    std::cout << "Задание 1" << std::endl;
    int k = 9;
    int* pk = &k;
    std::cout << "Адрес переменной: " << std::endl;
    std::cout << pk << std::endl; // Вывод адреса переменной
    setValue(k,10); // Передача переменной в качестве аргумента

    std::cout << "Задание 2" << std::endl;
    std::cout << "Значение адреса в памяти после первого вызова:" << std::endl;
    int* p_getPointer = getPointer(0);
    std::cout << *p_getPointer << std::endl; // Вывод значения по сохранённому адресу
    std::cout << "Значение того же адреса после поторного вызова:" << std::endl;
    getPointer(10); // Вызов функции с другим аргументом
    std::cout << *p_getPointer << std::endl; // Повторный вывод значения по тому же аресу

    std::cout << "Доп. задание 2" << std::endl;
    std::cout << "Размер типа Int " << sizeof(int) << " байт" << std::endl;
    int positiveNum = 1023;
    int negativeNum = -1023;
    std::cout << "Число 1023 в памяти:" << std::endl;
    ShowBin(positiveNum);
    std::cout << "Число -1023 в памяти:" << std::endl;
    ShowBin(negativeNum);
    // Отрицательные числа в дополненном коде, это значит, что знак кодируется первым битом

    return 0;
}


void setValue (int v, int value) {
    int* pv = &v;
    std::cout << "Адрес аргумента в памяти:" << std::endl;
    std::cout << pv << std::endl; // Вывод адреса аргумента
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
