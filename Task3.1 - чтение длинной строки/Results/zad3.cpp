
#include "stdafx.h"

#include <cstdio>
#include <cstring>
#include <clocale>
#include <iostream>
using namespace std;


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
    FILE* out = fopen("file1.txt", "w");
    // в функцию передаётся void* указатель, поэтому вторым параметром (1) мы говорим, сколько байт занимает один элемент массива
    fwrite(s, 1, strlen(s), out);
    // Не забываем закрыть файл!
    fclose(out);

    // Удаляем строку из кучи
    delete[] s;

    printf("Load it from file.txt\n");

    // Читаем файл
    FILE* in = fopen("file1.txt", "r");
	printf("ok\n");
    char* s2 = ReadLongString(in);
	printf("ok\n");
    fclose(in);

    printf("Read from file: %s", s2);

    // Не забываем освободить память
    delete[] s2;

    return 0;
}



//// вариант 2

char*  ReadLongString(FILE *f)
{
	int size = 5, R = size, L = 0;
	char *s = new char[size + 1];
	s[0] = 0, s[R - 1] = 0; // в начало массива ложим нулевой символ

	while (true) // бесконечный цикл
	{
		if (!fgets(s + L, R - L + 1, f)) // fgets возвращает NULL если произошла ошибка
		if (feof(f) && s[0])
			return s;	// конец файла был достигнут, но в массиве s что-то есть - возращаем его как результат работы программы
		else			// конец файла был достигнут и ни один символ не был прочитан
		{
			delete[]s; return 0;
		}

		//если функция fgets отработала, то проверяем - если в последнем элементе массива не пустой
		//символ (записан c fgets другой, а не признак конца строки - '\0' или '\n'), то значит еще не все считано
		if (*(s + R - 1) && *(s + R - 1) != '\n')
		{
			char* newS = new char(R + size + 1); // новый массив, увеличенный на size элементов
			strcpy(newS, s); // копируем в новый массив "старый" короткий
		//	cout << "String S = " << s << "\t" << "String newS = " << newS << endl; // отладка - удалить
			delete []s; // старый короткий массив теперь не нужен
			s = newS; // устанавливаем указатель на начало нового массива
			L = R;			//левый конец сдвигаем вправо
			R += size;		//правый конец тоже сдвигаем на size
			s[R - 1] = 0;	//обнуляем последний элемент char массива - ставим признак конца строки
		}
		else	return s;
	}
}
int main()
{
	//setlocale(LC_ALL, "Russian"); // только ломает

	printf("Input long string \n");

	char* s1 = ReadLongString(stdin);  // Читаем строчку с консоли
	//s = ReadLongString("1.txt");
	cout << s1 << endl;
	// Выводим. Длинна будет всегда на единицу больше визуальной, т.к. в строке будет перевод строки \n

	printf("Readed: %s\nLength=%d\n", s1, strlen(s1));

	// Сохраняем в файл - можно даже кириллицу набирать
	// но смотреть такой файло надо будет в Notepad++ --> Кодировки --> Кириллица --> OEM866
	printf("Saving it to file file.txt (encoding OEM866)\n");
	FILE* out = fopen("file.txt", "w");
	// в функцию передаётся void* указатель, поэтому вторым параметром (1) мы говорим, сколько байт занимает один элемент массива
	fwrite(s1, 1, strlen(s1), out);
	// Не забываем закрыть файл!
	fclose(out);

	// Удаляем строку из кучи
	delete [] s1;

	printf("Load it from file.txt\n");

	// Читаем файл
	FILE* in = fopen("file.txt", "r");
	if (in != NULL)
	{
		char* s2 = ReadLongString(in);
		fclose(in);

		printf("Read from file: %s", s2);

		// Не забываем освободить память
		delete[] s2;
	}
	else cout << "Error !!!" << endl;
	return 0;
}
//////////////////////////////////  realloc дополнительное задание
#include "stdafx.h"

#include <cstdio>
#include <cstring>
#include <clocale>
#include <iostream>

//using namespace System;
using namespace std;


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
	int N = 3;
char *p;
p = (char *) malloc(N);
//p = new char[N];
char *newp = new char[N];

if(!p) {
printf("Allocation error.");
exit (1);
}
fgets(p, N, stdin);
p[N-1]=123;
while (p[N-1] != 123)
{
fgets(p, N, stdin);
strcpy(newp, p);
newp = (char *) realloc (newp,++N);
if(!newp) {
printf("Allocation error.");
exit (1);
}
strcat (newp, p);
}

printf(p);


free(p);
free(newp);
//delete [] p;
//delete [] newp;
return 0;
}



