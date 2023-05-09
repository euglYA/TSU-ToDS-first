#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H
#include "filetracker.h"


class console_output
{
public:
    console_output();
    ~console_output();

public slots:
    void output(FileInfo file) const;


};

#endif // CONSOLE_OUTPUT_H
