#include "FileWatcher.h"

FileWatcher::FileWatcher(const QStringList &fileWays, QObject *parent)
    : QObject(parent)
{
    //инициализация списка файлов
    for (const QString &fileWay : fileWays)
    {
        watchedFiles.append(FileState(fileWay));
        //сохраняем начальное состояние каждого файла.
    }

    connect(&timer, &QTimer::timeout, this, &FileWatcher::checkFiles);
    //таймер будет вызывать checkFiles().

    timer.start(1000);
    //проверка каждую секунду.
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

