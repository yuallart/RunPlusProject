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
#include <iostream>
#include <qdir.h>
#include <QDebug>
#include <nlohmann/json.hpp>

/**
 * \brief 文件处理类
 */
class GetFileInfo
{
private:
    nlohmann::json* fileInfoJson = new nlohmann::basic_json<>;
    QFileInfoList* fileInfoList = new QFileInfoList();
    QMap<QString, QString>* fileInfoMap = new QMap<QString, QString>;
public:
    QFileInfoList* getFileInfoList() const;

    nlohmann::json* getFileInfoJson() const;

    /**
     * \brief 此函数用于获取指定文件路径下的所有文件，只检索文件
     * \param filePath 接收一个目录地址字符串
     * \return 返回文件列表的长度
     */
    GetFileInfo& getFileInfo(const char* filePath);

    /**
     * \brief 将获取到的文件信息转化为列表
     * \return 返回一个JSON对象
     */
    GetFileInfo& toInfoJson();

    /**
     * \brief 将获取到的文件信息转化为Map容器
     * \return 返回一个JSON对象
     */
    GetFileInfo& toInfoMap();
    /**
     * \brief 判断文件是否存在
     * \param filePath 文件路径
     * \param isCreate 文件不存在时是否创建
     * \return 返回是否存在的布尔值
     */
    bool isFileExist(const QString& filePath, bool isCreate = false) const
    {
        QFile file(filePath);
        if (!file.exists() && isCreate)
        {
            std::cout << "create isFileExist" << std::endl;
            return file.open(QIODevice::WriteOnly | QIODevice::Truncate);
        }
        return file.exists();
    }

    /**
     * \brief 判断文件夹是否存在
     * \param filePath 文件夹路径
     * \param isCreate 文件夹不存在时，是否创建
     * \return 返回是否存在的布尔值
     */
    bool isDirExist(const QString& filePath, bool isCreate = false) const
    {
        const QFileInfo fileInfo(filePath);
        if (!fileInfo.isDir() && isCreate)
        {
            const QDir dir;
            return dir.mkpath(filePath);
        }
        return fileInfo.exists();
    }

    /**
     * \brief 判断是否存在，当不确定文件类型时使用
     * \param filePath 文件路径
     * \return 返回是否存在的布尔值
     */
    bool isAnyExist(const QString& filePath) const
    {
        const QFileInfo fileInfo(filePath);
        return fileInfo.exists();
    }
};
