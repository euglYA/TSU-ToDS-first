#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H
#include "fileinfo.h"


class ConsoleOutput : public QObject
{
    Q_OBJECT
public:
    ~ConsoleOutput();
    static ConsoleOutput& get();

public slots:
    void output(FileInfo file);


private:
    ConsoleOutput();
    static ConsoleOutput *instance;
};

#endif // CONSOLE_OUTPUT_H
