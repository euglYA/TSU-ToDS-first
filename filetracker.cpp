
#include "filetracker.h"

FileTracker::FileTracker() { }

void FileTracker::addFile(const QString filePath) {

    if (repeatPathCheck(filePath))
        return;

    FileInfo file(filePath);
    filesArray.append(file);
}

bool FileTracker::repeatPathCheck(const QString filePath) const {
    for (int i = 0; i < filesArray.size(); i++) {
        if (filesArray[i].getPath() == filePath)
            return false;
    }

    return true;
}

void FileTracker::check() {
    for (int i = 0; i < filesArray.size(); i++) {
        if (filesArray[i].check()) {
            changed(filesArray[i]);
        }
    }
}
