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
    explicit FileWatcher(const QStringList &fileWays, QObject *parent = nullptr);

signals:
    void fileChanged(const FileState &file);
    //файл изменил размер.

    void fileExistChanged(const FileState &file);
    //файл появился или исчез.

private slots:
    void checkFiles();

private:
    QList<FileState> watchedFiles;
    //список файлов с сохранённым состоянием.

    QTimer timer;
    //таймер проверки.
};



#endif // FILEWATCHER_H
