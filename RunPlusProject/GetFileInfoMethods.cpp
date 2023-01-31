/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ┌──────────────────────────────────┐
 * │　\author: Yuallart
 * │　\version: 1.0.0
 * │  \saying: 不经一番寒彻骨，怎得梅花扑鼻香
 * │  \deprecated: The project must be described...
 * └──────────────────────────────────┘
 */

#include "GetFileInfoMethods.h"

QFileInfoList* GetFileInfoMethods::getFileInfoList() const
{
    return fileInfoList;
}

nlohmann::json* GetFileInfoMethods::getFileInfoJson() const
{
    return fileInfoJson;
}

GetFileInfoMethods& GetFileInfoMethods::getFileInfo(const char* filePath)
{
    QDir dir(QString::fromLocal8Bit(filePath));
    if (!dir.exists())
    {
        qDebug() << "Read failure";
        return *this;
    }
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
    dir.setSorting(QDir::DirsFirst);
    //指向一个list
    *fileInfoList = dir.entryInfoList();
    return *this;
}

GetFileInfoMethods& GetFileInfoMethods::toInfoJson()
{
    if (fileInfoList->empty())
    {
        qDebug() << "Read failure";
        return *this;
    }
    std::map<std::string, std::string> fileInfo;
    for (QFileInfoList::iterator iterator = fileInfoList->begin(); iterator != fileInfoList->end(); ++iterator)
    {
        std::string fileName = iterator.i->t().fileName().toStdString();
        std::string filePath = iterator.i->t().filePath().toStdString();
        fileInfo.insert(std::make_pair(fileName, filePath));
    }
    *fileInfoJson = nlohmann::json(fileInfo);
    return *this;
}

bool GetFileInfoMethods::isFileExist(const QString& filePath) const
{
    const QFileInfo fileInfo(filePath);
    return fileInfo.isFile();
}

bool GetFileInfoMethods::isDirExist(const QString& filePath) const
{
    const QFileInfo fileInfo(filePath);
    return fileInfo.isDir();
}

bool GetFileInfoMethods::isAnyExist(const QString& filePath) const
{
    const QFileInfo fileInfo;
    return fileInfo.exists();
}
