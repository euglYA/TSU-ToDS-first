#ifndef FILETRACKER_H
#define FILETRACKER_H
#include <QMap>
#include <QVector>
#include "fileinfo.h"



class FileTracker : public QObject
{
Q_OBJECT
public:
    FileTracker();
    ~FileTracker() override;
    void addFile(const QString filePath);
    bool repeatPathCheck(const QString filePath) const;
    void check();

signals:
    void changed(FileInfo file);

private:
    QVector<FileInfo> filesArray;
};

#endif // FILETRACKER_H
