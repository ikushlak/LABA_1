#ifndef CONSOLEREAD_H
#define CONSOLEREAD_H

#include <QThread>
#include <QString>
#include <atomic>

//класс для чтения консоли
class ConsoleRead : public QThread
{
    Q_OBJECT

public:
    explicit ConsoleRead(QObject *parent = nullptr);
    void stop();

protected:
    void run() override;

signals:
    void lineRead(const QString &line);

private:
    std::atomic<bool> running;
};


#endif // CONSOLEREAD_H
