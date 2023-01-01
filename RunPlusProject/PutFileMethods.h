/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ┌──────────────────────────────────┐
 * │　\author: Yuallart
 * │　\version: 1.0.0
 * │  \saying: 不经一番寒彻骨，怎得梅花扑鼻香
 * │  \deprecated: The project must be described...　　　　　　　　　　　　
 * └──────────────────────────────────┘
 */
#pragma once
#include <utility>

/**
 * \brief 文件写入类
 */
class PutFileMethods
{
    QByteArray encoding = "UTF-8";
public:
    PutFileMethods(QByteArray encoding): encoding(std::move(encoding))
    {
    }

    PutFileMethods() = default;

    /**
     * \brief 默认使用UTF-8编码写入文件
     * \param fileName 文件路径
     * \param fileText 文件内容
     */
    void writeFile(const char* fileName, const char* fileText) const
    {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
        QTextStream textStream(&file);
        textStream.setCodec(encoding);
        const QString text(encoding);
        textStream << text;
        file.close();
    }

    /**
     * \brief 默认使用UTF-8编码写入文件
     * \param fileName 文件路径
     * \param fileText 文件内容
     */
    void writeFile(QByteArray* fileName, QByteArray* fileText) const
    {
        QFile file(*fileName);
        file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
        QTextStream textStream(&file);
        textStream.setCodec(encoding);
        const QString text(*fileText);
        textStream << text;
        file.close();
    }

    /**
     * \brief 默认使用UTF-8编码写入文件
     * \param fileName 文件路径
     * \param fileText 文件内容
     */
    void writeFile(QString* fileName, QString* fileText) const
    {
        QFile file(*fileName);
        file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
        QTextStream textStream(&file);
        textStream.setCodec(encoding);
        const QString text(*fileText);
        textStream << text;
        file.close();
    }
};
