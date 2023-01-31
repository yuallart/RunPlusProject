#pragma once
#include <QTextStream>
#include <utility>
#include "GetFileInfoMethods.h"

/**
 * \brief 文件读取类
 */
class ReadFileMethods
{
    QByteArray codec = "UTF-8";
public:
    explicit ReadFileMethods(QByteArray codec);
    ReadFileMethods() = default;
    /**
     * \brief 文件内容读取方法
     * \param filePath 文件路径
     * \param fileText 文件内容
     * \return 返回读取到的文件内容
     */
    QString readFileAllData(const char* filePath, QString& fileText) const;

    /**
     * \brief 文件内容读取方法
     * \param filePath 文件路径
     * \param fileText 文件内容
     * \return 返回读取到的文件内容
     */
    QString readFileAllData(const QString& filePath, QString& fileText) const;
};
