#ifndef FILE_H
#define FILE_H
#include <QString>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <iostream>


class FileInfo
{
    enum class fileStates {exist, not_exist, changed};

public:
    FileInfo() {}
    FileInfo(const QString filePath);
    ~FileInfo() {}

    QString getPath() const;
    int getSize() const;
    fileStates getState() const;

    bool check();
    std::string stateToString();

private:
    int _size = 0;
    QString _path = "";
    fileStates _state = fileStates::not_exist;
};

#endif // FILE_H
