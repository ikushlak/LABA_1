#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>

#include "FileState.h"

int main( int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //проверка FileState
    FileState file("test.txt");

    qDebug() << "Way" <<file.getWay();
    qDebug() << "Exists" <<file.getExist();
    qDebug() << "Size" <<file.getSize();

    return 0;
}
