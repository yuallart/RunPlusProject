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
class WriteFile
{
    QByteArray codec = "UTF-8";
    QString errorText = "";
public:
    WriteFile() = default;

    explicit WriteFile(QByteArray codec);

    QByteArray getCodec() const
    {
        return codec;
    }

    void setCodec(const QByteArray& codec)
    {
        this->codec = codec;
    }

    /**
     * \brief 默认使用UTF-8编码写入文件
     * \param filePath 文件路径
     * \param fileText 文件内容
     */
    WriteFile& writeFile(const QByteArray& filePath, const QByteArray& fileText);

    WriteFile& writeFile(const QString& filePath, const QString& fileText);
};
