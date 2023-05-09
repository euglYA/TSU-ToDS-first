#include <iostream>
#include <QCoreApplication>
#include "filetracker.h"
#include "consoleoutput.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileTracker tracker;
    ConsoleOutput output;

    QObject::connect(&tracker, &FileTracker::changed, &output, &ConsoleOutput::output);

    tracker.addFile("C:\\Users\\euglYA\\Desktop\\zxc.txt");

    while(1)
        tracker.check();

    return a.exec();
}
