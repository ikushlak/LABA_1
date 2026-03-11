#ifndef FILESTATE_H
#define FILESTATE_H

#include <QString> //для пути к файлу
#include <QtGlobal> //для размера файла

struct FileState
{
    QString way; //путь к файлу

    bool exist = false; //есть ли файл

    qint64 size = 0; //его размер
};

#endif // FILESTATE_H
