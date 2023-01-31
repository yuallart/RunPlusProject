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
#include <QFile>
#include <QTextStream>
#include <QDebug>
/**
 * \brief 文件写入类
 */
class WriteFileMethods
{
    QByteArray codec;
public:

    WriteFileMethods() = default;

    WriteFileMethods(QByteArray codec);
    /**
     * \brief 默认使用UTF-8编码写入文件
     * \param fileName 文件路径
     * \param fileText 文件内容
     */
    bool writeFile(const char* fileName, const char* fileText) const;

    /**
     * \brief 默认使用UTF-8编码写入文件
     * \param fileName 文件路径
     * \param fileText 文件内容
     */
    bool writeFile(const QByteArray& fileName, const QByteArray& fileText) const;

    /**
     * \brief 默认使用UTF-8编码写入文件
     * \param fileName 文件路径
     * \param fileText 文件内容
     */
    bool writeFile(const QString& fileName, const QString& fileText) const;
};
