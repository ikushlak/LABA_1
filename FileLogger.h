#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <QObject>
#include "FileState.h"

class FileLogger : public QObject
{
    Q_OBJECT

public:
    explicit FileLogger(QObject *parent = nullptr);

public slots:
    void onFileChanged(const FileState &file);
    void onFileExist(const FileState &file);
};

#endif // FILELOGGER_H
