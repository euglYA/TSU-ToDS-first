
#include "filetracker.h"

FileTracker::FileTracker() { }

void FileTracker::addFile(const QString filePath) {

    for (int i = 0; i < filesArray.size(); i++) {
        if (filesArray[i].getPath() == filePath)
            return;
    }

    FileInfo file(filePath);
    filesArray.append(file);
}


