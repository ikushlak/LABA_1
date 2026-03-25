#include "FileWatcher.h"

//связываем таймер с проверкой
FileWatcher::FileWatcher(QObject *parent)
    : QObject(parent)
{
    connect(&timer, &QTimer::timeout, this, &FileWatcher::checkFiles);
    //таймер будет вызывать checkFiles().

    timer.start(1000);
    //проверка каждую секунду.
}

//добавление новых путей в список отслеживания
void FileWatcher::addWay(const QStringList &fileWays)
{
    //проходим по всем путям, которые нужно добавить
    for (const QString &way : fileWays)
    {
        bool found = false;

        //проверяем, нет ли такого файла в списке
        for (const FileState &file : watchedFiles)
        {
            if (file.getWay() == way)
            {
                found = true;
                break;
            }
        }

        //если нет, добавляем
        if (!found)
        {
            watchedFiles.append(FileState(way));
        }
    }
}

//удаление пути из списка отслеживания
bool FileWatcher::deleteWay(const QString &way)
{
    //ищем файл с указанным путем
    for (int i = 0; i < watchedFiles.size(); ++i)
    {
        if (watchedFiles[i].getWay() == way)
        {
            watchedFiles.removeAt(i);
            return true;
        }
    }

    //если не нашли false
    return false;
}

//возвращаем список отслеживаемых файлов
QList<FileState> FileWatcher::getWatchedFiles() const
{
    return watchedFiles;
}


void FileWatcher::checkFiles()
{
    for (int i = 0; i < watchedFiles.size(); ++i)
    {
        FileState oldFile = watchedFiles[i];
        //старое состояние.

        FileState newFile(oldFile.getWay());
        //новое состояние.

        if (oldFile.getExist() != newFile.getExist())
        {
            emit fileExistChanged(newFile);
            //файл появился или исчез.
        }
        else if (oldFile.getExist() && newFile.getExist() &&
                 oldFile.getSize() != newFile.getSize())
        {
            emit fileChanged(newFile);
            //размер файла изменился.
        }

        watchedFiles[i] = newFile;
        //обновляем состояние.
    }
}

