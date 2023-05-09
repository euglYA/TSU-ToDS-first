#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H
#include "fileinfo.h"


class ConsoleOutput : public QObject
{
    Q_OBJECT
public:
    ConsoleOutput();
    ~ConsoleOutput();

public slots:
    void output(FileInfo file);

};

#endif // CONSOLE_OUTPUT_H
