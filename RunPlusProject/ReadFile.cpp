/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ┌──────────────────────────────────┐
 * │　\author: Yuallart
 * │　\version: 1.0.0
 * │  \saying: 不经一番寒彻骨，怎得梅花扑鼻香
 * │  \deprecated: The project must be described...
 * └──────────────────────────────────┘
 */

#include "ReadFile.h"
#include <iostream>

 /**
  * \brief 文件内容读取方法
  * \param filePath 文件路径
  * \return 返回读取到的文件内容
  */
QString ReadFile::readFileData(const QByteArray& filePath)
{
    QString fileText;
    QFile file(filePath);
    if (!file.exists())
    {
        errorText = file.errorString();
        qDebug() << errorText;
        return nullptr;
    }
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream textStream(&file);
        textStream.setCodec(fileCodec);
        return textStream.readAll();
    }
    return nullptr;
}

QString ReadFile::readFileData(const QString& filePath)
{
    QString fileText;
    QFile file(filePath);
    if (!file.exists())
    {
        errorText = file.errorString();
        qDebug() << errorText;
        return nullptr;
    }
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream textStream(&file);
        textStream.setCodec(fileCodec);
        return textStream.readAll();
    }
    return nullptr;
}
