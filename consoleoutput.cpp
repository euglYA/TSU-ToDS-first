
#include "consoleoutput.h"

ConsoleOutput* ConsoleOutput::instance = nullptr;

ConsoleOutput::ConsoleOutput() { }

ConsoleOutput::~ConsoleOutput() { }

ConsoleOutput &ConsoleOutput::get() {
    if (instance == nullptr) {
        instance = new ConsoleOutput();
    }

    return *instance;
}

void ConsoleOutput::output(FileInfo file) {
    std::cout << file.getPath().toStdString() << file.stateToString() << std::endl;
}
