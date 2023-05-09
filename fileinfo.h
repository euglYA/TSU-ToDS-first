#ifndef FILE_H
#define FILE_H
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <iostream>
#include <QObject>


class FileInfo : public QObject
{
Q_OBJECT
public:

    enum class fileStates {exist, not_exist, changed};

    FileInfo() {}
    FileInfo(const QString& filePath);
    FileInfo(const FileInfo& file);
    ~FileInfo() {}

    QString getPath() const;
    int getSize() const;
    fileStates getState() const;

    bool check();
    std::string stateToString();

    FileInfo& operator=(const FileInfo& file);


private:
    int _size = 0;
    QString _path = "";
    fileStates _state = fileStates::not_exist;
};

#endif // FILE_H
