#include <iostream>
#include <QCoreApplication>
#include "filetracker.h"
#include "consoleoutput.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject::connect(&FileTracker::instance(), &FileTracker::changed, &ConsoleOutput::instance(), &ConsoleOutput::output);

    FileTracker::instance().addFile("C:\\Users\\euglYA\\Desktop\\zxc.txt");
    FileTracker::instance().addFile("C:\\Users\\euglYA\\Desktop\\zxc1.txt");
    FileTracker::instance().addFile("C:\\Users\\euglYA\\Desktop\\zxc2.txt");

    while (1) {
        FileTracker::instance().check();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return a.exec();
}
