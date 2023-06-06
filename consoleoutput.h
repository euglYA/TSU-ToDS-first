#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H
#include "fileinfo.h"


class ConsoleOutput : public QObject
{
    Q_OBJECT
public:
    static ConsoleOutput& instance() {
        static ConsoleOutput instance;
        return instance;
    }

public slots:
    void output(FileInfo file);


private:
    ConsoleOutput();
    ~ConsoleOutput();
};

#endif // CONSOLE_OUTPUT_H
