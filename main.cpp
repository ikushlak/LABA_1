#include <QCoreApplication>
//#include <QDebug>
//#include <QFileInfo>
#include <QStringList>
#include <QTextStream>

#include "FileState.h"
#include "FileWatcher.h"
#include "FileLogger.h"

int main( int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //проверка работы логгера в связке с остальным
    QStringList fileWays;
    fileWays << "test.txt";

    FileWatcher watcher(fileWays);
    FileLogger logger;

    QObject::connect(&watcher, &FileWatcher::fileChanged,
    &logger, &FileLogger::onFileChanged);

    QObject::connect(&watcher, &FileWatcher::fileExistChanged,
    &logger, &FileLogger::onFileExist);

    return a.exec();

    /*проверка file whather
    QStringList files;
    files << "test.txt";

    FileWatcher watcher(files);
    // Создаём watcher.

    QObject::connect(&watcher, &FileWatcher::fileChanged,[](const FileState &file)
    {
        qDebug() << "Changed:" << file.getWay()<< "size =" << file.getSize();
    });
    // Если файл изменился, просто выводим это.

    QObject::connect(&watcher, &FileWatcher::fileExistChanged,[](const FileState &file)
    {
        qDebug() << "Existence changed:" << file.getWay()<< "exists =" << file.getExist();
    });
    // Если файл появился или исчез, тоже просто выводим.

    return a.exec();*/

    /*проверка FileState
    FileState file("test.txt");

    qDebug() << "Way" <<file.getWay();
    qDebug() << "Exists" <<file.getExist();
    qDebug() << "Size" <<file.getSize();

    return 0;*/
}
