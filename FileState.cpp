#include "FileState.h"

FileState::FileState(const QString & failWay):
    failWay_d(failWay), exist_d(false), size_d(0)
{
    QFileInfo info(failWay_d);
    // Создаём QFileInfo, чтобы получить текущее состояние файла.

    exist_d = info.exists();
    // Сохраняем факт существования файла.

    if(exist_d)
    {
        size_d = int(info.size());
        // Сохраняем факт существования файла
    }
    else
    {
        size_d = 0;
    }

}

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
