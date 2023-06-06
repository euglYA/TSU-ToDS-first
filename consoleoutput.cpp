
#include "consoleoutput.h"

ConsoleOutput::ConsoleOutput() { }

ConsoleOutput::~ConsoleOutput() { }

void ConsoleOutput::output(FileInfo file) {
    std::cout << file.getPath().toStdString() << file.stateToString() << std::endl;
}
