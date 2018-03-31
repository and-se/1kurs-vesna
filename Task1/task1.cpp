#include<iostream>
using namespace std;
void setValue (int v, int value);
int* getPointer (int value);
void ShowBin (int a);

int main (int argc, char *argv[]) {
    std::cout << "Task 1" <<endl;
    int k = 9;
    int* pk = &k;
    cout << "Adress of variable: " <<endl;
    cout << pk <<endl; // Вывод адреса переменной
    setValue(k,10); // Передача переменной в качестве аргумента
    /*Адрес переменной внутри main и внутри setValue различаются, значит это две разные переменные*/

    cout << "Task2" << endl;
   cout << "Value in adress after first fuction call:" <<endl;
    int* p_getPointer = getPointer(0);
    cout << *p_getPointer << std::endl; // Вывод значения по сохранённому адресу
    cout << "Value in the same adress after second function call:" << endl;
    getPointer(10); // Вызов функции с другим аргументом
   cout << *p_getPointer <<endl << endl; // Повторный вывод значения по тому же аресу
    /*После первого вызова функции getPointer запоминаем адрес внутренней переменной,
    и проверяем значение по нему после первого и второго вызовов функции
    Значение по указателю меняется, без его явного изменения в программе,
    значит операционная система считает эту память свободной и переписывает значение в ней*/
    /*Вывод: переменная создаваемая внутри функции и существует только в ней.
    После выхода из функции зарезервированная функцией,
    а, как следствие, и всеми внутренними статическими переменными, память считается свободной*/

   cout << "Additional task 2" << endl;
    cout << "Size of Int type " << sizeof(int) << " byte" << endl;
    int positiveNum = 1023;
    int negativeNum = -1023;
    unsigned char* negNum_toChar_pointer = (unsigned char*)(&negativeNum);
    unsigned char* posNum_toChar_pointer = (unsigned char*)(&positiveNum);

    for (int i = 0; i < 4; ++i) {
        switch (i+1) {
            case 1: {
                cout << "First";
                break;
            }
            case 2: {
                cout << "Second";
                break;
            }
            case 3: {
                cout << "Third";
                break;
            }
            case 4: {
                cout << "Fourth";
                break;
            }
        }
        cout << " 8 bit of num -1023 in memory: " << (int)(*negNum_toChar_pointer) <<endl;
        negNum_toChar_pointer++;
    }

    for (int i = 0; i < 4; ++i) {
        switch (i+1) {
            case 1: {
                cout << "First";
                break;
            }
            case 2: {
               cout << "Second";
                break;
            }
            case 3: {
               cout << "Third";
                break;
            }
            case 4: {
                cout << "Fourth";
                break;
            }
        }
        cout << " 8 bit of num 1023 in memory: " << (int)(*posNum_toChar_pointer) << endl;
        posNum_toChar_pointer++;
    }

    /*Вывод числа показал, две вещи
    Во-первых, что числа кодируются в т.н. дополненном коде,
    то есть положительные числа просто переводятся в двоиную счситему считсления,
    а отрицательные инвертируются и к ним прибавляется 1.
    Такой способ позволяет держать знак в первом бите, а так же,
    в отличии от обратного кода, числа +0 и -0 кодируются одинаково.
    Во-вторых, из вывода на моей машине очевидно,
    что числа на моём компьютере хранятся в т.н. обратном порядке
    То есть наименьший бит числа находится в ячейке с меньшим адресом*/

    return 0;
}


void setValue (int v, int value) {
    int* pv = &v;
   cout << "Adress of argument in memory:" << endl;
   cout << pv << endl << endl; // Вывод адреса аргумента
    v = value;
}

int* getPointer (int value) {
    int a = value;
    int* pa = &a;

    return pa; // Возвращение адреса локальной переменой в качестве результата
}
