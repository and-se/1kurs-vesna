#include <cstdio>
#include <cstring>
#include <clocale>

char* ReadLongString(FILE* stream)
{
	int size = 3;

    char *buffer = new char[size];           // динамически выделяем символьную переменную
    char *readStart = buffer;                // приравнивается той же выделенной памяти

	int i = 0;

    buffer[size-1] = 123;

    while(true)
    {
        int fgets (char *buffer, int i, FILE *stream);
        char n = *(buffer + strlen(buffer) - 1);

        if ((n != '\n')&& (!feof(stream))) // Функция возвращает ненулевое значение, если операция чтения оказалась за концом файла
        {

            return buffer;
        }

        else
			{
       		 break;
    		}

        buffer[size-1] = 123;
    }

    return buffer;
}



int main()
{
    //setlocale(LC_ALL, "Russian"); // только ломает
    printf("Input long string\n");

    // Читаем строчку с консоли
    char* s = ReadLongString(stdin);

    // Выводим. Длинна будет всегда на единицу больше визуальной, т.к. в строке будет перевод строки \n
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
    delete[] s;

    printf("Load it from file.txt\n");

    // Читаем файл
    FILE* in = fopen("file.txt", "r");
    char* s2 = ReadLongString(in);
    fclose(in);

    printf("Read from file: %s", s2);

    // Не забываем освободить память
    delete[] s2;

    return 0;
}

