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
#include <qdir.h>
#include <QDebug>
#include <nlohmann/json.hpp>
/**
 * \brief 文件处理类
 */
class GetFileMethods
{
    nlohmann::json* fileInfoJson = new nlohmann::basic_json<>;
    QFileInfoList* fileInfoList = new QFileInfoList();
public:
    QFileInfoList* getFileInfoList() const
    {
        return fileInfoList;
    }

    nlohmann::json* getFileInfoJson() const
    {
        return fileInfoJson;
    }

    /**
     * \brief 此函数用于获取指定文件路径下的所有文件，只检索文件
     * \param filePath 接收一个目录地址字符串
     * \return 返回文件列表的长度
     */
    GetFileMethods& getFileInfo(const char* filePath)
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

    /**
     * @brief 将获取到的文件信息转化为列表
     * @return 返回一个JSON对象
     */
    GetFileMethods& toInfoJson()
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

    QString getFileText(const char* filePath, QString& fileText, const QByteArray& openCodec = "UTF-8") const
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
            textStream.setCodec(openCodec);
            fileText = textStream.readAll();
        }
        return file.errorString();
    }

    /**
     * \brief 文件内容读取方法
     * \param filePath 文件路径
     * \param fileText 文件内容
     * \param fileCodec 使用什么编码打开
     * \return 返回读取到的文件内容
     */
    QString getFileText(const QString& filePath, QString& fileText, const QByteArray& fileCodec = "UTF-8") const
    {
        QFile file(filePath.toUtf8());
        if (file.exists())
        {
            if (file.open(QIODevice::ReadOnly))
            {
                QTextStream textStream(&file);
                textStream.setCodec(fileCodec);
                fileText = textStream.readAll();
            }
        }
        return file.errorString();
    }
};
