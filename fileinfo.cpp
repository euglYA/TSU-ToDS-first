
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
        _path = filePath;
        _state = fileStates::not_exist;
    }
}

QString FileInfo::getPath() const {
    return _path;
}

int FileInfo::getSize() const {
    return _size;
}

FileInfo::fileStates FileInfo::getState() const {
    return _state;
}
