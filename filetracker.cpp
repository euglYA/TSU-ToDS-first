
#include "filetracker.h"

FileTracker* FileTracker::instance = nullptr;

FileTracker::FileTracker() { }

FileTracker::~FileTracker() { }

void FileTracker::addFile(const QString filePath) {

    if  (repeatPathCheck(filePath)) {
        return;
    }

    FileInfo file(filePath);

    filesArray.append(file);

    emit changed(filesArray[filesArray.size() - 1]);
}

bool FileTracker::repeatPathCheck(const QString filePath) const {
    for (int i = 0; i < filesArray.size(); i++) {
        if (filesArray[i].getPath() == filePath)
            return true;
    }

    return false;
}

void FileTracker::check() {
    for (int i = 0; i < filesArray.size(); i++) {
        if (filesArray[i].check()) {
            emit changed(filesArray[i]);
        }
    }
}

FileTracker &FileTracker::get() {
    if (instance == nullptr) {
        instance = new FileTracker();
    }

    return *instance;
}

//void FileTracker::startChecking() {
//    while (1) {
//        this->check();
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }
//}
