#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QStringList>
#include <QList>
#include <QTimer>
#include "FileState.h"

class FileWatcher : public QObject
{
    Q_OBJECT

public:
    explicit FileWatcher(QObject *parent = nullptr);

    void addWay(const QStringList &fileWays);//добавление нового пути отслеживания
    bool deleteWay(const QString &way);//удаление пути отслеживания
    QList<FileState> getWatchedFiles() const;//текущий список отслеживаемых файлов

signals:
    void fileChanged(const FileState &file);
    //файл изменил размер.

    void fileExistChanged(const FileState &file);
    //файл появился или исчез.

private slots:
    void checkFiles();//вызов таймера для проверки файлов

private:
    QList<FileState> watchedFiles;
    //список файлов с сохранённым состоянием.

    QTimer timer;
    //таймер проверки.
};



#endif // FILEWATCHER_H
