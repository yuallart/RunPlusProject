/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ┌──────────────────────────────────┐
 * │　\author: Yuallart
 * │　\version: 1.0.0
 * │  \saying: 不经一番寒彻骨，怎得梅花扑鼻香
 * │  \deprecated: The project must be described...
 * └──────────────────────────────────┘
 */

#include "ReadFileMethods.h"

#include <utility>


ReadFileMethods::ReadFileMethods(QByteArray codec):codec(std::move(codec))
{
}

QString ReadFileMethods::readFileAllData(const char* filePath, QString& fileText) const
{
    QFile file(QString::fromLocal8Bit(filePath));
    if (!file.exists())
    {
        qDebug() << "Read failure";
        return file.errorString();
    }
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream textStream(&file);
        textStream.setCodec(codec);
        fileText = textStream.readAll();
    }
    return file.errorString();
}

QString ReadFileMethods::readFileAllData(const QString& filePath, QString& fileText) const
{
    QFile file(filePath.toUtf8());
    if (file.exists())
    {
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream textStream(&file);
            textStream.setCodec(codec);
            fileText = textStream.readAll();
        }
    }
    return file.errorString();
}
