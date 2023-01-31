﻿/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ┌──────────────────────────────────┐
 * │　\author: Yuallart
 * │　\version: 1.0.0
 * │  \saying: 不经一番寒彻骨，怎得梅花扑鼻香
 * │  \deprecated: The project must be described...
 * └──────────────────────────────────┘
 */

#include "WriteFileMethods.h"
#include <nlohmann/json.hpp>
#include <QTextStream>
#include <QFile>

WriteFileMethods::WriteFileMethods(QByteArray codec): codec(std::move(codec))
{
}

bool WriteFileMethods::writeFile(const char* fileName, const char* fileText) const
{
    QFile file(fileName);
    const bool condition = file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    if (condition)
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
    return condition;
}

bool WriteFileMethods::writeFile(const QByteArray& fileName, const QByteArray& fileText) const
{
    QFile file(fileName);
    const bool condition = file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    if (condition)
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
    return condition;
}

bool WriteFileMethods::writeFile(const QString& fileName, const QString& fileText) const
{
    QFile file(fileName);
    const bool condition = file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    if (condition)
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
    return condition;
}
