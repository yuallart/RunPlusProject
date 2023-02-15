/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ┌──────────────────────────────────┐
 * │　\author: Yuallart
 * │　\version: 1.0.0
 * │  \saying: 不经一番寒彻骨，怎得梅花扑鼻香
 * │  \deprecated: The project must be described...
 * └──────────────────────────────────┘
 */

#include "WriteFile.h"
#include <nlohmann/json.hpp>
#include <QTextStream>
#include <QFile>

WriteFile::WriteFile(QByteArray codec): codec(std::move(codec))
{
}


WriteFile& WriteFile::writeFile(const QByteArray& filePath, const QByteArray& fileText)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream textStream(&file);
        textStream.setCodec(codec);
        textStream << fileText;
    }
    else
    {
        qDebug() << "write error!";
    }
    file.close();
    return *this;
}

WriteFile& WriteFile::writeFile(const QString& filePath, const QString& fileText)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream textStream(&file);
        textStream.setCodec(codec);
        textStream << fileText;
    }
    else
    {
        qDebug() << "write error!";
    }
    file.close();
    return *this;
}