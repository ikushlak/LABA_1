#include "FileState.h"

FileState::FileState(const QString & failWay):
    failWay_d(failWay), exist_d(false), size_d(0)
{
    QFileInfo info(failWay_d);

    exist_d = info.exists();

    if(exist_d)
    {
        size_d = int(info.size());
    }
    else
    {
        size_d = 0;
    }

} //запоминаем путь к файлу

QString FileState::getWay() const
{
    return failWay_d; //возвращаем путь к файлу
}

int FileState::getSize() const
{
    return size_d;//возвращаем размер файла
}

bool FileState::getExist() const
{
    return exist_d;//возвращаем существование файла
}
