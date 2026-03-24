#ifndef FILESTATE_H
#define FILESTATE_H

#include <QString> //для пути к файлу
#include <QFileInfo> //для размера файла

class FileState
{
public:
    FileState(const QString & failWay);//конструктор класса

    QString getWay() const; //получаем путь к файлу
    bool getExist() const; //узнаем есть ли файл
    int getSize() const; //узнаем его размер

private:
    //храним данные о файлах
    QString failWay_d;
    bool exist_d;
    int size_d;
};

#endif // FILESTATE_H
