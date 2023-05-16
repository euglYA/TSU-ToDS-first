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
    tracker.addFile("C:\\Users\\euglYA\\Desktop\\zxc1.txt");
    tracker.addFile("C:\\Users\\euglYA\\Desktop\\zxc2.txt");

    tracker.startChecking();

    return a.exec();
}
