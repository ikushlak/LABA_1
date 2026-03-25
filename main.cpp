#include <QCoreApplication>
//#include <QDebug>
//#include <QFileInfo>
#include <QStringList>
#include <QTextStream>

#include "FileState.h"
#include "FileWatcher.h"
#include "FileLogger.h"
#include "ConsoleRead.h"

int main( int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileWatcher watcher;
    FileLogger logger;
    ConsoleRead read;

    QObject::connect(&watcher, &FileWatcher::fileChanged,
    &logger, &FileLogger::onFileChanged);

    QObject::connect(&watcher, &FileWatcher::fileExistChanged,
    &logger, &FileLogger::onFileExist);

    //обработка строк из консоли
    QObject::connect(&read, &ConsoleRead::lineRead, [&](const QString &line)
    {
        QString input = line.trimmed();

        //команда выхода
        if (input.toLower() == "exit")
        {
            logger.onMessage("End program...");
            read.stop();
            QCoreApplication::quit();
            return;
        }


        //команда вывода списка
        if (input.toLower() == "list")
        {
            QList<FileState> files = watcher.getWatchedFiles();

            if (files.isEmpty())
            {
                logger.onMessage("List empty");
                return;
            }

            logger.onMessage("Wathed fails:");

            for (int i = 0; i < files.size(); ++i)
            {
                QString message = QString::number(i + 1) + ". " + files[i].getWay();

                if (files[i].getExist())
                {
                    message += " (exist, size = " + QString::number(files[i].getSize()) + ")";
                }
                else
                {
                    message += " (not exist)";
                }

                logger.onMessage(message);
            }

            return;
        }

        //команда удаления
        if (input.startsWith("delete ", Qt::CaseInsensitive))
        {
            QString way = input.mid(7).trimmed();

            if (watcher.deleteWay(way))
            {
                logger.onMessage("Delete file: " + way);
            }
            else
            {
                logger.onMessage("No this file in watched");
            }

            return;
        }

        //пустой ввод
        if (input.isEmpty())
        {
            logger.onMessage("Empty input");
            return;
        }

        //любой другой ввод считаем полным путем к файлу
        QStringList ways;
        ways << input;

        watcher.addWay(ways);
        logger.onMessage("Input: " + input);
    });

    logger.onMessage("Input way, list, delete <way> or exit:");
    read.start();

    return a.exec();
}
