#ifndef SLOVARDALYA_H_INCLUDED
#define SLOVARDALYA_H_INCLUDED

/// Модуль для работы со словарём Даля

/// Загрузка словаря из файла
void LoadDict(char* path);

/// Статья словаря
struct DictArticle
{
    /// Слово
    char* word;

    /// Описание значения слова
    char* data;
};

/// Итератор результатов поиска
struct DictSearchIterator
{
    /// Запрос, результаты которого возвращает итератор
    char* query;

    // информация, на основе которой итератор знает,
    // где искать следующую запись
};

/// Поиск в словаре по началу слова
/// Возвращает итератор по результатам поиска
DictSearchIterator SearchDict(char* query);

/// Возвращает следующую подходящую статью
/// или пустую, если результатов больше нет
/// (см. IsEmpty)
DictArticle NextResult(DictSearchIterator* iter); // почему указатель?

/// Проверяет, является ли статья пустой
bool IsEmpty(DictArticle a);

#endif // SLOVARDALYA_H_INCLUDED
