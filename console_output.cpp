
#include "console_output.h"

console_output::console_output() { }

console_output::~console_output() { }

void console_output::output(FileInfo file) const {
    std::cout << file.getPath().toStdString() << file.stateToString();
}
