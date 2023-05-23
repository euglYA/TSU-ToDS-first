#ifndef FILETRACKER_H
#define FILETRACKER_H
#include <QMap>
#include <QVector>
#include <thread>
#include <chrono>
#include "fileinfo.h"



class FileTracker : public QObject
{
Q_OBJECT
public:
    ~FileTracker() override;
    void addFile(const QString filePath);
    bool repeatPathCheck(const QString filePath) const;
    void check();
    static FileTracker& get();
    //void startChecking();

signals:
    void changed(FileInfo file);

private:
    FileTracker();

    QVector<FileInfo> filesArray;

    static FileTracker *instance;
};

#endif // FILETRACKER_H
