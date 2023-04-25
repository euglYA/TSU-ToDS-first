
#include "fileinfo.h"

FileInfo::FileInfo() { }

FileInfo::FileInfo(const QString filePath) {
    QFileInfo temp(filePath);

    if (temp.exists()) {
        _size = temp.size();
        _path = filePath;
        _state = fileStates::exist;
    }
    else {
        _size = 0;
        _state = fileStates::not_exist;
    }
}
