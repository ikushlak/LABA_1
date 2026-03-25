#include "FileLogger.h"
#include <QTextStream>

FileLogger::FileLogger(QObject *parent)
    : QObject(parent)
{
}

//вывод: файла изменил размер
void FileLogger::onFileChanged(const FileState &file)
{
    QTextStream(stdout) << "File " << file.getWay()
        << " exist. New size: "
        << file.getSize() << "\n";
}

//вывод: файл появился/исчез
void FileLogger::onFileExist(const FileState &file)
{
    if (file.getExist())
    {
        QTextStream(stdout) << "File " << file.getWay()
            << " exist. Size: "
            << file.getSize() << "\n";
    }
    else
    {
        QTextStream(stdout) << "File " << file.getWay()
            << " not exist\n";
    }
}

//вывод: информационного сообщения (реакция на liste, delete)
void FileLogger::onMessage(const QString &message)
{
    QTextStream(stdout) << message << "\n";
}
