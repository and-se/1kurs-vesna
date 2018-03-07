#include <cstdio>
#include <cstring>

// В этом модуле поместим функцию ReadLongString из первой части задания
#include "StringUtils.h"

int main()
{
    // Читаем файл
    FILE* in = fopen("SampleOEM866.txt", "r");

    char* s2;

    while(true)
    {
        char* s2 = ReadLongString(in);

        printf("Read line: %s", s2);

        // Есть проблемы с чтением последней строки
        // Нужна пустая строка с пробелом в конце...
        if(strlen(s2) <= 1)
        {
            break;
        }

        // Не забываем освободить память
        delete[] s2;
    }

    fclose(in);

    return 0;
}
