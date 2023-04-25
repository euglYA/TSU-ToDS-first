#ifndef FILE_H
#define FILE_H
#include <QString>
#include <QFile>
#include <QDir>
#include <QFileInfo>


class FileInfo
{
    enum class fileStates {exist, not_exist, changed};

public:
    FileInfo();
    FileInfo(const QString filePath);

private:
    int _size;
    QString _path;
    fileStates _state;
};

#endif // FILE_H
