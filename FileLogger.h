#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <QObject>
#include "FileState.h"

//для реализации сигнально слотной связи. выводит информацию в консоль
class FileLogger : public QObject
{
    Q_OBJECT

public:
    explicit FileLogger(QObject *parent = nullptr);

public slots:
    void onFileChanged(const FileState &file);//вывод о изменении файла
    void onFileExist(const FileState &file);//вывод о изменении существования файла
    void onMessage(const QString &message);//вывод информационных сообщений
};

#endif // FILELOGGER_H
