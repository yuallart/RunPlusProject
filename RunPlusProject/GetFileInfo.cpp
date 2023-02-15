/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ┌──────────────────────────────────┐
 * │　\author: Yuallart
 * │　\version: 1.0.0
 * │  \saying: 不经一番寒彻骨，怎得梅花扑鼻香
 * │  \deprecated: The project must be described...
 * └──────────────────────────────────┘
 */

#include "GetFileInfo.h"

QFileInfoList* GetFileInfo::getFileInfoList() const
{
    return fileInfoList;
}

nlohmann::json* GetFileInfo::getFileInfoJson() const
{
    return fileInfoJson;
}

GetFileInfo& GetFileInfo::getFileInfo(const char* filePath)
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

GetFileInfo& GetFileInfo::toInfoJson()
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

GetFileInfo& GetFileInfo::toInfoMap()
{
    if (fileInfoList->empty())
    {
        qDebug() << "Read failure";
        return *this;
    }
    QMap<QString, QString> fileMap;
    for (QFileInfoList::iterator iterator = fileInfoList->begin(); iterator != fileInfoList->end(); ++iterator)
    {
        fileMap.insert(iterator.i->t().fileName(), iterator.i->t().filePath());
    }
    *fileInfoMap = fileMap;
    return *this;
}
