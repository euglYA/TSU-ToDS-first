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
    QString getPath() const;
    int getSize() const;
    fileStates getState() const;

private:
    int _size = 0;
    QString _path = "";
    fileStates _state = fileStates::not_exist;
};

#endif // FILE_H
