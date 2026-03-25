#include "ConsoleRead.h"
#include <iostream>

ConsoleRead::ConsoleRead(QObject *parent)
    : QThread(parent), running(true)
{
}

void ConsoleRead::stop()
{
    running = false;
}

void ConsoleRead::run()
{
    std::string lines;

    while (running)
    {
        if (!std::getline(std::cin, lines))
        {
            break;
        }

        emit lineRead(QString::fromStdString(lines));
    }
}
