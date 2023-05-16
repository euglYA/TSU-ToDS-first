
#include "fileinfo.h"

FileInfo::FileInfo(const QString& filePath) {
    QFileInfo fl(filePath);

    if (fl.exists()) {
        _size   = fl.size();
        _path   = filePath;
        _state  = fileStates::exist;
    }
    else {
        _size   = 0;
        _path   = filePath;
        _state  = fileStates::not_exist;
    }
}

FileInfo::FileInfo(const FileInfo& file) {
    _path   = file._path;
    _size   = file._size;
    _state  = file._state;
}

QString FileInfo::getPath() const { return _path; }

int FileInfo::getSize()     const { return _size; }

FileInfo::fileStates FileInfo::getState() const { return _state; }

bool FileInfo::check() {
    QFileInfo fl(_path);

    if (fl.exists()) {
        int size = fl.size();

        if  (_size != size) {
            _state  = fileStates::changed;
            _size   = size;
            return true;
        }

        return false;
    }
    else {
        if  (_size != 0) {
            _state  = fileStates::not_exist;
            _size   = 0;
            return true;
        }
        return false;
    }
}

std::string FileInfo::stateToString() {
    switch (_state) {
    case fileStates::changed:
        return " ---> changed";
    case fileStates::exist:
        return " ---> exist";
    case fileStates::not_exist:
        return " ---> not exist";
    default:
        break;
    }

    return "Error, wrong file state";
}

FileInfo &FileInfo::operator=(const FileInfo &file) {

    if  (this == &file) {
        return *this;
    }

    _path   = file._path;
    _size   = file._size;
    _state  = file._state;

    return *this;
}



