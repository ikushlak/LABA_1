#include "FileLogger.h"
#include <QTextStream>

FileLogger::FileLogger(QObject *parent)
    : QObject(parent)
{
}

void FileLogger::onFileChanged(const FileState &file)
{
    QTextStream(stdout) << "Fail " << file.getWay()
        << " exist. New size: "
        << file.getSize() << "\n";
}

void FileLogger::onFileExist(const FileState &file)
{
    if (file.getExist())
    {
        QTextStream(stdout) << "Fail " << file.getWay()
            << " exist. Size: "
            << file.getSize() << "\n";
    }
    else
    {
        QTextStream(stdout) << "Fail " << file.getWay()
            << " not exist\n";
    }
}
