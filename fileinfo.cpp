
#include "fileinfo.h"

FileInfo::FileInfo() {
    _size = 0;
    _state = fileStates::not_exist;
    _path = "";
}

FileInfo::FileInfo(const QString filePath) {
    QFileInfo fl(filePath);

    if (fl.exists()) {
        _size = fl.size();
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

bool FileInfo::check() {
    QFileInfo fl(_path);

    if (fl.exists()) {
        int size = fl.size();

        if (_size != size) {
            _state = fileStates::changed;
        }

        return true;
    }
    else {
        _state = fileStates::not_exist;
        _size = 0;

        return false;
    }
}
