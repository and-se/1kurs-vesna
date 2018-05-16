#include <cstdio>
#include <cstring>
#include <cstdlib>

char* ReadLongString(FILE* input) {
    const int readBuffer = 100;
    int stringSize = readBuffer;
    char* string = (char*)(calloc(stringSize, sizeof(char)));
    int position = 0;

    while (true) {
        fgets(string + position, stringSize - position, input);
        char end = *(string + strlen(string) - 1);

        if ((end!= '\n') && (!feof(input))) {
            position = stringSize - 1;
            stringSize += readBuffer;
            char* newString = (char*)(calloc(stringSize, sizeof(char)));
            strcpy(newString, string);
            free(string);
            string = newString;
        } else {
            break;
        }

    }

    return string;
}

int main()
{
    
    printf("Input long string\n");

    // Читаем строчку с консоли
    char* s = ReadLongString(stdin);

    // Выводим. Длина будет всегда на единицу больше визуальной, т.к. в строке будет перевод строки \n
    printf("Readed: %s\nLength=%d\n", s, strlen(s));

    // Сохраняем в файл - можно даже кириллицу набирать
    // но смотреть такой файло надо будет в Notepad++ --> Кодировки --> Кириллица --> OEM866
    printf("Saving it to file file.txt (encoding OEM866)\n");
    FILE* out = fopen("file.txt", "w");
    // в функцию передаётся void* указатель, поэтому вторым параметром (1) мы говорим, сколько байт занимает один элемент массива
    fwrite(s, 1, strlen(s), out);
    // Не забываем закрыть файл!
    fclose(out);

    // Удаляем строку из кучи
    free(s);

    printf("Load it from file.txt\n");

    // Читаем файл
    FILE* in = fopen("file.txt", "r");
    char* s2 = ReadLongString(in);
    fclose(in);

    printf("Read from file: %s", s2);

    // Не забываем освободить память
    free(s2);

    return 0;
}
